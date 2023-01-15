#include "Button.h"

Button3Pin::Button3Pin()
{
}

Button3Pin::Button3Pin(int buttonPin, int ledPin, bool isToggle)
{
    buttonFor3Pin = Button2Pin(buttonPin, isToggle);
    pinMode(ledPin, OUTPUT);
    this->ledPin = ledPin;
}
// TODO:
bool Button3Pin::switchButtonStatus()
{
    return buttonFor3Pin.switchButtonStatus();
}

bool Button3Pin::buttonStatus()
{
    return ledstuts(buttonFor3Pin.buttonStatus());
}

int Button3Pin::buttonStatusInt()
{
    return buttonFor3Pin.buttonStatusInt();
}

int Button3Pin::buttonStatusRaw()
{
    return buttonFor3Pin.buttonStatusRaw();
}

int Button3Pin::buttonPinID()
{
    return buttonPin;
}

/**
 * Private method just switch the led on/off
 */
bool Button3Pin::ledstuts(bool state)
{
    if (state)
    {
        digitalWrite(ledPin, HIGH);
        return true;
    }
    else
    {
        digitalWrite(ledPin, LOW);
        return false;
    }
}