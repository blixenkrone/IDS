import processing.video.*;

Capture camera;
WebCam webcam = new WebCam();
public PImage img;

void setup(){
  size(640,480); 
  camera = new Capture(this, 640, 480);
  camera.start();
  frameRate(60);
  img = loadImage("got.jpg");
}

void draw(){
  webcam.webcamEffect();
}

void captureEvent(Capture c){
  c.read();
}