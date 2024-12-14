#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 5
#define ECHO_PIN 4
#define RED_LED 8
#define GREEN_LED 7
#define BUTTON_PIN 6
#define SERVO_PIN 9

const int distanceThreshold = 5;

Servo gateServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  gateServo.attach(SERVO_PIN);
  gateServo.write(0);
  lcd.init();
  lcd.backlight();
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print("Car Park System");
  delay(2000);
  lcd.clear();
}

void loop() {
  int distance = measureDistance();

  if (distance < distanceThreshold) {
    carDetectedSequence();
  } else {
    waitingForCarSequence();
  }

  delay(100);
}

int measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  return duration * 0.034 / 2;
}

void carDetectedSequence() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome");
  lcd.setCursor(0, 1);
  lcd.print("Get Ticket");
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);

  if (digitalRead(BUTTON_PIN) == HIGH) {
    ticketIssuedSequence();
  }
}

void ticketIssuedSequence() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ticket Issued!");
  lcd.setCursor(0, 1);
  lcd.print("Proceed");
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);

  openGate();
  delay(3000);
  closeGate();

  digitalWrite(GREEN_LED, LOW);
}

void waitingForCarSequence() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Waiting for Car");
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void openGate() {
  for (int pos = 0; pos <= 90; pos += 5) {
    gateServo.write(pos);
    delay(15);
  }
}

void closeGate() {
  for (int pos = 90; pos >= 0; pos -= 5) {
    gateServo.write(pos);
    delay(15);
  }
}
