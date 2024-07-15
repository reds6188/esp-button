#include "button.h"

void fNULL(void) {};

Button::Button(uint8_t pin, unsigned long debounce_time) {
	_pin = pin;
	_debounce_time = debounce_time;
	pinMode(_pin, INPUT_PULLUP);
	_on_press_func = fNULL;
	_on_release_func = fNULL;
}

Button::~Button(void) {
	_on_press_func = fNULL;
	_on_release_func = fNULL;
}

void Button::onPress(void (*func)(void)) {
	_on_press_func = func;
}

void Button::onRelease(void (*func)(void)) {
	_on_release_func = func;
}

void Button::loop(void) {
	_curr_state = digitalRead(_pin);

	if(_curr_state != _last_state) {
		_debounce_timer = millis();
		_last_state = _curr_state;
		_has_changed = true;
	}
	else if(_has_changed && ((millis() - _debounce_timer) > _debounce_time)) {
		if(_curr_state == LOW)
			(*_on_press_func)();
		else
			(*_on_release_func)();
		_has_changed = false;
	}
    /*
    uint8_t reading = digitalRead(_pin);

    if(reading != lastState) {
        _debounce_timer = millis();
    }

    if((millis() - _debounce_timer) > _debounce_time) {
        // if the button state has changed:
        if(reading != _curr_state) {
            _curr_state = reading;

            if(_curr_state == LOW)
                (*onPressFunc)();
            else
                (*onReleaseFunc)();
        }
    }

    lastState = reading;
    */
}