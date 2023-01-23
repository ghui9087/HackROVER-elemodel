#ifndef Button_h
#define Button_h
#include <Arduino.h>

/**
 * All Type of Button will be list in here
 * If you need it just call the fuction you need
 * @example I want to using 3 Pin Button
 * @example Button3Pin name(buttonPin, ledPin, isToggle);
 */
class Button
{
protected:
    bool isToggle = false;
    bool isButtonKEEP = false;
    int buttonState = 0;
    int buttonPin;
    int ledPin;
};
#endif

/**
 * Button with only 2 Pin Mode
 * ONly working with this
 * 5v --> button --> digital port(button pin)
 * @warning if you doing like this. It can not work and maybe broken your board
 * @warning Ground --> button --> digital port(button pin)
 */
class Button2Pin : public Button
{
protected:
    void loop(void);

    int previousSteadyState;  // the previous steady state from the input pin, used to detect pressed and released event
    int lastSteadyState;      // the last steady state from the input pin
    int lastFlickerableState; // the last flickerable state from the input pin
    unsigned long count;
    unsigned long debounceTime;
    unsigned long lastDebounceTime;
    // const int MAXEMPTYCHECK = 4;

public:
    /**
     * Empty constructor
     */
    Button2Pin();
    /**
     * Button constructor for 2 Pin
     * @param buttonPin the button power input in GPIO
     * @param isToggle checking wich the button need to be troggle or not
     * @warning Only button that is connect from 5v to digital port
     * @warning If it is connect From GND to button  than go in to digital port, IT WILL NOT WORKING
     */
    Button2Pin(int buttonPin, bool isToggle);
    /**
     * switchButtonStatus
     * @paragraph a way to turn on/off button without hit the button
     * @warning if this button is not in Lock mode would not work
     */
    bool switchButtonStatus();
    /**
     * isButtonOn
     * @paragraph return the status of button retime
     */
    bool buttonStatus();
    /**
     * @paragraph return button status retime
     * @paragraph 1 is buttom on. 0 is button off
     */
    int buttonStatusInt();
    /**
     *  return the curent button status without thinking
     */
    int buttonStatusRaw();

    /**
     *
     */
    int buttonPinID();
};

class Button3Pin : public Button
{
private:
    /**
     * jsut a helper you can not access from outside
     * @looong804 this method does not matter to public
     */
    bool ledstuts(bool state);
    Button2Pin buttonFor3Pin;

public:
    /**
     * Empty constructor
     */
    Button3Pin();
    /**
     * Button constructor for 3 Pin
     * @param buttonPin the button power input in GPIO
     * @param isToggle checking wich the button need to be troggle or not
     */
    Button3Pin(int bottonPort, int ledPin, bool isToggle);
    /**
     * switchButtonStatus
     * @paragraph a way to turn on/off button without hit the button
     * @warning if this button is not in Lock mode would not work
     */
    bool switchButtonStatus();
    /**
     * isButtonOn
     * @paragraph reading the buttom and change the output
     * @paragraph return the status of button retime
     */
    bool buttonStatus();
    /**
     * @paragraph return button status retime
     * @paragraph 1 is buttom on. 0 is button off
     */
    int buttonStatusInt();
    /**
     *  return the curent button status without thinking
     */
    int buttonStatusRaw();

    int buttonPinID();

    
};

class NewButton2Pin : public Button
{
	private:
		int btnPin;
		unsigned long debounceTime;
		unsigned long count;

		int previousSteadyState;  
		int lastSteadyState;      
		int lastFlickerableState; 

		unsigned long lastDebounceTime;

	public:
		NewButton2Pin(int pin);
		NewButton2Pin(int pin, int mode);
		int getState(void);
		int getStateRaw(void);
		bool isPressed(void);
		bool isReleased(void);
		void loop(void);
};
