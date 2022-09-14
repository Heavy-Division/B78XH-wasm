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
#include "AHRU.h"
#include "Alignable.h"
#include "IRU.h"
#include "Operable.h"
#include "Updateable.h"

class IRS final : public Operable, Alignable, Updateable {
	public:
		auto setTimeToAlign(double time) -> void override;
		auto isAligned() -> bool override;
		auto isAligning() -> bool override;
		auto getTimeToAlign() -> double override;
		auto update(double deltaTime) -> void override;
		auto setAlignState(AlignState state) -> void override;
	private:
		AHRU ahru;
		IRU iru;

		auto generateAlignTime() -> double;
};
