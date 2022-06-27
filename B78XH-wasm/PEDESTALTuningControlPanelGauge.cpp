#include "BaseGauge.h"
#include "PEDESTALTuningControlPanelGauge.h"

PEDESTALTuningControlPanelGauge::PEDESTALTuningControlPanelGauge(int id) {
	(*this).controlSwitchIdVariable = ("CONTROL_SWITCH_COM_" + std::to_string(id + 1));
	(*this).id = id;
}

bool PEDESTALTuningControlPanelGauge::preInstall() {
	(*this).controlSwitchIdVariableID = check_named_variable((*this).controlSwitchIdVariable.c_str());
	return true;
}

bool PEDESTALTuningControlPanelGauge::postInstall(FsContext context) {
	renderer.setContext(context);
	set_named_variable_value((*this).controlSwitchIdVariableID, 1);
	return true;
}

bool PEDESTALTuningControlPanelGauge::preDraw(sGaugeDrawData* data) {
	this->controlSwitchIdVariableValue = static_cast<TuningControlPanelControlSwitchID>(get_named_variable_value((*this).controlSwitchIdVariableID));

	if(this->controlSwitchIdVariableValue == TuningControlPanelControlSwitchID::off && this->isGaugeOff) {
		this->setGaugeOff(false, data);
		this->invalidateControl();
	} else if(this->controlSwitchIdVariableValue == TuningControlPanelControlSwitchID::off && !this->isGaugeOff) {
		this->setGaugeOff(true, data);
		return true;
	} else if(this->isGaugeOff) {
		return true;
	}

	if((*this).isControlInvalid()) {
		(*this).redrawControl(data);
	}
	return true;
}

bool PEDESTALTuningControlPanelGauge::preKill() {
	renderer.kill();
	return true;
}

void PEDESTALTuningControlPanelGauge::redrawControl(sGaugeDrawData* data) {
	GaugesInvalidateFlags.PEDESTALTuningControlGauge[(*this).id] = false;
	set_named_variable_value((*this).controlSwitchIdVariableID, 0);
	renderer.render(static_cast<TuningControlPanelControlSwitchID>((*this).controlSwitchIdVariableValue), data);
}

void PEDESTALTuningControlPanelGauge::setGaugeOff(bool state, sGaugeDrawData* data) {
	if(state) {
		set_named_variable_value((*this).controlSwitchIdVariableID, 0);
		renderer.renderOff(data);
	}
	this->isGaugeOff = state;
}

bool PEDESTALTuningControlPanelGauge::isControlInvalid() {
	if ((*this).controlSwitchIdVariableValue == TuningControlPanelControlSwitchID::doNothing && GaugesInvalidateFlags.PEDESTALTuningControlGauge[(*this).id] == false) {
		return false;
	}
	return true;
}

void PEDESTALTuningControlPanelGauge::invalidateControl() const {
	GaugesInvalidateFlags.PEDESTALTuningControlGauge[(*this).id] = true;
}
