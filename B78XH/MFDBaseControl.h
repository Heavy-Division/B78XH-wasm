#pragma once
#include "Control.h"

class MFDBaseControl : public Control {
	public:
		explicit MFDBaseControl(const string& name)
			: Control(name) {
		}

		enum class CONTROL_IDENT {
			SYS,
			CDU,
			INFO,
			CHKL,
			COMM,
			ND,
			EICAS,
			EMPTY,
			TEST,
			TEST2,
			TEST3,
			TEST4,
			TEST5,
			TEST6,
			UNKNOWN
		};

		[[nodiscard]] auto getIdent() const -> CONTROL_IDENT;
		auto setIdent(const CONTROL_IDENT ident) -> void;

	protected:
		CONTROL_IDENT ident_ = CONTROL_IDENT::UNKNOWN;
};
