// C++ code
/*
  Fade
  This example shows how to fade an LED on pin 9
  using the analogWrite() function.

  The analogWrite() function uses PWM, so if  you
  want to change the pin you're using, be  sure to
  use another PWM capable pin. On most  Arduino,
  the PWM pins are identified with   a "~" sign,
  like ~3, ~5, ~6, ~9, ~10 and ~11.
*/

int brightness = 0;

void setup()
{
  pinMode(0, OUTPUT);
}

void loop()
{
  for (brightness = 0; brightness <= 255; brightness += 1) {
    analogWrite(0, brightness);
    delay(5); // Wait for 100 millisecond(s)
  }
  for (brightness = 255; brightness >= 0; brightness -= 1) {
    analogWrite(0, brightness);
    delay(5); // Wait for 100 millisecond(s)
  }
}