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


#include "MFDCduGauge.h"

bool MFDCduGauge::preInstall() {
	renderer.preInstall();
	return true;
}

bool MFDCduGauge::postInstall(FsContext context) {
	renderer.postInstall(context);
	return true;
}

bool MFDCduGauge::preUpdate() {
	renderer.preUpdate();
	return true;
}

bool MFDCduGauge::preDraw(sGaugeDrawData* data) {
	renderer.preDraw(data);
	return true;
}

bool MFDCduGauge::preDraw(FsContext context, sGaugeDrawData* data) {
	return true;
}

bool MFDCduGauge::preKill() {
	renderer.preKill();
	return true;
}

CDUMouseMoveResolver& MFDCduGauge::getMouseMoveResolver() {
	return this->mouseMoveResolver;
}

CDUMouseClickResolver& MFDCduGauge::getMouseClickResolver() {
	return this->mouseClickResolver;
}
