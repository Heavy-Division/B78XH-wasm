#include "MFDBaseControl.h"

auto MFDBaseControl::getIdent() const -> CONTROL_IDENT {
	return ident_;
}

auto MFDBaseControl::setIdent(const CONTROL_IDENT ident) -> void {
	ident_ = ident;
}
