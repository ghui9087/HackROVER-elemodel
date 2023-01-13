#include "Button.h"
Button2Pin cat(15, false);
Button3Pin cats(15, 16, true);
void setup()
{
    cat.isButtonOn();

}