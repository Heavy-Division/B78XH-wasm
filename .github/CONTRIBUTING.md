Thank you for your interest in contributing to the B78XH-wasm project. 

# Supported Languages:
C++ 

# Setting up Environment
1. Fork the repository.
2. Download the [Visual Studio Installer](https://docs.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=vs-2022)
3. Follow the instructions and install Visual C++ Compiler and Build Tools
4. Download and install VS2022.

> Optional: If you are familiar with JetBrains tools and IDEs, and already own a license, it is recommended to download 
> and install [ReSharper](https://www.jetbrains.com/resharper/) Visual Studio Extension.

5. Clone your personal fork to the IDE. 
6. Launch the project by opening the .sln file in the IDE
7. Create a new branch with a title of what you are changing 
8. Download the the development version of the [B78XH](https://github.com/Heavy-Division/B78XH/archive/refs/heads/main.zip) mod file, name it `B78XH-developer` if you already have it downloaded, extract it somewhere outside of the community folder, and link it to the community folder using a [symbolic link](https://schinagl.priv.at/nt/hardlinkshellext/linkshellextension.html) program. 
10. Select the build path of the wasm repo by right clicking the `B78XH-wasm (MSFS)` at the top in the IDE file explorer, and selecting "properties". In the `Output Directory` field, open your `B78XH-developer` folder and set the path to `B78XH-developer/SimObjects/Airplanes/Asobo_B787/panel/`
12. Open the simulator and open the developer menu. If you don't have developer mode active, head to general settings -> developers, and enable developer mode.
13. Under `Options` menu on the top bar, select the `WASM debug` window. 
14. Make your changes in the IDE, save, and build the .wasm binary. 
15. Restart the flight to see your changes. 

**If creating or editing displays read below** 
To view or create a new display you'll need to create a callback function to that display, and edit the panel.cfg in SimObjects. 

Below is an example of a basic implementation of a new MFD Gauge using the Mouse Resolver:
New MFD Gauge Callback example: `MFDCommGaugeCallBack.cpp`
```cpp
 #pragma once 
 
 #include <MSFS\MSFS.h>
 #include "MSFS\MSFS_Render.h"
 #include <MSFS\Legacy\gauges.h>
 #include "MFDCommGauge.h"


 #ifdef _MSC_VER
 #define snprintf _snprintf_s
 #elif !defined(__MINGW32__)
 #include <iconv.h>
 #endif

 MFDCommGauge g_MFDCommGauge;

 // ------------------------
 // Callbacks
 extern "C" {
 	MSFS_CALLBACK bool mfd_comm_gauge_callback(FsContext ctx, int service_id, void* pData) {
 		switch (service_id) {
 		case PANEL_SERVICE_PRE_INSTALL: {
 			return g_MFDCommGauge.preInstall();
 		}
 									  break;
 		case PANEL_SERVICE_POST_INSTALL: {
 			return g_MFDCommGauge.postInstall(ctx);
 		}
 									   break;
 		case PANEL_SERVICE_PRE_DRAW: {
 			return g_MFDCommGauge.preDraw(static_cast<sGaugeDrawData*>(pData));
 		}
 								   break;
 		case PANEL_SERVICE_PRE_KILL: {
 			return g_MFDCommGauge.preKill();
 		}
 								   break;
 		}
 		return false;
 	}
  MSFS_CALLBACK void mfd_comm_mouse_callback(float fX, float fY, unsigned int iFlags) {
 		switch (iFlags) {
 		case MOUSE_MOVE: {
 			g_MFDCommGauge.getMouseMoveResolver().setPosition(fX, fY);
 		}
 					   break;
 		case MOUSE_LEFTDRAG: {
 		}
 						   break;
 		case MOUSE_RIGHTDRAG: {

 		}
 							break;
 		case MOUSE_MIDDLEDRAG: {

 		}
 							 break;
 		case MOUSE_LEFTRELEASE: {
 			g_MFDCommGauge.getMouseClickResolver().setPosition(fX, fY);
 		}
 							  break;
 		case MOUSE_RIGHTRELEASE: {

 		}
 							   break;
 		case MOUSE_MIDDLERELEASE: {

 		}
 								break;
 		case MOUSE_LEFTSINGLE: {

 		}
 							 break;
 		case MOUSE_RIGHTSINGLE: {

 		}
 							  break;
 		case MOUSE_MIDDLESINGLE: {

 		}
 							   break;
 		case MOUSE_LEFTDOUBLE: {

 		}
 							 break;
 		case MOUSE_RIGHTDOUBLE: {

 		}
 							  break;
 		case MOUSE_MIDDLEDOUBLE: {

 		}
 							   break;
 		case MOUSE_WHEEL_UP: {

 		}
 						   break;
 		case MOUSE_WHEEL_DOWN: {

 		}
 							 break;
 		default:
 			break;
 		}
 	}
 }

```



Header file where variable types and function return types are defined, as well as the Class
`MFCCommBaseGauge.h`:
```cpp
 #pragma once
 
 #include "CDUMouseClickResolver.h"
 #include "CDUMouseMoveResolver.h"
 #include "Drawable.h"
 #include "MSFS/Render/nanovg.h"
 #include "Tools.h"


 class MFDCommBasePage : public Drawable {
 public:
 	MFDCommBasePage(NVGcontext*& context,
 		CDUMouseMoveResolver& mouseMoveResolver,
 		CDUMouseClickResolver& mouseClickResolver,
 		const double x,
 		const double y,
 		const double width,
 		const double height,
 		char* const title = nullptr,
 		char* const title2 = nullptr) : context(context),
 		mouseMoveResolver(mouseMoveResolver),
 		mouseClickResolver(mouseClickResolver),
 		x(x),
 		y(y),
 		width(width),
 		height(height),
 		title(title),
 		title2(title2) {
 	}

 	std::function<void()> event;
 	void setBackgroundColor(NVGcolor color);
 	void draw() override;
 protected:
 	NVGcontext*& context;
 	NVGcolor backgroundColor = Tools::Colors::cduButtonGray;
 	CDUMouseMoveResolver& mouseMoveResolver;
 	CDUMouseClickResolver& mouseClickResolver;
 	double x;
 	double y;
 	double width;
 	double height;
 	double borderWidth = 5;
 	char* title;
 	char* title2;
 	float bounds[4] = { 0, 0, 0, 0 };
 	bool isSelected = false;

 	void drawTitle();
 	void drawButtonBorders();
 	void drawBackBorders(NVGcolor color = Tools::Colors::black);
 	void drawBackground() const;
 	bool isInFocus();
 	void shouldTriggerEvent();
 	virtual void calculateBounds();
 };
```

CPP file where the functions are defined: 
`MFDCommBaseGauge.cpp`:
```cpp
#pragma once 

#include "MFDCommBasePage.h"

 void MFDCommBasePage::draw() {
 	if (this->context != nullptr) {
 		drawBackground();
 		drawTitle();
 	}
 }

 void MFDCommBasePage::drawBackground() const {

 	nvgFillColor(this->context, this->backgroundColor);
 	nvgBeginPath(this->context);
 	{
 		nvgRect(this->context, this->x, this->y, this->width, this->height);
 	}
 	nvgClosePath(this->context);
 	nvgFill(this->context);
```

## Panel.cfg
Open the `PANEL.CFG` file located at `B78XH/SimObjects/Airplanes/Asobo_B787/panel/`

The aircraft panels are organized by [VCOCKPIT#] with 
 * size of the 3d element in mm (width, height)
 * pixel size of the renderable display (width, height)
 * texture (panel name) e.g. MFD, PFD, etc.
 * htmlgauge (path to gauge source code, X origin, Y origin, html size X, html size Y)

To set your new screen or gauge to display on the Captain's MFD for testing. Under [VCOCKPIT02] in the  `htmlgauge00` field replace the default with:
```cfg
htmlgauge00=WasmInstrument/WasmInstrument.html?wasm_module=B78XH-wasm.wasm&wasm_gauge=<callback_name>, 0,0, 1280, 950
```

replacing `<callback_name>` with the name of the callback you choose.

**Include a copy of the license a the top of every new file** 
```cpp
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
```
> Note: It is recommended to use Fast WASM compilation in the MSFS developer options menu. When returning to normal flying, it is recommended to turn this off. 



