/*
  Student: Dondon Herrera
  Due: December 06, 2024
  Activity: Arduino Code
*/


// CalcAreaOfCircle
/* Complete this function so that it computes and returns the  // area of a circle given the radius.
    Hint: look up how to do exponentiation in Arduino C.
    Hint: look up how to represent Pi in Arduino C (no it is not // 22/7).
  References:
    https://docs.arduino.cc/language-reference/en/functions/math/pow/
    https://forum.arduino.cc/t/pi-in-arduino/173649
*/
float CalcAreaOfCircle(float Radius) {
  float Answer = PI * pow(Radius, 2);
  return (Answer);
}

//
// CalcFactorial
/* Complete this function so that it returns the factorial of  // Value.
    Hint: look up what a factorial is if you don't remember.
    Hint: look up what an "edge case" means.
    Hint: look at the preceding function for how to return a    // value.
    Hint: look up how a while loop works.
  References:
    https://www.mathsisfun.com/numbers/factorial.html
    https://white-test.com/for-qa/useful-articles-for-qa/what-is-an-edge-case-in-software-testing/
*/
unsigned int CalcFactorial(unsigned int Value) {
  // Test for edge case where Value is at or below zero. If so, return zero.
  if (Value <= 0) return 0;

  // Ok, we know Value is at least one so we can start multiplying factors. Create an unsigned int variable called Answer and set its initial value to 1.
  unsigned int Answer = 1;

  // Keep going as long as Value is greater than zero and keep multiplying factors. Use a while loop to keep repeating this step until Value hits zero.
  while (Value > 0) {
    // Multiply Answer times Value and place the result in Answer.
    Answer *= Value;
    // Subtract one from Value and place the result in Value.
    Value--;
  }

  // Return final result.
  return (Answer);
}



// CalcSlopeAndIntercept
/* Complete this function so it calculates the slope and       // intercept of a line based on two points.
      Notice that it uses pass-by-reference variables for Slope and // Intercept.
      Hint: review "pass by reference" to ensure you understand how // it works.
      Hint: look up what it means to return "void" from a function.
      Hint: look up how to calculate the absolute value of a number // in Arduino C.
    References:
      https://docs.arduino.cc/language-reference/en/functions/math/abs/
*/
void CalcSlopeAndIntercept(float X1, float Y1, float X2, float Y2, float &Slope, float &Intercept) {
  // Set the Slope and Intercept return parameters to zero before we do anything else.
  Slope = 0;
  Intercept = 0;

  // Test for edge case where X2-X1 is zero (slope is undefined, line is vertical). If we detect this edge case, just return immediately. Remember we are not supposed to compare floating point values (conversion errors). Instead, calculate the absolute value of the difference between X2 and X1, and test if it is "close" to zero.
  float Difference = abs(X2 - X1);
  if (Difference < 0.00001) return;

  // Ok, we know we have a non-zero run, so let's calculate it, along with rise.
  float Rise = Y2 - Y1;
  float Run = X2 - X1;

  // Slope is rise over run.
  Slope = Rise / Run;

  // Intercept is y - mx, using (X1, Y1) for (x, y).
  Intercept = Y1 - (Slope * X1);
}

// -------------------------------------------------------------// -------------------------------------------------------------
// Don't change anything after this point. It's the usual Arduino setup() and loop() functions
// but with some test code added.
//
//
// setup()
//
void setup()
{
  Serial.begin(9600);
  Serial.println("Arduino Code Practice");
  Serial.print("Area of circle with radius 5 = ");
  Serial.println(CalcAreaOfCircle(5));
  Serial.print("Factorial of 5 = ");
  Serial.println(CalcFactorial(5));
  float Slope;
  float Intercept;
  Serial.print("Line through (1.5, 2.75) and (3.65, 9.25) has slope, intercept = ");
  CalcSlopeAndIntercept(1.5, 2.75, 3.65, 9.25, Slope, Intercept);
  Serial.print(Slope); Serial.print(", "); Serial.println(Intercept);
  Serial.println();
}
//
// loop()
//
void loop()
{ }
