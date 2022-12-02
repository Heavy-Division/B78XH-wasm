#pragma once

#define PANEL_SERVICE_STARTUP                            2       // extra_data = resource_handle
#define PANEL_SERVICE_AFTER_STARTUP                      3       // extra_data = resource_handle
#define PANEL_SERVICE_BEFORE_UPDATE                      6
#define PANEL_SERVICE_BEFORE_RENDER                      7
#define PANEL_SERVICE_RENDER                            10
#define PANEL_SERVICE_AFTER_RENDER                      11
#define PANEL_SERVICE_SHUTDOWN                          12
#define PANEL_SERVICE_POST_KILL                         13