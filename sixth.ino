#include <Servo.h>

Servo servo_0;

void setup()	//DEKLARACJA PINOW
{
  pinMode(A0, INPUT);
  servo_0.attach(0, 500, 2500);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop()
{
  if (analogRead(A0) >= 256) {	//WARUNEK PRZESUNIECIA O 22.5 STOPNIA GDY 
    servo_0.write(22.5);		//NAPIECIE WYNOSI 1.25V
  } else {
    servo_0.write(0);			//W PRZECIWNYM RAZIE WRACA DO POCZATKU
  }
  if (analogRead(A1) >= 511) {	//WARUNEK PRZESUNIECIA O 50 STOPNIA GDY
    servo_0.write(50);			//NAPIECIE WYNOSI 2.5V
  }
  if (analogRead(A2) >= 767) {	//WARUNEK PRZESUNIECIA O 72.5 STOPNIA GDY
    servo_0.write(72.5);		//NAPIECIE WYNOSI 3.75V
  }
  if (analogRead(A3) >= 1023) {	//WARUNEK PRZESUNIECIA O 90 STOPNIA GDY
    servo_0.write(90);			//NAPIECIE WYNOSI 5V
  }
  delay(10);		
}
//ZAOBRSEROWALEM ZE WARTOSCI PODCZAS POROWNYWANIA NIE MOGA WYNOSIC POTEGI
//LICZBY 256 TYLKO WARTOSC ZMNIEJSZONA O JEDEN. 