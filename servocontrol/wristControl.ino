#define WRISTMIN  150 
#define WRISTMAX  850


int wristRot() {

  int y_Pos = analogRead(y_Pin); //reads x axis of joystick
  
  Serial.println(wristPos);
  
  //Serial.println(y_Pos);
  if ((y_Pos != y_Zero) && (y_Pos > (y_Zero + 5))) {
    pwm.setPWM(wristHeader, 0, map((wristPos++), 0, 180, WRISTMIN, WRISTMAX));
  }

  if (wristPos >= 180) {
    wristPos = 180;
  }
  
  if ((y_Pos != y_Zero) && (y_Pos < (y_Zero - 5))) {
      pwm.setPWM(wristHeader, 0, map((wristPos--), 0, 180, WRISTMIN, WRISTMAX)); 
  }

  if (wristPos <= 0) {
    wristPos = 0;
  }

}



