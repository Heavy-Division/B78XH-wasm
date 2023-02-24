#pragma once
#include "CheckListItem.h"
#include "CheckListLine.h"
#include "CheckListTitle.h"
#include "CheckListLineSingle.h"

class CheckList : public CheckListItem {
    public:
        CheckList(const string& name, const CheckListTitle::TITLE_TYPE titleType, const string& titleText)
            : CheckListItem(name),
              currentLine_(0), title_(std::make_shared<CheckListTitle>("TITLE", titleType, titleText)) {
        }

        auto setupControls() -> void override;

    protected:
        /**
         * \brief The lines in this checklist. These lines have operational effects and counts towards the checklists overall completeness
         */
        std::vector<std::shared_ptr<CheckListLine>> lines_{};

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
        /**
        * \brief Setup layout for a basic checklist with all items in lines_ being 1 line height. This will suffice for most of the checklist.
        * For special checklist (e.g. with branch items), override this with its own layout.
        */
        virtual auto setupChecklistLayout() -> void;

    private:
        int currentLine_;
        const std::shared_ptr<CheckListTitle> title_;

        /**
         * \brief Invoked periodically to check the checklist
         */
        auto serviceChecklistUpdateLoop() -> void;
};
