#include "Button.h"

/**
 * Button constructor for 3 Pin
 * @param buttonPin the button power input in GPIO
 * @param isLock checking wich the button need to be troggle or not
 */
Button3Pin::Button3Pin(int buttonPin, int ledPin, bool isLock)
{
    pinMode(buttonPin, INPUT);
    pinMode(ledPin, OUTPUT);
    this->buttonPin = buttonPin;
    this->isLock = isLock;
    this->ledPin = ledPin;
    ledstuts(false);
}

/**
 * switchButtonStatus
 * @paragraph a way to turn on/off button without hit the button
 * @warning if this button is not in Lock mode would not work
 */
bool Button3Pin::switchButtonStatus()
{
    if (!isLock)
        return false;
    if (buttonState == 1)
    {
        buttonState = 0;
        ledstuts(false);
    }
    else
    {
        buttonState = 1;
        ledstuts(true);
    }
    return true;
}

/**
 * isButtonOn
 * @paragraph reading the buttom and change the output
 * @paragraph return the status of button retime
 */
bool Button3Pin::isButtonOn()
{
    if (!isLock)
        buttonState = digitalRead(buttonPin);
    else
    {
        if (buttonState == 1)
        {
            if (digitalRead(buttonPin) == 1)
            {
                buttonState = 0;
                ledstuts(false);
            }
        }
        else
        {
            if (digitalRead(buttonPin) == 1)
            {
                buttonState = 1;
                ledstuts(true);
            }
        }
    }

    if (buttonState == 1)
    {
        ledstuts(true);
        return true;
    }
    ledstuts(false);
    return false;
}

/**
 * @paragraph return button status retime
 * @paragraph 1 is buttom on. 0 is button off
 */
int Button3Pin::isButtonOnInt()
{
    if (isButtonOn())
        return 1;
    return 0;
}

/**
 * Private method just switch the led on/off
 */
void Button3Pin::ledstuts(bool state)
{
    if (state)
        digitalWrite(ledPin, HIGH);
    else
        digitalWrite(ledPin, LOW);
}