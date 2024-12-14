// C++ code
// This is not working in Tinkercad because the DHT.h in not included.

#include <LiquidCrystal_I2C.h>


// Initialize the LCD with I2C address 0x27 (common address)
LiquidCrystal_I2C lcd(0x27, 16, 2);


int redLED = 13;
int blueLED = 12;
int photor = A3;
int sensor;

const int threshold = 500;

void setup()
{
  Serial.begin(9600);
  
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
 
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop()
{
  sensor = analogRead(photor);
  Serial.println(sensor);
  delay(100);
  
  
  if(sensor < threshold)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, LOW);
    delay(100);
    lcd.clear(); 
    lcd.print("Good night!"); 
  }
  else
  {
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
    delay(100);
    lcd.clear(); 
    lcd.print("Good morning!"); 
  }
}
