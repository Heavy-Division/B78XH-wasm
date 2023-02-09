#pragma once

#include <functional>
#include <memory>
#include <list>
#include <string>
#include <vector>
#include <array>
#include <queue>

#include "ControlCrop.h"
#include "ControlPosition.h"

/*
 * TODO: TEMPORARY HACK -> SHOULD BE REMOVED WHEN THE CLASSES WILL BE MOVED TO B78XH SOLUTION
 */
#include <map>
#include <MSFS/Render/nanovg.h>

#include "DefaultLogger.h"
#include "NullLogger.h"

using std::string;
using std::list;
using std::vector;
using std::map;
using std::array;

class BaseControl {

	using RenderingContext = NVGcontext*;
	using Content = vector<array<string,2>>;

	protected:
		using ControlSharedPointer = std::shared_ptr<BaseControl>;
		enum class FONT_TYPE {
			DEFAULT,
			ADDITIONAL
		};

		class ContentHolder {
			public:
				enum class ALIGN {
					LEFT,
					CENTER,
					RIGHT
				};

				[[nodiscard]] auto getContent() const -> const Content&;
				auto setContent(const Content& content) -> void;
				__declspec(property(get = getContent, put = setContent)) Content content;
				[[nodiscard]] auto isContentInvalid() const -> bool;
				auto setContentInvalid(const bool contentInvalid) -> void;
				__declspec(property(get = isContentInvalid, put = setContentInvalid)) bool contentInvalid;

				[[nodiscard]] auto getAlign() const -> ALIGN;
				auto setAlign(ALIGN align) -> void;
				[[nodiscard]] auto getDefaultFontSize() const -> float;
				auto setDefaultFontSize(float fontSize) -> void;

				[[nodiscard]] auto getDefaultFontColor() -> NVGcolor&;
				auto setDefaultFontColor(const NVGcolor& fontColor) -> void;

				[[nodiscard]] auto getFontFace() const -> const string&;
				auto setFontFace(const string& fontFace) -> void;
				[[nodiscard]] auto getContentHorizontalAlign() const -> int;
				auto setContentHorizontalAlign(int contentHorizontalAlign) -> void;
				[[nodiscard]] auto getContentVerticalAlign() const -> int;
				auto setContentVerticalAlign(int contentVerticalAlign) -> void;

				auto addSize(string name, float size) -> void;
				auto addColor(string name, NVGcolor color) -> void;
				auto addContentVerticalOffset(string name, float offset) -> void;
				[[nodiscard]] auto getFontSizes() const -> const std::map<string, float>&;
				__declspec(property(get = getFontSizes)) std::map<string, float> fontSizes;
				[[nodiscard]] auto getFontColors() const -> const std::map<string, NVGcolor>&;
				__declspec(property(get = getFontColors)) std::map<string, NVGcolor> fontColors;
				[[nodiscard]] auto getContentVerticalOffset() const -> const std::map<string, float>&;
				__declspec(property(get = getContentVerticalOffset)) std::map<string, float> contentVerticalOffset;
				auto getChunkFontSize(int chunkNumber) -> float;
				auto getChunkFontColor(int chunkNumber) -> NVGcolor&;
				auto getChunkContentVerticalOffset(int chunkNumber) -> float;

			private:
				Content content_{};
				bool contentInvalid_ = false;
				float defaultFontSize_ = 23;
				NVGcolor defaultFontColor_ = nvgRGB(255, 255, 255);
				ALIGN align_ = ALIGN::LEFT;
				string fontFace_ = "heavy-fmc";
				int contentHorizontalAlign_ = NVG_ALIGN_LEFT;
				int contentVerticalAlign_ = NVG_ALIGN_MIDDLE;
				std::map<string, float> fontSizes_;
				std::map<string, NVGcolor> fontColors_;
				std::map<string, float> contentVerticalOffset_;

				auto checkContent(const Content& content) -> void;
		};

	public:
		using GaugeInstallData = struct {
			int iSizeX;
			int iSizeY;
			char* strParameters;
		};

