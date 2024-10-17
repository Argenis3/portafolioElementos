int Pot=0;

void setup()
{
  pinMode(3, OUTPUT);
}

void loop()
{
  Pot=analogRead(A2);
  
  if(Pot<=512){
    digitalWrite(3, HIGH);
  }
  else if (Pot>512){
    digitalWrite(3, LOW);
  }
    
}