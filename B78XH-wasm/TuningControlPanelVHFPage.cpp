#include "TuningControlPanelVHFPage.h"
#include "Tools.h"
#include <cmath>
#include <vector>

#include "GaugesInvalidateFlags.h"
#include "TuningControlPanelVHFStorage.h"
#include "fmt/core.h"
#include "SimConnectData.h"


TuningControlPanelVHFPage::TuningControlPanelVHFPage(TuningControlPanelScratchpad* scratchpad) {
	this->scratchpad = scratchpad;
	this->scratchpad->buffer.clear();
}

void TuningControlPanelVHFPage::loadData() {
	int numberOfPagesWithFrequencies = 0;

	if(TuningControlPanelVHFStorage::standbyFrequencies.size() > 24) {
		TuningControlPanelVHFStorage::standbyFrequencies.resize(24);
	}

	numberOfPagesWithFrequencies = std::ceil(TuningControlPanelVHFStorage::standbyFrequencies.size() / 8 + 2);

	this->numberOfPages = std::min<int>(4, std::max<int>(2, numberOfPagesWithFrequencies));
}

void TuningControlPanelVHFPage::handleEvent(TuningControlPanelControlPageEventsID eventId) {
	switch(eventId) {
		case tcp_page_event_l1: {
			this->onL1Pressed();
		}
		break;
		case tcp_page_event_l2: {
			this->onL2Pressed();
		}
		break;
		case tcp_page_event_l3: {
			this->onL3Pressed();
		}
		break;
		case tcp_page_event_l4:
			this->onL4Pressed();
			break;
		case tcp_page_event_r1: {
			this->onR1Pressed();
		}
		break;
		case tcp_page_event_r2: {
			this->onR2Pressed();
		}
		break;
		case tcp_page_event_r3: {
			this->onR3Pressed();
		}
		break;
		case tcp_page_event_r4:
			this->onR4Pressed();
			break;
		case tcp_page_event_prev:
			this->currentPage = std::max<int>(this->currentPage - 1, 1);
			break;
		case tcp_page_event_next:
			this->currentPage = std::min<int>(this->currentPage + 1, this->numberOfPages);
			break;
		case tcp_page_event_off: {
			break;
		}
		case tcp_page_event_stbyup:
			this->selectedStandbyFrequency = std::min<int>(this->selectedStandbyFrequency + 1,
			                                               TuningControlPanelVHFStorage::standbyFrequencies.size());
			break;
		case tcp_page_event_stbydown:
			this->selectedStandbyFrequency = std::max<int>(this->selectedStandbyFrequency - 1, 0);
			break;
		case tcp_page_event_swap: {
			Tools::Frequencies::vhf_index index = Tools::Frequencies::vhf_index::ONE;
			if(SimConnectData::comFrequencies.transmit1 != 0) {
				index = Tools::Frequencies::vhf_index::ONE;
			}

			if(SimConnectData::comFrequencies.transmit2 != 0) {
				index = Tools::Frequencies::vhf_index::TWO;
			}

			if(SimConnectData::comFrequencies.transmit3 != 0) {
				index = Tools::Frequencies::vhf_index::THREE;
			}
			if(this->selectedStandbyFrequency != 0) {
				Tools::Frequencies::setVHFStandbyFrequency(
					index, TuningControlPanelVHFStorage::standbyFrequencies.at(this->selectedStandbyFrequency - 1));
			}

			Tools::Frequencies::swapVHFFrequencies(index);
			this->selectedStandbyFrequency = 0;
		}
		break;
		default:
			break;
	}

	GaugesInvalidateFlags.PEDESTALTuningControlGauge[0] = true;
	GaugesInvalidateFlags.PEDESTALTuningControlGauge[1] = true;
	GaugesInvalidateFlags.PEDESTALTuningControlGauge[2] = true;
}

