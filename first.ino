// C++ code
//
int zm1,zm2 = 0;			//DEKLARACJA ZMIENNYCH

void setup()				//DEKLARACJA UZYWANYCH PINOW
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
							//USTAWIANIE WARTOSCI POCZATKOWYCH ZM.
  zm1 = 1000;
  zm2 = 1;
}

void loop()
{
  for (zm2 = 1; zm2 < 11; zm2++){			 //PETLA ZALACZAJACE LAMPKI
  	digitalWrite(zm2, HIGH);
  	delay(zm1);
}
  for (zm2 = 10; zm2 > 0; zm2--){ 			//PETLA GASZCZACE LAMPKI
  	digitalWrite(zm2, LOW);
  	delay(zm1);
}
  zm1 = zm1/2;						//ZMINIEJSZANIE WARTOSCI O POLOWE
  if (zm1 == 250) {					//SPRAWDZANIE CZY NIE ZEJDZIE PONIZEJ 250
    zm1 = 1000;					//ABY ZAPOBIEC DRASTYCZNEMU PRZYSPIESZENIU
}
}
