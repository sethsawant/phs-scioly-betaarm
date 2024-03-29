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

const int x_Zero = 509; //sets the zero value of the joystick
const int x_Buffer = 5; // Buffer size on both sides of the x value
const int x_Speed = 3; // Sets the speed at which the base servo moves

const int y_Zero = 503; //sets the zero value of the joystick
const int y_Buffer = 5; // Buffer size on both sides of the y value
const int y_Speed = 3; // Sets the speed at which the base servo moves

int basePos = 0;
const int baseHeader = 1;

const int wristHeader = 3;
int wristPos = 0;


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
  const int x_Zero = 509;
  
  clawButtonState = digitalRead(clawButtonPin);              //checks status of claw control button
  
  baseRot();
  wristRot();
  
  if ((clawButtonState == HIGH) && (clawState == true)) {     
    // Opens claw:    
    clawOpen();
    Serial.println("open");
  } 
  else if ((clawButtonState == HIGH) && (clawState == false)) {     
    // Opens claw:    
    clawClose();
    Serial.println("close");  
  } 
}
