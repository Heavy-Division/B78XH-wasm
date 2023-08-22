#include "MasterControl.h"
#include <memory>

#include "FirstGenerationControl.h"
#include "SecondGenerationControl.h"

void MasterControl::prepareControls() {
	BaseControl::prepareControls();
	this->addControl(std::make_unique<FirstGenerationControl>());
	//this->addControl(std::make_unique<FirstControl>());
	//this->addControl(std::make_unique<SecondGenerationControl>());
	//this->addControl(std::make_unique<SecondControl>());
	this->setAutoClearing(false);
}

void MasterControl::render(sGaugeDrawData* data) {
	BaseControl::render(data);
	this->executeRendering();
}
