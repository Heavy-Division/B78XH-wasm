#pragma once
#include "Control.h"
#include "Tools/Tools.h"
#include "CheckListDimensions.h"

/**
* \brief  An abstract representation of an "item" on the checklist. An Item simply has a "CHECKLIST_ITEM_STATE" and utility UI functions.
 */
class CheckListItem : public Control {
    public:
        enum class CHECKLIST_ITEM_STATE {
            OPEN,
            COMPLETED,
            OVERRIDDEN
        };

        CheckListItem(const string& name)
            : Control(name),
              currentState_(CHECKLIST_ITEM_STATE::OPEN) {
        }

        /**
         * \brief Sets the item to the desired state.
         */
        auto setCurrentState(CHECKLIST_ITEM_STATE state) -> void;
        /**
        * \brief Gets the current state of the item.
        */
        auto getCurrentState() const -> CHECKLIST_ITEM_STATE;

    protected:
        /**
         * \brief Checks if the item is being hovered by the cursor.
         * \return true if in focus, false otherwise
         */
        auto isInFocus() -> bool;
        /**
         * \brief Checks if mouse is clicking on this item
         * \return true if mouse is clicking, false otherwise
         */
        auto shouldTriggerEvent() -> bool;
        /**
         * \brief Gets the color corresponding to the current state.
         */
        auto getItemStateColor() const -> NVGcolor;
        /**
         * \brief Draws a magenta border around the item.
         */
        auto drawBorder() -> void;

        /**
         * \brief Draws a button-like boarder around the item.
         * \param background Background fill color.
         * \param top Top boarder color.
         * \param right Right boarder color.
         * \param bottom Bottom boarder color.
         * \param left Left boarder color.
         */
        auto drawButtonBorder(NVGcolor background, NVGcolor top, NVGcolor right, NVGcolor bottom, NVGcolor left) -> void;

    private:
        /**
         * \brief The item's current state.
         */
        CHECKLIST_ITEM_STATE currentState_;
        /**
         * \brief The item's bound in absolute space. Order is LRTB.
         */
        float bounds_[4] = {0, 0, 0, 0};
        /**
         * \brief Updates bounds_ with the current absolute position.
         */
        auto calculateBounds() -> void;
};
