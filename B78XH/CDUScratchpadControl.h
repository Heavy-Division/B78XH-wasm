#pragma once
#include "Control.h"

class CDUScratchpadControl : public Control {
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
			DOT,
			MINUS,
			A,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			SPACE,
			DELETE,
			SLASH,
			CLR,
			PREV,
			NEXT,
			EXEC,
			ENTER
		};

		explicit CDUScratchpadControl(const string& name);

		auto render() -> void override;

		[[nodiscard]] auto getBuffer() const -> const std::string&;
		auto clear() -> void;
		auto processEvent(events event) -> void;
		auto setupControl() -> void override;
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
