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
              line_type(line_type), isCurrent_(false) {
        }

        const CHECKLIST_LINE_TYPE line_type;

        auto setIsCurrent(bool current) -> void;
        auto getIsCurrent() const -> bool;
        auto render() -> void override;
        auto prepareControls() -> void override;
        auto setupControls() -> void override;

    private:
        std::shared_ptr<CheckListLineStateIndicator> stateIndicator_;
        bool isCurrent_;

        auto drawIsCurrentBorder() -> void;
};
