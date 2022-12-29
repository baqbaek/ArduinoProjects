#include <LiquidCrystal.h>

int seconds = 0; //DEKLARACJA ZMIENNYCH
double temp;
double max_temp;
int sensorInput;
int swiatlo;
int max_swiatlo;
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()  //DEKLARACJA PINOW
{
  lcd_1.begin(16, 2);
  pinMode(A0, INPUT);
  pinMode(A5, INPUT);
  pinMode(6, INPUT);
}

void loop()
{
  max_temp = temp;
  sensorInput = analogRead(A5); //ODCZYT TEMPERATURY
  temp = (double)sensorInput / 1024; 
  temp = temp * 5;  // ZAMIANA NA STOPNIE
  temp = temp - 0.5;
  temp = temp * 100; 
    
  lcd_1.setCursor(0, 0);  //USTAWIENIE KURSORA
  lcd_1.print(temp);  //WYDRUKOWANIE TEMPERATURY
  
  if(temp > max_temp){  //WARUNEK ZAPISANIA
  lcd_1.setCursor(0, 1); //MAX TEMPERATURY
  lcd_1.print(max_temp);
  }
  
  max_swiatlo = swiatlo;
  int x = analogRead(A0); //ODCZYT SWIATLA
  swiatlo = map(x, 0, 1023, 0, 100); //DEKLARACJA PROCENTOW 
  
  if (swiatlo > max_swiatlo){ //WARUNEK ZAPISANIA
    lcd_1.setCursor(13, 1);  //MAX SWIATLA
    lcd_1.print(swiatlo);
    lcd_1.setCursor(15, 1);
    lcd_1.print('%');
  }
  
  lcd_1.setCursor(13, 0);
  lcd_1.print(swiatlo);
  lcd_1.setCursor(15, 0);
  lcd_1.print('%');
  delay(200);
  
  if (digitalRead(6) == 0) {  //PRZYCISK RESETU
    lcd_1.setCursor(0, 0);
    lcd_1.print(0);
    lcd_1.setCursor(0, 1);
    lcd_1.print(0);
    lcd_1.setCursor(13, 0);
    lcd_1.print(0);
    lcd_1.setCursor(13, 1);
    lcd_1.print(0);
  }
    while (digitalRead(6) == 0) {
  }
  
}