void TuningControlPanelVHFPage::render(NVGcontext* context,
                                       float windowWidth,
                                       float windowHeight,
                                       float devicePixelRatio) {

	nvgBeginFrame(context, windowWidth, windowHeight, devicePixelRatio);
	{
		nvgFillColor(context, nvgRGB(0, 0, 0));
		nvgBeginPath(context);
		nvgRect(context, 0, 0, windowWidth, windowHeight);
		nvgFill(context);

		nvgFontFace(context, "heavy-fmc");
		nvgFillColor(context, nvgRGBA(255, 255, 255, 255));

		renderTitle(context);
		renderPages(context);
		renderLines(context);
		renderActive(context);
		renderScratchpad(context);
	}
	nvgEndFrame(context);
}

void TuningControlPanelVHFPage::renderLines(NVGcontext* context) {
	if(this->currentPage == 1) {
		int activeCOM = 0;

		if(SimConnectData::comFrequencies.transmit1 != 0) {
			activeCOM = 0;
		}

		if(SimConnectData::comFrequencies.transmit2 != 0) {
			activeCOM = 1;
		}

		if(SimConnectData::comFrequencies.transmit3 != 0) {
			activeCOM = 2;
		}

		const std::string L1 = fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency1);
		const std::string L2 = fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency2);
		const std::string L3 = fmt::format("<{:7.3f}", SimConnectData::comFrequencies.activeFrequency3);
		std::string R1;
		std::string R2;
		std::string R3;

		if(activeCOM == 0) {
			const FLOAT64 standByFrequency = (this->selectedStandbyFrequency == 0
				                                  ? SimConnectData::comFrequencies.standbyFrequency1
				                                  : TuningControlPanelVHFStorage::standbyFrequencies.at(
					                                  this->selectedStandbyFrequency - 1));
			R1 = fmt::format("{:7.3f}>", standByFrequency);
			R2 = fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency2);
			R3 = fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency3);
		} else if(activeCOM == 1) {
			const FLOAT64 standByFrequency = (this->selectedStandbyFrequency == 0
				                                  ? SimConnectData::comFrequencies.standbyFrequency2
				                                  : TuningControlPanelVHFStorage::standbyFrequencies.at(
					                                  this->selectedStandbyFrequency - 1));
			R1 = fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency1);
			R2 = fmt::format("{:7.3f}>", standByFrequency);
			R3 = fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency3);
		} else if(activeCOM == 2) {
			const FLOAT64 standByFrequency = (this->selectedStandbyFrequency == 0
				                                  ? SimConnectData::comFrequencies.standbyFrequency3
				                                  : TuningControlPanelVHFStorage::standbyFrequencies.at(
					                                  this->selectedStandbyFrequency - 1));
			R1 = fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency1);
			R2 = fmt::format("{:7.3f}>", SimConnectData::comFrequencies.standbyFrequency2);
			R3 = fmt::format("{:7.3f}>", standByFrequency);
		}

		nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
		nvgFontSize(context, 25.0f);
		nvgText(context, 5.0f, 65.0f, L1.c_str(), nullptr);
		nvgText(context, 5.0f, 118.0f, L2.c_str(), nullptr);
		nvgText(context, 5.0f, 168.0f, L3.c_str(), nullptr);
		nvgText(context, 5.0f, 215.0f, "<STORE ACTIVE", nullptr);
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgText(context, 335.0f, 65.0f, R1.c_str(), nullptr);
		nvgText(context, 335.0f, 118.0f, R2.c_str(), nullptr);
		nvgText(context, 335.0f, 168.0f, R3.c_str(), nullptr);
		nvgText(context, 335.0f, 215.0f, "", nullptr);
		nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
		nvgText(context, 170.0f, 65.0f, "- L -", nullptr);
		nvgText(context, 170.0f, 118.0f, "- C -", nullptr);
		nvgText(context, 170.0f, 168.0f, "- R -", nullptr);
		nvgText(context, 170.0f, 215.0f, "", nullptr);

		this->resetOnPressEvents();

		this->onL1Pressed = [this](void) {
			if(!this->scratchpad->buffer.empty()) {
				const FLOAT64 data = std::atof((*this).scratchpad->buffer.c_str());
				if(Tools::Frequencies::isVHFFrequencyValid(data)) {
					Tools::Frequencies::setVHFActiveFrequency(Tools::Frequencies::ONE, data);
					this->scratchpad->buffer.clear();
				}
			}
		};

		this->onL2Pressed = [this](void) {
			if(!this->scratchpad->buffer.empty()) {
				const FLOAT64 data = std::atof((*this).scratchpad->buffer.c_str());
				if(Tools::Frequencies::isVHFFrequencyValid(data)) {
					Tools::Frequencies::setVHFActiveFrequency(Tools::Frequencies::TWO, data);
					this->scratchpad->buffer.clear();
				}
			}
		};

		this->onL3Pressed = [this](void) {
			if(!this->scratchpad->buffer.empty()) {
				const FLOAT64 data = std::atof((*this).scratchpad->buffer.c_str());
				if(Tools::Frequencies::isVHFFrequencyValid(data)) {
					Tools::Frequencies::setVHFActiveFrequency(Tools::Frequencies::THREE, data);
					this->scratchpad->buffer.clear();
				}
			}
		};

		this->onL4Pressed = [](void) {
			FLOAT64 data = 0;
			if(SimConnectData::comFrequencies.transmit1 != 0) {
				data = SimConnectData::comFrequencies.activeFrequency1;
			}

			if(SimConnectData::comFrequencies.transmit2 != 0) {
				data = SimConnectData::comFrequencies.activeFrequency2;
			}

			if(SimConnectData::comFrequencies.transmit3 != 0) {
				data = SimConnectData::comFrequencies.activeFrequency3;
			}
			if(Tools::Frequencies::isVHFFrequencyValid(data)) {
				TuningControlPanelVHFStorage::standbyFrequencies.push_back(data);
			}
		};

		this->onR1Pressed = [this](void) {
			if(!this->scratchpad->buffer.empty()) {
				const FLOAT64 data = std::atof((*this).scratchpad->buffer.c_str());
				if(Tools::Frequencies::isVHFFrequencyValid(data)) {
					Tools::Frequencies::setVHFStandbyFrequency(Tools::Frequencies::ONE, data);
					this->scratchpad->buffer.clear();
				}
			}
		};

		this->onR2Pressed = [this](void) {
			if(!this->scratchpad->buffer.empty()) {
				const FLOAT64 data = std::atof((*this).scratchpad->buffer.c_str());
				if(Tools::Frequencies::isVHFFrequencyValid(data)) {
					Tools::Frequencies::setVHFStandbyFrequency(Tools::Frequencies::TWO, data);
					this->scratchpad->buffer.clear();
				}
			}
		};

		this->onR3Pressed = [this](void) {
			if(!this->scratchpad->buffer.empty()) {
				const FLOAT64 data = std::atof((*this).scratchpad->buffer.c_str());
				if(Tools::Frequencies::isVHFFrequencyValid(data)) {
					Tools::Frequencies::setVHFStandbyFrequency(Tools::Frequencies::THREE, data);
					this->scratchpad->buffer.clear();
				}
			}
		};

	} else {

		const int offset = (this->currentPage - 2) * 8;
		std::string values[8];
		const std::string newValue = " ------";


		for(int i = 0; i < 8; i++) {
			if(static_cast<std::vector<double>::size_type>(offset + i) < TuningControlPanelVHFStorage::standbyFrequencies.size()) {
				values[i] = fmt::format("{:7.3f}", TuningControlPanelVHFStorage::standbyFrequencies.at(offset + i));
			} else {
				values[i] = newValue;
				break;
			}
			
		}

		nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
		nvgFontSize(context, 25.0f);
		nvgText(context, 5.0f, 65.0f, values[0].c_str(), nullptr);
		nvgText(context, 5.0f, 118.0f, values[1].c_str(), nullptr);
		nvgText(context, 5.0f, 168.0f, values[2].c_str(), nullptr);
		nvgText(context, 5.0f, 215.0f, values[3].c_str(), nullptr);

		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgText(context, 335.0f, 65.0f, values[4].c_str(), nullptr);
		nvgText(context, 335.0f, 118.0f, values[5].c_str(), nullptr);
		nvgText(context, 335.0f, 168.0f, values[6].c_str(), nullptr);
		nvgText(context, 335.0f, 215.0f, values[7].c_str(), nullptr);

		this->resetOnPressEvents();


		const auto lambdaNewFrequency = [this]() {
			if(!this->scratchpad->buffer.empty()) {
				const FLOAT64 data = std::atof((*this).scratchpad->buffer.c_str());
				if(Tools::Frequencies::isVHFFrequencyValid(data)) {
					TuningControlPanelVHFStorage::standbyFrequencies.push_back(data);
					this->scratchpad->buffer.clear();
				}
			}
		};

		const auto lambdaRemoveFrequency = [this](int index, std::string newValue) {
			return [this, index, newValue]() {
				if(!this->scratchpad->buffer.empty() && this->scratchpad->buffer == newValue) {
					auto frequencies = &TuningControlPanelVHFStorage::standbyFrequencies;
					frequencies->erase(frequencies->begin() + index);
					this->scratchpad->buffer.clear();
				}
			};
		};
		const std::string clearValue = "CLEAR";

		if(values[0] == newValue) {
			this->onL1Pressed = lambdaNewFrequency;
		} else if(!values[0].empty()) {
			this->onL1Pressed = lambdaRemoveFrequency(0 + offset, clearValue);
		}

		if(values[1] == newValue) {
			this->onL2Pressed = lambdaNewFrequency;
		} else if(!values[1].empty()) {
			this->onL2Pressed = lambdaRemoveFrequency(1 + offset, clearValue);
		}

		if(values[2] == newValue) {
			this->onL3Pressed = lambdaNewFrequency;
		} else if(!values[2].empty()) {
			this->onL3Pressed = lambdaRemoveFrequency(2 + offset, clearValue);
		}

		if(values[3] == newValue) {
			this->onL4Pressed = lambdaNewFrequency;
		} else if(!values[3].empty()) {
			this->onL4Pressed = lambdaRemoveFrequency(3 + offset, clearValue);
		}

		if(values[4] == newValue) {
			this->onR1Pressed = lambdaNewFrequency;
		} else if(!values[4].empty()) {
			this->onR1Pressed = lambdaRemoveFrequency(4 + offset, clearValue);
		}

		if(values[5] == newValue) {
			this->onR2Pressed = lambdaNewFrequency;
		} else if(!values[5].empty()) {
			this->onR2Pressed = lambdaRemoveFrequency(5 + offset, clearValue);
		}

		if(values[6] == newValue) {
			this->onR3Pressed = lambdaNewFrequency;
		} else if(!values[6].empty()) {
			this->onR3Pressed = lambdaRemoveFrequency(6 + offset, clearValue);
		}

		if(values[7] == newValue) {
			this->onR4Pressed = lambdaNewFrequency;
		} else if(!values[7].empty()) {
			this->onR4Pressed = lambdaRemoveFrequency(7 + offset, clearValue);
		}
	}
}

