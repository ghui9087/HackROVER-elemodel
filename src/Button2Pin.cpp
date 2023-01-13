#include "Button.h"

/**
 * Button constructor for 2 Pin
 * @param buttonPin the button power input in GPIO
 * @param isLock checking wich the button need to be troggle or not
*/
Button2Pin::Button2Pin(int buttonPin, bool isLock)
{
    pinMode(buttonPin, INPUT);
    this->buttonPin = buttonPin;
    this->isLock = isLock;
}

/**
 * switchButtonStatus
 * @paragraph a way to turn on/off button without hit the button
 * @warning if this button is not in Lock mode would not work 
*/
bool Button2Pin::switchButtonStatus()
{
    if (!isLock)
        return false;
    if (buttonState == 1)
    {
        buttonState = 0;
    }
    else
    {
        buttonState = 1;
    }
    return true;
}

/**
 * isButtonOn
 * @paragraph return the status of button retime
*/
bool Button2Pin::isButtonOn()
{
    if (!isLock)
        buttonState = digitalRead(buttonPin);
    else
    {
        if (buttonState == 1)
        {
            if (digitalRead(buttonPin) == 1)
                buttonState = 0;
        }
        else
        {
            if (digitalRead(buttonPin) == 1)
                buttonState = 1;
        }
    }

    if (buttonState == 1)
        return true;
    return false;
}

/**
 * @paragraph return button status retime 
 * @paragraph 1 is buttom on. 0 is button off
*/
int Button2Pin::isButtonOnInt()
{
    if (isButtonOn())
        return 1;
    return 0;
}