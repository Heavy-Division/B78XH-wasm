#pragma once
#include "CheckListItem.h"
#include "CheckListLine.h"

class CheckList : public CheckListItem {
    public:
        CheckList(const string& name)
            : CheckListItem(name),
              currentLine_(0) {
        }

        auto setupControls() -> void override;

    protected:
        /**
         * \brief These lines have operational effects and counts towards the checklists overall completeness
         */
        const std::vector<std::shared_ptr<CheckListLine>> lines_;

        /**
         * \brief Evaluates the entire checklists status. This does not care about overridden checklist.
         */
        auto checkChecklistCompleted() -> void;
        /**
         * \brief Advances the current line pointer. This does not change the checklist's status.
         */
        auto advanceCurrentLine() -> void;
        /**
         * \brief Resets all checklist lines
         */
        auto resetChecklist() -> void;
        /**
         * \brief Used to check all closed loop items and set their completeness state.
         */
        virtual auto checkClosedLoopItems() -> void;

    private:
        int currentLine_;

        /**
         * \brief Invoked periodically to check the checklist
         */
        auto serviceChecklistUpdateLoop() -> void;
};
