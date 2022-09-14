//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


#include "CDUHeavyIRSPage.h"
#include "Simplane.h"
#include "B78XHConfiguration.h"

auto CDUHeavyIRSPage::preparePage() -> void {
	switch (this->subpage) {
		case INDEX: {
			this->prepareIndex();
		}
		break;
		case ALIGN_TIME_CONFIGURATION: {
			this->prepareAlignTimeConfiguration();
		}
		break;
		default: {
			this->prepareIndex();
		};
	}
}

auto CDUHeavyIRSPage::prepareIndex() -> void {
	this->LTP1({"IRS STATUS", ""});
	this->LLP1(this->getIrsStatusLine());
	this->LLP6({"<BACK", ""});
	this->RTP1({"ALIGN TIME"});
	this->RLP1(this->getAlignTimeLine());
	this->RLP5({"FORCE ALIGN", ""});

	this->rsk1Event = [this]() -> void {
		this->subpage = ALIGN_TIME_CONFIGURATION;
	};

	this->rsk5Event = [this]() -> void {
		Simplane::equipment::irs::forceAlign();
	};

	this->lsk6Event = [this]()-> void {
		this->switchPage(CDUPageType::HEAVY);
	};
}

auto CDUHeavyIRSPage::prepareAlignTimeConfiguration() -> void {
	this->LTP1({"IRS STATUS", ""});
	this->LLP1(this->getIrsStatusLine());

	this->RTP1({"ALIGN TIME"});
	this->RLP1(this->getAlignTimeLine());
	this->RLP2({"INSTANT>", ""});
	this->RLP3({"FAST>", ""});
	this->RLP4({"NORMAL>", ""});
	this->RLP5({"REAL>", ""});
	this->RLP6({"CANCEL>", ""});

	this->rsk1Event = [this]() -> void {
		this->switchPage(CDUPageType::HEAVY_IRS);
	};

	this->rsk2Event = [this]() -> void {
		B78XHConfiguration::irs::setAlignTimeType(IRSAlignTimeType::INSTANT);
		this->switchPage(CDUPageType::HEAVY_IRS);
	};

	this->rsk3Event = [this]() -> void {
		B78XHConfiguration::irs::setAlignTimeType(IRSAlignTimeType::FAST);
		this->switchPage(CDUPageType::HEAVY_IRS);
	};

	this->rsk4Event = [this]() -> void {
		B78XHConfiguration::irs::setAlignTimeType(IRSAlignTimeType::NORMAL);
		this->switchPage(CDUPageType::HEAVY_IRS);
	};

	this->rsk5Event = [this]() -> void {
		B78XHConfiguration::irs::setAlignTimeType(IRSAlignTimeType::REAL);
		this->switchPage(CDUPageType::HEAVY_IRS);
	};

	this->rsk6Event = [this]() -> void {
		this->switchPage(CDUPageType::HEAVY_IRS);
	};
}

auto CDUHeavyIRSPage::getIrsStatusLine() const -> std::vector<std::string> {
	const auto maxIrsState = std::max<IRSState>(Simplane::equipment::irs::l::state(),
	                                            Simplane::equipment::irs::r::state());
	switch (maxIrsState) {
		case IRSState::OFF: {
			return {"OFF", "cred"};
		}
		case IRSState::ALIGNING: {
			return {"ALIGNING", "cblue"};
		}
		case IRSState::ALIGNED: {
			return {"ALIGNED", "cgreen"};
		}
		case IRSState::UNKNOWN:
		default: {
			return {"UNKNOWN", "cred"};
		};
	}
}

auto CDUHeavyIRSPage::getAlignTimeLine() const -> std::vector<std::string> {
	
	switch (B78XHConfiguration::irs::alignTimeType()) {
		case IRSAlignTimeType::INSTANT: {
			return { "INSTANT>", "" };
		}
		case IRSAlignTimeType::FAST: {
			return { "FAST>", "" };
		}
		case IRSAlignTimeType::NORMAL: {
			return { "NORMAL>", "" };
		}
		case IRSAlignTimeType::REAL: {
			return { "REAL>", "" };
		}
		default: {
			return { "REAL>", "" };
		}
	}
}
