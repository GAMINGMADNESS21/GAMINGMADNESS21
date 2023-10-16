#include "Keyboard.h"
  #include <Mouse.h>

  #define DEBOUNCE 50 // delay for ensuring that the sensor presses do not overlap
  
  // Variables that won't change

  // Sensor Pins
  const int sensorPin1 = A1; 
  const int sensorPin2 = A2; 
  const int sensorPin3 = A3; 
  const int sensorPin4 = A4;
  const int sensorPin5 = A5;
  const int sensorPin6 = A6;
  const int sensorPin7 = A7;     
  
  // Keyboard Functions
  const int keyboardKey1 = KEY_UP_ARROW;   
  const int keyboardKey2 = KEY_DOWN_ARROW;  
  const int keyboardKey3 = KEY_RETURN;         
  const int keyboardKey4 = KEY_LEFT_ARROW;   
  const int keyboardKey5 = KEY_RIGHT_ARROW;
  const int keyboardKey6 = ' '; 

// Change this to a threshold that makes sense for your sensor(s). Use Examples -> 01.Basics -> AnalogInputSerial to determine.

  const int threshold = 500;

// Variables that will change

  int sensorValue1 = 0;
  int sensorValue2 = 0;
  int sensorValue3 = 0;
  int sensorValue4 = 0;
  int sensorValue5 = 0;
  int sensorValue6 = 0;
  int sensorValue7 = 0;
 
  void setup() {
 
// initialize serial
  Serial.begin(9600);

  Mouse.begin();
  Keyboard.begin();
} 

void loop() {

  // read all sensor pins
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);
  sensorValue4 = analogRead(sensorPin4);
  sensorValue5 = analogRead(sensorPin5);
  sensorValue6 = analogRead(sensorPin6);
  sensorValue7 = analogRead(sensorPin7);

  // use the sensor values to control keyboard
  if  (sensorValue1 > threshold) {
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Keyboard.write(keyboardKey1);
      Serial.println("Sensor 1 Pressed - Up Key");
      // Right Glove - Index Finger
  } 

    sensorValue2 = analogRead(sensorPin2);
  if  (sensorValue2 > threshold) {
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Keyboard.write(keyboardKey2);
      Serial.println("Sensor 2 Pressed - Down Key");
      // Right Glove - Middle Finger 
  } 

  if  (sensorValue3 > threshold) {
      Keyboard.write(keyboardKey3);
      Serial.println("Sensor 3 - Enter Key");
      // Left Glove - Third Finger
  }

       sensorValue4 = analogRead(sensorPin4);
  if  (sensorValue4 > threshold) {
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);
      Keyboard.write(keyboardKey4);

      Mouse.move(0, 30, 0);
      Serial.println("Sensor 4 Pressed - Right Key");
      // Left Glove - Index Finger
  } 

      sensorValue5 = analogRead(sensorPin5);
  if (sensorValue5 > threshold) {
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);
      Keyboard.write(keyboardKey5);

    
      Mouse.move(0, -30, 0);
 
      Serial.println("Sensor 5 Pressed - Left Key");
      // Left Glove - Middle Finger
  }    

     sensorValue6 = analogRead(sensorPin6);
 
   if  (sensorValue6 > threshold) {
      Keyboard.write(keyboardKey6);
      Serial.println("Sensor 6 - Spacebar");
      // Right Glove - Third Finger
  }

  if  (sensorValue7 > threshold) {
      Mouse.click();
      Serial.println("Sensor 7 - Mouse Click");
      // Right Glove - Pinky Finger
   }

   else {
      Keyboard.releaseAll();
   }

   delay(DEBOUNCE); // delay in between reads for stability
} 
 
