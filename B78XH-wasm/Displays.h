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
#include "LeftInboardDisplay.h"
#include "LeftOutboardDisplay.h"
#include "LowerCenterDisplay.h"
#include "McpAltitudeDisplay.h"
#include "McpHeadingDisplay.h"
#include "McpSpeedDisplay.h"
#include "McpVerticalSpeedDisplay.h"
#include "RightInboardDisplay.h"
#include "RightOutboardDisplay.h"

namespace Displays {
	inline LeftOutboardDisplay leftOutboardDisplay;
	inline LeftInboardDisplay leftInboardDisplay;
	/*
	 * RightOutboardDisplay is not needed for default ASOBO 787
	 */
	inline RightOutboardDisplay rightOutboardDisplay;
	inline RightInboardDisplay rightInboardDisplay;
	inline LowerCenterDisplay lowerCenterDisplay;
	inline McpAltitudeDisplay mcpAltitudeDisplay;
	inline McpHeadingDisplay mcpHeadingDisplay;
	inline McpSpeedDisplay mcpSpeedDisplay;
	inline McpVerticalSpeedDisplay mcpVerticalSpeedDisplay;

}
