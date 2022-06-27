#pragma once

#include "BaseGauge.h"
#include "MSFS/Render/nanovg.h"


class PFDPfdGauge: public BaseGauge {
	public:
		bool preInstall() override;
		bool postInstall(FsContext context) override;
		void registerVariables();
		bool preDraw(sGaugeDrawData* data) override;
		void test();
		void renderMainBackground();
		void renderAttitude();
		void renderPitch();
		void renderTriangle();
		void renderDashes();
		void renderDash(int angle, int length);
		void renderCursor();
		void renderSlipSkid();
		bool preDraw(FsContext context, sGaugeDrawData* data) override;
		bool preKill() override;
	private:
		FsContext fsContext = 0;
		NVGcontext* nvgContext = 0;
		float devicePixelRatio = 0;
		float windowWidth = 0;
		float windowHeight = 0;

		int slipSkidVariableId = 0;
		int slipSkidUnitsId = 0;
		int baseFont = 0;
		int heavyFont = 0;

		double pitchPosition = 0;
		double centerPosition = 0;
};
