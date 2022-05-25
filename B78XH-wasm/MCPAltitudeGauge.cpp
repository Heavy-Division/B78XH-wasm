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

struct sMCPAltitudeVars
{
	NVGcontext* m_nvgctx = nullptr;
	ENUM m_eFeet;
	ENUM m_eDisplayedAltitudeLockValue;
	int m_iFont;
};

sMCPAltitudeVars g_MCPAltitudeVars;

// ------------------------
// Callbacks
extern "C" {
	MSFS_CALLBACK bool MCPAltitude_gauge_callback(FsContext ctx, int service_id, void* pData)
	{
		switch (service_id)
		{
		case PANEL_SERVICE_PRE_INSTALL:
		{
			sGaugeInstallData* p_install_data = (sGaugeInstallData*)pData;
			g_MCPAltitudeVars.m_eFeet = get_units_enum("FEET");
			g_MCPAltitudeVars.m_eDisplayedAltitudeLockValue = get_aircraft_var_enum("AUTOPILOT ALTITUDE LOCK VAR");
			return true;
		}
		break;
		case PANEL_SERVICE_POST_INSTALL:
		{
			NVGparams params;
			params.userPtr = ctx;
			params.edgeAntiAlias = true;
			NVGcontext* nvgctx = nvgCreateInternal(&params);
			g_MCPAltitudeVars.m_nvgctx = nvgctx;
			g_MCPAltitudeVars.m_iFont = nvgCreateFont(nvgctx, "sans", "./data/DSEG7ClassicMini-Italic.ttf");
			return true;
		}
		break;
		case PANEL_SERVICE_PRE_DRAW:
		{
			sGaugeDrawData* p_draw_data = (sGaugeDrawData*)pData;
			FLOAT64 fAltitude = aircraft_varget(g_MCPAltitudeVars.m_eDisplayedAltitudeLockValue, g_MCPAltitudeVars.m_eFeet, 3);
			const char* sAltitude = std::to_string(static_cast<int>(fAltitude)).c_str();

			float pxRatio = (float)p_draw_data->fbWidth / (float)p_draw_data->winWidth;
			NVGcontext* nvgctx = g_MCPAltitudeVars.m_nvgctx;
			nvgBeginFrame(nvgctx, p_draw_data->winWidth, p_draw_data->winHeight, pxRatio);
			{
				nvgFillColor(nvgctx, nvgRGB(0, 0, 0));
				nvgBeginPath(nvgctx);
				nvgRect(nvgctx, 0, 0, p_draw_data->winWidth, p_draw_data->winHeight);
				nvgFill(nvgctx);

				nvgFontSize(nvgctx, 90.0f);
				nvgFontFace(nvgctx, "sans");
				nvgFillColor(nvgctx, nvgRGBA(255, 255, 255, 255));

				nvgTextAlign(nvgctx, NVG_ALIGN_RIGHT | NVG_ALIGN_TOP);
				nvgText(nvgctx, 500, 12, sAltitude, nullptr);
			}
			nvgEndFrame(nvgctx);
			return true;
		}
		break;
		case PANEL_SERVICE_PRE_KILL:
		{
			NVGcontext* nvgctx = g_MCPAltitudeVars.m_nvgctx;
			nvgDeleteInternal(nvgctx);
			return true;
		}
		break;
		}
		return false;
	}
}