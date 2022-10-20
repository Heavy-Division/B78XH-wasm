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


#pragma once

#include <vector>

#include "CDUEvent.h"
#include "CDULine.h"
#include "CDULinePerformance.h"
#include "CDUPageType.h"
#include "MSFS/Render/nanovg.h"
#include "functional";


class CDUPage {
	protected:
		CDUPage(NVGcontext*& context);
		auto switchPage(CDUPageType pageId) -> void;
		auto triggerEvent(CDUEvent eventId) -> void;
		NVGcontext*& context;
		std::vector<CDULinePerformance> lines = {};
		std::function<void()> lsk1Event;
		std::function<void()> lsk2Event;
		std::function<void()> lsk3Event;
		std::function<void()> lsk4Event;
		std::function<void()> lsk5Event;
		std::function<void()> lsk6Event;
		std::function<void()> rsk1Event;
		std::function<void()> rsk2Event;
		std::function<void()> rsk3Event;
		std::function<void()> rsk4Event;
		std::function<void()> rsk5Event;
		std::function<void()> rsk6Event;

		auto LTP1(std::vector<std::string> value) -> void;
		auto LTP2(std::vector<std::string> value) -> void;
		auto LTP3(std::vector<std::string> value) -> void;
		auto LTP4(std::vector<std::string> value) -> void;
		auto LTP5(std::vector<std::string> value) -> void;
		auto LTP6(std::vector<std::string> value) -> void;
		auto LLP1(std::vector<std::string> value) -> void;
		auto LLP2(std::vector<std::string> value) -> void;
		auto LLP3(std::vector<std::string> value) -> void;
		auto LLP4(std::vector<std::string> value) -> void;
		auto LLP5(std::vector<std::string> value) -> void;
		auto LLP6(std::vector<std::string> value) -> void;
		auto CTP1(std::vector<std::string> value) -> void;
		auto CTP2(std::vector<std::string> value) -> void;
		auto CTP3(std::vector<std::string> value) -> void;
		auto CTP4(std::vector<std::string> value) -> void;
		auto CTP5(std::vector<std::string> value) -> void;
		auto CTP6(std::vector<std::string> value) -> void;
		auto CLP1(std::vector<std::string> value) -> void;
		auto CLP2(std::vector<std::string> value) -> void;
		auto CLP3(std::vector<std::string> value) -> void;
		auto CLP4(std::vector<std::string> value) -> void;
		auto CLP5(std::vector<std::string> value) -> void;
		auto CLP6(std::vector<std::string> value) -> void;
		auto RTP1(std::vector<std::string> value) -> void;
		auto RTP2(std::vector<std::string> value) -> void;
		auto RTP3(std::vector<std::string> value) -> void;
		auto RTP4(std::vector<std::string> value) -> void;
		auto RTP5(std::vector<std::string> value) -> void;
		auto RTP6(std::vector<std::string> value) -> void;
		auto RLP1(std::vector<std::string> value) -> void;
		auto RLP2(std::vector<std::string> value) -> void;
		auto RLP3(std::vector<std::string> value) -> void;
		auto RLP4(std::vector<std::string> value) -> void;
		auto RLP5(std::vector<std::string> value) -> void;
		auto RLP6(std::vector<std::string> value) -> void;
		auto LT1(std::vector<std::vector<std::string>> value) -> void;
		auto LT2(std::vector<std::vector<std::string>> value) -> void;
		auto LT3(std::vector<std::vector<std::string>> value) -> void;
		auto LT4(std::vector<std::vector<std::string>> value) -> void;
		auto LT5(std::vector<std::vector<std::string>> value) -> void;
		auto LT6(std::vector<std::vector<std::string>> value) -> void;
		auto LL1(std::vector<std::vector<std::string>> value) -> void;
		auto LL2(std::vector<std::vector<std::string>> value) -> void;
		auto LL3(std::vector<std::vector<std::string>> value) -> void;
		auto LL4(std::vector<std::vector<std::string>> value) -> void;
		auto LL5(std::vector<std::vector<std::string>> value) -> void;
		auto LL6(std::vector<std::vector<std::string>> value) -> void;
		auto CT1(std::vector<std::vector<std::string>> value) -> void;
		auto CT2(std::vector<std::vector<std::string>> value) -> void;
		auto CT3(std::vector<std::vector<std::string>> value) -> void;
		auto CT4(std::vector<std::vector<std::string>> value) -> void;
		auto CT5(std::vector<std::vector<std::string>> value) -> void;
		auto CT6(std::vector<std::vector<std::string>> value) -> void;
		auto CL1(std::vector<std::vector<std::string>> value) -> void;
		auto CL2(std::vector<std::vector<std::string>> value) -> void;
		auto CL3(std::vector<std::vector<std::string>> value) -> void;
		auto CL4(std::vector<std::vector<std::string>> value) -> void;
		auto CL5(std::vector<std::vector<std::string>> value) -> void;
		auto CL6(std::vector<std::vector<std::string>> value) -> void;
		auto RT1(std::vector<std::vector<std::string>> value) -> void;
		auto RT2(std::vector<std::vector<std::string>> value) -> void;
		auto RT3(std::vector<std::vector<std::string>> value) -> void;
		auto RT4(std::vector<std::vector<std::string>> value) -> void;
		auto RT5(std::vector<std::vector<std::string>> value) -> void;
		auto RT6(std::vector<std::vector<std::string>> value) -> void;
		auto RL1(std::vector<std::vector<std::string>> value) -> void;
		auto RL2(std::vector<std::vector<std::string>> value) -> void;
		auto RL3(std::vector<std::vector<std::string>> value) -> void;
		auto RL4(std::vector<std::vector<std::string>> value) -> void;
		auto RL5(std::vector<std::vector<std::string>> value) -> void;
		auto RL6(std::vector<std::vector<std::string>> value) -> void;

