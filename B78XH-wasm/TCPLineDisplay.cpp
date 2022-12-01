#include "TCPLineDisplay.h"

#include "TCPLeftLine.h"

#include <string>

void TCPLineDisplay::prepareLines() {
	this->addLine(this->leftLineOne);
}

void TCPLineDisplay::setupLines() {
}

void TCPLineDisplay::init() {
	this->prepareLines();
	this->setupLines();
}
