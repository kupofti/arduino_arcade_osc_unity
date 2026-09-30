#include <Arduino.h>
#include <Bounce2.h>
#include <MicroOscSlip.h>


Bounce2::Button button;
MicroOscSlip<128> osc(&Serial);

void setup()
{
    // button setup
    button.attach(2, INPUT_PULLUP);
    button.setPressedState(LOW);

    // LED setup
    pinMode(3, OUTPUT);

    Serial.begin(115200);
}

void loop() {
    button.update();

    if (button.pressed()) osc.sendInt("/button", 1);
    if (button.released()) osc.sendInt("/button", 0);

    if (button.isPressed()) {
        digitalWrite(3, HIGH);
    } else {
        digitalWrite(3, LOW);
    }
}
