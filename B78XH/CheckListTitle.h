#pragma once
#include "Control.h"
#include "Tools/Tools.h"

/**
 * \brief The title line displayed in the electronic checklist.
 * This can show title for both checklists and menus, with the difference is the checklist one shows 2 "triangles" enclosing the title text
 */
class CheckListTitle : public Control {
    public:
        enum class TITLE_TYPE {
            NORMAL_CHECKLIST,
            NON_NORMAL_CHECKLIST,
            MENU,
        };
    
        CheckListTitle(const string& name, const TITLE_TYPE type, const string& titleText)
            : Control(name),
              titleText_(titleText), type_(type) {
        }

        auto render() -> void override;

    private:
        const string titleText_;
        const TITLE_TYPE type_;
};
