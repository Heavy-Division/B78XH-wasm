#pragma once

#include  <string>
#include "Severity.h"

class CrewAlertMessage {
public:

	CrewAlertMessage(std::string id, Severity severity, bool checklistItem) :
		id(id), severity(severity), checklistItem(checklistItem) {};



	bool operator==(const CrewAlertMessage& message) const {
		return message.id == id;
	};


	auto getId() -> std::string;
	auto getSeverity() -> Severity;
	auto isChecklistItem() -> bool;

private:

	std::string id = 0;
	Severity severity;
	bool checklistItem = false;
};