#include <led.h>

led2Pin::led2Pin()
{
}

led2Pin::led2Pin(int ledPin) {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    this->ledPin = ledPin;
}

void led2Pin::changeStatus()
{
    isOn != isOn;
    digitalWrite(ledPin, isOn);
}

void led2Pin::changeStatus(bool status)
{
    isOn = status;
    digitalWrite(ledPin, isOn);
}

bool led2Pin::currentLedStatus()
{
    return isOn;
}
