#include "MCPVSpeedGauge.h"
#include "SimConnectData.h"

bool MCPVSpeedGauge::preInstall() {
	this->verticalSpeedValueVariable = check_named_variable("AP_VS_ACTIVE");
	this->isFPAModeActiveVariable = check_named_variable("XMLVAR_FPA_MODE_ACTIVE");
	return true;
}

bool MCPVSpeedGauge::postInstall(FsContext context) {
	this->fsContext = context;
	NVGparams params;
	params.userPtr = context;
	params.edgeAntiAlias = true;
	this->nvgContext = nvgCreateInternal(&params);

	this->verticalSpeedFont = nvgCreateFont(this->nvgContext, "dseg", "./data/DSEG7ClassicMini-Italic.ttf");
	this->typeFont = nvgCreateFont(this->nvgContext, "roboto", "./data/Roboto-Regular.ttf");
	return true;
}

bool MCPVSpeedGauge::preDraw(sGaugeDrawData* data) {
	const int actualIsFPAModeActive = static_cast<int>(get_named_variable_value(this->isFPAModeActiveVariable));
	const bool actualIsVerticalSpeedActive = static_cast<bool>(get_named_variable_value(this->verticalSpeedValueVariable));

	if(this->lastFPAModeActive != actualIsFPAModeActive || this->lastVerticalSpeedActive != actualIsVerticalSpeedActive) {
		GaugesInvalidateFlags.MCPVSpeedGauge = true;
	}

	if(GaugesInvalidateFlags.MCPVSpeedGauge != true) {
		return true;
	}

	GaugesInvalidateFlags.MCPVSpeedGauge = false;

	this->lastVerticalSpeedActive = actualIsVerticalSpeedActive;
	this->lastFPAModeActive = actualIsFPAModeActive;

	std::string sVSpeed = "";
	std::string sVSpeedMode = "";

	FLOAT64 fVSpeedActive = get_named_variable_value(this->verticalSpeedValueVariable);
	if (this->lastVerticalSpeedActive != false) {
		const int actualDisplayedVerticalSpeed = static_cast<int>(SimConnectData::Autopilot::verticalSpeed.verticalSpeedHoldVar1);
		if (this->lastFPAModeActive == true) {
			sVSpeedMode = "FPA";
			sVSpeed = fmt::format("{}", actualDisplayedVerticalSpeed / 100);
		}
		else {
			sVSpeedMode = "V/S";
			sVSpeed = fmt::format("{}", actualDisplayedVerticalSpeed);
		}
	}

	sGaugeDrawData* p_draw_data = (sGaugeDrawData*)data;
	float pxRatio = (float)p_draw_data->fbWidth / (float)p_draw_data->winWidth;
	
	nvgBeginFrame(this->nvgContext, p_draw_data->winWidth, p_draw_data->winHeight, pxRatio);
	{
		nvgFillColor(this->nvgContext, nvgRGB(0, 0, 0));
		nvgBeginPath(this->nvgContext);
		nvgRect(this->nvgContext, 0, 0, p_draw_data->winWidth, p_draw_data->winHeight);
		nvgFill(this->nvgContext);
		if (fVSpeedActive != 0) {
			nvgFontSize(this->nvgContext, 80.0f);
			nvgFontFace(this->nvgContext, "roboto");
			nvgFillColor(this->nvgContext, nvgRGBA(255, 255, 255, 255));

			nvgTextAlign(this->nvgContext, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
			nvgText(this->nvgContext, 12, -10, sVSpeedMode.c_str(), nullptr);

			nvgFontSize(this->nvgContext, 85.0f);
			nvgFontFace(this->nvgContext, "dseg");
			nvgFillColor(this->nvgContext, nvgRGBA(255, 255, 255, 255));

			nvgTextAlign(this->nvgContext, NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);
			nvgText(this->nvgContext, 500, 12, sVSpeed.c_str(), nullptr);
		}
	}
	nvgEndFrame(this->nvgContext);
	return true;
}

bool MCPVSpeedGauge::preKill() {
	nvgDeleteInternal(this->nvgContext);
	return true;
}
