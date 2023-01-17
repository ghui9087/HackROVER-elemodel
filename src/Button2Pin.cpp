#include "Button.h"

Button2Pin::Button2Pin()
{
}

Button2Pin::Button2Pin(int _buttonPin, bool isLock)
{
    pinMode(buttonPin, INPUT);
    digitalWrite(buttonPin, HIGH);
    this->buttonPin = _buttonPin;
    this->isToggle = isLock;
    Serial.begin(9600);
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
    {
        buttonState = (digitalPinRead == 1) ? true : false;
        return (buttonState == 1) ? true : false;
    }
    if (digitalPinRead == 1)
    {
        timeCheck++;
    }
    else
    {
        timeCheck = 0;
        buttonState = 0;
    }

    if (timeCheck > totalCheck)
    {
        buttonState = !buttonState;
        timeCheck = totalCheck;
        Serial.println(timeCheck);
    }

    return (buttonState == 1) ? true : false;
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

int Button2Pin::buttonPinID()
{
    return buttonPin;
}

void Button2Pin::totalTimeCheck(int count)
{
    this->totalCheck = count;
}
