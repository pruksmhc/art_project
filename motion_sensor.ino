// Define the pin for the sensor output
const int sensorPin = 7; // Connect the sensor's OUT pin to D2

void setup() {
  // Initialize the serial monitor
  Serial.begin(9600);
  
  // Set the sensor pin as input
  pinMode(sensorPin, INPUT);
}

void loop() {
  // Read the sensor value (HIGH or LOW)
  int sensorValue = digitalRead(sensorPin);
  Serial.println(sensorValue);
  // Print the result
  if (sensorValue == LOW) {
    delay(500);
    Serial.println("Object detected!");
    
  } else {
    Serial.println("No object detected.");
  }
  
  // Add a small delay for readability
}

