void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);	//LED1
  pinMode(8, INPUT);	//BOTON1
  pinMode(2, INPUT);	//BOTON2
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(8) == HIGH && digitalRead(2) == HIGH)		//Pregunta si se cumple la condición
  {
    digitalWrite(13, HIGH);			//SI: encendemos el led1
  }
  else	//En caso contrario
  {
    digitalWrite(13, LOW);			//NO: apagamos el led1
  }
}