		using GaugeDrawData = struct {
			double mx;
			double my;
			double t;
			double dt;
			int winWidth;
			int winHeight;
			int fbWidth;
			int fbHeight;
		};
		using EventInterface = std::function<bool(BaseControl& control)>;

		inline static auto SKIP_VALIDATION_EVENT = []([[maybe_unused]] BaseControl& control) -> bool {
			return true;
		};

		inline static auto EMPTY_EVENT = []([[maybe_unused]] BaseControl& control) -> bool {
			return true;
		};

		virtual ~BaseControl();
		BaseControl() = delete;
		
		[[nodiscard]] auto getName() const -> const string&;
		auto setName(const string& name) -> void;
		__declspec(property(get = getName, put = setName)) string& name;

		[[nodiscard]] auto getContext() const -> RenderingContext;
		auto setContext(RenderingContext const context) -> void;
		__declspec(property(get = getContext, put = setContext)) const RenderingContext context;

		[[nodiscard]] auto hasContext() const -> bool;

		auto propagateContext(RenderingContext const context) -> void;

		auto add(ControlSharedPointer control) -> void;
		[[nodiscard]] auto getControls() -> list<ControlSharedPointer>&;
		__declspec(property(get = getControls)) list<ControlSharedPointer>& controls;

		[[nodiscard]] auto getControl(string name) -> ControlSharedPointer&;

		[[nodiscard]] auto getSystemControls() -> list<ControlSharedPointer>&;
		__declspec(property(get = getSystemControls)) const list<ControlSharedPointer>& systemControls;

		[[nodiscard]] auto getRelativePosition() -> ControlPosition&;
		auto setRelativePosition(const ControlPosition& position) -> void;
		__declspec(property(get = getRelativePosition, put = setRelativePosition)) ControlPosition position;

		[[nodiscard]] auto getAbsolutePosition() -> ControlPosition&;
		auto setAbsolutePosition(const ControlPosition& position) -> void;
		__declspec(property(get = getAbsolutePosition, put = setAbsolutePosition)) ControlPosition absolutePosition;

		[[nodiscard]] auto getCrop() -> ControlCrop&;
		auto setCrop(const ControlCrop& crop) -> void;
		__declspec(property(get = getCrop, put = setCrop)) ControlCrop crop;

		/* Lifecycle */
		auto preInstall(GaugeInstallData* data) -> void;
		auto postInstall(RenderingContext context) -> void;
		auto preUpdate() -> void;
		auto postUpdate() -> void;
		auto preDraw(GaugeDrawData* data) -> void;
		virtual auto render() -> void;
		auto postDraw() -> void;
		auto preKill() const -> void;
		auto postKill() -> void;
		auto restart() -> void;

		auto addOnValidate(EventInterface event) -> void;
		auto addOnBeforeRender(EventInterface event) -> void;

		[[nodiscard]] auto getContentHolder() -> ContentHolder&;
		__declspec(property(get = getContentHolder)) ContentHolder contentHolder;

		auto setLogger(std::unique_ptr<BaseLogger> logger) -> void;
		[[nodiscard]] auto getLogger() const -> const std::unique_ptr<BaseLogger>&;

		auto propagateMouseMove(float x, float y) -> void;
		auto propagateMouseClick(float x, float y) -> void;
		auto queueMouseClick(float x, float y) -> void;
		auto queueMouseMove(float x, float y) -> void;
	protected:
		enum class ControlType {
			MASTER,
			NORMAL
		};

		using MouseEvent = struct {
			float x = -10000;
			float y = -10000;
		};

		MouseEvent mouseMove_;
		MouseEvent mouseClick_{};

		std::queue<MouseEvent> mouseClickQueue_{};

		explicit BaseControl(string name) : name_(std::move(name)), controlType_(ControlType::NORMAL) {
		}


