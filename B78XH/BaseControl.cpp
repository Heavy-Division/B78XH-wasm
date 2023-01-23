#include "BaseControl.h"
#include <iostream>

#include "Tools/Console.h"


auto BaseControl::prepareRenderingContextDefaults() -> void {
	prepareRenderingContextDefaultsFonts();
}

auto BaseControl::prepareRenderingContextDefaultsFonts() -> void {
	addFont("roboto", "Roboto-Regular.ttf", FONT_TYPE::DEFAULT, "./data/");
	addFont("heavy-fmc", "Heavy787FMC.ttf", FONT_TYPE::DEFAULT, "./data/");
	addFont("dseg7", "DSEG7ClassicMini-Italic.ttf", FONT_TYPE::DEFAULT, "./data/");
}

auto BaseControl::addFont(string alias, string filename, FONT_TYPE type, string path) -> void {
	if (nvgFindFont(getContext(), alias.c_str()) != -1) {
		return;
	};
	nvgCreateFont(getContext(), alias.c_str(), path.append(filename).c_str());
}

auto BaseControl::getOnBeforeRender() -> BaseControl::ControlEvents& {
	return onBeforeRender_;
}

auto BaseControl::getOnValidate() -> BaseControl::ControlEvents& {
	return onValidate_;
}

auto BaseControl::hasContext() const -> bool {
	return getContext() == nullptr ? false : true;
}

auto BaseControl::propagateContext(RenderingContext const context) -> void {
	for (auto& control : getControls()) {
		control->setContext(context);
		control->propagateContext(context);
	}
}

auto BaseControl::add(ControlSharedPointer control) -> void {
	controls_.add(control);
}


auto BaseControl::getControls() -> list<ControlSharedPointer>& {
	return controls_.getControls();
}

auto BaseControl::getControl(string name) -> ControlSharedPointer& {
	return controls_.getControl(name);
}


auto BaseControl::getSystemControls() -> list<ControlSharedPointer>& {
	return systemControls_.getControls();
}

auto BaseControl::getPosition() -> ControlPosition& {
	return position_;
}

auto BaseControl::setPosition(const ControlPosition& position) -> void {
	position_ = position;
}

auto BaseControl::getCrop() -> ControlCrop& {
	return crop_;
}

auto BaseControl::setCrop(const ControlCrop& crop) -> void {
	crop_ = crop;
}

auto BaseControl::preInstall(GaugeInstallData* data) -> void {
	setGaugeInstallData(data);
	prepareControls();
	executeControlsPreInstall();
}

auto BaseControl::postInstall(RenderingContext context) -> void {
	setContext(context);
	prepareRenderingContextDefaults();
	propagateContext(context);
	setupControl();
	setupControls();
	executeControlsPostInstall();
}

auto BaseControl::preUpdate() -> void {
	executeOnBeforeRenderEvents(*this);
}

auto BaseControl::postUpdate() -> void {
}

BaseControl::~BaseControl() {
	getLogger()->debug("Control destructed; NAME: " + getName());
}

auto BaseControl::getName() const -> const string& {
	return name_;
}

auto BaseControl::setName(const string& name) -> void {
	name_ = name;
}

auto BaseControl::getContext() const -> RenderingContext {
	return context_;
}

auto BaseControl::setContext(RenderingContext const context) -> void {
	context_ = context;
}


auto BaseControl::getControlType() const -> ControlType {
	return controlType_;
}

auto BaseControl::setControlType(const ControlType controlType) -> void {
	controlType_ = controlType;
}

auto BaseControl::getContentHolder() -> ContentHolder& {
	return contentHolder_;
}

auto BaseControl::setLogger(std::unique_ptr<BaseLogger> logger) -> void {
	#ifndef NDEBUG
	logger_ = std::move(logger);
	#endif
}

auto BaseControl::addSystemControl(ControlSharedPointer control) -> void {
	systemControls_.add(control);
}

auto BaseControl::isControlInvalid() -> bool {
	if (getContentHolder().isContentInvalid()) {
		getLogger()->info("Invalid by content (invalid): " + getName());
		return true;
	}

	for (auto& event : onValidate_.getEvents()) {
		if (!event(*this)) {
			getLogger()->info("Events are empty (invalid): " + getName());
			return true;
		}
	}

	getLogger()->info("Control is valid (valid): " + getName());
	return false;
}

auto BaseControl::prepareControls() -> void {
}

auto BaseControl::setupControls() -> void {
}

auto BaseControl::setupControl() -> void {
}

auto BaseControl::executeControlsPreInstall() -> void {
	for (auto& control : controls) {
		control->preInstall(getGaugeInstallData());
	}
}

auto BaseControl::executeControlsPostInstall() -> void {
	for (auto& control : controls) {
		control->postInstall(getContext());
	}
}

auto BaseControl::getLogger() const -> const std::unique_ptr<BaseLogger>& {
	return logger_;
}

auto BaseControl::addOnValidate(EventInterface event) -> void {
	onValidate_.add(event);
}