void TuningControlPanelVHFPage::renderTitle(NVGcontext* context) {
	const std::string title = (this->currentPage == 1 ? "VHF" : "STORED VHF");

	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 25.0f);
	nvgText(context, 170.0f, 28.0f, title.c_str(), nullptr);
}

void TuningControlPanelVHFPage::renderPages(NVGcontext* context) {
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 17.0f);
	std::string pages = fmt::format("{}/{}", this->currentPage, this->numberOfPages);
	nvgText(context, 320.0f, 28.0f, pages.c_str(), nullptr);
}

void TuningControlPanelVHFPage::renderActive(NVGcontext* context) {
	if(this->currentPage != 1) {
		return;
	}
	/*
	 * Offsets:
	 * Line 1: 0;
	 * Line 2: 53;
	 * Line 3: 103;
	 * Line 4: not needed;
	 */

	int offset = 0;

	if(SimConnectData::comFrequencies.transmit1 != 0) {
		offset = 0;
	}

	if(SimConnectData::comFrequencies.transmit2 != 0) {
		offset = 1;
	}

	if(SimConnectData::comFrequencies.transmit3 != 0) {
		offset = 2;
	}

	const int offsets[3]{0, 53, 103};

	auto beginX = 158;
	auto beginY = 61 + offsets[offset];
	auto endX = 140;
	auto endY = 61 + offsets[offset];
	auto width = 4.0f;
	auto angle = atan2(endY - beginY, endX - beginX);
	auto arrowX1 = endX - 4 * cos(angle - NVG_PI / 7);
	auto arrowY1 = endY - 4 * sin(angle - NVG_PI / 7);
	auto arrowX2 = endX - 4 * cos(angle + NVG_PI / 7);
	auto arrowY2 = endY - 4 * sin(angle + NVG_PI / 7);

	/*
	 * Left arrow
	 */
	nvgBeginPath(context);
	nvgMoveTo(context, beginX, beginY);
	nvgLineTo(context, endX, endY);
	nvgStrokeColor(context, nvgRGBA(59, 183, 213, 255));
	nvgStrokeWidth(context, width);
	nvgLineCap(context, NVG_ROUND);
	nvgStroke(context);
	nvgClosePath(context);

	nvgBeginPath(context);
	nvgStrokeColor(context, nvgRGBA(59, 183, 213, 255));
	nvgStrokeWidth(context, width);
	nvgLineJoin(context, NVG_MITER);

	nvgMoveTo(context, endX, endY);
	nvgLineTo(context, arrowX1, arrowY1);
	nvgLineTo(context, arrowX2, arrowY2);
	nvgLineTo(context, endX, endY);
	nvgStroke(context);
	nvgClosePath(context);

	/**
	 * Right arrow
	 */

	beginX = 181;
	endX = 199;

	angle = atan2(endY - beginY, endX - beginX);
	arrowX1 = endX - 4 * cos(angle - NVG_PI / 7);
	arrowY1 = endY - 4 * sin(angle - NVG_PI / 7);
	arrowX2 = endX - 4 * cos(angle + NVG_PI / 7);
	arrowY2 = endY - 4 * sin(angle + NVG_PI / 7);

	nvgBeginPath(context);
	nvgMoveTo(context, beginX, beginY);
	nvgLineTo(context, endX, endY);
	nvgStrokeColor(context, nvgRGBA(59, 183, 213, 255));
	nvgStrokeWidth(context, width);
	nvgLineCap(context, NVG_ROUND);
	nvgStroke(context);
	nvgClosePath(context);

	nvgBeginPath(context);
	nvgStrokeColor(context, nvgRGBA(59, 183, 213, 255));
	nvgStrokeWidth(context, width);
	nvgLineJoin(context, NVG_MITER);

	nvgMoveTo(context, endX, endY);
	nvgLineTo(context, arrowX1, arrowY1);
	nvgLineTo(context, arrowX2, arrowY2);
	nvgLineTo(context, endX, endY);
	nvgStroke(context);
	nvgClosePath(context);

	/* ACTIVE + STBY TEXTS*/

	const std::string activeText = "ACTIVE";
	std::string standbyText = "STBY";
	if(!TuningControlPanelVHFStorage::standbyFrequencies.empty()) {
		standbyText = fmt::format("STBY - {}/{}", this->selectedStandbyFrequency + 1,
			TuningControlPanelVHFStorage::standbyFrequencies.size() + 1);
	}

	nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 17.0f);
	nvgFillColor(context, nvgRGBA(59, 183, 213, 255));

	nvgText(context, 20.0f, 50.0f + offsets[offset], activeText.c_str(), nullptr);
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BASELINE);
	nvgText(context, 320.0f, 50.0f + offsets[offset], standbyText.c_str(), nullptr);
}
