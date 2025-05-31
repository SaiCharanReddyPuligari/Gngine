#pragma once

#include "Event.h"
#include <sstream>

namespace Gngine {
class GE_API KeyEvent : public Event {
public:
	inline int GetKeyCode() const {
		return m_keycode;
	}

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
protected:
	KeyEvent(int keycode) :m_keycode(keycode){}

	int m_keycode;
};

class GE_API KeyPressedEvent : public KeyEvent {
private:
	int m_repeatcount;
public:
	KeyPressedEvent(int keycode, int repeatCount = 0)
		: KeyEvent(keycode), m_repeatcount(repeatCount) {
	}

	inline int GetRepeatCount() const {
		return m_repeatcount;
	}

	std::string ToString() const override {
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_keycode << " (" << m_repeatcount << " repeats)";
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyPressed)

};

class GE_API KeyReleasedEvent : public KeyEvent {
public:
	KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

	std::string ToString() const override {
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_keycode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyReleased)
};
}
