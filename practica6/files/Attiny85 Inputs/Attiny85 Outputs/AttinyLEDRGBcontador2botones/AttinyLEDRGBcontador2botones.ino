// Codigo Attiny85
//
int contador=0;

void setup()
{
  pinMode(2, OUTPUT); //Rojo
  pinMode(1, OUTPUT); //Azul
  pinMode(0, OUTPUT); //Verde
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop()
{
  if(digitalRead(3)==HIGH){
    contador++;
  }
  
  if(digitalRead(4)==HIGH){
    contador--;
  }
  
  if(contador>7){
    contador=7;
  }
  
  if(contador<0){
    contador=0;
  }
  
  if(contador==0){
  	digitalWrite(0, LOW);
  	digitalWrite(1, LOW);
  	digitalWrite(2, LOW);
  }
  else if(contador==1){    //ROJO
  	digitalWrite(0, HIGH);
  	digitalWrite(1, LOW);
  	digitalWrite(2, LOW);
  }
  else if(contador==2){
  	digitalWrite(0, LOW);
  	digitalWrite(1, HIGH);   //AZUL
  	digitalWrite(2, LOW);
  }
  else if(contador==3){
  	digitalWrite(0, LOW);
  	digitalWrite(1, LOW);
  	digitalWrite(2, HIGH);  //VERDE
  }
  else if(contador==4){
  	digitalWrite(0, LOW);
  	digitalWrite(1, HIGH);
  	digitalWrite(2, HIGH);  //ROSA
  }
  else if(contador==5){
  	digitalWrite(0, HIGH);
  	digitalWrite(1, LOW);
  	digitalWrite(2, HIGH);  //AMARILLO
  }
  else if(contador==6){
  	digitalWrite(0, HIGH);
  	digitalWrite(1, HIGH);
  	digitalWrite(2, LOW);  //CYAN
  }
  else if(contador==7){
  	digitalWrite(0, HIGH);
  	digitalWrite(1, HIGH);
  	digitalWrite(2, HIGH);  //BLANCO
  }
  
  delay(500);
}