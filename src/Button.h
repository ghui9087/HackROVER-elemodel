#ifndef Button_h
#define Button_h
// #include <Arduino.h>

class Button
{
};
#endif

class Button2Pin : public Button
{
private:
    bool switchState = false;
    int switchPort;
    int ledPort;

public:
    Button2Pin(int bottonPort, bool isLock);
    bool switchButtonStatus();
    bool isButtonOn();

};

class Button3Pin : public Button
{
    private:
    bool switchState = false;

    public:
    Button3Pin(int bottonPort, int ledPort, bool isLock);
};
