#pragma once
#pragma once

#include "CrewAlertMessage.h"
#include "EICASBaseControl.h"
#include "CrewAlertMessageDispatch.h"

class CrewAlertMessageControl : public EICASBaseControl {


	// std::vector<CrewAlertMessage> activeMessages = {
	// 	CrewAlertMessages::messages.at(APU_COOLDOWN),
	// 	CrewAlertMessages::messages.at(ENG_AUTOSTART_L),
	// 	CrewAlertMessages::messages.at(ENG_AUTOSTART_R),
	// 	CrewAlertMessages::messages.at(ENG_CORE_ANTI_ICE_L),
	// 	CrewAlertMessages::messages.at(APU_LIMIT),
	// 	CrewAlertMessages::messages.at(APU_RUNNING),
	// 	CrewAlertMessages::messages.at(ENG_EEC_MODE_L),
	// 	CrewAlertMessages::messages.at(ENG_CORE_ANTI_ICE_R),
	// 	CrewAlertMessages::messages.at(ENG_EEC_MODE_R),
	// 	CrewAlertMessages::messages.at(ENG_OIL_PRESS_R),
	// 	CrewAlertMessages::messages.at(ENG_FAIL_L),
	// 	CrewAlertMessages::messages.at(ENG_FAIL_R),
	// 	CrewAlertMessages::messages.at(ENG_FUEL_VALVE_L),
	// 	CrewAlertMessages::messages.at(ENG_OIL_TEMP_L),
	// 	CrewAlertMessages::messages.at(ENG_SEC_AIR_VLV_R),
	// };



public:
	CrewAlertMessageControl(const string& name)
		: EICASBaseControl(name) {}

	auto render() -> void override;

private:
	CrewAlertMessageDispatch dispatch;
	auto printMessage(double x, double y, CrewAlertMessage& message) -> void;
	auto clearMessages() -> void;
	auto getIsUpdated() -> bool;
	auto setUpdated() -> void;
	auto queueMessage(CrewAlertMessage message) -> void;
	auto removeMessage() -> void;
	auto getMesssageXOffset(Severity severity) -> double;
	auto getMessageColor(CrewAlertMessage message) -> NVGcolor;
	auto sortMessages() -> void;
	auto getMessages() -> void;

protected:
	auto setupControl() -> void override;
};

