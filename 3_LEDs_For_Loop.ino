/*
  Connect 3 LEDs and make them to work one after the other using For loop
  Dondon Herrera
  TECH1102
*/

int redLED = 3;
int blueLED = 6;
int greenLED = 9;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i <= 20; i++) {
    Serial.println(i);
    
    digitalWrite(greenLED, LOW);  
    digitalWrite(redLED, LOW);    
    digitalWrite(blueLED, HIGH);  
    
    delay(500);
  }

  for (int i = 0; i <= 20; i++) {
    Serial.println(i);
    
    digitalWrite(greenLED, LOW); 
    digitalWrite(blueLED, LOW);  
    digitalWrite(redLED, HIGH);  
    
    delay(500); 
  }

  
  for (int i = 0; i <= 20; i++) {
    Serial.println(i);
    
    digitalWrite(redLED, LOW);    
    digitalWrite(blueLED, LOW);   
    digitalWrite(greenLED, HIGH); 
    
    delay(500);
  }
}
