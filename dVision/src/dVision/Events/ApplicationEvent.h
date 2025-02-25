#pragma once

#include "Event.h"

namespace dVision {

	class DVISION_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width_, unsigned int height_)
			: width(width_), height(height_) {}

		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int width, height;
	};

	class DVISION_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class DVISION_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class DVISION_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class DVISION_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}

//Enable easy logging
template <> struct fmt::formatter<dVision::WindowResizeEvent> : ostream_formatter {};
template <> struct fmt::formatter<dVision::WindowCloseEvent> : ostream_formatter {};
template <> struct fmt::formatter<dVision::AppTickEvent> : ostream_formatter {};
template <> struct fmt::formatter<dVision::AppUpdateEvent> : ostream_formatter {};
template <> struct fmt::formatter<dVision::AppRenderEvent> : ostream_formatter {};