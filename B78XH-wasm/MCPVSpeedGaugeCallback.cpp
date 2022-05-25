#include <MSFS\MSFS.h>
#include "MSFS\MSFS_Render.h"
#include "MSFS\Render\nanovg.h"
#include <MSFS\Legacy\gauges.h>

#include <string>

#ifdef _MSC_VER
#define snprintf _snprintf_s
#elif !defined(__MINGW32__)
#include <iconv.h>
#endif

struct sMCPVSpeedVars {
	NVGcontext* m_nvgctx = nullptr;
	ENUM m_eFeet;
	ENUM m_eDisplayedVerticalSpeedHoldValue;
	ID m_VSpeedActiveValue;
	ID m_FPAModeActive;
	int m_iFont;
	int m_iTypeFont;
};

sMCPVSpeedVars g_MCPVSpeedVars;

// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool mcp_vspeed_gauge_callback(FsContext ctx, int service_id, void* pData) {
		switch(service_id) {
			case PANEL_SERVICE_PRE_INSTALL: {
				sGaugeInstallData* p_install_data = (sGaugeInstallData*)pData;
				g_MCPVSpeedVars.m_eFeet = get_units_enum("	feet/minute");
				g_MCPVSpeedVars.m_eDisplayedVerticalSpeedHoldValue = get_aircraft_var_enum(
					"AUTOPILOT VERTICAL HOLD VAR");
				g_MCPVSpeedVars.m_VSpeedActiveValue = check_named_variable("AP_VS_ACTIVE");
				g_MCPVSpeedVars.m_FPAModeActive = check_named_variable("XMLVAR_FPA_MODE_ACTIVE");
				return true;
			}
			break;
			case PANEL_SERVICE_POST_INSTALL: {
				NVGparams params;
				params.userPtr = ctx;
				params.edgeAntiAlias = true;
				NVGcontext* nvgctx = nvgCreateInternal(&params);
				g_MCPVSpeedVars.m_nvgctx = nvgctx;
				g_MCPVSpeedVars.m_iFont = nvgCreateFont(nvgctx, "sans", "./data/DSEG7ClassicMini-Italic.ttf");
				g_MCPVSpeedVars.m_iTypeFont = nvgCreateFont(nvgctx, "roboto", "./data/Roboto-Regular.ttf");
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_DRAW: {
				sGaugeDrawData* p_draw_data = (sGaugeDrawData*)pData;
				const char* sVSpeed = "";
				const char* sVSpeedMode = "";
				FLOAT64 fVSpeedActive = get_named_variable_value(g_MCPVSpeedVars.m_VSpeedActiveValue);
				if(fVSpeedActive != 0) {
					FLOAT64 fVSpeed = aircraft_varget(g_MCPVSpeedVars.m_eDisplayedVerticalSpeedHoldValue,
					                                  g_MCPVSpeedVars.m_eFeet, 0);
					if(get_named_variable_value(g_MCPVSpeedVars.m_FPAModeActive) == 1) {
						sVSpeedMode = "FPA";
						fVSpeed = fVSpeed / 100;
					} else {
						sVSpeedMode = "V/S";
					}

					sVSpeed = std::to_string(static_cast<int>(fVSpeed)).c_str();
				}


				float pxRatio = (float)p_draw_data->fbWidth / (float)p_draw_data->winWidth;
				NVGcontext* nvgctx = g_MCPVSpeedVars.m_nvgctx;
				nvgBeginFrame(nvgctx, p_draw_data->winWidth, p_draw_data->winHeight, pxRatio);
				{
					nvgFillColor(nvgctx, nvgRGB(0, 0, 0));
					nvgBeginPath(nvgctx);
					nvgRect(nvgctx, 0, 0, p_draw_data->winWidth, p_draw_data->winHeight);
					nvgFill(nvgctx);
					if(fVSpeedActive != 0) {
						nvgFontSize(nvgctx, 80.0f);
						nvgFontFace(nvgctx, "roboto");
						nvgFillColor(nvgctx, nvgRGBA(255, 255, 255, 255));

						nvgTextAlign(nvgctx, NVG_ALIGN_LEFT | NVG_ALIGN_TOP);
						nvgText(nvgctx, 12, -10, sVSpeedMode, nullptr);

						nvgFontSize(nvgctx, 85.0f);
						nvgFontFace(nvgctx, "sans");
						nvgFillColor(nvgctx, nvgRGBA(255, 255, 255, 255));

						nvgTextAlign(nvgctx, NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);
						nvgText(nvgctx, 500, 12, sVSpeed, nullptr);
					}
				}
				nvgEndFrame(nvgctx);
				return true;
			}
			break;
			case PANEL_SERVICE_PRE_KILL: {
				NVGcontext* nvgctx = g_MCPVSpeedVars.m_nvgctx;
				nvgDeleteInternal(nvgctx);
				return true;
			}
			break;
		}
		return false;
	}
}
