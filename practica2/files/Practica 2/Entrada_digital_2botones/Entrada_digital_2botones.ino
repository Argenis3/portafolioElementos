void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);	//LED1
  pinMode(8, INPUT);	//BOTON1
  pinMode(11, OUTPUT);	//LED2
  pinMode(2, INPUT);	//BOTON2

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, digitalRead(8)); //Escribimpos en el LED1 el valor del BOTON1
  digitalWrite(11, digitalRead(2)); //Escribimpos en el LED2 el valor del BOTON2

}
