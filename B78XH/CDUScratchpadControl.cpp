#include "CDUScratchpadControl.h"

#include "Tools/Console.h"


CDUScratchpadControl::CDUScratchpadControl(const string& name) : Control(name) {
}

auto CDUScratchpadControl::render() -> void {
	Control::render();
	prepareDefaults();
	float bounds[4] = {0, 0, 0, 0};

	nvgFillColor(getContext(), nvgRGB(0, 0, 0));
	nvgStrokeColor(getContext(), nvgRGB(255, 255, 255));
	nvgStrokeWidth(getContext(), 2.0f);
	nvgBeginPath(getContext());
	{
		nvgRect(getContext(), 0, 0, position.width, position.height);
		nvgFill(getContext());
		nvgStroke(getContext());
	}
	nvgClosePath(getContext());

	nvgBeginPath(getContext());
	{
		for (int i = 0; i < getContentHolder().getContent().size(); i++) {
			prepareColor(i);
			prepareFontSize(i);
			prepareAlign(i);
			float verticalOffset = getContentHolder().getChunkContentVerticalOffset(i);
			auto textToRender = getContentHolder().getContent().at(i)[0].c_str();

			nvgText(getContext(), bounds[2] + 5, verticalOffset + 22, textToRender, nullptr);
			nvgTextBounds(getContext(), bounds[2] + 5, verticalOffset + 22, textToRender, nullptr, bounds);
		}
	}
	nvgClosePath(getContext());
	nvgFill(getContext());
}

auto CDUScratchpadControl::getBuffer() const -> const std::string& {
	return buffer_;
}

auto CDUScratchpadControl::clear() -> void {
	buffer_.clear();
}

auto CDUScratchpadControl::processEvent(events event) -> void {
	if (eventsDisabled) {
		return;
	}
	switch (event) {
		case events::NUM1: {
			buffer_.push_back(49);
			break;
		}
		case events::NUM2: {
			buffer_.push_back(50);
			break;
		}
		case events::NUM3: {
			buffer_.push_back(51);
			break;
		}
		case events::NUM4: {
			buffer_.push_back(52);
			break;
		}
		case events::NUM5: {
			buffer_.push_back(53);
			break;
		}
		case events::NUM6: {
			buffer_.push_back(54);
			break;
		}
		case events::NUM7: {
			buffer_.push_back(55);
			break;
		}
		case events::NUM8: {
			buffer_.push_back(56);
			break;
		}
		case events::NUM9: {
			buffer_.push_back(57);
			break;
		}
		case events::NUM0: {
			buffer_.push_back(48);
			break;
		}
		case events::CLR: {
			if (buffer_.empty()) {
				buffer_.append("CLEAR");
			}
			else {
				buffer_ == "CLEAR" ? buffer_.clear() : buffer_.pop_back();
			}
			break;
		}
		case events::DOT: {
			buffer_.push_back(46);
			break;
		}
		case events::MINUS: {
			buffer_.push_back(45);
			break;
		}
		case events::A: {
			buffer_.push_back(65);
			break;
		}
		case events::B: {
			buffer_.push_back(66);
			break;
		}
		case events::C: {
			buffer_.push_back(67);
			break;
		}
		case events::D: {
			buffer_.push_back(68);
			break;
		}
		case events::E: {
			buffer_.push_back(69);
			break;
		}
		case events::F: {
			buffer_.push_back(70);
			break;
		}
		case events::G: {
			buffer_.push_back(71);
			break;
		}
		case events::H: {
			buffer_.push_back(72);
			break;
		}
		case events::I: {
			buffer_.push_back(73);
			break;
		}
		case events::J: {
			buffer_.push_back(74);
			break;
		}
		case events::K: {
			buffer_.push_back(75);
			break;
		}
		case events::L: {
			buffer_.push_back(76);
			break;
		}
		case events::M: {
			buffer_.push_back(77);
			break;
		}
		case events::N: {
			buffer_.push_back(78);
			break;
		}
		case events::O: {
			buffer_.push_back(79);
			break;
		}
		case events::P: {
			buffer_.push_back(80);
			break;
		}
		case events::Q: {
			buffer_.push_back(81);
			break;
		}
		case events::R: {
			buffer_.push_back(82);
			break;
		}
		case events::S: {
			buffer_.push_back(83);
			break;
		}
		case events::T: {
			buffer_.push_back(84);
			break;
		}
		case events::U: {
			buffer_.push_back(85);
			break;
		}
		case events::V: {
			buffer_.push_back(86);
			break;
		}
		case events::W: {
			buffer_.push_back(87);
			break;
		}
		case events::X: {
			buffer_.push_back(88);
			break;
		}
		case events::Y: {
			buffer_.push_back(89);
			break;
		}
		case events::Z: {
			buffer_.push_back(90);
			break;
		}
		case events::SPACE: {
			buffer_.push_back(32);
			break;
		}
		case events::DELETE: {
			/*
			 * TODO: Delele behavior
			 */
			if (buffer_.empty()) {
				buffer_.append("DELETE");
			}
			else {
				buffer_ == "DELETE" ? buffer_.clear() : buffer_.pop_back();
			}
			break;
			break;
		}
		case events::SLASH: {
			buffer_.push_back(47);
			break;
		}
		case events::PREV: {
			//buffer_.push_back(0);
			break;
		}
		case events::NEXT: {
			//buffer_.push_back(0);
			break;
		}
		case events::EXEC: {
			//buffer_.push_back(0);
			break;
		}
		case events::ENTER: {
			//buffer_.push_back(0);
			break;
		}
		default: ;
	}
}

