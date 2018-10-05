#include "Button.h"

#define TIME_DOUBLE_CLICK 700
#define BUTTON	A0
#define LED		12

Button button(BUTTON, true, true, 1);
bool ledStt = false;
void setup()
{
	pinMode(LED, OUTPUT);
	digitalWrite(LED, ledStt);
	Serial.begin(115200);
}

void loop()
{
	static bool press = false;
	static bool press_pre = false;
	static unsigned long t_press = 0;
	button.read();
	press_pre = press;
	press = button.isPressed();
	if (press) {
		Serial.println("press");
	}
	if (!press_pre && press) { //press
		unsigned long duration = millis() - t_press;
		Serial.println("duration " + String(duration));
		t_press = millis();
		if (duration < TIME_DOUBLE_CLICK) {
			ledStt = !ledStt;
			digitalWrite(LED, ledStt);
		}
	}
}
