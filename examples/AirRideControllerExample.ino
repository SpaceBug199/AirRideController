#include <AirRideController.h>

// Example getPosition functions
int getFRPosition() { return analogRead(A0); }
int getFLPosition() { return analogRead(A1); }
int getRRPosition() { return analogRead(A2); }
int getRLPosition() { return analogRead(A3); }

// Define the pins for each quarter
const int FR_UP_PIN = 2;
const int FR_DOWN_PIN = 3;
const int FL_UP_PIN = 4;
const int FL_DOWN_PIN = 5;
const int RR_UP_PIN = 6;
const int RR_DOWN_PIN = 7;
const int RL_UP_PIN = 8;
const int RL_DOWN_PIN = 9;

// Create the AirRideController object
AirRideController airRideController(FR_UP_PIN, FR_DOWN_PIN, FL_UP_PIN, FL_DOWN_PIN, RR_UP_PIN, RR_DOWN_PIN, RL_UP_PIN, RL_DOWN_PIN,
                                    10000, getFRPosition, getFLPosition, getRRPosition, getRLPosition, 10);

void setup() {
    Serial.begin(9600);
    pinMode(FR_UP_PIN, OUTPUT);
    pinMode(FR_DOWN_PIN, OUTPUT);
    pinMode(FL_UP_PIN, OUTPUT);
    pinMode(FL_DOWN_PIN, OUTPUT);
    pinMode(RR_UP_PIN, OUTPUT);
    pinMode(RR_DOWN_PIN, OUTPUT);
    pinMode(RL_UP_PIN, OUTPUT);
    pinMode(RL_DOWN_PIN, OUTPUT);

    // Move to initial positions
    airRideController.moveTo(500, 500, 500, 500); // set the position values in arbitrary number 
    // TODO: 
    // Convert the values to mm from ground
}

void loop() {
    airRideController.update();
    // Other non-blocking code can go here
}
