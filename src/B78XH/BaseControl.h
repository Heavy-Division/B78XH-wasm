#pragma once
#include <MSFS/Legacy/gauges.h>
#include "MSFS/Render/nanovg.h"

#include <vector>
#include <string>

class BaseControl {
	public:
		BaseControl() = default;
		virtual ~BaseControl() = default;
		BaseControl(const BaseControl& other) = delete;

		BaseControl(BaseControl&& other) noexcept
			: fsContext(other.fsContext),
			  nvgContext(other.nvgContext),
			  storedGaugeDrawData(other.storedGaugeDrawData),
			  storedGaugeInstallData(other.storedGaugeInstallData),
			  controls(std::move(other.controls)) {
		}

		auto operator=(const BaseControl& other) -> BaseControl& = delete;

		auto operator=(BaseControl&& other) noexcept -> BaseControl& {
			if (this == &other)
				return *this;
			fsContext = other.fsContext;
			nvgContext = other.nvgContext;
			storedGaugeDrawData = other.storedGaugeDrawData;
			storedGaugeInstallData = other.storedGaugeInstallData;
			controls = std::move(other.controls);
			return *this;
		}

		/* Life cycle */
		virtual auto startup(sGaugeInstallData* data) -> void;
		virtual auto afterStartup(FsContext fsContext) -> void;
		virtual auto beforeUpdate() -> void;
		virtual auto afterUpdate() -> void;
		virtual auto beforeRender() -> void;
		virtual auto render(sGaugeDrawData* data) -> void;
		virtual auto shutdown() -> void;

		auto executeRendering() -> void;

		auto setAutoCrop(bool autoCrop) -> void;
		auto getAutoCrop() const -> bool;
		void setMargin(double left, double top);
		void setCropMargin(double left, double top);
		void setSize(double width, double height);
		void setWidth(double width);
		void setHeight(double height);
		auto getWidth() const -> double;
		auto getHeight() const -> double;
		auto getMarginLeft() const -> double;
		auto getMarginTop() const -> double;
		auto getCropMarginLeft() const -> double;
		auto getCropMarginTop() const -> double;
		auto isControlInvalid()-> bool;

		std::vector<std::function<bool()>> onValidate;

	protected:
		auto clearDisplay(double width, double height) const -> void;
		auto setAutoClearing(bool autoClearing) -> void;
		/* Controls handling */
		virtual auto prepareControls() -> void;
		virtual auto setupControls() -> void;
		auto addControl(std::unique_ptr<BaseControl> pointer) -> void;
		auto executeControlsStartup() const -> void;
		auto executeControlsAfterStartup() const -> void;

		auto prepareRenderingContext() -> void;
		auto prepareRenderingContextDefaults() -> void;
		auto prepareRenderingContextDefaultsFonts() -> void;
		auto addFont(std::string alias, std::string filename, PSTRINGZ path = "./data/fonts/") -> void;
		auto getContext() const -> NVGcontext*;

		auto safeShutdown() const -> void;

		auto getLevel() const -> int;
		auto setLevel(int level) -> void;

	private:
		FsContext fsContext = 0;
		NVGcontext* nvgContext = nullptr;
		sGaugeDrawData* storedGaugeDrawData = nullptr;
		sGaugeInstallData* storedGaugeInstallData = nullptr;
		std::vector<int> defaultFonts{};
		std::vector<int> fonts{};
		std::vector<std::unique_ptr<BaseControl>> controls{};

		bool autoClearing = true;
		bool autoCrop = false;
		double marginLeft = 0;
		double marginTop = 0;
		double width = 0;
		double height = 0;
		double cropMarginLeft = 0;
		double cropMarginTop = 0;
		int level = 0;

		auto processRender(std::unique_ptr<BaseControl>& control) const -> void;

		enum class FONT_TYPE {
			DEFAULT_FONT,
			FONT
		};

		auto addFont(std::string alias, std::string filename, FONT_TYPE type, PSTRINGZ path = "./data/fonts/") -> void;
		auto addDefaultFont(std::string alias, std::string filename, PSTRINGZ path = "./data/fonts/") -> void;
};
