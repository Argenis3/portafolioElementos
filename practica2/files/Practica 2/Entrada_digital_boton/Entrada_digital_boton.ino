void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(8,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, digitalRead(8)); //Escribimos en el LED el valor del BOTON

}
