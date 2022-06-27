#include "TuningControlPanelALTNNAVPage.h"

void TuningControlPanelALTNNAVPage::render(NVGcontext* context,
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

void TuningControlPanelALTNNAVPage::renderTitle(NVGcontext* context) {
	const std::string title = "ALTN NAV RADIO";

	nvgTextAlign(context, NVG_ALIGN_CENTER | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 25.0f);
	nvgText(context, 170.0f, 28.0f, title.c_str(), nullptr);
}

void TuningControlPanelALTNNAVPage::renderLines(NVGcontext* context) {
	const std::string L1 = "-------";
	const std::string L2 = "---";
	const std::string L3 = "";
	const std::string L4 = "";

	float boundsR12[4];
	float boundsR13[4];
	float boundsR14[4];

	const std::string R11 = "ON";
	const std::string R12 = "←→";
	const std::string R13 = "OFF";
	const std::string R14 = ">";

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


	nvgText(context, 335.0f, 65.0f, R14.c_str(), nullptr);
	nvgTextBounds(context, 335.0f, 65.0f, R14.c_str(), nullptr, boundsR14);
	nvgFillColor(context, nvgRGBA(29, 170, 5, 255));
	nvgText(context, boundsR14[0], 65.0f, R13.c_str(), nullptr);
	nvgTextBounds(context, boundsR14[0], 65.0f, R13.c_str(), nullptr, boundsR13);
	nvgFillColor(context, nvgRGBA(255, 255, 255, 255));
	nvgFontSize(context, 17.0f);
	nvgText(context, boundsR13[0], 63.0f, R12.c_str(), nullptr);
	nvgTextBounds(context, boundsR13[0], 65.0f, R12.c_str(), nullptr, boundsR12);
	nvgFontSize(context, 25.0f);
	nvgText(context, boundsR12[0], 65.0f, R11.c_str(), nullptr);


	nvgText(context, 335.0f, 118.0f, R2.c_str(), nullptr);
	nvgText(context, 335.0f, 168.0f, R3.c_str(), nullptr);
	nvgText(context, 335.0f, 215.0f, R4.c_str(), nullptr);


	/*
	 * TITLES
	 */

	constexpr float offsets[4]{0, 53, 103, 150};

	nvgTextAlign(context, NVG_ALIGN_LEFT | NVG_ALIGN_BASELINE);
	nvgFontSize(context, 17.0f);

	nvgText(context, 20.0f, 50.0f + offsets[0], "ILS-GLS", nullptr);
	nvgText(context, 20.0f, 50.0f + offsets[2], "COURSE", nullptr);

	nvgTextAlign(context, NVG_ALIGN_RIGHT | NVG_ALIGN_BASELINE);
	nvgText(context, 320.0f, 50.0f + offsets[0], "CTRL", nullptr);

	this->resetOnPressEvents();
}
