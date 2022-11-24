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
8. Download the the development version of the [B78XH](https://github.com/Heavy-Division/B78XH/archive/refs/heads/main.zip) mod file, name it `B78XH-develeoper` if you already have it downloaded, extract it somewhere outside of the community folder, and link it to the community folder using a [symbolic link](https://schinagl.priv.at/nt/hardlinkshellext/linkshellextension.html) program. 
10. Select the build path of the wasm repo by right clicking the `B78XH-wasm (MSFS)` at the top in the IDE file explorer, and selecting "properties". In the `Output Directory` field, open your `B78XH-developer` folder and set the path to `B78XH-developer/SimObjects/Airplanes/Asobo_B787/panel/`
11. Load the simulator and open the developer menu. If you don't have developer mode active, head to general settings -> developers, and enable developer mode.
12. Under `Options` menu on the top bar, select the `WASM debug` window. 
13. Make your changes in the IDE, save, and build the .wasm binary. 
14. Restart the flight to see your changes. 

> Note: It is recommended to use Fast WASM compilation in the MSFS developer options menu. When returning to normal flying, it is recommended to turn this off. 



