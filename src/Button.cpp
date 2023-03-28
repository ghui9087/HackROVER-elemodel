#include "Button.h"

Button::Button(int pin) : buttonPin(pin), buttonType(PRESS)
{
    pinMode(pin, INPUT);
}

Button::Button(int pin, buttonState type) : buttonPin(pin), buttonType(type)
{
    pinMode(pin, INPUT);
}

bool Button::switchButtonState()
{
    return false;
}

bool Button::getButtonState()
{
    loop();
    if (!buttonType)
    {
        return currentState;
    }
    if (currentState)
    {
        isButtonKEEP = !isButtonKEEP;
        return isButtonKEEP;
    }
    return isButtonKEEP;
}

bool Button::getButtonStateRaw()
{
    return digitalRead(buttonPin);
}

void Button::loopState()
{
    int stateCount = digitalRead(buttonPin);
    if (!buttonType)
    {
        return;
    }

    delay(10);
    stateCount += digitalRead(buttonPin);

    delay(10);
    stateCount += digitalRead(buttonPin);

    currentState = (stateCount == 3) ? 1 : 0;
}
