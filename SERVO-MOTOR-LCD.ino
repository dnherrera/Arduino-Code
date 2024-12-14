#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo MyServoMotor;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialize the LCD with I2C address 0x27 and 16x2 characters

int a; // The degree where the arm is positioning

void setup() {
    Serial.begin(9600); // Initialize serial communication
    MyServoMotor.attach(5); // Attach the servo motor to pin 5
    pinMode(7, OUTPUT); // Green LED
    pinMode(8, OUTPUT); // Red LED
    lcd.init(); // Initialize the LCD
    lcd.backlight(); // Turn on the backlight
}

void loop() {
    movingServoMotor90Degree();
    movingServoMotor180Degree();
}

void movingServoMotor180Degree() {
    for (a = 0; a <= 180; a += 1) {
        MyServoMotor.write(a);
        Serial.println(a);

        // Update LCD with the current angle
        lcd.clear(); // Clear previous content
        lcd.setCursor(0, 0); // Set cursor to the first row
        lcd.print("Angle: ");
        lcd.print(a);

        if (a > 90) {
            digitalWrite(8, HIGH); // Turn on Red LED
            digitalWrite(7, LOW);  // Turn off Green LED
        } else {
            digitalWrite(7, HIGH); // Turn on Green LED
            digitalWrite(8, LOW);  // Turn off Red LED
        }
         delay(50);
    }

    
}

void movingServoMotor90Degree() {
    for (a = 0; a <= 90; a += 1) {
        MyServoMotor.write(a);
        Serial.println(a);

        // Update LCD with the current angle
        lcd.clear(); // Clear previous content
        lcd.setCursor(0, 0); // Set cursor to the first row
        lcd.print("Angle: ");
        lcd.print(a);

        if (a < 90) {
            digitalWrite(7, HIGH); // Turn on Green LED
            digitalWrite(8, LOW);  // Turn off Red LED
        }
         delay(50);
    }

    
}
