#include <Servo.h>
#include <WiFi.h>  // Use the appropriate library for your network

Servo myServo;
const int buttonPin = 2;  // Pin connected to the button
int buttonState = HIGH;   // Variable to store the button state

int servoPin = 7;  // Pin connected to the servo
int startPosition = 90;  // Starting position (90 degrees)
int counterClockwisePosition = 180;  // Position for counterclockwise rotation (180 degrees)

const char* server = "your_server_endpoint";  // Replace with your actual server URL

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);

  // Set the button pin as input with an internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  myServo.attach(servoPin);  // Attach the servo to pin 7
  myServo.write(startPosition);  // Set the initial position to 90 degrees

  // Initialize network (replace with your WiFi/Ethernet setup)
  WiFi.begin("your_SSID", "your_PASSWORD");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);
  
  // Check if the button is pressed (LOW state)
  if (buttonState == LOW) {
    Serial.println("Button pressed");
    
    // 1. Ping the server (placeholder for actual HTTP request)
    pingServer();
    
    // 2. Wait 63 seconds
    delay(65000);  // 65 seconds delay until "the reveal"
    
    // 3. Ping the server again
    pingServer();
    
    // 4. Rotate the motor (counterclockwise)
    myServo.write(counterClockwisePosition);
    
    // 5. Wait 5 seconds
    delay(6000);  // 1 second to open door + 5 seconds delay
    
    // 6. Rotate the motor back to the starting position
    myServo.write(startPosition);
    
    // 7. Wait 3 seconds
    delay(3000);  // 1 second to close door + 2 seconds delay to reset. 
    
    // 8. Ping the server again
    pingServer();
  }
}

// Placeholder function to simulate pinging a server
void pingServer() {
  Serial.println("Pinging server...");
  // Add your HTTP request logic here to ping the server
  // Example: HTTP GET request using WiFiClient or HTTPClient
}