#pragma once
#include "CheckListItem.h"
#include "CheckListDimensions.h"

class CheckListLine;

/**
 * \brief The main state indicator of a "line" in a checklist. This is typically the "checkbox"/"checkmark". Internal, Owned by "CheckListLine"
 */
class CheckListLineStateIndicator : public CheckListItem {
    public:
        CheckListLineStateIndicator(const string& name, const CheckListLine* parentLine)
            : CheckListItem(name),
                line_(parentLine){
        }

        auto render() -> void override;

    private:
        const CheckListLine* line_;     // weak_ptr here?
};
