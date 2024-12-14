#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD with I2C address 0x27 (common address)
DHT dht(DHTPIN, DHTTYPE);

int soilMoisturePin = A0; // Use A0 for analog input
int lightSensorPin = A3;
int ledRedPin = 13;
int ledGreenPin = 11;
int ledBluePin = 12;
int buzzerPin = 8;
int relayPin = 7;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  lcd.setCursor(0, 0);
  
  dht.begin(); // Initialize DHT sensor
  delay(1000); // Wait for sensor to stabilize 
  
  pinMode(soilMoisturePin, INPUT);
  pinMode(lightSensorPin, INPUT);
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT); 
  digitalWrite(relayPin, LOW); // Ensure relay is off initially
  
  servo.attach(servoPin);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  int soilMoisture = analogRead(soilMoisturePin); // Read analog value
  int lightLevel = analogRead(lightSensorPin);

  String message = "";
  // Determine the message to scroll
  if (soilMoisture > 400) {
    message += "Water me! ";
    digitalWrite(ledRedPin, HIGH);
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(relayPin, HIGH); // Turn on relay (and water pump)
  } else if (temperature < 15 || temperature > 30) {
    message += "Temperature Issue! ";
    digitalWrite(ledRedPin, HIGH);
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(relayPin, LOW);
  } else {
    message += "I am happy! ";
    digitalWrite(ledGreenPin, HIGH);
    digitalWrite(ledRedPin, LOW);
    digitalWrite(relayPin, LOW); // Turn off relay (and water pump)
  }

  if (lightLevel < 300) {
    message += "Need more light ";
    digitalWrite(ledBluePin, LOW);
  } else {
    message += "Light is good ";
    digitalWrite(ledBluePin, HIGH);
  }

  // Scroll the message
  for (int i = 0; i < message.length(); i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message.substring(i, min(i + 16, message.length())));
    lcd.setCursor(0, 1);
    lcd.print("S: ");
    lcd.print(soilMoisture);
    lcd.print(" T: ");
    lcd.print(temperature);
    lcd.print("C");

    delay(300); // Scrolling speed
  }
}
