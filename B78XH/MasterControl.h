#pragma once
#include "BaseControl.h"
#include "CDUMouseClickResolver.h"
#include "CDUMouseMoveResolver.h"

class MasterControl : public BaseControl {
	public:
		explicit MasterControl(const string& name)
			: BaseControl(name) {
			setControlType(ControlType::MASTER);
		}

		[[nodiscard]] auto getMouseMoveResolver() -> CDUMouseMoveResolver&;
		[[nodiscard]] auto getMouseClickResolver() -> CDUMouseClickResolver&;

	private:
		using BaseControl::setControlType;

		CDUMouseMoveResolver mouseMoveResolver_ = CDUMouseMoveResolver();
		CDUMouseClickResolver mouseClickResolver_ = CDUMouseClickResolver();
};
