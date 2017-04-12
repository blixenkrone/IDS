//variabler til lås
const int redPin = 13;
const int greenPin = 12;
const int knockSensor = A1;
const int threshold = 100;
int sensorReading = 0;
int lockLedState = HIGH;

//variabler til temperatur
const int temperaturePin = A4;
const int yellowPin =  11;
int temperaturLedState = HIGH;
unsigned long previousMillis = 0;
int tempRead = 0;

//variabler til lyd
int soundLedState = LOW;
//knockSensor A1, noteA, noteB;

char ON_OFF;

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

float getTemperature(int temperaturePin) {
  float voltRead = analogRead(temperaturePin);
  float volt = voltRead * (5.0 / 1023);
  float voltInCelc = (volt - 0.5) * 100;
  Serial.println(voltInCelc);

  if (voltInCelc >= 25 || voltInCelc <= 1) { //Til tests er det 24 - normalt køleskab er måske maks 7 *c.
    ON_OFF = 'A';
    temperaturAlarm(50);
    piezoSound();
  } else {
    getTemperature(temperaturePin);
    ON_OFF = 'B';
    Serial.print("Reset");
  }
  return voltInCelc;
}

void temperaturAlarm(int interval) {
  unsigned long currentMillis = millis();
  if (ON_OFF = 'A') {
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
  }
}

void piezoSound() {
  if (ON_OFF = 'A') {
    const int noteA = 440;
    const int noteB = 750;
    if (soundLedState == LOW) {
      tone(knockSensor, noteA);
    } else if (soundLedState == HIGH) {
      tone(knockSensor, noteB);
    }
  }
}

void lockSensor() {
  Serial.print(sensorReading);

  //  if (ON_OFF = 'B') {
  if (sensorReading >= threshold) {
    lockLedState = !lockLedState;
    digitalWrite(greenPin, lockLedState);
  } else {
    digitalWrite(redPin, !lockLedState);
    delay(200);
    //    }
  }
}



//LAV EN LAMPE DER KAN JUSTERE LYSSTYRKE FRA DREJEKNAP
//ENTEN BOOLEAN ELLER SEND TIL PROCESSING ELLER GOTO
//FRITZING

//MANGLER: LockSensor virker ikke ordenligt.