auto BaseControl::addOnBeforeRender(EventInterface event) -> void {
	onBeforeRender_.add(event);
}

auto BaseControl::renderScreen() -> void {
	if (!hasContext()) {
		return;
	}

	if (!needRedraw(isFirstRun())) {
		return;
	}

	const float pxRatio = static_cast<float>(getGaugeDrawData()->fbWidth) / static_cast<float>(getGaugeDrawData()->winWidth);
	const auto winWidth = static_cast<float>(getGaugeDrawData()->winWidth);
	const auto winHeight = static_cast<float>(getGaugeDrawData()->winHeight);

	nvgBeginFrame(getContext(), winWidth, winHeight, pxRatio);
	{
		nvgSave(getContext());
		{
			nvgTranslate(getContext(), 0, 0);
			{
				nvgFillColor(getContext(), nvgRGB(0, 0, 0));
				nvgBeginPath(getContext());
				{
					nvgRect(getContext(), 0, 0, winWidth, winHeight);
				}
				nvgClosePath(getContext());
				nvgFill(getContext());
				nvgSave(getContext());
				{
					if (getCrop().isPositionSet()) {
						nvgScissor(getContext(), getCrop().getLeft(), getCrop().getTop(), getCrop().getWidth(), getCrop().getHeight());
						{
							renderControls();
						}
						nvgResetScissor(getContext());
					}
					else {
						renderControls();
					}
				}
				nvgRestore(getContext());
			}
			nvgResetTransform(getContext());
		}
		nvgRestore(getContext());
	}
	nvgEndFrame(getContext());
}

/*
 * TODO: Add support for master crop
 */
auto BaseControl::renderControls() -> void {
	if (getControlType() == ControlType::NORMAL) {
		nvgSave(getContext());
		{
			nvgTranslate(getContext(), getPosition().getLeft(), getPosition().getTop());
			{
				nvgSave(getContext());
				{
					if (getCrop().isPositionSet()) {
						nvgScissor(getContext(), getCrop().getLeft(), getCrop().getTop(), getCrop().getWidth(), getCrop().getHeight());
						{
							render();
						}
						nvgResetScissor(getContext());
					}
					else {
						render();
					}
				}
				nvgRestore(getContext());
			}
			nvgResetTransform(getContext());
		}
		nvgRestore(getContext());
	}

	if (!getControls().empty()) {
		for (const auto& control : getControls()) {
			control->renderControls();
		}
	}
}

auto BaseControl::needRedraw(bool force) -> bool {
	if (force) {
		setFirstRun(false);
		return true;
	}

	return isControlInvalid(*this);
}

auto BaseControl::isControlInvalid(BaseControl& control) -> bool {
	if (control.isControlInvalid()) {
		return true;
	}

	for (auto& con : control.getControls()) {
		bool isInvalid = isControlInvalid(*con);
		if (isInvalid) {
			return true;
		}
	}

	return false;
}

auto BaseControl::executeOnBeforeRenderEvents(BaseControl& control) -> void {
	for (auto& event : control.onBeforeRender_.getEvents()) {
		event(*this);
	}

	for (auto& con : control.getControls()) {
		con->executeOnBeforeRenderEvents(*con);
	}
}

auto BaseControl::preDraw(GaugeDrawData* data) -> void {
	setGaugeDrawData(data);
	if (getControlType() == ControlType::MASTER) {
		renderScreen();
	}
}

auto BaseControl::render() -> void {
}

auto BaseControl::postDraw() -> void {
}

auto BaseControl::preKill() const -> void {
	if (getContext() != nullptr) {
		nvgDeleteInternal(context_);
	}
}

auto BaseControl::postKill() -> void {
}

auto BaseControl::restart() -> void {
	getOnBeforeRender().clear();
	getOnValidate().clear();
	getControls().clear();
	setFirstRun(true);
	preInstall(getGaugeInstallData());
	postInstall(getContext());
}

auto BaseControl::getGaugeInstallData() const -> GaugeInstallData* {
	return gaugeInstallData_;
}

auto BaseControl::setGaugeInstallData(GaugeInstallData* const gaugeInstallData) -> void {
	gaugeInstallData_ = gaugeInstallData;
}

auto BaseControl::getGaugeDrawData() const -> GaugeDrawData* {
	return gaugeDrawData_;
}

auto BaseControl::setGaugeDrawData(GaugeDrawData* const gaugeDrawData) -> void {
	position_.setPosition(0, 0, gaugeDrawData->winWidth, gaugeDrawData->winHeight);
	crop_.setPosition(0, 0, gaugeDrawData->winWidth, gaugeDrawData->winHeight);
	gaugeDrawData_ = gaugeDrawData;
}

auto BaseControl::ControlsHolder::add(ControlSharedPointer& control) -> void {
	controls_.emplace_back(control);
}

auto BaseControl::ControlsHolder::getControls() -> list<ControlSharedPointer>& {
	return controls_;
}

auto BaseControl::ControlsHolder::getControl(string name) -> ControlSharedPointer& {
	for (auto& control : getControls()) {
		if (control->getName() == name) {
			return control;
		}
	}
	return nullControl_;
}