auto CDUScratchpadControl::setupControl() -> void {
	Control::setupControl();
	addOnBeforeRender([this](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{getBuffer()}});
		return true;
	});
}

auto CDUScratchpadControl::prepareColor(int chunkNumber) -> void {
	nvgFillColor(getContext(), getContentHolder().getChunkFontColor(chunkNumber));
}

auto CDUScratchpadControl::prepareFontSize(int chunkNumber) -> void {
	nvgFontSize(getContext(), getContentHolder().getChunkFontSize(chunkNumber));
}

auto CDUScratchpadControl::prepareAlign(int chunkNumber) -> void {
	if (getContentHolder().getContent().at(chunkNumber)[1].find("top") != std::string::npos) {
		nvgTextAlign(getContext(), getContentHolder().getContentHorizontalAlign() | NVG_ALIGN_TOP);
	}
	else if (getContentHolder().getContent().at(chunkNumber)[1].find("bottom") != std::string::npos) {
		nvgTextAlign(getContext(), getContentHolder().getContentHorizontalAlign() | NVG_ALIGN_BOTTOM);
	}
	else if (getContentHolder().getContent().at(chunkNumber)[1].find("baseline") != std::string::npos) {
		nvgTextAlign(getContext(), getContentHolder().getContentHorizontalAlign() | NVG_ALIGN_BASELINE);
	}
	else if (getContentHolder().getContent().at(chunkNumber)[1].find("middle") != std::string::npos) {
		nvgTextAlign(getContext(), getContentHolder().getContentHorizontalAlign() | NVG_ALIGN_MIDDLE);
	}
	else {
		nvgTextAlign(getContext(), getContentHolder().getContentHorizontalAlign() | getContentHolder().getContentVerticalAlign());
	}
}

auto CDUScratchpadControl::prepareDefaults() -> void {
	nvgFontFace(getContext(), getContentHolder().getFontFace().c_str());
}

auto CDUScratchpadControl::isEventsDisabled() const -> bool {
	return eventsDisabled;
}

auto CDUScratchpadControl::setEventsDisabled(const bool eventsDisabled) -> void {
	this->eventsDisabled = eventsDisabled;
}
