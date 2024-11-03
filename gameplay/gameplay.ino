#include <Servo.h>
#include <Keyboard.h>

Servo myServo;
// pins
const int buttonPin = 2;  // Pin connected to the button
const int funnelPin = 7; 
int servoPin = 5;  // Pin connected to the servo

// VARIABLES
int buttonState = HIGH;   // Variable to store the button state
int startPosition = 90;  // Starting position (90 degrees)
int counterClockwisePosition = 180;  // Position for counterclockwise rotation (180 degrees)


void nextSlide(){
  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.release(KEY_RIGHT_ARROW);
}
void setup() {
  Serial.begin(9600);
  pinMode(funnelPin, OUTPUT); 
  pinMode(buttonPin, INPUT_PULLUP);
  myServo.attach(servoPin);
  myServo.write(startPosition);
  Keyboard.begin();  // Initialize the Keyboard library
}

void countdownSlides() {
  // Slide 3
  Serial.println("Countdown");
  nextSlide();
  delay(500);

  // Slide 2
  nextSlide();
  delay(500);

  // Slide 1
  nextSlide();
  delay(500);

  // Slide for instructions
  nextSlide();
}

void emptyTrash() {
  // Rotate the motor to empty trash
  delay(1500);
  Serial.println("Empty trash");
  myServo.write(counterClockwisePosition);
  
  // Wait 5 seconds
  delay(6000);

  // Rotate the motor back to the starting position
  myServo.write(startPosition);

  // Wait 3 seconds
  delay(3000);
}
void glitch() {
      // Slide for glitching
   nextSlide();
    nextSlide();
    nextSlide();
    nextSlide();
   nextSlide();
   nextSlide();
   nextSlide();
   nextSlide();
   nextSlide();
   delay(6000); // VIDEO PLAYING OF HACKER
   nextSlide();
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    Serial.println("Button pressed");

    // 2. Perform the countdown for slides
    countdownSlides();
    Serial.println("Turn on funnel, start game.");
    digitalWrite(funnelPin, HIGH);
    //delay(65000);  // 65 seconds delay until end of game 
    delay(5000); 

    // CONGRATS!
    Serial.println("Turn off funnel");
    digitalWrite(funnelPin, LOW);
    nextSlide();// CONGRATS slide
    delay(2500);

    glitch(); 
  
    // 3. Empty the trash
    emptyTrash();

    // 4. Restart slide
    Keyboard.press(KEY_HOME);
    delay(100);
    Keyboard.release(KEY_HOME);
  }
}