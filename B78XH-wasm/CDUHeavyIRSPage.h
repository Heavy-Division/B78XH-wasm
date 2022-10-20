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
#include "CDUPage.h"

class CDUHeavyIRSPage : public CDUPage {
	public:
		CDUHeavyIRSPage(NVGcontext*& context)
			: CDUPage(context) {
		}

		auto preparePage() -> void override;
		auto getIrsStatusLine() const -> std::vector<std::string>;
		auto getAlignTimeLine() const -> std::vector<std::string>;
	private:
		enum SubPageType{
			INDEX,
			ALIGN_TIME_CONFIGURATION
		};

		SubPageType subpage = INDEX;

		auto prepareIndex() -> void;
		auto prepareAlignTimeConfiguration() -> void;
};
