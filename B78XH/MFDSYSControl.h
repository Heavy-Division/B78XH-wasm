#pragma once
#include "MFDBaseControl.h"

class MFDSYSControl : public MFDBaseControl {
	public:
		explicit MFDSYSControl(const string& name)
			: MFDBaseControl(name) {
			ident_ = CONTROL_IDENT::TEST;
		}

		auto render() -> void override;
};

class MFDINFOControl : public MFDBaseControl {
	public:
		explicit MFDINFOControl(const string& name)
			: MFDBaseControl(name) {
			ident_ = CONTROL_IDENT::TEST2;
		}

		auto render() -> void override;
};

class MFDCHKLControl : public MFDBaseControl {
	public:
		explicit MFDCHKLControl(const string& name)
			: MFDBaseControl(name) {
			ident_ = CONTROL_IDENT::TEST3;
		}

		auto render() -> void override;
};

class MFDCOMMControl : public MFDBaseControl {
	public:
		explicit MFDCOMMControl(const string& name)
			: MFDBaseControl(name) {
			ident_ = CONTROL_IDENT::TEST4;
		}

		auto render() -> void override;
};

class MFDTest6Control : public MFDBaseControl {
	public:
		explicit MFDTest6Control(const string& name)
			: MFDBaseControl(name) {
			ident_ = CONTROL_IDENT::TEST6;
		}

		auto render() -> void override;
};
