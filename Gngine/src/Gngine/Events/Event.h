#pragma once
#include "Gngine/Core.h"
#include <string>
#include <functional>

namespace Gngine {
	//The events we are writing here are blocking events
	//meaning, they stop the exexution until they are dealt with
	//in popular systems, such events are made assync for better work flow

	enum class EventType
	{
		None = 0,
	    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton    = BIT(4),
	    
	};
#define EVENT_CLASS_TYPE(type)  static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlag() const override { return category; }

	class GE_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlag() const = 0;
		virtual std::string ToString() const {
			return GetName();
		}

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlag() & category;
		}
	protected:
		bool m_handled = false;
	};

	class EventDispatcher {

		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event):m_event(event){}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_event.GetEventType() == T::GetStaticType()) {

				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}

			return false;
		}
	private:
		Event& m_event;
	};

	/*inline std::ostream& operator<<(std::ostream& os, const Event& e) {

		return os << e.ToString();
	}*/
	inline std::string format_as(const Event& e) {
		return e.ToString();
	}

}
