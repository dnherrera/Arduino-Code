void setup() {
  // Start the serial communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("Enter a number:");
}

void loop() {
  // Check if there are incoming bytes available to read
  if (Serial.available() > 0) {

    String inputString = Serial.readStringUntil('\n');
    int number = ReadFunction(inputString);
    
    int square = SquareFunction(number);

    
    DisplayResult(number, square);
    
  }
}

int ReadFunction(String input){
   // Read the incoming string and convert it to an integer
    int number = input.toInt();
    return number;
}

int SquareFunction(int number){
  // Calculate the square of the number
    int square = number * number;
    return square;
}

void DisplayResult(int number, int square){
  // Print the result
    Serial.print("The square of ");
    Serial.print(number);
    Serial.print(" is ");
    Serial.println(square);
}
