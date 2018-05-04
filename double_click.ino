#include <Button.h>

#define TIME_DOUBLE_CLICK 500
#define BUTTON	8
#define LED		12

Button button(BUTTON, true, false, 10);
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
	if (!press_pre && press) { //press
		unsigned long duration = millis() - t_press;
		Serial.println("press " + String(duration));
		t_press = millis();
		if (duration < TIME_DOUBLE_CLICK) {
			ledStt = !ledStt;
			digitalWrite(LED, ledStt);
		}
	}
}
