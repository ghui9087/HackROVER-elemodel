#ifndef Button_h
#define Button_h
#include <Arduino.h>

class Button
{
};
#endif

/**
 * 
*/
class Button2Pin : public Button
{
private:
    bool isLock = false;
    int buttonState = 0;
    int buttonPin;

public:
    /**
     * Button constructor for 2 Pin
     * @param buttonPin the button power input in GPIO
     * @param isLock checking wich the button need to be troggle or not
     */
    Button2Pin(int buttonPin, bool isLock);
    bool switchButtonStatus();
    bool isButtonOn();
    int isButtonOnInt();
};

class Button3Pin : public Button
{
private:
    bool isLock = false;
    int buttonState = 0;
    int buttonPin;
    int ledPin;
    void ledstuts(bool state);

public:
    Button3Pin(int bottonPort, int ledPin, bool isLock);
    bool switchButtonStatus();
    bool isButtonOn();
    int isButtonOnInt();
};
