#include "DHT.h"
#include <LiquidCrystal.h>

// Define the DHT sensor model and pin
#define DHTPIN A0     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT sensor type (DHT11 or DHT22)

// Initialize DHT sensor object
DHT dht(DHTPIN, DHTTYPE);

// Initialize LCD object with pins
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Humidity and Temperature");

  // Initialize DHT sensor
  dht.begin();

  // Initialize LCD
  lcd.begin(16, 2);  // Set LCD dimensions (16 columns x 2 rows)
  lcd.clear();       // Clear the LCD screen
  lcd.print("Temp: ");
  lcd.setCursor(9, 0);
  lcd.print("Humid: ");
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read temperature and humidity from DHT sensor
  float temperature = dht.readTemperature();  // Read temperature in Celsius
  float humidity = dht.readHumidity();        // Read humidity as percentage

  // Check if any reads failed and exit early (to try again)
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Print successful temperature and humidity readings to Serial Monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Display temperature and humidity on LCD
    lcd.setCursor(6, 0);   // Set LCD cursor position for temperature display
    lcd.print(temperature);
    lcd.print(" C");

    lcd.setCursor(8, 1);   // Set LCD cursor position for humidity display
    lcd.print(humidity);
    lcd.print(" %");
  }
}
