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
#include "IsfdDisplay.h"
#include "LeftInboardDisplay.h"
#include "LeftOutboardDisplay.h"
#include "LowerCenterDisplay.h"
#include "McpAltitudeDisplay.h"
#include "McpHeadingDisplay.h"
#include "McpSpeedDisplay.h"
#include "McpVerticalSpeedDisplay.h"
#include "RightInboardDisplay.h"
#include "RightOutboardDisplay.h"
#include "TcpCenterDisplay.h"
#include "TcpRightDisplay.h"
#include "TCPMasterControl.h"
#include "ExampleMasterControl.h"
#include "LeftOutboardMasterControl.h"
#include "MFDLeftInboardMasterControl.h"
#include "MFDCenterMasterControl.h"
#include "MFDRightInboardMasterControl.h"
#include "RightOutboardMasterControl.h"


namespace Displays {
	inline LeftOutboardDisplay leftOutboardDisplay;
	inline LeftInboardDisplay leftInboardDisplay;
	inline RightOutboardDisplay rightOutboardDisplay;
	inline RightInboardDisplay rightInboardDisplay;
	inline LowerCenterDisplay lowerCenterDisplay;

	inline McpAltitudeDisplay mcpAltitudeDisplay;
	inline McpHeadingDisplay mcpHeadingDisplay;
	inline McpSpeedDisplay mcpSpeedDisplay;
	inline McpVerticalSpeedDisplay mcpVerticalSpeedDisplay;

	inline IsfdDisplay isfdDisplay;

	inline TcpCenterDisplay tcpCenterDisplay;
	inline TcpRightDisplay tcpRightDisplay;

	//inline OldMasterControl oldMasterControl;
	//inline std::unique_ptr<MasterControl> masterControl = std::make_unique<MasterControl>("HAHA");

	inline std::unique_ptr<MasterControl> masterControl = std::make_unique<TCPMasterControl>("TCPMasterControl");
	inline std::unique_ptr<MasterControl> exampleControl = std::make_unique<ExampleControl>("ExampleControl");
	inline std::unique_ptr<MasterControl> leftOutBoardControl = std::make_unique<LeftOutBoardMasterControl>("LeftOutboardControl");
	inline std::unique_ptr<MasterControl> leftInboardControl = std::make_unique<MFDLeftInboardMasterControl>("LeftInboardControl");
	inline std::unique_ptr<MasterControl> centerMFDControl = std::make_unique<MFDCenterMasterControl>("CenterMFDControl");
	inline std::unique_ptr<MasterControl> rightInboardControl = std::make_unique<MFDRightInboardMasterControl>("RightInboardControl");
	inline std::unique_ptr<MasterControl> rightOutBoardControl = std::make_unique<RightOutboardMasterControl>("RightOutboardControl");
}
