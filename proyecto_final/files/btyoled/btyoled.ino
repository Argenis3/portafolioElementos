/* MyIRBot (c)Mans Rademaker 2023
 * board:ATTiny25/45/85 processor:ATTiny85 programmer Arduino as ISP Use_Tiny:yes
 * board:digispark      processor:digi     programmer Microneus      Use_Tiny:no 
 */
 #include <SoftwareSerial.h>
 
#define     Use_Tiny         // use digispark drivers or Tiny4Koled
#ifdef      Use_Tiny         // ATTiny straight
  #include "TinyWireM.h"
  #include "Tiny4kOLED.h"
#else                        // Digispark board
  #include <DigisparkOLED.h>
  #include <Wire.h>
#endif
#include "my_eyes.h"
#define MOTOR_A_IA 4 // Dirección A del motor A
#define MOTOR_A_IB 5 // Dirección B del motor A
#define MOTOR_B_IA 6 // Dirección A del motor B
#define MOTOR_B_IB 7 // Dirección B del motor B

// Pines del módulo Bluetooth
#define RX_PIN 2
#define TX_PIN 3
SoftwareSerial BTSerial(RX_PIN, TX_PIN); // Configura el puerto Bluetooth

bool test     = false;
bool flat     = false;
int  sleeping = 0;
int  analog3; // left
int  analog2; // right
int  digital; // updown
int  xpos;
int  ypos;
int  old_xpos;
int  old_ypos;

void setup() {
  // Configuración OLED
  #ifdef Use_Tiny
    oled.begin(128, 32, sizeof(tiny4koled_init_128x32br), tiny4koled_init_128x32br);
    oled.setInternalIref(true);
    oled.setFont(FONT6X8P);
  #else
    oled.begin();
  #endif

  // Configuración de pines de entrada
  pinMode(PB1, INPUT); // PB1
  pinMode(A2, INPUT);  // PB4
  pinMode(A3, INPUT);  // PB3  

  // Configuración de pines de motores
  pinMode(MOTOR_A_IA, OUTPUT);
  pinMode(MOTOR_A_IB, OUTPUT);
  pinMode(MOTOR_B_IA, OUTPUT);
  pinMode(MOTOR_B_IB, OUTPUT);
  stopMotors();

  // Configuración de Bluetooth
  BTSerial.begin(9600);

  // Demo texto en OLED
  oled.clear();
  oled.setFontX2(FONT6X8P);
  oled.setCursor(16, 1);
  oled.print("(Argenis");
  oled.on();
  delay(500);
  WhatsUp(); // Animar ojos al inicio 
}
// Funciones de control del motor
void moveForward() {
  digitalWrite(MOTOR_A_IA, HIGH);
  digitalWrite(MOTOR_A_IB, LOW);
  digitalWrite(MOTOR_B_IA, HIGH);
  digitalWrite(MOTOR_B_IB, LOW);
}

void moveBackward() {
  digitalWrite(MOTOR_A_IA, LOW);
  digitalWrite(MOTOR_A_IB, HIGH);
  digitalWrite(MOTOR_B_IA, LOW);
  digitalWrite(MOTOR_B_IB, HIGH);
}

void turnLeft() {
  digitalWrite(MOTOR_A_IA, LOW);
  digitalWrite(MOTOR_A_IB, HIGH);
  digitalWrite(MOTOR_B_IA, HIGH);
  digitalWrite(MOTOR_B_IB, LOW);
}

void turnRight() {
  digitalWrite(MOTOR_A_IA, HIGH);
  digitalWrite(MOTOR_A_IB, LOW);
  digitalWrite(MOTOR_B_IA, LOW);
  digitalWrite(MOTOR_B_IB, HIGH);
}

void stopMotors() {
  digitalWrite(MOTOR_A_IA, LOW);
  digitalWrite(MOTOR_A_IB, LOW);
  digitalWrite(MOTOR_B_IA, LOW);
  digitalWrite(MOTOR_B_IB, LOW);
}

// Configuración inicial

  


