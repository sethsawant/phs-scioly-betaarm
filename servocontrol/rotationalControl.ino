#define ROTMIN  150 
#define ROTMAX  385

const int baseHeader = 0; // Sets which shield header the base servo is wired to

int baseRot() {
  for (uint16_t pulselen = ROTMAX; pulselen > ROTMIN; pulselen--) {
    pwm.setPWM(baseHeader, 0, pulselen);
  }
}


