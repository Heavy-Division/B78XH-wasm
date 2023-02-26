#pragma once
#include "CheckList.h"

class PreFlightCheckList : public CheckList {
    public:
        explicit PreFlightCheckList(const string& name)
            : CheckList(name, CheckListTitle::TITLE_TYPE::NORMAL_CHECKLIST, "PREFLIGHT") {
            lines_.push_back(std::make_shared<CheckListLineSingle>(
                "OXYGEN", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP,
                "Oxygen . . . . . . . . . . . . . . . . . . . . . . Tested,100%"));
            lines_.push_back(std::make_shared<CheckListLineSingle>(
                "FLIGHT_INST", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP,
                "Flight Instruments . . . Heading___,Altimeter___"));
            lines_.push_back(std::make_shared<CheckListLineSingle>(
                "PAX_SIGN", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP,
                "Passenger Signs . . . . . . . . . . . . . . . . . . . . . Set"));
            resetChecklist();
        }
};
