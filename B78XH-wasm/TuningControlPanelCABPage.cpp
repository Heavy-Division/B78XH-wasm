#include "TuningControlPanelCABPage.h"

void TuningControlPanelCABPage::render(NVGcontext* context,
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
		renderLines(context);
	}
	nvgEndFrame(context);
}

void TuningControlPanelCABPage::renderTitle(NVGcontext* context) {
	const std::string title = "CABIN INTERPHONE";

	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 25.0f);
	nvgText(context, 170.0f, 28.0f, title.c_str(), nullptr);
}

void TuningControlPanelCABPage::renderLines(NVGcontext* context) {
	nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
	nvgText(context, 5.0f, 65.0f, "<DOOR 1L", nullptr);
	nvgText(context, 5.0f, 118.0f, "<ALL CALL", nullptr);
	nvgText(context, 5.0f, 168.0f, "<PURSER", nullptr);
	nvgText(context, 5.0f, 215.0f, "<MAKE CALL", nullptr);
	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
	nvgText(context, 335.0f, 65.0f, "DOOR 1R>", nullptr);
	nvgText(context, 335.0f, 118.0f, "GALLEY FWD>", nullptr);
	nvgText(context, 335.0f, 168.0f, "DOOR 3L>", nullptr);
	nvgText(context, 335.0f, 215.0f, "DIRECTORY>", nullptr);

	/*
	 * TITLES
	 */

	constexpr float offsets[4]{0, 53, 103, 150};

	nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 17.0f);

	nvgText(context, 20.0f, 50.0f + offsets[0], "SPEED DIAL", nullptr);

	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BASELINE);
	nvgText(context, 320.0f, 50.0f + offsets[0], "CALL QUEUE", nullptr);

	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);
	nvgText(context, 170.0f, 50.0f + offsets[3], "----------- PA IN USE -----------", nullptr);
}
