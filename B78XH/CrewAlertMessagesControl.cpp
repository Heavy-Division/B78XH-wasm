#include "CrewAlertMessagesControl.h"


auto CrewAlertMessageControl::printMessage(double x, double y, CrewAlertMessage& message) -> void {

	nvgStrokeColor(getContext(), Tools::Colors::white);
	nvgFontFace(getContext(), "heavy-fmc");
	nvgFontSize(getContext(), 20.0f);
	nvgTextAlign(getContext(), NVG_ALIGN_LEFT);
	nvgFillColor(getContext(), getMessageColor(message));
	nvgBeginPath(getContext());
	{
		// nvgText(getContext(), x + dispatch.getMesssageXOffset(message.getSeverity()), y, message.getId().c_str(), nullptr);
		nvgText(getContext(), 100, 100, "te", nullptr);
		nvgText(getContext(), 100, 100, "te", nullptr);
		nvgText(getContext(), 100, 100, "te", nullptr);
		nvgFill(getContext());

	}
	
	if (message.isChecklistItem()) {
		nvgBeginPath(getContext());
		{
			nvgRect(getContext(), x - 20, y - 15, 10, 10);
			nvgStroke(getContext());
		}
	}
}