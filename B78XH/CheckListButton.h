#pragma once
#include <functional>
#include "CheckListItem.h"
#include "Control.h"
#include "Tools/Console.h"

/**
 * \brief A clickable button on the checklist. This mostly shows up at the header/footer and in the menus
 */
class CheckListButton : public CheckListItem {
    public:
        CheckListButton(const string& name, const std::function<void()>& invoke, const string& displayText)
            : CheckListItem(name),
              invoke_(invoke), displayText_(displayText) {
        }

        auto render() -> void override;

    private:
        const std::function<void()> invoke_;
        const string displayText_;
};
