import processing.serial.*;

Serial myPort;
int val = 0;

void setup() 
{
  size(200, 200);
  String portName = Serial.list()[3];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  val = myPort.read();

  if (val > 1) {
    println(val);
  }
}