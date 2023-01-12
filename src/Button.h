#ifndef Button_h
#define Button_h
#include <Arduino.h>

class Button
{
};
#endif

class Button2Pin : public Button
{
private:
    bool isLock = false;
    int buttonState = 0;
    int buttonPin;
    int ledPort;


public:
    Button2Pin(int buttonPin, bool isLock);
    bool switchButtonStatus();
    bool isButtonOn();

};

class Button3Pin : public Button
{
    private:
    int buttonState = 0;

    public:
    Button3Pin(int bottonPort, int ledPort, bool isLock);
};
