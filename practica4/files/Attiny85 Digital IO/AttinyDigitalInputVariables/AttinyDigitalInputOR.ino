// Codigo Attiny85
//
int boton=LOW;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
}

void loop()
{
  boton=digitalRead(4);
  
  if(boton==HIGH){
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }
}