// Bucle principal
void loop() {
  // Control de Bluetooth
  if (BTSerial.available()) {
    char command = BTSerial.read();
    processCommand(command);
  }

  // Lógica de ojos (puede incluir inputs analógicos o digitales si lo deseas)
  digital = digitalRead(PB1);
  analog2 = analogRead(A2);
  analog3 = analogRead(A3);

  if (analog2 < 50) {
    if (xpos < 3) xpos++;
  }
  if (analog3 < 50) {
    if (xpos > 0) xpos--;
  }
  if (digital == false) {
    ypos--;
  } else {
    ypos++;
  }

  // Asegurar límites de los ojos
  if (xpos == 0 || xpos == 3) {
    if (ypos < 2) ypos = 2;
    if (ypos > 4) ypos = 4;
  } else {
    if (ypos < 1) ypos = 1;
    if (ypos > 5) ypos = 5;
  }

  if (xpos != old_xpos || ypos != old_ypos) {
    DrawEyes(xpos);
    sleeping = 0;
  } else {
    sleeping++;
    if (sleeping > 100) {
      WhatsUp();
      sleeping = 0;
    }
  }

  delay(100);
}
void processCommand(char command) {
  switch (command) {case 'F': // Adelante
      moveForward();
      BTSerial.println("Avanzando");
      break;
    case 'B': // Atrás
      moveBackward();
      BTSerial.println("Retrocediendo");
      break;
    case 'I': // Girar izquierda
      turnLeft();
      BTSerial.println("Girando izquierda");
      break;
    case 'D': // Girar derecha
      turnRight();
      BTSerial.println("Girando derecha");
      break;
    case 'S': // Detener
      stopMotors();
      BTSerial.println("Motores detenidos");
      break;

    default:
      BTSerial.println("Comando no reconocido");
      break;
  }
}


void DrawEyes   (int i){   // 0-3 = left to right 
  if (flat){
  //oled.bitmap (START X IN PIXELS, START Y IN ROWS OF 8 PIXELS, END X IN PIXELS, END Y IN ROWS OF 8 PIXELS, IMAGE ARRAY);
    oled.bitmap ((i*8)         ,0,48+(i*8)   ,8,      oflat);     //48x64 
    oled.bitmap ((i*8)+56      ,0,48+(i*8)+56,8,      oflat);
    oled.bitmap ((i*12)+10,ypos,(i*12)+26    ,ypos+1, pupilhalf); //16x8
    oled.bitmap ((i*12)+66,ypos,(i*12)+82    ,ypos+1, pupilhalf);
  }else {     
    if   (ypos==4&&(xpos==3||xpos==0)){
      if (xpos==3){      
        oled.bitmap ((i*8)         ,0,(i*8)+48   ,8,      winkl);     //48x64 
        oled.bitmap ((i*8)+56      ,0,(i*8)+104  ,8,      winkl);
      } else {
        oled.bitmap ((i*8)         ,0,(i*8)+48   ,8,      winkr);     //48x64 
        oled.bitmap ((i*8)+56      ,0,(i*8)+104  ,8,      winkr);
      }
    } else {
      if (ypos==1){
        oled.bitmap   ((i*8)       ,0,(i*8)+48   ,8,      oflat);     //48x64 
        oled.bitmap   ((i*8)+56    ,0,(i*8)+104  ,8,      oflat);
      } else {
        oled.bitmap   ((i*8)       ,0,(i*8)+48   ,8,      eye);       //48x64 
        oled.bitmap   ((i*8)+56    ,0,(i*8)+104  ,8,      eye);
      }
    }
    oled.bitmap     ((i*12)+10,ypos,(i*12)+26    ,ypos+2, pupil);     //16x16
    oled.bitmap     ((i*12)+66,ypos,(i*12)+82    ,ypos+2, pupil);
  }
  #ifdef Use_Tiny
    oled.on     ();
  #endif  
  old_xpos=xpos;
  old_ypos=ypos;
}

void WhatsUp(){
  oled.clear();  
  xpos=0;ypos=2;DrawEyes(xpos);
  delay(500);
  xpos=1;ypos=1;DrawEyes(xpos);
  delay(250);
  xpos=2;ypos=1;DrawEyes(xpos);
  delay(250);
  xpos=3;ypos=2;DrawEyes(xpos);
  delay(500);
  oled.clear();  
  xpos=2;ypos=5;DrawEyes(xpos);
}