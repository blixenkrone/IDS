public class WebCam{
  void webcamEffect(){
     image(img,0,0,640,480);
       for(int j = 0; j < camera.height; j++){
        for(int i = 0; i < camera.width; i++){
          color c = camera.pixels[(j*width)+i];
          if(brightness(c)>100){
            stroke(c);
            noSmooth();
            point(i,j);
            camera.pixels[(j*width)+i] = c;      
         }
        }
       }
    text(frameRate,30,30);
 }
}