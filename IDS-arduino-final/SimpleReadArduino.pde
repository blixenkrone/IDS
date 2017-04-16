import processing.serial.*;

Serial myPort;
int val = 0, xPos = 0, yPos = 0;



void setup() 
{
  size(400, 400);
  String portName = Serial.list()[3];
  myPort = new Serial(this, portName, 9600);
}

void draw() {

  while (myPort.available() > 0) {
    float val = myPort.read();
    println(val);

    if (xPos>=width) {
      xPos=0;
      background(0);
    } else {
      xPos++;
    }

    val = map(val, 0, 40, 0, height);
    stroke(127, 34, 255);
    line(xPos, height, xPos, height-val);
  }
}