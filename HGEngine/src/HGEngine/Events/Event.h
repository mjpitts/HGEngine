#pragma once

#include "../Core.h"

#include <string>
#include <functional>

namespace HGEngine 
{
	/* 
		Currently the events in this engine are blocking, this means that
		the engine handles them as the arrive. 

		TODO: Swtich event system to a buffered system, this may allow scheduling.
	*/

	enum class EventType
	{
		None = 0,
		WindowClose, Windowresize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, 
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// May be used for event filtering. 
	// Bit def in core.h
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)

	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() { return GetStaticType(); }\
								virtual cost char* GetName() const override {return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HGE_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }


		inline bool IsInCateGory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		// See if event has been handled
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	private:
		Event& m_Event;
	public:
		EventDispatcher(Event& event)
			:m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func) 
		{
			if (m_Event.EventType() == t::GetStaticType())
			{
				m_Event.m_Handled == func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}
