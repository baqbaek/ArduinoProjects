#include <Adafruit_NeoPixel.h>

#define LED_PIN 2  // Pin podłączony do paska LED
#define NUM_LEDS 12  // Liczba diod na pasku LED
#define COLOR_POT A0  // Pin podłączony do potencjometru koloru
#define SPEED_POT A1  // Pin podłączony do potencjometru szybkości

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int currentLED = 0;  // Aktualnie wyświetlana dioda
int counter = 0;  // Licznik szybkości zmian diod

struct Color {
  int red;
  int green;
  int blue;
};

// Tablica z definicjami kolorów
Color colors[] = {
  {255, 0, 0},   // Czerwony
  {255, 255, 0}, // Żółty
  {0, 255, 255}, // Jasnoniebieski
  {255, 255, 255}, // Biały
  {0, 192, 0}, // Zielony
  {100, 100, 100},   // Jasnoszary
  {255, 0, 255},   // Fioletowy
  {0, 255, 0},   // Zielony
  {255, 255, 255},   // Biały
  {192, 192, 192},   // Szary
  {128, 128, 128},   // Ciemnoszary
  {64, 64, 64},   // Ciemniejszy szary
  {255, 160, 15}, // Pomarańczowy
  {160, 128, 96}, // Brązowy
  {255, 96, 208}, // Różowy
  {0, 0, 255}, // Niebieski
  {100, 100, 100} // Jasnoszary
  };
int numColors = sizeof(colors) / sizeof(Color); // Liczba dostępnych kolorów

void setup() {
strip.begin();
strip.show();

pinMode(COLOR_POT, INPUT);
pinMode(SPEED_POT, INPUT);
}

void loop() {
// Odczyt wartości z potencjometrów
int color = map(analogRead(COLOR_POT), 0, 1023, 0, numColors - 1);
int speed = map(analogRead(SPEED_POT), 0, 1023, 0, 9);

// Ustawienie diod LED według aktualnie wybranego koloru
for (int i = 0; i < NUM_LEDS; i++) {
if (i == currentLED) {
// Ustawienie aktualnie wyświetlanej diody
strip.setPixelColor(i, colors[color].red, colors[color].green, colors[color].blue);
} else {
// Wyłączenie pozostałych diod
strip.setPixelColor(i, 0, 0, 0);
}
}
strip.show();

// Zwiększenie licznika szybkości zmian diod
counter++;
// Sprawdzenie, czy należy zmienić kolor na następny
if (counter >= speed) {
// Zresetowanie licznika
counter = 0;
  // Zmiana na następny kolor
currentLED++;
if (currentLED >= NUM_LEDS) {
  currentLED = 0;
}
  }

// Opóźnienie
delay(10);
}
