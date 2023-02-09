#include "Control.h"

auto Control::render() -> void {
	BaseControl::render();
	/*
	 * We re-rendering the control so the content is no longer invalid
	 * TODO: Move to onAfterRender events??
	 */
	getContentHolder().setContentInvalid(false);
}