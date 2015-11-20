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
  const int x_Zero = 509;
  
  clawButtonState = digitalRead(clawButtonPin);              //checks status of claw control button 
  
  int y_Pos = analogRead(y_Pin);
  int x_Pos = analogRead(x_Pin); //reads x axis of joystick
  
  Serial.println(x_Pos); // Prints analog value of x axis on joystick
  
  if ((x_Pos != x_Zero) && (x_Pos > x_Zero)) {
    
    #define SERVOMIN  150
    #define SERVOMAX  385
    
    const int baseHeader = 1;
    int pulselen = map(degrees, 0, 180, SERVOMIN, SERVOMAX);
    pulselen++;
    pwm.setPWM(baseHeader, 1, pulselen);
    Serial.println("joystick x >");  
  }
  
  if ((x_Pos != x_Zero) && (x_Pos < x_Zero)) {
    
    #define SERVOMIN  150
    #define SERVOMAX  385
    
    const int baseHeader = 1;
    int degrees;
    int pulselen = map(degrees, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(baseHeader, 1, pulselen);
    Serial.println("joystick x <");  
  }
  
  
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
