int nap = 0;	//DEKLARACJA ZMIENNYCH
int dioda = 0;
void setup()	//DEKLARACJA PINOW
{
  pinMode(A0, INPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  if (analogRead(A0) >= nap + 1) {	//PETLA SPRAWDZAJACA CZY NAPIECIE ZOSTALO
    digitalWrite(dioda, HIGH);		//OSIAGNIETE JESLI TAK URUCHAMIA ODPOWIEDNIA DIODE
    nap = nap + 103;				//ZWIEKSZANIE ZMIENNEJ NAPIECIE
    dioda++;     					//INKREMENTACJA ODPOWIEDNIEJ DIODY
  } else {
      digitalWrite(dioda, LOW);		//WYLACZENIE DIODY W PRZYPADKU NIE OSIAGNIECIA
  	  nap = nap - 103;				//ODPOWIEDNIEGO NAPIECIA
  	  dioda--;
  }									
}