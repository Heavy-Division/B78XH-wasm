#include <MSFS/MSFS.h>
#include "fmt/core.h"
#include "SimConnectConnector.h"

extern "C" MSFS_CALLBACK void module_init(void) {
	connector.connect("Global SimConnect connection");
	fmt::print("B78XH WASM: Module init");
	fflush(stdout);
}

extern "C" MSFS_CALLBACK void module_deinit(void) {
	connector.disconnect();
	fmt::print("B78XH WASM: Module deinit");
	fflush(stdout);
}