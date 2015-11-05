#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

#define CLAWMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define CLAWMAX  385// this is the 'maximum' pulse length count (out of 4096)

// our servo # counter
uint8_t servonum = 0;
const int clawButtonPin = 2;
const int clawHeader = 0;
int clawButtonState = 0;
int clawState = 0;


void setup() {
  Serial.begin(9600);
  Serial.println("Initalizing serial communication.");

  pwm.begin();
  pinMode(clawButtonPin, INPUT);
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  Serial.println("PWM initialized");
}


int clawOpen() {
  Serial.println("Opening claw.");
  for (uint16_t pulselen = CLAWMIN; pulselen < CLAWMAX; pulselen++) {
    pwm.setPWM(clawHeader, 0, pulselen);
    clawState = 0;
  }
}

int clawClose() {
  Serial.println("Closing claw.");
  for (uint16_t pulselen = CLAWMAX; pulselen > CLAWMIN; pulselen--) {
    pwm.setPWM(clawHeader, 0, pulselen);
    clawState = 1;
  }
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
