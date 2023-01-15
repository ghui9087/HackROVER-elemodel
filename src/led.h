#ifndef led_h
#define led_h
#include <Arduino.h>

class LED
{
protected:
    bool isOn = false;
    int ledPin;

};

class led2Pin : public LED
{
private:
public:
    led2Pin();
    led2Pin(int ledPin);
    void changeStatus();
    void changeStatus(bool status);
    bool currentLedStatus();
};

#endif