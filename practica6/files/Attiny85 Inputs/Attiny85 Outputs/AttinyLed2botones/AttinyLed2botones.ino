// Codigo Attiny85
//

int flag=0;
  
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop()
{
  if(digitalRead(3)==HIGH){
    flag=1;
  }
  
  if(digitalRead(4)==HIGH){
    flag=0;
  }
  
  if(flag==1){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
  
  delay(100);
}