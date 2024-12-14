/*
  If-Statement
  Dondon Herrera
  TECH1102
*/

const int blueLED = 3;
const int redLED = 4;
const int greenLED = 5;
const int whiteLED = 6;
const int yellowLED = 9;

void setup() {
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

  Serial.begin(9600);

  Serial.println("Enter color (red, green, blue, yellow, white)");
}

void loop() {
  if (Serial.available() > 0) {
    String userInput = Serial.readString(); 
    userInput.trim();

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(whiteLED, LOW);

    if (userInput.equalsIgnoreCase("red")) 
    {
      digitalWrite(redLED, HIGH);
    } 
    else if (userInput.equalsIgnoreCase("green")) 
    {
      digitalWrite(greenLED, HIGH);
    } 
    else if (userInput.equalsIgnoreCase("blue")) 
    {
      digitalWrite(blueLED, HIGH);
    } 
    else if (userInput.equalsIgnoreCase("yellow")) 
    {
      digitalWrite(yellowLED, HIGH);
    } 
    else if (userInput.equalsIgnoreCase("white")) 
    {
      digitalWrite(whiteLED, HIGH);
    } 
    else 
    {
      Serial.println("Invalid input.");
    }
  }
}
