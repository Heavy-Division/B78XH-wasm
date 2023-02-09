#include "CDUIdentPageControl.h"

#include "CDULeftLineControl.h"
#include "CDULineControl.h"

auto CDUIdentPageControl::prepareControls() -> void {
	CDUPageControl::prepareControls();
}

auto CDUIdentPageControl::setupControls() -> void {
	CDUPageControl::setupControls();

	pageTitle->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"AIRLINE POLICY", ""}});
		return true;
	});

	leftLineOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"", ""}});
		return true;
	});

	leftLineTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"-10/-20", "settable"}});
		return true;
	});

	leftLineThree->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"1.30",}});
		return true;
	});

	leftLineFour->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"1",}});
		return true;
	});

	leftLineFive->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"-37°",}});
		return true;
	});

	leftLineSix->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"<INDEX"}});
		return true;
	});


	rightLineOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{""}});
		return true;
	});

	rightLineTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"300"}});
		return true;
	});

	rightLineThree->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"CLB/300",}});
		return true;
	});

	rightLineFour->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"800",}});
		return true;
	});

	rightLineFive->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"800/ 800",}});
		return true;
	});

	rightLineSix->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{""}});
		return true;
	});


	centerLineOne->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{""}});
		return true;
	});

	centerLineTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{""}});
		return true;
	});

	leftLineTitleTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"TO 1/TO 2"}});

		return true;
	});

	rightLineTitleTwo->addOnBeforeRender([](BaseControl& control) -> bool {
		control.getContentHolder().setContent({{"R/C CLB"}});

		return true;
	});
}
