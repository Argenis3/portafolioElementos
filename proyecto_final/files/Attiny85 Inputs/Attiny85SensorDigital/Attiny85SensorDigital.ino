int Boton=0;

void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
}

void loop()
{
  Boton=digitalRead(4);
  if(Boton==HIGH){
    digitalWrite(3, HIGH);
  }
  else if (Boton==LOW){
    digitalWrite(3, LOW);
  }
    
}