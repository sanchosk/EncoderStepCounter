#include "EncoderStepCounter.h"


#define ENCODER_PIN1 14
#define ENCODER_PIN2 19

// Create instance for one half step encoder
EncoderStepCounter encoder(ENCODER_PIN1, ENCODER_PIN2, HALF_STEP);

void setup() {
  Serial.begin(9600);
  // Initialize encoder
  encoder.begin();
}

void interrupt() {
  encoder.tick();
}

signed char lastpos = 0;
void loop() {
  // Call tick on every loop
  encoder.tick();
  // Print out current encoder value
  // Have a look at the InterruptExample on how
  // to have a bigger variable for the counter
  signed char pos = encoder.getPosition();
  if (pos != lastpos) {
    lastpos = pos;
    Serial.println(pos);
  }
}
