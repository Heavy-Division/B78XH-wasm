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


#include "CDUPageRenderer.h"

#include "CDUHeavyConfigurationPage.h"
#include "CDUHeavyIRSPage.h"
#include "CDUHeavyPage.h"
#include "CDUHeavyPayloadManagerPage.h"
#include "CDUHeavySimbriefConfigurationPage.h"
#include "CDUInopPage.h"
#include "CDUNavRadioPage.h"
#include "CDURoutePage.h"

auto CDUPageRenderer::switchPage(CDUPageType page) -> void {
	switch (page) {
		case CDUPageType::INOP: {
			delete this->cduPage;
			this->cduPage = new CDUInopPage(this->context);
		}
		break;
		case CDUPageType::IDENT: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::INIT_REF: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::RTE: {
			delete this->cduPage;
			this->cduPage = new CDURoutePage(this->context);
		}
		break;
		case CDUPageType::DEP_ARR: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::ALTN: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::VNAV: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::FIX: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::LEGS: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::HOLD: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::FMC_COMM: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::PROG: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::NAV_RAD: {
			delete this->cduPage;
			this->cduPage = new CDUNavRadioPage(this->context);
		}
		break;
		case CDUPageType::OFST: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::RTA: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::HEAVY: {
			delete this->cduPage;
			this->cduPage = new CDUHeavyPage(this->context);
		}
		break;
		case CDUPageType::INDEX: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::POS: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::PERF: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::THRUST_LIM: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::TAKEOFF: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::APPROACH: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::NAV_DATA: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::MAINT: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
		break;
		case CDUPageType::HEAVY_IRS: {
			delete this->cduPage;
			this->cduPage = new CDUHeavyIRSPage(this->context);
		}
		break;
		case CDUPageType::HEAVY_CONFIGURATION: {
			delete this->cduPage;
			this->cduPage = new CDUHeavyConfigurationPage(this->context);
		}
		break;
		case CDUPageType::HEAVY_PAYLOAD_MANAGER: {
			delete this->cduPage;
			this->cduPage = new CDUHeavyPayloadManagerPage(this->context);
		}
		break;
		case CDUPageType::HEAVY_SIMBRIEF_CONFIGURATION: {
			delete this->cduPage;
			this->cduPage = new CDUHeavySimbriefConfigurationPage(this->context);
		}
		break;
		default: {
			delete this->cduPage;
			this->cduPage = new CDUIdentPage(this->context);
		}
	}
}

auto CDUPageRenderer::preparePage() -> void {
	/*
	 * Memory leak protection
	 * Lines have to be cleared before every draw (before every calling of getLines() function)
	 */
	this->cduPage->clearLines();
	this->cduPage->clearEvents();
	this->cduPage->preparePage();
}

auto CDUPageRenderer::render() -> void {
	this->preparePage();
	this->drawBackground();
	this->drawLines();
}

auto CDUPageRenderer::drawBackground() -> void {

	nvgFillColor(this->context, nvgRGB(0, 0, 0));
	nvgBeginPath(this->context);
	{
		nvgRect(this->context, 0, 0, 498, 398);
	}
	nvgClosePath(this->context);
	nvgFill(this->context);
}

auto CDUPageRenderer::drawLines() -> void {
	auto lines = this->cduPage->getLines();
	const auto numberOfLines = lines.size();

	for (int i = 0; i < numberOfLines; i++) {
		lineRenderer.draw(lines.at(i).lineType, lines.at(i).lineNumber, lines.at(i).lineAlign, lines.at(i).getData());
	}
}
