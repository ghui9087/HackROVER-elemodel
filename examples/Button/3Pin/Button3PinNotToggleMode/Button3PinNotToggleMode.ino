#include <Button.h>


static const int buttonPin = 2;
static const int ledPin = 13;
static const bool isToggle = false;

Button3Pin testing(buttonPin,ledPin,isToggle);

void setup() {
  Serial.begin(9600);

}

void loop() {

  Serial.println(cat.buttonStatus());
  
  delay(150);
}
