#include <Servo.h>
#include <Keyboard.h>

const int funnelPin = 7;      // Pin connected to relay module's SIG
int buttonState = HIGH;   // Variable to store the button state
const int buttonPin = 2;  // Pin connected to the button
const int motorPin = 5;

int startPosition = 90;  // Starting position (90 degrees)
int counterClockwisePosition = 180;  // Position for counterclockwise rotation (180 degrees)
Servo myServo;


void setup() {
  pinMode(funnelPin, OUTPUT);       // Set relay pin as an output
   pinMode(buttonPin, INPUT_PULLUP);
Serial.println(buttonState); 
  myServo.attach(servoPin);
    myServo.write(startPosition);
Keyboard.begin();  // Initialize the Keyboard library

  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  myServo.attach(servoPin);
  myServo.write(startPosition);
  Keyboard.begin();  // Initialize the Keyboard library
  
}

void debugFunnel() {
    delay(1000);
    digitalWrite(funnelPin, HIGH);
    delay(3000);
    digitalWrite(funnelPin, LOW);
}
void debugServo() {
  Serial.println("Empty trash");
  myServo.write(counterClockwisePosition);
  
  // Wait 5 seconds
  delay(6000);

  // Rotate the motor back to the starting position
  myServo.write(startPosition);

  // Wait 3 seconds
  delay(3000);
}

void debugButton() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState); 
  if (buttonState == LOW) {
    Serial.println("Button pressed"); 
    delay(1000);
  }
}

void debugKeyboard(){
  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
}

void loop() {
// debugButton()
// debugFunnel()
//debugKeyboard()
// debugServo()

}