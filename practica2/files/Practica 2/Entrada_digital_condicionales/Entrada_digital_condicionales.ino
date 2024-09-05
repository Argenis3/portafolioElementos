void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(8,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(8) == HIGH)		//Pregunta si el boton1 esta activado
  {
    digitalWrite(13, HIGH);			//SI: encendemos el led1
  }
  else if(digitalRead(8) == LOW)	//Pregunta si el boton1 esta desactivado
  {
    digitalWrite(13, LOW);			//SI: apagamos el led1
  }

}
