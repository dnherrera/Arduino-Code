int count;
int sum;
void setup() 
{
  
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("How many numbers do you have?");
}

void loop() 
{
  if(Serial.available() > 0)
  {
    
    String input = Serial.readStringUntil('\n');
    
    if(count == 0)
    {
      count = input.toInt(); 
      
      inputValidation(count);
      
      int sumResult = processInput(count);
      
      displayResult(sumResult, count);
   
    }
  }
}

void inputValidation(int count)
{
  if(count > 0)
  {
    Serial.println("Enter the numbers: ");
  }
  else
  {
    Serial.println("Incorrect input");
  }
}

void displayResult(int sum, int count)
{
    Serial.print("The sum is ");
      Serial.print(sum);
      
      Serial.print("\n");
  
      Serial.print("The count is ");
      Serial.print(count);
    
      Serial.print("\n");
      
  
      Serial.print("The average is ");
      float average = (float)sum / count;
      Serial.print(average);
}

int processInput(int count)
{
  int sum = 0;
  
  for(int i = 0 ;  i < count; i++)
      {
        while(true)
        {
          if(Serial.available()> 0 )
          {
            String input = Serial.readStringUntil('\n');
            
            int number = input.toInt();
            Serial.println(number);
            
            sum = sum + number;
            
            break;
          }
        }
      }
  
  return sum;
}
