int licznik = 0;	//DEKLARACJA ZMIENNYCH
int los = random(1,10);	//ZMIENNA LOSOWA OD 1 DO 10

void setup()	//DEKLARACJA PINOW
{
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  if (digitalRead(1) == 0) {	//PRZYCISK ZLICZAJACY
    licznik = licznik + 1;		//INKREMENTACJA PRZYCISNIEC
  }
  while (digitalRead(1) == 0) {
  }
  	
  if (digitalRead(0) == 0) {	//PRZYCISK SPRAWDZAJACY
    if (licznik == los){		//SPRAWDZANIE ODGADNIECIA
      digitalWrite(2, HIGH);	//WLACZENIE DIODY ZIELONEJ
      digitalWrite(3, LOW);		//WYLACZENIE DIODY CZERWONEJ
    }else{
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW); //WLACZENIE DIODY CZERWONEJ
    }
   while (digitalRead(1) == 0) {
  }
    delay(10); //OPOZNIENIE
  }
}