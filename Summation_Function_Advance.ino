void setup() {
  Serial.println("\nEnter the total number of inputs:");
  while (!Serial.available());
  totalNumbers = Serial.parseInt();

  sum = 0; 
  for (int i = 0; i < totalNumbers; i++) {
    Serial.print("Input number ");
    Serial.print(i + 1);
    Serial.print(": ");
    while (!Serial.available()); // Wait for input
    int number = Serial.parseInt();
    sum += number;
  }
  
  average = (float)sum / totalNumbers;
  Serial.print("Total Sum: ");
  Serial.println(sum);
  Serial.print("Average: ");
  Serial.println(average);
}

void loop() {
  // put your main code here, to run repeatedly:

}
