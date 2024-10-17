// Codigo Attiny85
//
  
void setup()
{
  pinMode(2, OUTPUT); //Rojo
  pinMode(1, OUTPUT); //Azul
  pinMode(0, OUTPUT); //Verde
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop()
{
  if(digitalRead(3)==HIGH){
    digitalWrite(2, HIGH);
  }
  else if(digitalRead(4)==HIGH){
    digitalWrite(1, HIGH);
  }
  else{
    digitalWrite(2, LOW);
    digitalWrite(1, LOW);
  }   
  
  delay(100);
}