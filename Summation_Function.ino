#include <Arduino.h>

void setup() {
  Serial.begin(9600);

  Serial.println("Enter the total number of inputs:");
  while (!Serial.available());
  int totalNumbers = Serial.parseInt();
  
  int sum = 0;
  for (int i = 0; i < totalNumbers; i++) {
    Serial.print("Input number ");
    Serial.print(i + 1);
    Serial.print(": ");
    while (!Serial.available());
    int number = Serial.parseInt();
    sum += number;
  }
  
  float average = (float)sum / totalNumbers;
  Serial.print("Total Sum: ");
  Serial.println(sum);
  Serial.print("Average: ");
  Serial.println(average);
}

void loop() {
  // No need to loop anything
}
