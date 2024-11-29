// Codigo Attiny85
//
int Pot=0;

void setup()
{
  pinMode(3, OUTPUT);
}

void loop()
{
  Pot=analogRead(A2);
  
  digitalWrite(3, HIGH);
  delay(Pot);
  digitalWrite(3, LOW);
  delay(Pot);
    
}