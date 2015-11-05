#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// our servo # counter
//Test comment
uint8_t servonum = 0;
const int clawButtonPin = 2; // Sets the pin that takes the claw button input
const int clawHeader = 0; // Sets which shield header the claw servo is wired to
int clawButtonState = 0; // Marks the button as open to begin
int clawState = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Initalizing serial communication.");

  pwm.begin();
  pinMode(clawButtonPin, INPUT); // Sets the claw button pin to accept inputs
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  Serial.println("PWM initialized");
}

void loop() {
  clawButtonState = digitalRead(clawButtonPin);
  if ((clawButtonState == HIGH) && (clawState == 1)) {     
    // Opens claw:    
    clawOpen();
    Serial.println("open");
  } 
  else if ((clawButtonState == HIGH) && (clawState == 0)) {     
    // Opens claw:    
    clawClose();
    Serial.println("close");
  } 
}
