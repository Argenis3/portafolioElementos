// C++ PWM ~0, ~1, ~3, ~4

int brightness = 0;

void setup()
{
  pinMode(0, OUTPUT);
}

void loop()
{
  if(digitalRead(3)==HIGH){
    brightness=brightness+5;
  }
  
  if(digitalRead(4)==HIGH){
    brightness=brightness-5;
  }
  
  if(brightness>255){
    brightness=255;
  }
  
  if(brightness<0){
    brightness=0;
  }
   analogWrite(0, brightness);
  delay(100);
}