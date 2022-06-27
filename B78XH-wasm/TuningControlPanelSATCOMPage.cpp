#include "TuningControlPanelSATCOMPage.h"
#include "GaugesInvalidateFlags.h"
#include "fmt/core.h"

void TuningControlPanelSATCOMPage::render(NVGcontext* context,
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
	}
	nvgEndFrame(context);
}

void TuningControlPanelSATCOMPage::handleEvent(TuningControlPanelControlPageEventsID eventId) {
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
		case tcp_page_event_prev: {
			this->currentPage = std::max<int>(1, this->currentPage - 1);
		}
		break;
		case tcp_page_event_next: {
			this->currentPage = std::min<int>(this->numberOfPages, this->currentPage + 1);
		}
		break;
		case tcp_page_event_off: {
			break;
		}
		case tcp_page_event_stbyup:
			break;
		case tcp_page_event_stbydown:
			break;
		case tcp_page_event_swap:
			break;
		default:
			break;
	}
}

void TuningControlPanelSATCOMPage::renderTitle(NVGcontext* context) {
	const std::string title = (this->currentPage == 1 ? "SATCOM" : "SAT-PHONE");

	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 25.0f);
	nvgText(context, 170.0f, 28.0f, title.c_str(), nullptr);
}

void TuningControlPanelSATCOMPage::renderPages(NVGcontext* context) {
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 17.0f);
	std::string pages = fmt::format("{}/{}", this->currentPage, this->numberOfPages);
	nvgText(context, 320.0f, 28.0f, pages.c_str(), nullptr);
}

void TuningControlPanelSATCOMPage::renderLines(NVGcontext* context) {
	if(this->currentPage == 1) {
		const std::string L1 = "<MAKE CALL";
		const std::string L2 = "";
		const std::string L3 = "<MAKE CALL";
		const std::string L4 = "";

		const std::string R1 = "LOW>";
		const std::string R2 = "DIRECTORY>";
		const std::string R3 = "LOW>";
		const std::string R4 = "";

		nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
		nvgFontSize(context, 25.0f);
		nvgText(context, 5.0f, 65.0f, L1.c_str(), nullptr);
		nvgText(context, 5.0f, 118.0f, L2.c_str(), nullptr);
		nvgText(context, 5.0f, 168.0f, L3.c_str(), nullptr);
		nvgText(context, 5.0f, 215.0f, L4.c_str(), nullptr);
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgText(context, 335.0f, 65.0f, R1.c_str(), nullptr);
		nvgText(context, 335.0f, 118.0f, R2.c_str(), nullptr);
		nvgText(context, 335.0f, 168.0f, R3.c_str(), nullptr);
		nvgText(context, 335.0f, 215.0f, R4.c_str(), nullptr);


		/*
		 * TITLES
		 */

		constexpr float offsets[4]{0, 53, 103, 150};

		nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_BASELINE);
		nvgFontSize(context, 17.0f);

		nvgText(context, 20.0f, 50.0f + offsets[0], "SAT-1: NOT READY", nullptr);
		nvgText(context, 20.0f, 50.0f + offsets[1], "", nullptr);
		nvgText(context, 20.0f, 50.0f + offsets[2], "SAT-2: NOT READY", nullptr);
		nvgText(context, 20.0f, 50.0f + offsets[3], "", nullptr);

		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BASELINE);
		nvgText(context, 320.0f, 50.0f + offsets[0], "PRIORITY", nullptr);
		nvgText(context, 320.0f, 50.0f + offsets[1], "", nullptr);
		nvgText(context, 320.0f, 50.0f + offsets[2], "PRIORITY", nullptr);
		nvgText(context, 320.0f, 50.0f + offsets[3], "", nullptr);

		this->resetOnPressEvents();


	} else {
		const std::string L1 = "<LOG";
		const std::string L2 = "<DIR DETAILS";
		const std::string L3 = "";
		const std::string L4 = "<RETURN";

		const std::string R1 = "BITE OK>";
		const std::string R2 = "CONFIG>";
		const std::string R3 = "";
		const std::string R4 = "";

		nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
		nvgFontSize(context, 25.0f);
		nvgText(context, 5.0f, 65.0f, L1.c_str(), nullptr);
		nvgText(context, 5.0f, 118.0f, L2.c_str(), nullptr);
		nvgText(context, 5.0f, 168.0f, L3.c_str(), nullptr);
		nvgText(context, 5.0f, 215.0f, L4.c_str(), nullptr);
		nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
		nvgText(context, 335.0f, 65.0f, R1.c_str(), nullptr);
		nvgText(context, 335.0f, 118.0f, R2.c_str(), nullptr);
		nvgText(context, 335.0f, 168.0f, R3.c_str(), nullptr);
		nvgText(context, 335.0f, 215.0f, R4.c_str(), nullptr);

		this->resetOnPressEvents();

		this->onL4Pressed = [this](void) {
			this->currentPage = 1;
			GaugesInvalidateFlags.PEDESTALTuningControlGauge[0] = true;
			GaugesInvalidateFlags.PEDESTALTuningControlGauge[1] = true;
			GaugesInvalidateFlags.PEDESTALTuningControlGauge[2] = true;
		};

	}
}
