#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// our servo # counter
//Test comment
uint8_t servonum = 0;
const int x_Pin = 0; // Sets the analog pin for the joystick x-axis
const int y_Pin = 1; // Sets the analog pin for the joystick x-axis\

int basePos = 0;
const int clawButtonPin = 2; // Sets the pin that takes the claw button input
const int clawHeader = 0; // Sets which shield header the claw servo is wired to
int clawButtonState = 0; // Marks the button as open to begin
boolean clawState = false; // Sets the claw state to closed


void setup() {
  Serial.begin(9600);
  Serial.println("Initalizing serial communication.");

  pwm.begin();
  pinMode(clawButtonPin, INPUT); // Sets the claw button pin to accept inputs
  pinMode(x_Pin, INPUT);
  pinMode(y_Pin, INPUT);
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  Serial.println("PWM initialized");
}

void loop() {
  int x_Pos = analogRead(x_Pin);
  Serial.println(x_Pos);
  if (x_Pos)
}