		CDULinePerformance leftTitleOne =
				CDULinePerformance(CDULineType::TITLE, CDULineAlign::LEFT, CDULineNumber::ONE);
		CDULinePerformance leftTitleTwo =
				CDULinePerformance(CDULineType::TITLE, CDULineAlign::LEFT, CDULineNumber::TWO);
		CDULinePerformance leftTitleThree = CDULinePerformance(CDULineType::TITLE, CDULineAlign::LEFT,
		                                                       CDULineNumber::THREE);
		CDULinePerformance leftTitleFour = CDULinePerformance(CDULineType::TITLE, CDULineAlign::LEFT,
		                                                      CDULineNumber::FOUR);
		CDULinePerformance leftTitleFive = CDULinePerformance(CDULineType::TITLE, CDULineAlign::LEFT,
		                                                      CDULineNumber::FIVE);
		CDULinePerformance leftTitleSix =
				CDULinePerformance(CDULineType::TITLE, CDULineAlign::LEFT, CDULineNumber::SIX);
		CDULinePerformance leftLineOne = CDULinePerformance(CDULineType::LINE, CDULineAlign::LEFT, CDULineNumber::ONE);
		CDULinePerformance leftLineTwo = CDULinePerformance(CDULineType::LINE, CDULineAlign::LEFT, CDULineNumber::TWO);
		CDULinePerformance leftLineThree = CDULinePerformance(CDULineType::LINE, CDULineAlign::LEFT,
		                                                      CDULineNumber::THREE);
		CDULinePerformance leftLineFour =
				CDULinePerformance(CDULineType::LINE, CDULineAlign::LEFT, CDULineNumber::FOUR);
		CDULinePerformance leftLineFive =
				CDULinePerformance(CDULineType::LINE, CDULineAlign::LEFT, CDULineNumber::FIVE);
		CDULinePerformance leftLineSix = CDULinePerformance(CDULineType::LINE, CDULineAlign::LEFT, CDULineNumber::SIX);

