#ifndef Button_h
#define Button_h
#include <Arduino.h>

/**
 * All Type of Button will be list in here
 * If you need it just call the fuction you need
 * @example I want to using 3 Pin Button
 * @example Button3Pin name(buttonPin, ledPin, isToggle);
 */

enum buttonState
{
    PRESS = 0,
    TOGGLE = 1
};

class Button
{
protected:
    Button(int pin = 0) : buttonPin(pin), buttonType(PRESS){};
    Button(int pin = 0, buttonState type = PRESS) : buttonPin(pin), buttonType(type){};

    bool getButtonState();
    bool getButtonStateRaw();
    void loopState();

private:
    bool isButtonKEEP = false;
    int currentState = 0;
    int buttonPin;
    buttonState buttonType;
};

#endif