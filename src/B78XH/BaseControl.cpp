#include "BaseControl.h"

#include "Tools/Tools.h"

auto BaseControl::addControl(std::unique_ptr<BaseControl> pointer) -> void {
	this->controls.emplace_back(std::move(pointer));
	
}

auto BaseControl::render(sGaugeDrawData* data) -> void {
	this->storedGaugeDrawData = data;
}

auto BaseControl::startup(sGaugeInstallData* data) -> void {
	this->storedGaugeInstallData = data;
	this->prepareControls();
	this->executeControlsStartup();
}

auto BaseControl::afterStartup(FsContext fsContext) -> void {
	this->fsContext = fsContext;
	this->prepareRenderingContext();
	this->prepareRenderingContextDefaults();
	this->executeControlsAfterStartup();
	this->setupControls();
}

auto BaseControl::beforeUpdate() -> void {
}

auto BaseControl::afterUpdate() -> void {
}

auto BaseControl::beforeRender() -> void {
}

auto BaseControl::shutdown() -> void {
	this->safeShutdown();
}

auto BaseControl::prepareControls() -> void {

}

auto BaseControl::setupControls() -> void {
}

auto BaseControl::executeRendering() -> void {
	if (this->nvgContext == nullptr) {
		return;
	}

	const float pxRatio = static_cast<float>(this->storedGaugeDrawData->fbWidth) / static_cast<float>(this->
		storedGaugeDrawData->winWidth);
	const auto winWidth = static_cast<float>(this->storedGaugeDrawData->winWidth);
	const auto winHeight = static_cast<float>(this->storedGaugeDrawData->winHeight);

	nvgBeginFrame(this->nvgContext, winWidth, winHeight, pxRatio);
	{
		if (this->autoClearing) {
			this->clearDisplay(winWidth, winHeight);
		}

		for (auto& con : this->controls) {
			this->setLevel(this->level + 1);
			const bool controlAutoCrop = con->getAutoCrop();
			nvgSave(this->nvgContext);
			{
				nvgTranslate(this->nvgContext, con->getMarginLeft(), con->getMarginTop());
				{
					nvgSave(this->nvgContext);
					{
						if (controlAutoCrop == true) {
							nvgScissor(this->nvgContext, con->getCropMarginLeft(), con->getCropMarginTop(),
							           con->getWidth(), con->getHeight());
							con->processRender(con);
							nvgResetScissor(this->nvgContext);
						}
						else {
							con->processRender(con);
						}
					}
					nvgRestore(this->nvgContext);
				}
				nvgResetTransform(this->nvgContext);
			}
			nvgRestore(this->nvgContext);
		}
	}
	nvgEndFrame(this->nvgContext);
}

auto BaseControl::setAutoCrop(bool autoCrop) -> void {
	this->autoCrop = autoCrop;
}

auto BaseControl::getAutoCrop() const -> bool {
	return this->autoCrop;
}

void BaseControl::setMargin(double left, double top) {
	this->marginLeft = left;
	this->marginTop = top;
}

void BaseControl::setCropMargin(double left, double top) {
	this->cropMarginLeft = left;
	this->cropMarginTop = top;
}

void BaseControl::setSize(double width, double height) {
	this->width = width;
	this->height = height;
}

void BaseControl::setWidth(double width) {
	this->width = width;
}

void BaseControl::setHeight(double height) {
	this->height = height;
}

auto BaseControl::getWidth() const -> double {
	return this->width;
}

auto BaseControl::getHeight() const -> double {
	return this->height;
}

auto BaseControl::getMarginLeft() const -> double {
	return this->marginLeft;
}

auto BaseControl::getMarginTop() const -> double {
	return this->marginTop;
}

auto BaseControl::getCropMarginLeft() const -> double {
	return this->cropMarginLeft;
}

auto BaseControl::getCropMarginTop() const -> double {
	return this->cropMarginTop;
}

auto BaseControl::isControlInvalid() -> bool {
	if(this->onValidate.empty()) {
		return true;
	}
	for(auto& validate : this->onValidate) {
		if(!validate()) {
			return true;
		}
	}
	return false;
}

auto BaseControl::clearDisplay(double width, double height) const -> void {
	nvgFillColor(nvgContext, Tools::Colors::black);
	nvgBeginPath(nvgContext);
	{
		nvgRect(nvgContext, 0, 0, width, height);
	}
	nvgFill(nvgContext);
	nvgClosePath(nvgContext);
}

auto BaseControl::setAutoClearing(bool autoClearing) -> void {
	this->autoClearing = autoClearing;
}

auto BaseControl::executeControlsStartup() const -> void {
	for (auto& con : this->controls) {
		con->startup(this->storedGaugeInstallData);
	}
}

auto BaseControl::executeControlsAfterStartup() const -> void {
	for (auto& con : this->controls) {
		con->afterStartup(this->fsContext);
	}
}

auto BaseControl::processRender(std::unique_ptr<BaseControl>& control) const -> void {
	if (this->nvgContext == nullptr) {
		return;
	}
	if(control->isControlInvalid()) {
		control->render(this->storedGaugeDrawData);
	}
	for (auto& con : control->controls) {
		con->processRender(con);
	}

}

auto BaseControl::addFont(std::string alias, std::string filename, BaseControl::FONT_TYPE type, PSTRINGZ path) -> void {
	/*
	 * Do not load font if the font is already loaded
	 */
	if (nvgFindFont(this->nvgContext, "alias") != -1) {
		return;
	}

	(type == FONT_TYPE::DEFAULT_FONT ? this->defaultFonts : this->fonts).emplace_back(nvgCreateFont(this->nvgContext,
		alias.c_str(), std::string(path).append(filename).c_str()));
}

auto BaseControl::addDefaultFont(std::string alias, std::string filename, PSTRINGZ path) -> void {
	this->addFont(alias, filename, FONT_TYPE::DEFAULT_FONT, path);
}

auto BaseControl::prepareRenderingContext() -> void {
	NVGparams params;
	params.userPtr = this->fsContext;
	params.edgeAntiAlias = true;
	this->nvgContext = nvgCreateInternal(&params);
}

auto BaseControl::prepareRenderingContextDefaults() -> void {
	this->prepareRenderingContextDefaultsFonts();
}

auto BaseControl::prepareRenderingContextDefaultsFonts() -> void {
	this->addDefaultFont("roboto", "Roboto-Regular.ttf", "./data/");
	this->addDefaultFont("heavy-fmc", "Heavy787FMC.ttf", "./data/");
	this->addDefaultFont("dseg7", "DSEG7ClassicMini-Italic.ttf", "./data/");
}

auto BaseControl::addFont(std::string alias, std::string filename, PSTRINGZ path) -> void {
	this->addFont(alias, filename, FONT_TYPE::FONT, path);
}

auto BaseControl::getContext() const -> NVGcontext* {
	return this->nvgContext;
}

auto BaseControl::safeShutdown() const -> void {
	if (this->nvgContext == nullptr) {
		return;
	}
	nvgDeleteInternal(this->nvgContext);
}

auto BaseControl::getLevel() const -> int {
	return this->level;
}

auto BaseControl::setLevel(int level) -> void {
	this->level = level;
}
