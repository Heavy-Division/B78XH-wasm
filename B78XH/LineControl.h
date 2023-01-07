#pragma once
#include "Control.h"

class LineControl: public Control {
	public:
		explicit LineControl(const string& name)
			: Control(name) {
		}

		auto render() -> void override;

	protected:
		auto renderContent() -> void;
		auto renderContentAlignLeft() -> void;
		auto renderContentAlignCenter() -> void;
		auto renderContentAlignRight() -> void;

		auto prepareColor(int chunkNumber) -> void;
		auto prepareFontSize(int chunkNumber) -> void;
		auto prepareAlign(int chunkNumber) -> void;
		auto prepareDefaults() -> void;
};
