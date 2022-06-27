#pragma once
#include "BaseGauge.h"
#include "TuningControlPanelRenderer.h"

class PEDESTALTuningControlPanelGauge: public BaseGauge {
	public:
		PEDESTALTuningControlPanelGauge(int id);
		bool preInstall() override;
		bool postInstall(FsContext context) override;
		bool preDraw(sGaugeDrawData* data) override;
		bool preKill() override;

		bool isControlInvalid();
		void invalidateControl() const;
		void redrawControl(sGaugeDrawData* data);
		int id;
	private:
		TuningControlPanelRenderer renderer;
		std::string controlSwitchIdVariable;
		ID controlSwitchIdVariableID{};
		TuningControlPanelControlSwitchID controlSwitchIdVariableValue{};
		bool isGaugeOff = false;
		void setGaugeOff(bool state, sGaugeDrawData* data);
};
