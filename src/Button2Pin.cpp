#include "Button.h"


Button2Pin::Button2Pin(int buttonPort, bool isLock){
    pinMode(buttonPort, INPUT);
}

bool Button2Pin::switchButtonStatus()
{
    switchState = true;
    return true;
}

bool Button2Pin::isButtonOn(){

}