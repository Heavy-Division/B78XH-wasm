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

#include "CDULine.h"
#include "MSFS/Render/nanovg.h"
#include "functional";


class CDUPage {

	protected:
		CDUPage(NVGcontext*& context);

	public:
		virtual ~CDUPage();
		virtual std::vector<CDULine>& getLines();
		const std::function<void()>& getLSK1Event() const;
		const std::function<void()>& getLSK2Event() const;
		const std::function<void()>& getLSK3Event() const;
		const std::function<void()>& getLSK4Event() const;
		const std::function<void()>& getLSK5Event() const;
		const std::function<void()>& getLSK6Event() const;
		const std::function<void()>& getRSK1Event() const;
		const std::function<void()>& getRSK2Event() const;
		const std::function<void()>& getRSK3Event() const;
		const std::function<void()>& getRSK4Event() const;
		const std::function<void()>& getRSK5Event() const;
		const std::function<void()>& getRSK6Event() const;

	protected:
		NVGcontext*& context;
		std::vector<CDULine> lines = {};
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
};
