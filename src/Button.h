#ifndef Button_h
#define Button_h
#include <Arduino.h>

/**
 * All Type of Button will be list in here
 * If you need it just call the fuction you need
 * @example I want to using 3 Pin Button
 * @example Button3Pin name(buttonPin, ledPin, isToggle);
 */

/**
 *  Different state that button can have
 * @param PRESS press down turn on unpress not turn on
 * @param TOGGLE press and let go and it’ll stay that state
 */
enum buttonState
{
    PRESS = 0,
    TOGGLE = 1
};

class Button
{
protected:
    // Constueder
    /**
     * Base constudent 
     * 
     */
    Button(int pin = 0);
    Button(int pin = 0, buttonState type = PRESS);

    bool switchButtonState();

    bool getButtonState();
    bool getButtonStateRaw();
    void loopState();

private:
    bool isButtonKEEP = false;
    bool currentState = false;
    int buttonPin;
    buttonState buttonType;
};

#endif