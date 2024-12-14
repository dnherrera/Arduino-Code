
/*
  Fade an LED up and down once using For loop
  Dondon Herrera
  TECH1102
*/
int redLED = 5;

void setup() {
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
  
  // Fade up
  for (int i = 0; i <= 255; i++) {
    Serial.println(i);
    analogWrite(redLED, i);
    delay(20); 
  }
  
  // Fade down
  for (int i = 100; i >= 0; i--) {
    Serial.println(i);
    analogWrite(redLED, i); 
    delay(20);
  }
}

void loop() {
  
}
