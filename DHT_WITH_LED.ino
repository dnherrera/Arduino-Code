#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address 0x27 (common address)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define dhtPin A0
#define dhtType DHT11
#define redLEDPin 8    // Pin for red LED
#define blueLEDPin 9   // Pin for blue LED

DHT HumidityTemp(dhtPin, dhtType);

float Humidity;
float Temp;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight

  pinMode(redLEDPin, OUTPUT);   // Set red LED pin as output
  pinMode(blueLEDPin, OUTPUT);  // Set blue LED pin as output

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

  // Check temperature and control red LED
  if (Temp >= 23) {
    digitalWrite(redLEDPin, HIGH); // Turn on red LED
  } else {
    digitalWrite(redLEDPin, LOW);  // Turn off red LED
  }

  // Check humidity and control blue LED
  if (Humidity >= 28) {
    digitalWrite(blueLEDPin, HIGH); // Turn on blue LED
  } else {
    digitalWrite(blueLEDPin, LOW);  // Turn off blue LED
  }

  delay(1000); // Wait for 1 second before updating the display
}
