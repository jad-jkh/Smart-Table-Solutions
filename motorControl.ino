#define DOWN_BTN PB12
#define UP_BTN PB15
#define ENABLE PA6  // EN
#define MOTOR_CONTROL PA5  // PH
#define LED_RESERVE PB7

void setup() {
  // BUTTON PIN CONFIGURATION
  pinMode(DOWN_BTN, INPUT_PULLUP);
  pinMode(UP_BTN, INPUT_PULLUP);
  
  // MOTOR DRIVER PIN OUTPUT
  pinMode(ENABLE, OUTPUT);
  pinMode(MOTOR_CONTROL, OUTPUT);
  
  // RESERVED PIN, THIS TABLE DID NOT USE
  pinMode(LED_RESERVE, OUTPUT);
  
  // MOTOR INITIALIZED STOPPED
  digitalWrite(ENABLE, LOW);
  digitalWrite(MOTOR_CONTROL, LOW);
}

void loop() {

  if (digitalRead(DOWN_BTN) == LOW && digitalRead(UP_BTN) == LOW) {
  // BOTH PRESSED, STOP
  digitalWrite(ENABLE, LOW);
  digitalWrite(MOTOR_CONTROL, LOW);
  }

  // CHECK DOWN BUTTON (active low)
  else if (digitalRead(DOWN_BTN) == LOW) {
    digitalWrite(ENABLE, HIGH);
    digitalWrite(MOTOR_CONTROL, LOW);   // PH = LOW
  }
  // CHECK UP BUTTON (pull high)
  else if (digitalRead(UP_BTN) == LOW) {
    digitalWrite(ENABLE, HIGH);
    digitalWrite(MOTOR_CONTROL, HIGH);  // PH = HIGH
  }
  // No button pressed - Stop
  else {
    digitalWrite(ENABLE, LOW);   // EN = LOW
    digitalWrite(MOTOR_CONTROL, LOW);   // PH = LOW
  }
  
  delay(10);  // DEBOUNCE 10MS
}



