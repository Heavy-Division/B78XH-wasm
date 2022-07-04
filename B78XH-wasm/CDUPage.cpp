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


#include "CDUPage.h"

CDUPage::CDUPage(NVGcontext*& context): context(context) {
}

CDUPage::~CDUPage() = default;

std::vector<CDULine>& CDUPage::getLines() {
	return this->lines;
}

const std::function<void()>& CDUPage::getLSK1Event() const { return this->lsk1Event; }

const std::function<void()>& CDUPage::getLSK2Event() const { return this->lsk2Event; }

const std::function<void()>& CDUPage::getLSK3Event() const { return this->lsk3Event; }

const std::function<void()>& CDUPage::getLSK4Event() const { return this->lsk4Event; }

const std::function<void()>& CDUPage::getLSK5Event() const { return this->lsk5Event; }

const std::function<void()>& CDUPage::getLSK6Event() const { return this->lsk6Event; }

const std::function<void()>& CDUPage::getRSK1Event() const { return this->rsk1Event; }

const std::function<void()>& CDUPage::getRSK2Event() const { return this->rsk2Event; }

const std::function<void()>& CDUPage::getRSK3Event() const { return this->rsk3Event; }

const std::function<void()>& CDUPage::getRSK4Event() const { return this->rsk4Event; }

const std::function<void()>& CDUPage::getRSK5Event() const { return this->rsk5Event; }

const std::function<void()>& CDUPage::getRSK6Event() const { return this->rsk6Event; }
