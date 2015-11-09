#define CLAWMIN  150 // These pulse lengths for the claw servo positions are correct currently.
#define CLAWMAX  385

int clawOpen() {
  Serial.println("Opening claw.");
  for (uint16_t pulselen = CLAWMIN; pulselen < CLAWMAX; pulselen++) {
    pwm.setPWM(clawHeader, 0, pulselen);
    clawState = false; //Marks claw as open
  }
}

int clawClose() {
  Serial.println("Closing claw.");
  for (uint16_t pulselen = CLAWMAX; pulselen > CLAWMIN; pulselen--) {
    pwm.setPWM(clawHeader, 0, pulselen);
    clawState = true; // Marks claw is closed
  }
}

