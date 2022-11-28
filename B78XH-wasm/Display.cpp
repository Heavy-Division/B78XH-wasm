//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


#include "Display.h"

#include "Tools.h"

auto Display::setupApplicationsContext() -> void {
	for (auto application : applications) {
		application.get().setContext(this->nvgContext);
	}
}

auto Display::runApplicationsPostInstall() -> void {
	for (auto application : applications) {
		application.get().postInstall();
	}
}

auto Display::runApplicationsPreKill() -> void {
	for (auto application : applications) {
		application.get().preKill();
	}
}

auto Display::addApplication(Application& application) -> void {
	this->applications.emplace_back(application);
}

auto Display::addFont(int font) -> void {
	this->fonts.emplace_back(font);
}

auto Display::clearDisplay(double width, double height) -> void {
	nvgFillColor(nvgContext, Tools::Colors::black);
	nvgBeginPath(nvgContext);
	nvgRect(nvgContext, 0, 0, width, height);
	nvgFill(nvgContext);
	nvgClosePath(nvgContext);
}

auto Display::preInstall() -> bool {
	this->prepareApplications();
	this->setupApplications();
	return true;
}

auto Display::postInstall(FsContext context) -> bool {
	this->fsContext = context;
	NVGparams params;
	params.userPtr = this->fsContext;
	params.edgeAntiAlias = true;
	nvgContext = nvgCreateInternal(&params);
	this->setupFonts();
	this->setupApplicationsContext();
	this->runApplicationsPostInstall();
	return true;
}

auto Display::setupFonts() -> void {
	this->addFont(nvgCreateFont(this->nvgContext, "roboto", "./data/Roboto-Regular.ttf"));
	this->addFont(nvgCreateFont(this->nvgContext, "heavy-fmc", "./data/Heavy787FMC.ttf"));
	this->addFont(nvgCreateFont(this->nvgContext, "dseg7", "./data/DSEG7ClassicMini-Italic.ttf"));
}

auto Display::preDraw(sGaugeDrawData* data) -> bool {
	if (this->nvgContext == nullptr) {
		return true;
	}
	const float pxRatio = static_cast<float>(data->fbWidth) / static_cast<float>(data->winWidth);
	const auto winWidth = static_cast<float>(data->winWidth);
	const auto winHeight = static_cast<float>(data->winHeight);

	nvgBeginFrame(this->nvgContext, winWidth, winHeight, pxRatio); {
		this->clearDisplay(winWidth, winHeight);
		for (auto application : applications) {
			const bool applicationAutoCrop = application.get().getAutoCrop();
			nvgSave(this->nvgContext);
			{
				nvgTranslate(this->nvgContext, application.get().getMarginLeft(), application.get().getMarginTop());
				{
					nvgSave(this->nvgContext);
					{
						if (applicationAutoCrop == true) {
							nvgScissor(this->nvgContext, application.get().getCropMarginLeft(), application.get().getCropMarginTop(), application.get().getWidth(), application.get().getHeight());
							application.get().render(data);
							nvgResetScissor(this->nvgContext);
						}
						else {
							application.get().render(data);
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
	return true;
}

auto Display::preKill() -> bool {
	this->runApplicationsPreKill();
	nvgDeleteInternal(nvgContext);
	return true;
}
