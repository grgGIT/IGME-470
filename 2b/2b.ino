// Define the pins for LEDs and microphone
const int micPin = A0;
const int redLEDPin = 8;
const int yellowLEDPin = 9;
const int greenLEDPin = 10;

void setup() {
  // Set LED pins as outputs
  pinMode(redLEDPin, OUTPUT);
  pinMode(yellowLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  
  // Initialize serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the microphone
  int soundLevel = analogRead(micPin);
  
  // Map the analog value to different ranges for LED control
  if (soundLevel < 300) {
    // Low sound level (turn on red LED)
    digitalWrite(redLEDPin, HIGH);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(greenLEDPin, LOW);
  } else if (soundLevel >= 300 && soundLevel < 700) {
    // Medium sound level (turn on yellow LED)
    digitalWrite(redLEDPin, LOW);
    digitalWrite(yellowLEDPin, HIGH);
    digitalWrite(greenLEDPin, LOW);
  } else {
    // High sound level (turn on green LED)
    digitalWrite(redLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
  }
  
  // Print the sound level value to serial monitor (optional)
  Serial.println(soundLevel);
  
  // Add a delay to control the rate of reading (adjust as needed)
  delay(100); // 100ms delay
}

