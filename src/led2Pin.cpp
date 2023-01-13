#include <led.h>

led2Pin::led2Pin()
{
}

led2Pin::led2Pin(int ledPin) {
    pinMode(ledPin, OUTPUT);
    this->ledPin = ledPin;
}

void led2Pin::changeStatus()
{
    isOn != isOn;
}

void led2Pin::changeStatus(bool status)
{
    isOn = status;
}

bool led2Pin::currentLedStatus()
{
    return isOn;
}
