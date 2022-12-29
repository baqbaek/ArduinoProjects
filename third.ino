int licznik = 0;	//DEKLARACJA ZMIENNYCH
int dioda = 0;

void setup()	//DEKLARACJA UZYWANYCH PINOW
{
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  

  
}

void loop()
  
{
  if (digitalRead(0) == 0) {	//PETLA WLACZAJACA DIODE, INKREMENTUJACA SIE. PIERWSZY PRZYCISK
    licznik = licznik + 1;
    dioda = dioda + 1;
    while (digitalRead(0) == 0) {
    }
    if (licznik == dioda) {		//SPRAWDZANIE KTORA DIODA MA SIE WLACZYC
      digitalWrite(dioda, HIGH);	//WLACZENIE DIODY
      digitalWrite(dioda - 1, LOW);		//WYLACZENIE POPRZEDNIEJ DIODY
    }
  }
  if (digitalRead(1) == 0) { //PETLA WLACZAJCA DIODE, DEKREMETUJACA SIE. DRUGI PRZYCISK
    licznik = licznik - 1;		
    dioda = dioda - 1;
    while (digitalRead(1) == 0) {
    }
    if (licznik == dioda) {		//SPRAWDZANIE KTORA DIODA MA SIE WLACZYC A KTORA WYLACZYC
      digitalWrite(dioda, HIGH);	//WLACZENIE DIODY
      digitalWrite(dioda + 1, LOW);		//WYLACZENIE DIODY
    }
  }
  delay(10); // OPOZNIENIE
}