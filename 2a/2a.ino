// Constants for ultrasonic sensor pins
const int trigPin = 2;
const int echoPin = 3;

// Constants for motor control with MOSFET
const int motorControlPin = 9;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set motor control pin
  pinMode(motorControlPin, OUTPUT);
}

void loop() {
  // Trigger ultrasonic sensor to measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse duration to calculate distance
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Convert pulse duration to distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check distance threshold to activate fan motor
  if (distance < 20) {  // Adjust this threshold as needed
    // Turn on the motor using MOSFET
    digitalWrite(motorControlPin, HIGH);
  } else {
    // Turn off the motor
    digitalWrite(motorControlPin, LOW);
  }

  delay(100); // Adjust delay time as needed for sensor readings
}
