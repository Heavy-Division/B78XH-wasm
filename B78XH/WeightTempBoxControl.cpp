#include "WeightTempBoxControl.h"
#include "LineControl.h"
#include "Simplane.h"
#include "Tools/Tools.h"
#include <cstdio>
#include <string>
#include "fmt/core.h"

#include "bitset"
#include "Tools/Console.h"

const auto* line_separator = "--------------";

void WeightTempBoxControl::prepareControls() {
	Control::prepareControls();
	add(std::make_unique<LineControl>("WeightTempBoxControl"));
}

void WeightTempBoxControl::setupControl() {
	Control::setupControl();
	auto& line = getControl("WeightTempBoxControl");
	line->getContentHolder().setAlign(ContentHolder::ALIGN::CENTER);
	line->getContentHolder().setDefaultFontSize(30);
	line->getContentHolder().setDefaultFontColor(Tools::Colors::white);
	line->getContentHolder().addColor("cyan", Tools::Colors::cyan);
	line->position.setPosition(400, 920, 0, 0);
	line->getContentHolder().setContent({{"TEST"}});

	auto engineDataHandler = [](double data) -> std::string {
		return fmt::format("{:.1f}", data);
	};

	line->addOnBeforeRender([engineDataHandler](BaseControl& control) -> bool {
		control.getContentHolder().setContent({ {"N1:", "cyan"},
		{ engineDataHandler(Simplane::aircraft::systems::powerplant::engine_1::n1_rpm()), "cyan"},
		{line_separator},
        {"N2:", "cyan"},
		{engineDataHandler(SimConnectData::systems::powerplant::engine.engine1_n2), "cyan"}});
		return true;
		});

}


void WeightTempBoxControl::setupControls() {
	Control::setupControls();
}
