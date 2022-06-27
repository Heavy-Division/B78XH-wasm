#include "TuningControlPanelScratpad.h"

void TuningControlPanelScratchpad::render() {
}

void TuningControlPanelScratchpad::handleEvent(TuningControlPanelControlScratchpadEventsID event) {
	BaseScratchpad::handleEvent(event);

	switch(event) {
		case tcp_scratchpad_event_num1:
			(*this).buffer.push_back(49);
			break;
		case tcp_scratchpad_event_num2:
			(*this).buffer.push_back(50);
			break;
		case tcp_scratchpad_event_num3:
			(*this).buffer.push_back(51);
			break;
		case tcp_scratchpad_event_num4:
			(*this).buffer.push_back(52);
			break;
		case tcp_scratchpad_event_num5:
			(*this).buffer.push_back(53);
			break;
		case tcp_scratchpad_event_num6:
			(*this).buffer.push_back(54);
			break;
		case tcp_scratchpad_event_num7:
			(*this).buffer.push_back(55);
			break;
		case tcp_scratchpad_event_num8:
			(*this).buffer.push_back(56);
			break;
		case tcp_scratchpad_event_num9:
			(*this).buffer.push_back(57);
			break;
		case tcp_scratchpad_event_num0:
			(*this).buffer.push_back(48);
			break;
		case tcp_scratchpad_event_clr:
			if((*this).buffer.length() > 0) {
				if((*this).buffer == "CLEAR") {
					(*this).buffer.clear();
				} else {
					(*this).buffer.pop_back();
				}
			} else {
				(*this).buffer.append("CLEAR");
			}
			break;
		case tcp_scratchpad_event_star:
			(*this).buffer.push_back(46);
			break;
		default: 
			break;
	}
}
