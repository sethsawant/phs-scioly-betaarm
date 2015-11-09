#define WRISTMIN  150 // These pulse lengths for the claw servo positions are correct currently.
#define WRISTMAX  385

int wristForw() {
  Serial.println("Opening claw.");
  for (uint16_t pulselen = CLAWMIN; pulselen < CLAWMAX; pulselen++) {
    pwm.setPWM(clawHeader, 0, pulselen);
    clawState = 0; //Marks claw as open
  }
}

int wistBack() {
  Serial.println("Closing claw.");
  for (uint16_t pulselen = CLAWMAX; pulselen > CLAWMIN; pulselen--) {
    pwm.setPWM(clawHeader, 0, pulselen);
    clawState = 1; // Marks claw is closed
  }
}

