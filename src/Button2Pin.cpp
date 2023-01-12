#include "Button.h"

Button2Pin::Button2Pin(int buttonPin, bool isLock)
{
    pinMode(buttonPin, INPUT);
    this->buttonPin = buttonPin;
    this->isLock = isLock;
}

bool Button2Pin::switchButtonStatus()
{
    buttonState = true;
    return true;
}

bool Button2Pin::isButtonOn()
{
    if (!isLock)
    buttonState = digitalRead(buttonPin);
    
        if (buttonState == 1)
            return true;
        return false;

}