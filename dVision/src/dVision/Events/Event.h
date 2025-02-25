#pragma once

#include "dVision/Core.h"
#include "dVision/Logger.h"

namespace dVision {

	//Current event system is blocking
	//meaning that when an event occurs
	//it deals with it automaticaly better
	//future approcah would be to add it
	//to an event buffer and process it later

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MosueScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication		= BIT(0),
		EventCategoryInput				= BIT(1),
		EventCategoryKeyboard			= BIT(2),
		EventCategoryMouse				= BIT(3),
		EventCategoryMouseButton		= BIT(4)
	};

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	class DVISION_API Event {
		friend class EventDispacher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline friend std::ostream& operator<<(std::ostream& os, const Event& e)
		{
			return os << e.ToString();
		}

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool handled = false;
	};

	class EventDispacher {
		template <typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispacher(Event& event_)
			: event(event_) {}

		template <typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (event.GetEventType() == T::GetStaticType())
			{
				event.handled = func(*(T*)&event);
				return true;
			}
			return false;
		}

	private:
		Event& event;
	};
}

template <> struct fmt::formatter<dVision::Event> : ostream_formatter {};