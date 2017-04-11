void lockSensor() {
  if (sensorReading >= threshold) {
    lockLedState = !lockLedState;
    digitalWrite(greenPin, lockLedState);
  } else {
    digitalWrite(redPin, !lockLedState);
  }
}

