#include "ExampleMasterControl.h"

#include "HelloWorldControl.h"
#include "ExampleLineControl.h"
#include "MasterControl.h"


void ExampleControl::prepareControls() {
	MasterControl::prepareControls();
	add(std::make_unique<HelloWorldControl>("HelloWorld"));
	add(std::make_unique<ExampleLineControl>("LineControl"));
}

void ExampleControl::setupControls() {
	MasterControl::setupControls();
	addOnValidate([](BaseControl& control) -> bool {
	return false;
		});
}
