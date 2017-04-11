//variabler til lås
const int redPin = 13;
const int greenPin = 12;
const int knockSensor = A1;
const int threshold = 100;
int sensorReading = 0;
int lockLedState = HIGH;

//variabler til temperatur
const int temperaturPin = A4;
const int yellowPinNumber =  11;
int temperaturLedState = HIGH;


void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPinNumber, OUTPUT);

}

void loop() { 
  sensorReading = analogRead(knockSensor);
  Serial.println(sensorReading);
  lockSensor();
  delay(200);
}

//LAV EN LAMPE DER KAN JUSTERE LYSSTYRKE FRA DREJEKNAP
//LAV TEMEPRATUR 
//LAV LYD UD AF PIEZO HVIS TEMP ER LAV EFTER LÆNGERE TID
//ENTEN BOOLEAN ELLER SEND TIL PROCESSING ELLER GOTO
//FRITZING
