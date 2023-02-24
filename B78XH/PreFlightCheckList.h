#pragma once
#include "CheckList.h"

class PreFlightCheckList : public CheckList {
    public:
        explicit PreFlightCheckList(const string& name)
            : CheckList(name, CheckListTitle::TITLE_TYPE::NORMAL_CHECKLIST, "PREFLIGHT") {
            lines_.push_back(std::make_shared<CheckListLineSingle>(
                "OXYGEN", CheckListLine::CHECKLIST_LINE_TYPE::OPEN_LOOP,
                "Oxygen . . . . . . . . . . . . . . . . . . . . . . Tested,100%"));
        }
};
