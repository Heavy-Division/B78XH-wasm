#pragma once
#include "Control.h"
#include "Tools/Console.h"

class TCPScratchpadControl : public Control {
	public:
		enum class events {
			NUM1,
			NUM2,
			NUM3,
			NUM4,
			NUM5,
			NUM6,
			NUM7,
			NUM8,
			NUM9,
			NUM0,
			CLR,
			STAR,
			FORCE_CLR
		};

		explicit TCPScratchpadControl(const string& name);

		auto render() -> void override;

		[[nodiscard]] auto getBuffer() const -> const std::string&;
		auto clear() -> void;
		auto processEvent(events event) -> void;

	protected:
		auto prepareColor(int chunkNumber) -> void;
		auto prepareFontSize(int chunkNumber) -> void;
		auto prepareAlign(int chunkNumber) -> void;
		auto prepareDefaults() -> void;

	private:
		std::string buffer_ = "";
		bool eventsDisabled = false;

	public:
		[[nodiscard]] auto isEventsDisabled() const -> bool;

		auto setEventsDisabled(const bool eventsDisabled) -> void;
};
