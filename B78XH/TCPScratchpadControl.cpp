#include "TCPScratchpadControl.h"

auto TCPScratchpadControl::render() -> void {
	Control::render();
	prepareDefaults();
	float bounds[4] = {0, 0, 0, 0};

	nvgBeginPath(getContext());
	{
		for (int i = 0; i < getContentHolder().getContent().size(); i++) {
			prepareColor(i);
			prepareFontSize(i);
			prepareAlign(i);
			float verticalOffset = getContentHolder().getChunkContentVerticalOffset(i);
			auto textToRender = getContentHolder().getContent().at(i)[0].c_str();
			nvgText(getContext(), bounds[2], verticalOffset, textToRender, nullptr);
			nvgTextBounds(getContext(), bounds[2], verticalOffset, textToRender, nullptr, bounds);
		}
	}
	nvgClosePath(getContext());
	nvgFill(getContext());
}

auto TCPScratchpadControl::getBuffer() const -> const std::string& {
	return buffer_;
}

auto TCPScratchpadControl::setBuffer(const std::string& buffer) -> void {
	buffer_ = buffer;
	getContentHolder().setContent({{buffer_}});
}

auto TCPScratchpadControl::clear() -> void {
	buffer_.clear();
}

auto TCPScratchpadControl::processEvent(events event) -> void {
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
		case events::STAR: {
			buffer_.push_back(46);
			break;
		}
		case events::FORCE_CLR: {
			buffer_.clear();
			break;
		}
		default: ;
	}
	getContentHolder().setContent({{buffer_}});
}

auto TCPScratchpadControl::prepareColor(int chunkNumber) -> void {
	nvgFillColor(getContext(), getContentHolder().getChunkFontColor(chunkNumber));
}

auto TCPScratchpadControl::prepareFontSize(int chunkNumber) -> void {
	nvgFontSize(getContext(), getContentHolder().getChunkFontSize(chunkNumber));
}

auto TCPScratchpadControl::prepareAlign(int chunkNumber) -> void {
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

auto TCPScratchpadControl::prepareDefaults() -> void {
	nvgFontFace(getContext(), getContentHolder().getFontFace().c_str());
}
