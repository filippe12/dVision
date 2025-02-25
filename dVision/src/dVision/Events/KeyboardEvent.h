#pragma once

#include "Event.h"

namespace dVision {

	class DVISION_API KeyboardEvent : public Event
	{
	public:
		inline int GetKeyboardCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyboardEvent(int keyCode_) : keyCode(keyCode_) {}
		int keyCode;
	};

	class DVISION_API KeyPressedEvent : public KeyboardEvent
	{
	public:
		KeyPressedEvent(int keycode_, int repeatCount_)
			: KeyboardEvent(keycode_), repeatCount(repeatCount_) {}

		inline int GetREpeatCount() const { return repeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " {" << repeatCount << " repeats}";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int repeatCount;
	};

	class DVISION_API KeyReleasedEvent : public KeyboardEvent
	{
	public:
		KeyReleasedEvent(int keycode_)
			: KeyboardEvent(keycode_) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}

//Enable easy logging
template <> struct fmt::formatter<dVision::KeyPressedEvent> : ostream_formatter {};
template <> struct fmt::formatter<dVision::KeyReleasedEvent> : ostream_formatter {};