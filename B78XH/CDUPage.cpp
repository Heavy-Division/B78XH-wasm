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
#include "LVarsGetter.h"

CDUPage::CDUPage(NVGcontext*& context): context(context) {

}

auto CDUPage::switchPage(CDUPageType pageId) -> void {
	LVarsGetter::setCDUControlId(pageId);
}

auto CDUPage::triggerEvent(CDUEvent eventId) -> void {
	LVarsGetter::setCDUControlId(eventId);
}

auto CDUPage::LTP1(std::vector<std::string> value) -> void {
	this->leftTitleOne.data.push_back(value);
}

auto CDUPage::LTP2(std::vector<std::string> value) -> void {
	this->leftTitleTwo.data.push_back(value);
}

auto CDUPage::LTP3(std::vector<std::string> value) -> void {
	this->leftTitleThree.data.push_back(value);
}

auto CDUPage::LTP4(std::vector<std::string> value) -> void {
	this->leftTitleFour.data.push_back(value);
}

auto CDUPage::LTP5(std::vector<std::string> value) -> void {
	this->leftTitleFive.data.push_back(value);
}

auto CDUPage::LTP6(std::vector<std::string> value) -> void {
	this->leftTitleSix.data.push_back(value);
}

auto CDUPage::LLP1(std::vector<std::string> value) -> void {
	this->leftLineOne.data.push_back(value);
}

auto CDUPage::LLP2(std::vector<std::string> value) -> void {
	this->leftLineTwo.data.push_back(value);
}

auto CDUPage::LLP3(std::vector<std::string> value) -> void {
	this->leftLineThree.data.push_back(value);
}

auto CDUPage::LLP4(std::vector<std::string> value) -> void {
	this->leftLineFour.data.push_back(value);
}

auto CDUPage::LLP5(std::vector<std::string> value) -> void {
	this->leftLineFive.data.push_back(value);
}

auto CDUPage::LLP6(std::vector<std::string> value) -> void {
	this->leftLineSix.data.push_back(value);
}

auto CDUPage::CTP1(std::vector<std::string> value) -> void {
	this->centerTitleOne.data.push_back(value);
}

auto CDUPage::CTP2(std::vector<std::string> value) -> void {
	this->centerTitleTwo.data.push_back(value);
}

auto CDUPage::CTP3(std::vector<std::string> value) -> void {
	this->centerTitleThree.data.push_back(value);
}

auto CDUPage::CTP4(std::vector<std::string> value) -> void {
	this->centerTitleFour.data.push_back(value);
}

auto CDUPage::CTP5(std::vector<std::string> value) -> void {
	this->centerTitleFive.data.push_back(value);
}

auto CDUPage::CTP6(std::vector<std::string> value) -> void {
	this->centerTitleSix.data.push_back(value);
}

auto CDUPage::CLP1(std::vector<std::string> value) -> void {
	this->centerLineOne.data.push_back(value);
}

auto CDUPage::CLP2(std::vector<std::string> value) -> void {
	this->centerLineTwo.data.push_back(value);
}

auto CDUPage::CLP3(std::vector<std::string> value) -> void {
	this->centerLineThree.data.push_back(value);
}

auto CDUPage::CLP4(std::vector<std::string> value) -> void {
	this->centerLineFour.data.push_back(value);
}

auto CDUPage::CLP5(std::vector<std::string> value) -> void {
	this->centerLineFive.data.push_back(value);
}

auto CDUPage::CLP6(std::vector<std::string> value) -> void {
	this->centerLineSix.data.push_back(value);
}

auto CDUPage::RTP1(std::vector<std::string> value) -> void {
	this->rightTitleOne.data.push_back(value);
}

auto CDUPage::RTP2(std::vector<std::string> value) -> void {
	this->rightTitleTwo.data.push_back(value);
}

auto CDUPage::RTP3(std::vector<std::string> value) -> void {
	this->rightTitleThree.data.push_back(value);
}

auto CDUPage::RTP4(std::vector<std::string> value) -> void {
	this->rightTitleFour.data.push_back(value);
}

auto CDUPage::RTP5(std::vector<std::string> value) -> void {
	this->rightTitleFive.data.push_back(value);
}

auto CDUPage::RTP6(std::vector<std::string> value) -> void {
	this->rightTitleSix.data.push_back(value);
}

auto CDUPage::RLP1(std::vector<std::string> value) -> void {
	this->rightLineOne.data.push_back(value);
}

auto CDUPage::RLP2(std::vector<std::string> value) -> void {
	this->rightLineTwo.data.push_back(value);
}

auto CDUPage::RLP3(std::vector<std::string> value) -> void {
	this->rightLineThree.data.push_back(value);
}

auto CDUPage::RLP4(std::vector<std::string> value) -> void {
	this->rightLineFour.data.push_back(value);
}

auto CDUPage::RLP5(std::vector<std::string> value) -> void {
	this->rightLineFive.data.push_back(value);
}

auto CDUPage::RLP6(std::vector<std::string> value) -> void {
	this->rightLineSix.data.push_back(value);
}

