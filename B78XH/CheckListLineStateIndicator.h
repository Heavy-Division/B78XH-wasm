#pragma once
#include "CheckListItem.h"
#include "CheckListDimensions.h"

class CheckListLine;

/**
 * \brief The main state indicator of a "line" in a checklist. This is typically the "checkbox"/"checkmark". Internal, Owned by "CheckListLine"
 */
class CheckListLineStateIndicator : public Control {
    public:
        CheckListLineStateIndicator(const string& name, const CheckListLine* parentLine)
            : Control(name),
                line_(parentLine){
        }

        auto render() -> void override;

    private:
        const CheckListLine* line_;     // weak_ptr here?

        auto drawOpenLoopIndicator() -> void;
        auto drawCheckMark() -> void;
};
