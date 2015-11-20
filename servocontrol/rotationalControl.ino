#define ROTMIN  150 
#define ROTMAX  385


int baseRot() {

  int x_Pos = analogRead(x_Pin); //reads x axis of joystick

  if ((x_Pos != x_Zero) && (x_Pos > (x_Zero + 5))) {
    pwm.setPWM(baseHeader, 0, map((basePos++), 0, 180, ROTMIN, ROTMAX));
  }

  if (basePos > 180) {
    basePos = 180;
  }

  if (basePos < 0) {
    basePos = 0;
  }

  if ((x_Pos != x_Zero) && (x_Pos < (x_Zero - 5))) {
      pwm.setPWM(baseHeader, 0, map((basePos--), 0, 180, ROTMIN, ROTMAX)); 
  }

}



