#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Initialize the LCD with I2C address 0x27 (common address)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define dhtPin A0
#define dhtType DHT11

DHT HumidityTemp(dhtPin, dhtType);

float Humidity;
float Temp;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight

  HumidityTemp.begin(); // Initialize DHT sensor
  delay(1000); // Wait for sensor to stabilize
}

void loop() {
  Humidity = HumidityTemp.readHumidity();
  Temp = HumidityTemp.readTemperature();
  
  // Display humidity and temperature on the LCD
  lcd.clear(); // Clear previous content
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(Humidity);
  lcd.print("%");
  
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(Temp);
  lcd.print(" C");

  delay(1000);
  
}
