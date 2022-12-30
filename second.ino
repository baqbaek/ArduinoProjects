// C++ code
//
int zm1,zm2,zm3 = 0; //DEKLARACJA ZMIENNYCH
void setup() //DEKLARACJA UZYWANYCH PINOW
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
  zm1 = 250;
  zm2 = 1;
  zm3 = 1;
}
void loop()
{

 for (zm3 = 0; zm3 < 10; zm3++){ //PETLA POWTARZAJACA SIE 10X
     for (zm2 = 1; zm2 < 11; zm2++){ //PETLA ZALACZAJACE LAMPKI W KOLEJNOSCI
         for(int i = 0; i < zm3; i++){ //PETLA ODPOWIADAJCA ZA ILOSC POWTORZEN WLACZENIA DIODY
              digitalWrite(zm2, HIGH);
              delay(zm1); //OPOZNIENIE
              digitalWrite(zm2, LOW);
              delay(zm1);
         }
     }
 }
}
 
