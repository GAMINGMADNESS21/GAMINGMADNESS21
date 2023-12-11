// This code reads the push buttons from right arm and left arms and blink the respective LEDs
// constants won't change. They're used here to set pin numbers:
// Used analog PINs for reading push buttons. I had to use a resistor with ground for digital read for push buttons. So, I decided to use analog read and used a threshold in the code to detect if the button is pressed.
const int rightPin = A0;  // the number of the push button pin for right button, please see comments above for using analog read.
const int leftPin = A1;  // the number of the push button pin for left
const int ledPinRight = 2;    // the number of the LED pin
const int ledPinLeft = 4;    // the number of the LED pin
const int ledPinCent = 6;    // to NeoPixels

// variables will change:
int rButtonState = 0;  // variable for reading the pushbutton status
int lButtonState = 0;  // variable for reading the pushbutton status
int toggleR = 0;
int toggleL = 0;
void setup() {
   digitalWrite(ledPinCent, HIGH); // Red LED on the back of the jacket, this will be on all the time

  Serial.begin(9600); // for debugging purpose
  pinMode(rightPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(ledPinRight, OUTPUT);
  pinMode(ledPinLeft, OUTPUT);
  pinMode(ledPinCent, OUTPUT);
}

void loop() {
   // read the state of the Right pushbutton value:
  //=========================================================================

  rButtonState = analogRead(rightPin);
  //    Serial.println(rButtonState);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (rButtonState > 1000) {

    if (toggleR == 0){
    digitalWrite(ledPinRight, HIGH);
    toggleR = 1;
   // Serial.println(toggleR);
    delay(10);      // pause
    }
    else
    {
      digitalWrite(ledPinRight, LOW);
          toggleR = 0;
     //     Serial.println(toggleR);
          delay(10);      // pauses for 50 microseconds

    }
    // turn LED on:
  }
    else {
    // turn LED off:
    digitalWrite(ledPinRight, LOW);
 
}
  // read the state of the Left pushbutton value:
  //==========================================================================
  lButtonState = analogRead(leftPin);
      Serial.println(lButtonState);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (lButtonState > 1000) {

    if (toggleL == 0){
    digitalWrite(ledPinLeft, HIGH);
    toggleL = 1;
    Serial.println(toggleL);
    delay(10);      // pauses for 50 microseconds
    }
    else
    {
      digitalWrite(ledPinLeft, LOW);
          toggleL = 0;
          Serial.println(toggleL);
          delay(10);      // pauses for 50 microseconds

    }
    // turn LED on:
  }
    else {
    // turn LED off:
    digitalWrite(ledPinLeft, LOW);
 
}
          delay(500);      // pauses for 50 microseconds

}