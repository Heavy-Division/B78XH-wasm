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
