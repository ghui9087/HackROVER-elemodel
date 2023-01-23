#include "Button.h"

Button2Pin::Button2Pin()
{
}

Button2Pin::Button2Pin(int _buttonPin, bool isLock)
{
    pinMode(buttonPin, INPUT_PULLUP);
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
    loop();
    if (!isToggle)
    {
        return lastSteadyState;
    }
    if(lastSteadyState == 1)
    {
        isButtonKEEP == false;
    }
    if(isButtonKEEP){
        return buttonState;
    }
    if (lastSteadyState == 0 && !isButtonKEEP)
    {
        isButtonKEEP == true;
        if(buttonState == true){
            buttonState == false;
            return buttonState;
        }
        if(buttonState == false){
            buttonState == true;
            return buttonState;
        }
    }
    
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

void Button2Pin::loop(void)
{
    int currentState = digitalRead(buttonPin);
    unsigned long currentTime = millis();

    if (currentState != lastFlickerableState)
    {

        lastDebounceTime = currentTime;

        lastFlickerableState = currentState;
    }

    if ((currentTime - lastDebounceTime) >= debounceTime)
    {
        previousSteadyState = lastSteadyState;
        lastSteadyState = currentState;
    }

    if (previousSteadyState != lastSteadyState)
    {
        if (previousSteadyState == HIGH && lastSteadyState == LOW)
            count++;
    }
}