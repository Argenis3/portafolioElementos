void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
}

void loop()
{
  digitalWrite(3, digitalRead(4));
}
