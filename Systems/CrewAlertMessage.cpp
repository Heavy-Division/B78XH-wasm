#include "CrewAlertMessage.h"

auto CrewAlertMessage::getId() -> std::string {
	return this->id;
}
auto CrewAlertMessage::getSeverity() -> Severity {
	return this->severity;
}
auto CrewAlertMessage::isChecklistItem() -> bool {
	return this->checklistItem;
}
