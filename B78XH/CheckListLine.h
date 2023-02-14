#pragma once

#include "CheckListItem.h"
#include "CheckListLineStateIndicator.h"

/**
 * \brief A line in the check list. This typically consists of 1 "LineStateIndicator" and several "CheckListItem" 
 */
class CheckListLine : public CheckListItem {
    public:
        enum class CHECKLIST_LINE_TYPE {
            OPEN_LOOP,
            CLOSED_LOOP
        };

        CheckListLine(const string& name, const CHECKLIST_LINE_TYPE line_type)
            : CheckListItem(name),
              line_type(line_type) {
        }

        const CHECKLIST_LINE_TYPE line_type;
    
        auto prepareControls() -> void override;
        auto setupControls() -> void override;
};