auto CDUPage::LT1(std::vector<std::vector<std::string>> value) -> void {
	this->leftTitleOne.data = value;
}

auto CDUPage::LT2(std::vector<std::vector<std::string>> value) -> void {
	this->leftTitleTwo.data = value;
}

auto CDUPage::LT3(std::vector<std::vector<std::string>> value) -> void {
	this->leftTitleThree.data = value;
}

auto CDUPage::LT4(std::vector<std::vector<std::string>> value) -> void {
	this->leftTitleFour.data = value;
}

auto CDUPage::LT5(std::vector<std::vector<std::string>> value) -> void {
	this->leftTitleFive.data = value;
}

auto CDUPage::LT6(std::vector<std::vector<std::string>> value) -> void {
	this->leftTitleSix.data = value;
}

auto CDUPage::LL1(std::vector<std::vector<std::string>> value) -> void {
	this->leftLineOne.data = value;
}

auto CDUPage::LL2(std::vector<std::vector<std::string>> value) -> void {
	this->leftLineTwo.data = value;
}

auto CDUPage::LL3(std::vector<std::vector<std::string>> value) -> void {
	this->leftLineThree.data = value;
}

auto CDUPage::LL4(std::vector<std::vector<std::string>> value) -> void {
	this->leftLineFour.data = value;
}

auto CDUPage::LL5(std::vector<std::vector<std::string>> value) -> void {
	this->leftLineFive.data = value;
}

auto CDUPage::LL6(std::vector<std::vector<std::string>> value) -> void {
	this->leftLineSix.data = value;
}

auto CDUPage::CT1(std::vector<std::vector<std::string>> value) -> void {
	this->centerTitleOne.data = value;
}

auto CDUPage::CT2(std::vector<std::vector<std::string>> value) -> void {
	this->centerTitleTwo.data = value;
}

auto CDUPage::CT3(std::vector<std::vector<std::string>> value) -> void {
	this->centerTitleThree.data = value;
}

auto CDUPage::CT4(std::vector<std::vector<std::string>> value) -> void {
	this->centerTitleFour.data = value;
}

auto CDUPage::CT5(std::vector<std::vector<std::string>> value) -> void {
	this->centerTitleFive.data = value;
}

auto CDUPage::CT6(std::vector<std::vector<std::string>> value) -> void {
	this->centerTitleSix.data = value;
}

auto CDUPage::CL1(std::vector<std::vector<std::string>> value) -> void {
	this->centerLineOne.data = value;
}

auto CDUPage::CL2(std::vector<std::vector<std::string>> value) -> void {
	this->centerLineTwo.data = value;
}

auto CDUPage::CL3(std::vector<std::vector<std::string>> value) -> void {
	this->centerLineThree.data = value;
}

auto CDUPage::CL4(std::vector<std::vector<std::string>> value) -> void {
	this->centerLineFour.data = value;
}

auto CDUPage::CL5(std::vector<std::vector<std::string>> value) -> void {
	this->centerLineFive.data = value;
}

auto CDUPage::CL6(std::vector<std::vector<std::string>> value) -> void {
	this->centerLineSix.data = value;
}

auto CDUPage::RT1(std::vector<std::vector<std::string>> value) -> void {
	this->rightTitleOne.data = value;
}

auto CDUPage::RT2(std::vector<std::vector<std::string>> value) -> void {
	this->rightTitleTwo.data = value;
}

auto CDUPage::RT3(std::vector<std::vector<std::string>> value) -> void {
	this->rightTitleThree.data = value;
}

auto CDUPage::RT4(std::vector<std::vector<std::string>> value) -> void {
	this->rightTitleFour.data = value;
}

auto CDUPage::RT5(std::vector<std::vector<std::string>> value) -> void {
	this->rightTitleFive.data = value;
}

auto CDUPage::RT6(std::vector<std::vector<std::string>> value) -> void {
	this->rightTitleSix.data = value;
}

auto CDUPage::RL1(std::vector<std::vector<std::string>> value) -> void {
	this->rightLineOne.data = value;
}

auto CDUPage::RL2(std::vector<std::vector<std::string>> value) -> void {
	this->rightLineTwo.data = value;
}

auto CDUPage::RL3(std::vector<std::vector<std::string>> value) -> void {
	this->rightLineThree.data = value;
}

auto CDUPage::RL4(std::vector<std::vector<std::string>> value) -> void {
	this->rightLineFour.data = value;
}

auto CDUPage::RL5(std::vector<std::vector<std::string>> value) -> void {
	this->rightLineFive.data = value;
}

auto CDUPage::RL6(std::vector<std::vector<std::string>> value) -> void {
	this->rightLineSix.data = value;
}


CDUPage::~CDUPage() = default;

