# esp-button
Button library for ESP32

## API Documentation

### `Button(uint8_t pin, unsigned long debounce_time)`
Create a button instance assigned to `pin` input with `debounce_time` in milliseconds.

### `onPress(void (*func)(void))`
Assing `func` function to button press event.

### `onRelease(void (*func)(void))`
Assing `func` function to button release event.

### `loop(void)`
Handle debouncing and press/release events.

Place this function in the main loop program.
