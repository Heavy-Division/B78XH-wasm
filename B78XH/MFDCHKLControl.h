#pragma once
#include "MFDBaseControl.h"
#include "CheckListLine.h"
#include "CheckListButton.h"
#include "CheckListDimensions.h"

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
        std::shared_ptr<CheckListButton> normalMenuButton_;
        std::shared_ptr<CheckListButton> resetsButton_;
        std::shared_ptr<CheckListButton> nonNormalMenuButton_;
};
