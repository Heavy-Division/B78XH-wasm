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


#include "CDURenderer.h"

CDURenderer::CDURenderer(NVGcontext*& nvg_context,
                         CDUMouseMoveResolver& mouse_move_resolver,
                         CDUMouseClickResolver& mouse_click_resolver
		) : nvgContext(nvg_context),
		    mouseMoveResolver(mouse_move_resolver),
		    mouseClickResolver(mouse_click_resolver),
		    pageRenderer(CDUPageRenderer(nvg_context)), CDUControlIdVariableID(0),
		    mouseCursor(CDUMouseCursor(nvg_context, mouse_move_resolver)),

		    MKInitRef(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 11, 486, "INIT", "REF")),

		    MKRte(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 89, 486, "RTE")),
		    MKDepArr(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 167, 486, "DEP", "ARR")),
		    MKAltn(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 245, 486, "ALTN")),
		    MKVnav(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 323, 486, "VNAV")),

		    MKFix(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 11, 538, "FIX")),
		    MKLegs(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 89, 538, "LEGS")),
		    MKHold(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 167, 538, "HOLD")),
		    MKFmcComm(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 245, 538, "FMC", "COMM")),
		    MKProg(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 323, 538, "PROG")),

		    MKNavRad(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 11, 590, "NAV", "RAD")),
		    MKOfst(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 89, 590, "OFST")),
		    MKRta(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 167, 590, "RTA")),
		    MKHeavy(CDUMainKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 245, 590, "HEAVY")),

		    LSK1(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 86)),
		    LSK2(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 147)),
		    LSK3(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 208)),
		    LSK4(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 269)),
		    LSK5(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 330)),
		    LSK6(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 17, 391)),
		    RSK1(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 86, true)),
		    RSK2(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 147, true)),
		    RSK3(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 208, true)),
		    RSK4(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 269, true)),
		    RSK5(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 330, true)),
		    RSK6(CDUSelectKeyButton(nvgContext, mouse_move_resolver, mouse_click_resolver, 595, 391, true)) {
	this->CDUControlIdVariable = ("CDU_CONTROL_ID");
}

void CDURenderer::render(sGaugeDrawData* data) {
	const auto devicePixelRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
	const auto windowWidth = static_cast<float>(data->winWidth);
	const auto windowHeight = static_cast<float>(data->winHeight);

	nvgBeginFrame(this->nvgContext, windowWidth, windowHeight, devicePixelRatio);
	{
		nvgFillColor(this->nvgContext, nvgRGB(97, 100, 127));
		nvgBeginPath(this->nvgContext);
		{
			nvgRect(this->nvgContext, 0, 0, windowWidth, windowHeight);
		}
		nvgFill(this->nvgContext);
		nvgSave(this->nvgContext);
		{
			nvgTranslate(this->nvgContext, windowWidth / 2 - 249, 34);
			{
				this->pageRenderer.render();
			}
			nvgResetTransform(this->nvgContext);
		}
		nvgRestore(this->nvgContext);

		this->LSK1.event = this->pageRenderer.getCDUPage()->getLSK1Event();
		this->LSK2.event = this->pageRenderer.getCDUPage()->getLSK2Event();
		this->LSK3.event = this->pageRenderer.getCDUPage()->getLSK3Event();
		this->LSK4.event = this->pageRenderer.getCDUPage()->getLSK4Event();
		this->LSK5.event = this->pageRenderer.getCDUPage()->getLSK5Event();
		this->LSK6.event = this->pageRenderer.getCDUPage()->getLSK6Event();
		this->RSK1.event = this->pageRenderer.getCDUPage()->getRSK1Event();
		this->RSK2.event = this->pageRenderer.getCDUPage()->getRSK2Event();
		this->RSK3.event = this->pageRenderer.getCDUPage()->getRSK3Event();
		this->RSK4.event = this->pageRenderer.getCDUPage()->getRSK4Event();
		this->RSK5.event = this->pageRenderer.getCDUPage()->getRSK5Event();
		this->RSK6.event = this->pageRenderer.getCDUPage()->getRSK6Event();

		this->MKInitRef.draw();
		this->MKRte.draw();
		this->MKDepArr.draw();
		this->MKAltn.draw();
		this->MKVnav.draw();
		this->MKFix.draw();
		this->MKLegs.draw();
		this->MKHold.draw();
		this->MKFmcComm.draw();
		this->MKProg.draw();
		this->MKNavRad.draw();
		this->MKOfst.draw();
		this->MKRta.draw();
		this->MKHeavy.draw();
		this->LSK1.draw();
		this->LSK2.draw();
		this->LSK3.draw();
		this->LSK4.draw();
		this->LSK5.draw();
		this->LSK6.draw();
		this->RSK1.draw();
		this->RSK2.draw();
		this->RSK3.draw();
		this->RSK4.draw();
		this->RSK5.draw();
		this->RSK6.draw();

		this->setupMainKeysEvents();

		this->mouseCursor.draw();
	}
	nvgEndFrame(nvgContext);
}

auto CDURenderer::setContext(FsContext context) -> void {
	NVGparams params;
	params.userPtr = context;
	params.edgeAntiAlias = true;
	this->nvgContext = nvgCreateInternal(&params);
	nvgCreateFont(this->nvgContext, "heavy-fmc", "./data/Heavy787FMC.ttf");
}

auto CDURenderer::preInstall() -> void {
	this->CDUControlIdVariableID = check_named_variable(this->CDUControlIdVariable.c_str());
}

auto CDURenderer::postInstall(FsContext context) -> void {
	this->setContext(context);
}

auto CDURenderer::preUpdate() -> void {
	const double controlId = get_named_variable_value(this->CDUControlIdVariableID);
	this->handleControlId(controlId);
}

auto CDURenderer::preDraw(sGaugeDrawData* data) -> void {
	this->render(data);
}

auto CDURenderer::preKill() -> void {
	nvgDeleteInternal(this->nvgContext);
}

auto CDURenderer::setupMainKeysEvents() -> void {
	this->MKInitRef.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::INIT_REF);
	};
	this->MKRte.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::RTE);
	};
	this->MKDepArr.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::DEP_ARR);
	};
	this->MKAltn.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::ALTN);
	};
	this->MKVnav.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::VNAV);
	};
	this->MKFix.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::FIX);
	};
	this->MKLegs.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::LEGS);
	};
	this->MKHold.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::HOLD);
	};
	this->MKFmcComm.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::FMC_COMM);
	};
	this->MKProg.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::PROG);
	};
	this->MKNavRad.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::NAV_RAD);
	};
	this->MKOfst.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::OFST);
	};
	this->MKRta.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::RTA);
	};
	this->MKHeavy.event = [this]() {
		this->pageRenderer.switchPage(CDUPageType::HEAVY);
	};
}

/*
 * TODO: Need to be implemented
 */
auto CDURenderer::handleCDUEvents(CDUEvent eventId) -> void {
}

auto CDURenderer::handlePageSwitching(CDUPageType pageId) -> void {
	this->pageRenderer.switchPage(pageId);
}

auto CDURenderer::handleControlId(double controlId) -> void {
	if(controlId >= 1000) {
		this->handlePageSwitching(static_cast<CDUPageType>(controlId));
	} else if(controlId > 0 && controlId < 1000) {
		this->handleCDUEvents(static_cast<CDUEvent>(controlId));
	}
	set_named_variable_value(this->CDUControlIdVariableID, 0);
}
