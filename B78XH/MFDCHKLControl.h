#pragma once
#include "MFDBaseControl.h"
#include "CheckListLine.h"
#include "CheckListTitle.h"
#include "CheckListButton.h"
#include "CheckListDimensions.h"
#include "PreFlightCheckList.h"

class MFDCHKLControl : public MFDBaseControl {
    public:
        explicit MFDCHKLControl(const string& name)
            : MFDBaseControl(name) {
            ident_ = CONTROL_IDENT::CHKL;
        }

        auto render() -> void override;
        auto prepareControls() -> void override;
        auto setupControls() -> void override;

    private:
        std::shared_ptr<CheckListButton> normalMenuButton_ = std::make_shared<CheckListButton>("NORMAL_MENU", nullptr, "NORMAL MENU");
        std::shared_ptr<CheckListButton> resetsButton_ = std::make_shared<CheckListButton>("RESETS", nullptr, "RESETS");
        std::shared_ptr<CheckListButton> nonNormalMenuButton_ = std::make_shared<CheckListButton>("NON_NORMAL_MENU", nullptr, "NON-NORMAL MENU");
        std::shared_ptr<CheckListButton> normalButton_ = std::make_shared<CheckListButton>("NORMAL", nullptr, "NORMAL");
        std::shared_ptr<CheckListButton> resetChecklistButton_ = std::make_shared<CheckListButton>("CHKL_RESET", nullptr, "CHKL\nRESET");

        // TODO: Temp, remove, use a "current pointer"
        std::shared_ptr<PreFlightCheckList> preflight_ = std::make_shared<PreFlightCheckList>("PREFLIGHT");
};
