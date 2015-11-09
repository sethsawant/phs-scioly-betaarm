#define ROTMIN  150 
#define ROTMAX  385

int baseRot() {
  for (uint16_t pulselen = ROTMAX; pulselen > ROTMIN; pulselen--) {
    pwm.setPWM(baseHeader, 0, pulselen);
  }
}