		[[nodiscard]] auto getGaugeInstallData() const -> GaugeInstallData*;
		auto setGaugeInstallData(GaugeInstallData* const gaugeInstallData) -> void;
		__declspec(property(get = getGaugeInstallData, put = setGaugeInstallData)) const GaugeInstallData* gaugeInstallData;
		[[nodiscard]] auto getGaugeDrawData() const -> GaugeDrawData*;
		auto setGaugeDrawData(GaugeDrawData* gaugeDrawData) -> void;
		__declspec(property(get = getGaugeDrawData, put = setGaugeDrawData)) const GaugeDrawData* gaugeDrawData;

		[[nodiscard]] auto getControlType() const -> ControlType;
		auto setControlType(const ControlType controlType) -> void;
		__declspec(property(get = getControlType, put = setControlType)) const ControlType controlType;

		auto isControlInvalid() -> bool;

		virtual auto prepareControls() -> void;
		virtual auto setupControls() -> void;
		virtual auto setupControl() -> void;

		auto executeControlsPreInstall() -> void;
		auto executeControlsPostInstall() -> void;

	private:
		class ControlsHolder {
			public:
				auto add(ControlSharedPointer& control) -> void;
				[[nodiscard]] auto getControls() -> list<ControlSharedPointer>&;
				__declspec(property(get = getControls)) const list<ControlSharedPointer>& controls;
				[[nodiscard]] auto getControl(string name) -> ControlSharedPointer&;

			private:
				/* Forward declaration of NullControl. See declaration below. */
				class NullControl;
				list<ControlSharedPointer> controls_{};
				ControlSharedPointer nullControl_ = nullptr;
		};

		class ControlEvents {
			public:
				auto add(const EventInterface& event) -> void;
				auto clear() -> void;
				[[nodiscard]] auto size() const -> size_t;
				[[nodiscard]] auto getEvents() const -> const std::vector<EventInterface>&;
				__declspec(property(get = getEvents)) const std::vector<EventInterface>& events;

			private:
				std::vector<EventInterface> events_;
		};

		[[nodiscard]] auto isFirstRun() const -> bool;
		auto setFirstRun(const bool firstRun) -> void;
		__declspec(property(get = isFirstRun, put = setFirstRun)) bool firstRun;

		string name_;
		bool firstRun_ = true;
		ControlType controlType_;
		ControlsHolder controls_;
		ControlsHolder systemControls_;
		ContentHolder contentHolder_;


		ControlPosition relativePosition_;
		ControlPosition absolutePosition_;
		ControlCrop crop_;

		ControlEvents onBeforeRender_;
		ControlEvents onValidate_;

		GaugeInstallData* gaugeInstallData_ = nullptr;
		GaugeDrawData* gaugeDrawData_ = nullptr;

		RenderingContext context_ = nullptr;
		#ifdef NDEBUG
		std::unique_ptr<BaseLogger> logger_ = std::make_unique<NullLogger>();
		#else
		std::unique_ptr<BaseLogger> logger_ = std::make_unique<DefaultLogger>();
		// std::unique_ptr<BaseLogger> logger_ = std::make_unique<NullLogger>();
		#endif

		auto addSystemControl(ControlSharedPointer control) -> void;

		auto renderScreen() -> void;
		auto renderControls(float parentLeft, float parentTop) -> void;

		auto needRedraw(bool force = false) -> bool;
		auto isControlInvalid(BaseControl& control) -> bool;

		auto executeOnBeforeRenderEvents(BaseControl& control) -> void;

		auto prepareRenderingContextDefaults() -> void;
		auto prepareRenderingContextDefaultsFonts() -> void;
		auto addFont(string alias, string filename, FONT_TYPE type = FONT_TYPE::ADDITIONAL, string path = "./data/fonts/") -> void;

	public:
		[[nodiscard]] auto getOnBeforeRender() -> ::BaseControl::ControlEvents&;
		[[nodiscard]] auto getOnValidate() -> ::BaseControl::ControlEvents&;
};


/*
 * Delayed declaration of NullControl
 *
 * NOTE: The class can not be declared in inner ControlHolder class because
 *		the class inherits from BaseControl -> BaseControl is incomplete type
 *		in ControlsHolder
 */
class BaseControl::ControlsHolder::NullControl : public BaseControl {
	public:
		explicit NullControl(const string& name)
			: BaseControl(name) {
		}
};