auto BaseControl::ControlEvents::add(const EventInterface& event) -> void {
	events_.push_back(event);
}

auto BaseControl::ControlEvents::clear() -> void {
	events_.clear();
}

auto BaseControl::ControlEvents::size() const -> size_t {
	return events_.size();
}

auto BaseControl::ControlEvents::getEvents() const -> const std::vector<EventInterface>& {
	return events_;
}

auto BaseControl::isFirstRun() const -> bool {
	return firstRun_;
}

auto BaseControl::setFirstRun(const bool firstRun) -> void {
	firstRun_ = firstRun;
}

auto BaseControl::ContentHolder::getContent() const -> const Content& {
	return content_;
}

auto BaseControl::ContentHolder::setContent(const Content& content) -> void {
	if (getAlign() == ALIGN::RIGHT) {
		Content copy = content;
		std::reverse(copy.begin(), copy.end());
		checkContent(copy);
	} else {
		checkContent(content);
	}
}

auto BaseControl::ContentHolder::checkContent(const Content& content) -> void {
	if (content_ != content) {
		setContentInvalid(true);
		content_ = content;
	}
}

auto BaseControl::ContentHolder::isContentInvalid() const -> bool {
	return contentInvalid_;
}

auto BaseControl::ContentHolder::setContentInvalid(const bool contentInvalid) -> void {
	contentInvalid_ = contentInvalid;
}

auto BaseControl::ContentHolder::getAlign() const -> ALIGN {
	return align_;
}

auto BaseControl::ContentHolder::setAlign(ALIGN align) -> void {
	align_ = align;
}

auto BaseControl::ContentHolder::getDefaultFontSize() const -> float {
	return defaultFontSize_;
}

auto BaseControl::ContentHolder::setDefaultFontSize(float fontSize) -> void {
	defaultFontSize_ = fontSize;
}

auto BaseControl::ContentHolder::getDefaultFontColor() -> NVGcolor& {
	return defaultFontColor_;
}

auto BaseControl::ContentHolder::setDefaultFontColor(const NVGcolor& fontColor) -> void {
	defaultFontColor_ = fontColor;
}

auto BaseControl::ContentHolder::getFontFace() const -> const string& {
	return fontFace_;
}

auto BaseControl::ContentHolder::setFontFace(const string& fontFace) -> void {
	fontFace_ = fontFace;
}

auto BaseControl::ContentHolder::getContentHorizontalAlign() const -> int {
	return contentHorizontalAlign_;
}

auto BaseControl::ContentHolder::setContentHorizontalAlign(int contentHorizontalAlign) -> void {
	contentHorizontalAlign_ = contentHorizontalAlign;
}

auto BaseControl::ContentHolder::getContentVerticalAlign() const -> int {
	return contentVerticalAlign_;
}

auto BaseControl::ContentHolder::setContentVerticalAlign(int contentVerticalAlign) -> void {
	contentVerticalAlign_ = contentVerticalAlign;
}

auto BaseControl::ContentHolder::addSize(string name, float size) -> void {
	/*
	 * This is not an error... This is some kind of MSFS SDK bullsh*t...
	 */
	fontSizes_.emplace(name, size);
}

auto BaseControl::ContentHolder::addColor(string name, NVGcolor color) -> void {
	/*
	 * This is not an error... This is some kind of MSFS SDK bullsh*t...
	 */
	fontColors_.emplace(name, color);
}

auto BaseControl::ContentHolder::addContentVerticalOffset(string name, float offset) -> void {
	/*
	 * This is not an error... This is some kind of MSFS SDK bullsh*t...
	 */
	contentVerticalOffset_.emplace(name, offset);
}

auto BaseControl::ContentHolder::getFontSizes() const -> const std::map<string, float>& {
	return fontSizes_;
}

auto BaseControl::ContentHolder::getFontColors() const -> const std::map<string, NVGcolor>& {
	return fontColors_;
}

auto BaseControl::ContentHolder::getContentVerticalOffset() const -> const std::map<string, float>& {
	return contentVerticalOffset_;
}

auto BaseControl::ContentHolder::getChunkFontSize(int chunkNumber) -> float {
	for (auto& size : fontSizes_) {
		if (getContent().at(chunkNumber)[1].find(size.first) != std::string::npos) {
			return size.second;
		}
	}

	return getDefaultFontSize();
}

auto BaseControl::ContentHolder::getChunkFontColor(int chunkNumber) -> NVGcolor& {
	for (auto& color : fontColors_) {
		if (getContent().at(chunkNumber)[1].find(color.first) != std::string::npos) {
			return color.second;
		}
	}

	return getDefaultFontColor();
}

auto BaseControl::ContentHolder::getChunkContentVerticalOffset(int chunkNumber) -> float {
	for (auto& offset : contentVerticalOffset_) {
		if (getContent().at(chunkNumber)[1].find(offset.first) != std::string::npos) {
			return offset.second;
		}
	}

	return 0;
}
