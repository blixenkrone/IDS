//variabler til lås
const int redPin = 13;
const int greenPin = 12;
const int knockSensor = A1;
const int threshold = 100;
int sensorReading = 0;
int lockLedState = HIGH;

//variabler til temperatur
float voltRead;
const int temperaturePin = A4;
const int yellowPin =  11;
int temperaturLedState = HIGH;
unsigned long previousMillis = 0;
int voltInCelc = 0;

//variabler til lyd
int soundLedState = LOW;
const int piezoSensor = A1;
//knockSensor A1, noteA, noteB;

int alarmState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
}

void loop() {
  sensorReading = analogRead(knockSensor);
  lockSensor();
  getTemperature(temperaturePin);
  delay(500);
}

void getTemperature(int temperaturePin) {
  float voltRead = analogRead(temperaturePin);
  float volt = voltRead * (5.0 / 1023);
  float voltInCelc = (volt - 0.5) * 100;
  
  Serial.write((int) voltInCelc); //Send til processing
  if (voltInCelc >= 23 || voltInCelc <= 1) { //Til tests er det 24 - normalt køleskab er måske maks 7 *c.
    alarmState = 1;
  } else {
    alarmState = 0;
  }
  temperaturAlarm(5000);
  piezoSound();
}

void temperaturAlarm(int interval) {
  unsigned long currentMillis = millis();
  if (alarmState == 1) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if (temperaturLedState == LOW) {
        temperaturLedState = HIGH;
        soundLedState = HIGH;
      } else {
        temperaturLedState = LOW;
        soundLedState = LOW;
      }
      digitalWrite(yellowPin, temperaturLedState);
    }
  } else {
    noTone(piezoSensor); 
  }
}

void piezoSound() {
  if (alarmState == 1) {
    const int noteA = 440;
    const int noteB = 750;
    if (soundLedState == LOW) {
      tone(piezoSensor, noteA);
    } else if (soundLedState == HIGH) {
      tone(piezoSensor, noteB);
    }
  }
}

void lockSensor() {

  if (alarmState) {
    if (sensorReading >= threshold) {
      lockLedState = !lockLedState;
      digitalWrite(greenPin, lockLedState);
    } else {
      digitalWrite(redPin, !lockLedState);
      delay(200);
    }
  }
}
