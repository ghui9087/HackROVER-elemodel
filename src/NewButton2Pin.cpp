#include <Button.h>

NewButton2Pin::NewButton2Pin(int pin) : NewButton2Pin(pin, INPUT_PULLUP){};

NewButton2Pin::NewButton2Pin(int pin, int mode)
{
	btnPin = pin;
	debounceTime = 0;
	count = 0;

	pinMode(btnPin, mode);

	previousSteadyState = digitalRead(btnPin);
	lastSteadyState = previousSteadyState;
	lastFlickerableState = previousSteadyState;

	lastDebounceTime = 0;
}

int NewButton2Pin::getState(void)
{
	loop();
	return lastSteadyState;
}

int NewButton2Pin::getStateRaw(void)
{
	return digitalRead(btnPin);
}

bool NewButton2Pin::isPressed(void)
{
	if (previousSteadyState == HIGH && lastSteadyState == LOW)
		return true;
	else
		return false;
}

bool NewButton2Pin::isReleased(void)
{
	if (previousSteadyState == LOW && lastSteadyState == HIGH)
		return true;
	else
		return false;
}

void NewButton2Pin::loop(void)
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

	if (previousSteadyState != lastSteadyState)
	{
		if (previousSteadyState == HIGH && lastSteadyState == LOW)
			count++;
	}
}