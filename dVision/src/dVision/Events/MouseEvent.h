#pragma once

#include "Event.h"

namespace dVision {

	class DVISION_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: mouse_x(x), mouse_y(y) {}

		inline float GetX() const { return mouse_x; }
		inline float GetY() const { return mouse_y; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mouse_x << ", " << mouse_y;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mouse_x, mouse_y;
	};

	class DVISION_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset_, float yOffset_)
			: xOffset(xOffset_), yOffset(yOffset_) {}

		inline float GetXOffset() const { return xOffset; }
		inline float GetYOffset() const { return yOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MosueScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float xOffset, yOffset;
	};

	class DVISION_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button_)
			: button(button_) {
		}

		int button;
	};

	class DVISION_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button_)
			: MouseButtonEvent(button_) {
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class DVISION_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button_)
			: MouseButtonEvent(button_) {
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}

//Enable easy logging
template <> struct fmt::formatter<dVision::MouseMovedEvent> : ostream_formatter {};
template <> struct fmt::formatter<dVision::MouseScrolledEvent> : ostream_formatter {};
template <> struct fmt::formatter<dVision::MouseButtonPressedEvent> : ostream_formatter {};
template <> struct fmt::formatter<dVision::MouseButtonReleasedEvent> : ostream_formatter {};