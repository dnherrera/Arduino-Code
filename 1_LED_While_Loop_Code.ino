/*
  Fade an LED up and down using While loop
  Dondon Herrera
  TECH1102
*/
int redLED = 5;

void setup() {
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int x = 0; 

  // Fade up
  while (x <= 255) { 
    Serial.println(x);
    analogWrite(redLED, x);
    delay(40);
    x += 4; // Increment x by 4
  }

  // Fade down
  while (x >= 0) { 
    Serial.println(x);
    analogWrite(redLED, x); 
    delay(40);
    x -= 4; 
  }
}
