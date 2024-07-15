#ifndef BUTTON_H_
#define BUTTON_H_

#include <Arduino.h>

#define DEBOUNCE_80MS     80

class Button {
	private:
		uint8_t _pin;
		bool _curr_state, _last_state, _has_changed;
		unsigned long _debounce_timer;
		unsigned long _debounce_time;
		void (*_on_press_func)(void);
		void (*_on_release_func)(void);
	public:
		Button(uint8_t pin, unsigned long debounce_time = 100);
		~Button(void);
		void onPress(void (*func)(void));
		void onRelease(void (*func)(void));
		void loop(void);
};

#endif  /* BUTTON_H_ */