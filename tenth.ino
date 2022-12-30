#include <Keypad.h>
#include <LiquidCrystal.h>

//LCD z połączeniami pinów
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// Zmienne do przechowywania operandów i wyniku
int first, second;
float total;
// Zmienna do przechowywania wciśniętego klawisza
char customKey;

// Układ klawiatury i połączenia pinów
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'=','0','C','/'}
};
byte rowPins[ROWS] = {7,6,5,4};
byte colPins[COLS] = {3,2,1,0};

// Inicjalizacja obiektu klawiatury
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup() {
  lcd.begin(16, 2);  // start LCD
  lcd.setCursor(0,0);
  lcd.print("KALKULATOR");  // Wyświetlenie tytułu na pierwszej linii
  lcd.setCursor(0,1);
  lcd.print("A+;B-;C*;D/;");  // Wyświetlenie dostępnych operacji na drugiej linii
  delay(3000);  // Czekaj 3 sekundy
  lcd.clear();  // Wyczyść ekran
  lcd.setCursor(0, 0);
}

void loop() {
  // Oczekiwanie na wciśnięcie klawisza
  customKey = customKeypad.getKey();
  
  // Sprawdzenie wciśniętego klawisza
  switch(customKey) {
    // Jeśli został wciśnięty klawisz z cyfrą, dodaj go do bieżącej wartości first
    case '0' ... '9': 
      lcd.setCursor(0,0);
      first = first * 10 + (customKey - '0');
      lcd.print(first);
      break;
      
    // Jeśli został wciśnięty +, wykonaj dodawanie
    case '+':
      lcd.setCursor(5,0);
      lcd.print("+");
      second = getSecondNumber(); // Pobierz drugą liczbę
      total = first + second;
      lcd.setCursor(0,3);
      lcd.print(total);
      first = 0, second = 0; // Wyzeruj wartości
      break;
      
    // Jeśli został wciśnięty -, wykonaj odejmowanie
    case '-':
      lcd.setCursor(5,0);
      lcd.print("-");
      second = getSecondNumber();
      total = first - second;
      lcd.setCursor(0,3);
      lcd.print(total);
      first = 0, second = 0;
      break;
      
    // Jeśli został wciśnięty *, wykonaj mnożenie
    case '*':
      lcd.setCursor(5,0);
      lcd.print("*");
      second = getSecondNumber();
      total = first * second;
      lcd.setCursor(0,3);
      lcd.print("/");
      second = getSecondNumber();
      lcd.setCursor(0,3);
    
    // Jeśli został wciśnięty /, wykoanj dzielenie
    case '/':
 	  lcd.setCursor(5,0);
      lcd.print("/");
      second = getSecondNumber();
      lcd.setCursor(0,3);

    // Sprawdzenie dzielenia przez zero
      if (second == 0) {
        lcd.print("Nieprawidłowe");
      } else {
        total = (float)first / (float)second;
        lcd.print(total);
      }
      first = 0, second = 0;
      break;

    case 'C':
      // Wyczyść ekran i wyzeruj wartości
      total = 0;
      lcd.clear();
      break;
  }
}

// Funkcja do pobierania drugiej liczby
long getSecondNumber() {
  while( 1 ) {
    customKey = customKeypad.getKey();
    if(customKey >= '0' && customKey <= '9') {
      second = second * 10 + (customKey - '0');
      lcd.setCursor(7,0);
      lcd.print(second);
      lcd.setCursor(15,0);
      lcd.print('=');
    }
    if(customKey == '=') break; 
  }
  return second; 
}