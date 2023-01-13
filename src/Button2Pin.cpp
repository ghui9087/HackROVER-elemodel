#include "Button.h"

Button2Pin::Button2Pin()
{
}

Button2Pin::Button2Pin(int buttonPin, bool isLock)
{
    pinMode(buttonPin, INPUT);
    digitalWrite(buttonPin, HIGH);
    this->buttonPin = buttonPin;
    this->isToggle = isLock;
}

bool Button2Pin::switchButtonStatus()
{
    if (!isToggle)
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

bool Button2Pin::buttonStatus()
{
    int digitalPinRead = digitalRead(buttonPin);
    if (!isToggle)
        buttonState = digitalPinRead;
    else if (digitalPinRead == 0)
        if (buttonState == 1)
            buttonState = 0;
        else
            buttonState = 1;

    if (buttonState == 0)
        return true;
    return false;
}

int Button2Pin::buttonStatusInt()
{
    if (buttonStatus())
        return 1;
    return 0;
}

int Button2Pin::buttonStatusRaw()
{
    return digitalRead(buttonPin);
}
