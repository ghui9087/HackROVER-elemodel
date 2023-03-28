#include <Button.h>

Button2Pin::Button2Pin(int pin, buttonState state) : Button2Pin(pin) { this->isToggle = istrogle; };

Button2Pin::Button2Pin(int pin) : Button2Pin(pin, INPUT_PULLUP){};

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

/**
 * getStateRaw 
 * Reading the data from the data so you can read the data from button on-time
 *
 */
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