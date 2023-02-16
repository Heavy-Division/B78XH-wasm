#pragma once
#include "CheckListLine.h"

/**
 * \brief Specialized to render a checklist line that's just "single line".
 * This is so common that it deserves it's own class.
 */
class CheckListLineSingle : public CheckListLine {
    public:
        CheckListLineSingle(const string& name, CHECKLIST_LINE_TYPE line_type, const string& textDisplayed)
            : CheckListLine(name, line_type),
              textDisplayed_(textDisplayed){
        }

        auto render() -> void override;
    private:
        const string textDisplayed_;
};