auto CDUPage::getLines() -> std::vector<CDULinePerformance>& {
	this->lines.push_back(this->leftTitleOne);
	this->lines.push_back(this->leftTitleTwo);
	this->lines.push_back(this->leftTitleThree);
	this->lines.push_back(this->leftTitleFour);
	this->lines.push_back(this->leftTitleFive);
	this->lines.push_back(this->leftTitleSix);

	this->lines.push_back(this->leftLineOne);
	this->lines.push_back(this->leftLineTwo);
	this->lines.push_back(this->leftLineThree);
	this->lines.push_back(this->leftLineFour);
	this->lines.push_back(this->leftLineFive);
	this->lines.push_back(this->leftLineSix);

	this->lines.push_back(this->centerTitleOne);
	this->lines.push_back(this->centerTitleTwo);
	this->lines.push_back(this->centerTitleThree);
	this->lines.push_back(this->centerTitleFour);
	this->lines.push_back(this->centerTitleFive);
	this->lines.push_back(this->centerTitleSix);

	this->lines.push_back(this->centerLineOne);
	this->lines.push_back(this->centerLineTwo);
	this->lines.push_back(this->centerLineThree);
	this->lines.push_back(this->centerLineFour);
	this->lines.push_back(this->centerLineFive);
	this->lines.push_back(this->centerLineSix);

	this->lines.push_back(this->rightTitleOne);
	this->lines.push_back(this->rightTitleTwo);
	this->lines.push_back(this->rightTitleThree);
	this->lines.push_back(this->rightTitleFour);
	this->lines.push_back(this->rightTitleFive);
	this->lines.push_back(this->rightTitleSix);

	this->lines.push_back(this->rightLineOne);
	this->lines.push_back(this->rightLineTwo);
	this->lines.push_back(this->rightLineThree);
	this->lines.push_back(this->rightLineFour);
	this->lines.push_back(this->rightLineFive);
	this->lines.push_back(this->rightLineSix);
	return this->lines;
}

auto CDUPage::preparePage() -> void {
}

auto CDUPage::clearEvents() -> void {
	this->lsk1Event = nullptr;
	this->lsk2Event = nullptr;
	this->lsk3Event = nullptr;
	this->lsk4Event = nullptr;
	this->lsk5Event = nullptr;
	this->lsk6Event = nullptr;
	this->rsk1Event = nullptr;
	this->rsk2Event = nullptr;
	this->rsk3Event = nullptr;
	this->rsk4Event = nullptr;
	this->rsk5Event = nullptr;
	this->rsk6Event = nullptr;
}

auto CDUPage::clearLines() -> void {
	this->lines.clear();
	this->clearLinesData();
}

auto CDUPage::clearLinesData() -> void {
	this->leftTitleOne.data.clear();
	this->leftTitleTwo.data.clear();
	this->leftTitleThree.data.clear();
	this->leftTitleFour.data.clear();
	this->leftTitleFive.data.clear();
	this->leftTitleSix.data.clear();

	this->leftLineOne.data.clear();
	this->leftLineTwo.data.clear();
	this->leftLineThree.data.clear();
	this->leftLineFour.data.clear();
	this->leftLineFive.data.clear();
	this->leftLineSix.data.clear();

	this->centerTitleOne.data.clear();
	this->centerTitleTwo.data.clear();
	this->centerTitleThree.data.clear();
	this->centerTitleFour.data.clear();
	this->centerTitleFive.data.clear();
	this->centerTitleSix.data.clear();

	this->centerLineOne.data.clear();
	this->centerLineTwo.data.clear();
	this->centerLineThree.data.clear();
	this->centerLineFour.data.clear();
	this->centerLineFive.data.clear();
	this->centerLineSix.data.clear();

	this->rightTitleOne.data.clear();
	this->rightTitleTwo.data.clear();
	this->rightTitleThree.data.clear();
	this->rightTitleFour.data.clear();
	this->rightTitleFive.data.clear();
	this->rightTitleSix.data.clear();

	this->rightLineOne.data.clear();
	this->rightLineTwo.data.clear();
	this->rightLineThree.data.clear();
	this->rightLineFour.data.clear();
	this->rightLineFive.data.clear();
	this->rightLineSix.data.clear();
}

auto CDUPage::getLSK1Event() const -> const std::function<void()>& {
	return this->lsk1Event;
}

auto CDUPage::getLSK2Event() const -> const std::function<void()>& {
	return this->lsk2Event;
}

auto CDUPage::getLSK3Event() const -> const std::function<void()>& {
	return this->lsk3Event;
}

auto CDUPage::getLSK4Event() const -> const std::function<void()>& {
	return this->lsk4Event;
}

auto CDUPage::getLSK5Event() const -> const std::function<void()>& {
	return this->lsk5Event;
}

auto CDUPage::getLSK6Event() const -> const std::function<void()>& {
	return this->lsk6Event;
}

auto CDUPage::getRSK1Event() const -> const std::function<void()>& {
	return this->rsk1Event;
}

auto CDUPage::getRSK2Event() const -> const std::function<void()>& {
	return this->rsk2Event;
}

auto CDUPage::getRSK3Event() const -> const std::function<void()>& {
	return this->rsk3Event;
}

auto CDUPage::getRSK4Event() const -> const std::function<void()>& {
	return this->rsk4Event;
}

auto CDUPage::getRSK5Event() const -> const std::function<void()>& {
	return this->rsk5Event;
}

auto CDUPage::getRSK6Event() const -> const std::function<void()>& {
	return this->rsk6Event;
}
