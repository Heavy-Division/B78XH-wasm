#include "LineControl.h"


auto LineControl::render() -> void {
	Control::render();
	this->renderContent();
}

auto LineControl::renderContent() -> void {
	switch (getContentHolder().getAlign()) {
		case ContentHolder::ALIGN::LEFT: {
			renderContentAlignLeft();
			break;
		}
		case ContentHolder::ALIGN::CENTER: {
			renderContentAlignCenter();
			break;
		}
		case ContentHolder::ALIGN::RIGHT: {
			renderContentAlignRight();
			break;
		}
	}
}

auto LineControl::renderContentAlignLeft() -> void {
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

auto LineControl::renderContentAlignCenter() -> void {
	prepareDefaults();

	float boundsPreCalculated[4] = {0, 0, 0, 0};
	float width = 0;

	for (int i = 0; i < getContentHolder().getContent().size(); i++) {
		prepareFontSize(i);
		nvgTextBounds(getContext(), 0, 0, getContentHolder().getContent().at(i)[0].c_str(), nullptr, boundsPreCalculated);
		width = width + boundsPreCalculated[2];
	}

	float bounds[4] = {0, 0, 0, 0};
	nvgSave(getContext());
	{
		nvgTranslate(getContext(), -(width / 2), 0);
		{
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
		nvgResetTransform(getContext());
	}
	nvgRestore(getContext());
}

auto LineControl::renderContentAlignRight() -> void {
	prepareDefaults();
	float bounds[4] = {0, 0, 0, 0};
	float width = 0;

	nvgBeginPath(getContext());
	{
		for (int i = 0; i < getContentHolder().getContent().size(); i++) {
			prepareColor(i);
			prepareFontSize(i);
			prepareAlign(i);
			float verticalOffset = getContentHolder().getChunkContentVerticalOffset(i);
			nvgTextBounds(getContext(), 0, verticalOffset, getContentHolder().getContent().at(i)[0].c_str(), nullptr, bounds);
			width = width + (bounds[2] - bounds[0]);
			nvgText(getContext(), -width, verticalOffset, getContentHolder().getContent().at(i)[0].c_str(), nullptr);
		}
	}
	nvgClosePath(getContext());
	nvgFill(getContext());
}

auto LineControl::prepareColor(int chunkNumber) -> void {
	nvgFillColor(getContext(), getContentHolder().getChunkFontColor(chunkNumber));
}

auto LineControl::prepareFontSize(int chunkNumber) -> void {
	nvgFontSize(getContext(), getContentHolder().getChunkFontSize(chunkNumber));
}

auto LineControl::prepareAlign(int chunkNumber) -> void {
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

auto LineControl::prepareDefaults() -> void {
	nvgFontFace(getContext(), getContentHolder().getFontFace().c_str());
}
