public class WebCam{
  void webcamEffect(){
     image(img,0,0,640,480);
     loadPixels();
       for(int j = 0; j < camera.height; j++){
        for(int i = 0; i < camera.width; i++){
          color c = camera.pixels[(j*width)+i];
          if(brightness(c)>100){
            pixels[(j*width)+i] = c;      
         }
          if(keyCode == DOWN){
            c = pixels[i]+color(255);
            println("Hej!");
          }
        }
       }
       updatePixels();
    text(frameRate,30,30);
 }
}