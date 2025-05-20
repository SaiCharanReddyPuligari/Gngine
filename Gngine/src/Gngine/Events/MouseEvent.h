#pragma once

#include "Event.h"
#include <string>
#include <sstream>

namespace Gngine {

	class GE_API MouseMovedEvent : public Event {
	private:
		float m_mouseX, m_mouseY;
	public:
		MouseMovedEvent(float x, float y) : m_mouseX(x), m_mouseY(y){}

		inline float GetX() const {
			return m_mouseX;
		}

		inline float GetY() const {
			return m_mouseY;
		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class GE_API MouseScrolledEvent : public Event {
	private:
		float m_XOffSet, m_YOffSet;
	public:
		MouseScrolledEvent(float xOffSet, float yOffSet) : m_XOffSet(xOffSet), m_YOffSet(yOffSet) {}

		inline float GetYOffSet() const {
			return m_XOffSet;
		}

		inline float GetXOffSet() const {
			return m_YOffSet;
		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffSet() << ", " << GetYOffSet();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolledEvent)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class GE_API MouseButtonEvent : public Event {
	protected:
		MouseButtonEvent(int button) : m_button(button){}
		int m_button;
	public:
		inline int GetMouseButton() const {
			return m_button;
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class GE_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button){}

		std::string ToString() const override {
			
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class GE_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {

			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}