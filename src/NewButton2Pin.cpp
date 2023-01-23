#include <Button.h>

Button2Pin::Button2Pin(int pin, bool istrogle) : Button2Pin(pin) { this->isToggle = istrogle; };

Button2Pin::Button2Pin(int pin) : Button2Pin(pin, INPUT_PULLUP){};

Button2Pin::Button2Pin(int pin, int mode)
{
	btnPin = pin;
	debounceTime = 0;

	pinMode(btnPin, mode);

	previousSteadyState = digitalRead(btnPin);
	lastSteadyState = previousSteadyState;
	lastFlickerableState = previousSteadyState;

	lastDebounceTime = 0;
}

int Button2Pin::getState(void)
{
	loop();
	if (!isToggle)
	{
		return lastSteadyState;
	}
	if (isButtonKEEP)
	{
		if (lastSteadyState == false)
		{
			return buttonState;
		}
		if (lastSteadyState == true)
		{
			isButtonKEEP == false;
			return buttonState;
		}
	}
	if (lastSteadyState == false)
	{
		isButtonKEEP == true;
		return !buttonState;
	}
}

int Button2Pin::getStateRaw(void)
{
	return digitalRead(btnPin);
}

bool Button2Pin::isPressed(void)
{
	if (previousSteadyState == HIGH && lastSteadyState == LOW)
		return true;
	else
		return false;
}

bool Button2Pin::isReleased(void)
{
	if (previousSteadyState == LOW && lastSteadyState == HIGH)
		return true;
	else
		return false;
}

void Button2Pin::loop(void)
{
	int currentState = digitalRead(btnPin);
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
}