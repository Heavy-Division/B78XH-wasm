#include "TuningControlPanelRenderer.h"
#include "TuningControlPanelMENUPage.h"
#include "TuningControlPanelALTNNAVPage.h"
#include "TuningControlPanelCABPage.h"
#include "TuningControlPanelGPWSPage.h"
#include "TuningControlPanelINOPPage.h"
#include "TuningControlPanelSATCOMPage.h"
#include "TuningControlPanelVHFPage.h"
#include "TuningControlPanelXPDRPage.h"


void TuningControlPanelRenderer::render(TuningControlPanelControlSwitchID page, sGaugeDrawData* data) {
	checkPage(page);
	(*this).scratchpad.size[0] = 330;
	(*this).scratchpad.size[1] = 25;
	(*this).scratchpad.position[0] = 5;
	(*this).scratchpad.position[1] = 240;

	this->page->loadData();
	const auto pxRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
	const auto winWidth = static_cast<float>(data->winWidth);
	const auto winHeight = static_cast<float>(data->winHeight);
	(*this).page->render(nvgContext, winWidth, winHeight, pxRatio);
}

	void TuningControlPanelRenderer::renderOff(sGaugeDrawData* data){
		const auto devicePixelRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
		const auto windowWidth = static_cast<float>(data->winWidth);
		const auto windowHeight = static_cast<float>(data->winHeight);

		nvgBeginFrame(this->nvgContext, windowWidth, windowHeight, devicePixelRatio);
		{
			nvgFillColor(this->nvgContext, nvgRGB(0, 0, 0));
			nvgBeginPath(this->nvgContext);
			nvgRect(this->nvgContext, 0, 0, windowWidth, windowHeight);
			nvgFill(this->nvgContext);
		}
		nvgEndFrame(this->nvgContext);
	}

void TuningControlPanelRenderer::setContext(FsContext context) {
	NVGparams params;
	params.userPtr = context;
	params.edgeAntiAlias = true;

	nvgContext = nvgCreateInternal(&params);
	nvgCreateFont(nvgContext, "heavy-fmc", "./data/Heavy787FMC.ttf");
}

void TuningControlPanelRenderer::kill() {
	nvgDeleteInternal(nvgContext);
}

/*
 * TODO: Rename the method... The method is not only about switching pages... Better to name the method like "processEvents" and so on.
 */
void TuningControlPanelRenderer::checkPage(TuningControlPanelControlSwitchID page) {
	switch(page) {
		case doNothing:
			break;
		case vhf:
			delete (*this).page;
			(*this).page = new TuningControlPanelVHFPage(&this->scratchpad);
			break;
		case hf:
			delete (*this).page;
			(*this).page = new TuningControlPanelINOPPage("HF");
			break;
		case sat:
			delete (*this).page;
			(*this).page = new TuningControlPanelSATCOMPage();
			break;
		case cab:
			delete (*this).page;
			(*this).page = new TuningControlPanelCABPage();
			break;
		case gpws:
			delete (*this).page;
			(*this).page = new TuningControlPanelGPWSPage();
			break;
		case wxr:
			delete (*this).page;
			(*this).page = new TuningControlPanelINOPPage("WEATHER RADAR");
			break;
		case xpdr:
			delete (*this).page;
			(*this).page = new TuningControlPanelXPDRPage(&this->scratchpad);
			break;
		case l1:
			(*this).page->handleEvent(tcp_page_event_l1);
			break;
		case l2:
			(*this).page->handleEvent(tcp_page_event_l2);
			break;
		case l3:
			(*this).page->handleEvent(tcp_page_event_l3);
			break;
		case l4:
			(*this).page->handleEvent(tcp_page_event_l4);
			break;
		case r1:
			(*this).page->handleEvent(tcp_page_event_r1);
			break;
		case r2:
			(*this).page->handleEvent(tcp_page_event_r2);
			break;
		case r3:
			(*this).page->handleEvent(tcp_page_event_r3);
			break;
		case r4:
			(*this).page->handleEvent(tcp_page_event_r4);
			break;
		case num1:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num1);
			break;
		case num2:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num2);
			break;
		case num3:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num3);
			break;
		case num4:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num4);
			break;
		case num5:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num5);
			break;
		case num6:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num6);
			break;
		case num7:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num7);
			break;
		case num8:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num8);
			break;
		case num9:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num9);
			break;
		case num0:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_num0);
			break;
		case clr:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_clr);
			break;
		case star:
			(*this).scratchpad.handleEvent(tcp_scratchpad_event_star);
			break;
		case prev:
			(*this).page->handleEvent(tcp_page_event_prev);
			break;
		case next:
			(*this).page->handleEvent(tcp_page_event_next);
			break;
		case nav:
			delete (*this).page;
			(*this).page = new TuningControlPanelALTNNAVPage();
			break;
		case menu:
			delete (*this).page;
			(*this).page = new TuningControlPanelMENUPage();
			break;
		case off:
			(*this).page->handleEvent(tcp_page_event_off);
			break;
		case stbyup:
			(*this).page->handleEvent(tcp_page_event_stbyup);
			break;
		case stbydown:
			(*this).page->handleEvent(tcp_page_event_stbydown);
			break;
		case swap:
			(*this).page->handleEvent(tcp_page_event_swap);
			break;
		default:
			delete (*this).page;
			(*this).page = new TuningControlPanelVHFPage(&(*this).scratchpad);
			break;
	}
}
