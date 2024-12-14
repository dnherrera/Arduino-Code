/*
  Fade an LED up and down for 2 minutes &nbsp;using while loop (optional).
  Dondon Herrera
  TECH1102
*/

int ledPin = 9; 
int brightness = 0; 
int fadeAmount = 5;
unsigned long startTime; 
unsigned long duration = 120000;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  startTime = millis();
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - startTime < duration) {
    
    while (brightness < 255) {
      simulateDigitalFade(ledPin, brightness); 
      Serial.println(brightness);
      brightness += fadeAmount; 
      delay(20); 
    }

    while (brightness > 0) {
      simulateDigitalFade(ledPin, brightness);
      Serial.println(brightness);
      brightness -= fadeAmount; 
      delay(20); 
    }

    brightness = 0;
    
  } else {
    digitalWrite(ledPin, LOW);
    while (true); 
  }
}

void simulateDigitalFade(int pin, int brightness) {
  int onTime = map(brightness, 0, 255, 0, 10); 
  int offTime = 10 - onTime;                 
  
  digitalWrite(pin, HIGH);
  delay(onTime);          
  
  digitalWrite(pin, LOW); 
  delay(offTime);         
}
