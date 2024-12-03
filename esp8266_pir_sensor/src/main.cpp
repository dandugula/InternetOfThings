#include "Arduino.h"

const int led_input_pin = 12;
const int motion_sensor_output_pin = 13;
int motion_state = LOW;
int prev_motion_state = LOW;


void setup () {
    Serial.begin(115200);
    pinMode(motion_sensor_output_pin, INPUT);
    pinMode(led_input_pin, OUTPUT);
}

void loop () {
    prev_motion_state = motion_state; // Store old state
    motion_state = digitalRead(motion_sensor_output_pin); // read new state
    if (prev_motion_state == LOW && motion_state == HIGH) {
        Serial.println("Motion detected");
        digitalWrite(led_input_pin, HIGH);
    } else if (prev_motion_state == HIGH && motion_state == LOW) {
        Serial.println("No motion");
        digitalWrite(led_input_pin, LOW);
    }
}
