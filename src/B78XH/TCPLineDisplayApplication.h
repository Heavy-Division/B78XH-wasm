#pragma once
#include "Application.h"
#include "TCPLineDisplay.h"

class TCPLineDisplayApplication : public Application {
	public:
		auto render(sGaugeDrawData* data) -> void override;
		auto postInstall() -> void override;

	private:
		TCPLineDisplay tcpLineDisplay;
};
