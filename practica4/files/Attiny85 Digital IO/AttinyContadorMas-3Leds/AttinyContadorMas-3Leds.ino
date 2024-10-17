// Codigo Attiny85
//

int contador=0;
  
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop()
{
  if(digitalRead(3)==HIGH){
    contador++;
  }
  
  if(digitalRead(4)==HIGH){
    contador--;
  }
  
  if(contador>3){
    contador=3;
  }
  
  if(contador<0){
    contador=0;
  }
  
  if(contador==0){
  	digitalWrite(0, LOW);
  	digitalWrite(1, LOW);
  	digitalWrite(2, LOW);
  }
  else if(contador==1){
  	digitalWrite(0, HIGH);
  	digitalWrite(1, LOW);
  	digitalWrite(2, LOW);
  }
  else if(contador==2){
  	digitalWrite(0, HIGH);
  	digitalWrite(1, HIGH);
  	digitalWrite(2, LOW);
  }
  else if(contador==3){
  	digitalWrite(0, HIGH);
  	digitalWrite(1, HIGH);
  	digitalWrite(2, HIGH);
  }
  
  delay(500);
}