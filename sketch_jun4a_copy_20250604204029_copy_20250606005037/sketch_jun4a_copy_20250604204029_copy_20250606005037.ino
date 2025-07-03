const int ledPin = 7;
const int buttonPin = 2;

int brightnessLevels[] = {0, 90, 200, 300};  // PWM values for Off, Low, Med, High
int currentLevel = 0;
int lastButtonState = LOW;
bool buttonPressed = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  // Detect a press (LOW to HIGH transition)
  if (buttonState == HIGH && lastButtonState == LOW && !buttonPressed) {
    buttonPressed = true;
    currentLevel = (currentLevel + 1) % 4;  // Cycle through 0-1-2-3-0
    analogWrite(ledPin, brightnessLevels[currentLevel]);
    delay(50);  // debounce delay
  }

  // Wait until button is released to allow next press
  if (buttonState == LOW) {
    buttonPressed = false;
  }

  lastButtonState = buttonState;
}
