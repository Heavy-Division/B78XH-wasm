#pragma once
#include "Control.h"

class CheckList;

/**
 * \brief The overall status indicator on a checklist.
 */
class CheckListStatus : public Control {
    public:
        CheckListStatus(const string& name, const CheckList* parentChecklist)
            : Control(name),
              parentChecklist_(parentChecklist) {
        }

        auto render() -> void override;
    private:
        const CheckList* parentChecklist_;
};
