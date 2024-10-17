// Codigo Attiny85
//
int boton1=LOW;
int boton2=LOW;

void setup()
{
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(2, OUTPUT);
  
}

void loop()
{
  boton1=digitalRead(4);
  boton2=digitalRead(3);
  
  if(boton1==HIGH || boton2==HIGH  ){
    digitalWrite(2,HIGH);
  }
  else{
    digitalWrite(2,LOW);
  }
}