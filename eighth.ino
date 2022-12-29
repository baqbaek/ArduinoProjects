
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); //DEKLARACJA ZMIENNYCH ORAZ GLOSNIKA
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()  //DEKLARACJA PINOW
{
  pinMode(A4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{ //PRAWY CZUJNIK -DZIALANIE KAZDEGO CZUJNIKA JEST TAKIE SAME
  if (0.01723 * readUltrasonicDistance(0, 0) < 200) { //WARUENK ZAPALENIA DIOD ZIELONYCH PRZY ODLEGLOSCI < 200CM
    while ((0.01723 * readUltrasonicDistance(0, 0) < 200)) { 
      delay(2000); 
      tone(A4, 523, 100); //ZAGRANIE DZWIEKU W TONIE 60 PRZEZ 0.1S
    }
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    delay(200); 
    if (0.01723 * readUltrasonicDistance(0, 0) < 100) { //WARUENK ZAPALENIA DIOD ZIELONYCH PRZY ODLEGLOSCI < 100CM
      while ((0.01723 * readUltrasonicDistance(0, 0) < 100)) {
        delay(1000); 
        tone(A4, 92, 100); //ZAGRANIE DZWIEKU W TONIE 30 PRZEZ 0.1S
      }
      digitalWrite(5, HIGH);
      digitalWrite(4, HIGH);
      delay(200); 
      if (0.01723 * readUltrasonicDistance(0, 0) < 50) { //WARUENK ZAPALENIA DIOD ZIELONYCH PRZY ODLEGLOSCI < 50CM
        delay(200); 
        while ((0.01723 * readUltrasonicDistance(0, 0) < 50)) {
          tone(A4, 52, 100); //ZAGRANIE DZWIEKU W TONIE 10 PRZEZ 0.1S
        }
        digitalWrite(3, HIGH);
      } else {
        digitalWrite(3, LOW);
      }
    } else {
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
    }
  } else {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
  } //DRUGI CZUJNIK SRODKOWY
  if (0.01723 * readUltrasonicDistance(1, 1) < 200) {
    while ((0.01723 * readUltrasonicDistance(1, 1) < 200)) {
      delay(2000); 
      tone(A4, 523, 100); 
    }
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    if (0.01723 * readUltrasonicDistance(1, 1) < 100) {
      while ((0.01723 * readUltrasonicDistance(1, 1) < 100)) {
        delay(1000); 
        tone(A4, 523, 100); 
      }
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      if (0.01723 * readUltrasonicDistance(1, 1) < 50) {
        while ((0.01723 * readUltrasonicDistance(1, 1) < 50)) {
          tone(A4, 523, 100); 
        }
        digitalWrite(8, HIGH);
      } else {
        digitalWrite(8, LOW);
      }
    } else {
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
    }
  } else {
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  } //LEWY CZUJNIK
  if (0.01723 * readUltrasonicDistance(2, 2) < 200) {
    while ((0.01723 * readUltrasonicDistance(2, 2) < 200)) {
      delay(2000);
      tone(A4, 523, 100); 
    }
    digitalWrite(A3, HIGH);
    digitalWrite(A2, HIGH);
    if (0.01723 * readUltrasonicDistance(2, 2) < 100) {
      while ((0.01723 * readUltrasonicDistance(2, 2) < 100)) {
        delay(1000);
        tone(A4, 523, 100); 
      }
      digitalWrite(A1, HIGH);
      digitalWrite(A0, HIGH);
      if (0.01723 * readUltrasonicDistance(2, 2) < 50) {
        while ((0.01723 * readUltrasonicDistance(2, 2) < 50)) {
          tone(A4, 523, 100); 
        }
        digitalWrite(13, HIGH);
      } else {
        digitalWrite(13, LOW);
      }
    } else {
      digitalWrite(A1, LOW);
      digitalWrite(A0, LOW);
    }
  } else {
    digitalWrite(A3, LOW);
    digitalWrite(A2, LOW);
  }
}
