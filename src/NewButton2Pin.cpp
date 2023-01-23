#include <Button.h>

NewButton2Pin::NewButton2Pin(int pin) : NewButton2Pin(pin, INPUT_PULLUP){};

NewButton2Pin::NewButton2Pin(int pin, int mode)
{
	btnPin = pin;
	debounceTime = 0;
	count = 0;
	countMode = 0;

	pinMode(btnPin, mode);

	previousSteadyState = digitalRead(btnPin);
	lastSteadyState = previousSteadyState;
	lastFlickerableState = previousSteadyState;

	lastDebounceTime = 0;
}

void NewButton2Pin::setDebounceTime(unsigned long time)
{
	debounceTime = time;
}

int NewButton2Pin::getState(void)
{
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

void NewButton2Pin::setCountMode(int mode)
{
	countMode = mode;
}

unsigned long NewButton2Pin::getCount(void)
{
	return count;
}

void NewButton2Pin::resetCount(void)
{
	count = 0;
}

void NewButton2Pin::loop(void)
{
	// read the state of the switch/button:
	int currentState = digitalRead(btnPin);
	unsigned long currentTime = millis();

	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH), and you've waited long enough
	// since the last press to ignore any noise:

	// If the switch/button changed, due to noise or pressing:
	if (currentState != lastFlickerableState)
	{
		// reset the debouncing timer
		lastDebounceTime = currentTime;
		// save the the last flickerable state
		lastFlickerableState = currentState;
	}

	if ((currentTime - lastDebounceTime) >= debounceTime)
	{
		// whatever the reading is at, it's been there for longer than the debounce
		// delay, so take it as the actual current state:

		// save the the steady state
		previousSteadyState = lastSteadyState;
		lastSteadyState = currentState;
	}

	if (previousSteadyState != lastSteadyState)
	{
		if (previousSteadyState == HIGH && lastSteadyState == LOW)
			count++;
	}
}