		CDULinePerformance rightTitleOne = CDULinePerformance(CDULineType::TITLE, CDULineAlign::RIGHT,
		                                                      CDULineNumber::ONE);
		CDULinePerformance rightTitleTwo = CDULinePerformance(CDULineType::TITLE, CDULineAlign::RIGHT,
		                                                      CDULineNumber::TWO);
		CDULinePerformance rightTitleThree = CDULinePerformance(CDULineType::TITLE, CDULineAlign::RIGHT,
		                                                        CDULineNumber::THREE);
		CDULinePerformance rightTitleFour = CDULinePerformance(CDULineType::TITLE, CDULineAlign::RIGHT,
		                                                       CDULineNumber::FOUR);
		CDULinePerformance rightTitleFive = CDULinePerformance(CDULineType::TITLE, CDULineAlign::RIGHT,
		                                                       CDULineNumber::FIVE);
		CDULinePerformance rightTitleSix = CDULinePerformance(CDULineType::TITLE, CDULineAlign::RIGHT,
		                                                      CDULineNumber::SIX);
		CDULinePerformance rightLineOne =
				CDULinePerformance(CDULineType::LINE, CDULineAlign::RIGHT, CDULineNumber::ONE);
		CDULinePerformance rightLineTwo =
				CDULinePerformance(CDULineType::LINE, CDULineAlign::RIGHT, CDULineNumber::TWO);
		CDULinePerformance rightLineThree = CDULinePerformance(CDULineType::LINE, CDULineAlign::RIGHT,
		                                                       CDULineNumber::THREE);
		CDULinePerformance rightLineFour = CDULinePerformance(CDULineType::LINE, CDULineAlign::RIGHT,
		                                                      CDULineNumber::FOUR);
		CDULinePerformance rightLineFive = CDULinePerformance(CDULineType::LINE, CDULineAlign::RIGHT,
		                                                      CDULineNumber::FIVE);
		CDULinePerformance rightLineSix =
				CDULinePerformance(CDULineType::LINE, CDULineAlign::RIGHT, CDULineNumber::SIX);

		CDULinePerformance centerTitleOne = CDULinePerformance(CDULineType::TITLE, CDULineAlign::CENTER,
		                                                       CDULineNumber::ONE);
		CDULinePerformance centerTitleTwo = CDULinePerformance(CDULineType::TITLE, CDULineAlign::CENTER,
		                                                       CDULineNumber::TWO);
		CDULinePerformance centerTitleThree = CDULinePerformance(CDULineType::TITLE, CDULineAlign::CENTER,
		                                                         CDULineNumber::THREE);
		CDULinePerformance centerTitleFour = CDULinePerformance(CDULineType::TITLE, CDULineAlign::CENTER,
		                                                        CDULineNumber::FOUR);
		CDULinePerformance centerTitleFive = CDULinePerformance(CDULineType::TITLE, CDULineAlign::CENTER,
		                                                        CDULineNumber::FIVE);
		CDULinePerformance centerTitleSix = CDULinePerformance(CDULineType::TITLE, CDULineAlign::CENTER,
		                                                       CDULineNumber::SIX);
		CDULinePerformance centerLineOne = CDULinePerformance(CDULineType::LINE, CDULineAlign::CENTER,
		                                                      CDULineNumber::ONE);
		CDULinePerformance centerLineTwo = CDULinePerformance(CDULineType::LINE, CDULineAlign::CENTER,
		                                                      CDULineNumber::TWO);
		CDULinePerformance centerLineThree = CDULinePerformance(CDULineType::LINE, CDULineAlign::CENTER,
		                                                        CDULineNumber::THREE);
		CDULinePerformance centerLineFour = CDULinePerformance(CDULineType::LINE, CDULineAlign::CENTER,
		                                                       CDULineNumber::FOUR);
		CDULinePerformance centerLineFive = CDULinePerformance(CDULineType::LINE, CDULineAlign::CENTER,
		                                                       CDULineNumber::FIVE);
		CDULinePerformance centerLineSix = CDULinePerformance(CDULineType::LINE, CDULineAlign::CENTER,
		                                                      CDULineNumber::SIX);

	public:
		virtual ~CDUPage();
		virtual auto getLines() -> std::vector<CDULinePerformance>&;
		virtual auto preparePage() -> void;
		auto clearEvents() -> void;
		auto clearLines() -> void;
		inline auto clearLinesData() -> void;
		auto getLSK1Event() const -> const std::function<void()>&;
		auto getLSK2Event() const -> const std::function<void()>&;
		auto getLSK3Event() const -> const std::function<void()>&;
		auto getLSK4Event() const -> const std::function<void()>&;
		auto getLSK5Event() const -> const std::function<void()>&;
		auto getLSK6Event() const -> const std::function<void()>&;
		auto getRSK1Event() const -> const std::function<void()>&;
		auto getRSK2Event() const -> const std::function<void()>&;
		auto getRSK3Event() const -> const std::function<void()>&;
		auto getRSK4Event() const -> const std::function<void()>&;
		auto getRSK5Event() const -> const std::function<void()>&;
		auto getRSK6Event() const -> const std::function<void()>&;
};
