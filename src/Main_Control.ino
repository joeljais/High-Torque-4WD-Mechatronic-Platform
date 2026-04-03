// BTS7960 Motor Driver pins for both motors
#define RPWM 5  // Right side motors PWM
#define LPWM 6  // Left side motors PWM
#define R_EN 7  // Right side enable
#define L_EN 8  // Left side enable

// Bluetooth commands
char command; // To store commands from the Bluetooth module

int Speed = 204; // Default motor speed (0 - 255)

void setup() {
  // Set motor driver pins as output
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);

  // Enable motor driver channels
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);

  // Initialize Serial communication for Bluetooth
  Serial.begin(9600); // HC-05 default baud rate
  Serial.println("Bluetooth RC Car Ready");
}

void loop() {
  // Check if a Bluetooth command is available
  if (Serial.available()) {
    command = Serial.read(); // Read the command
    controlMotors(command);  // Call the motor control function
  }
}

// Function to control motors based on Bluetooth commands
void controlMotors(char cmd) {
  switch (cmd) {
    case 'F': // Move Forward
      Serial.println("Moving Forward");
      moveMotors(Speed, Speed);
      break;

    case 'B': // Move Backward
      Serial.println("Moving Backward");
      moveMotors(-Speed, -Speed);
      break;

    case 'L': // Turn Left
      Serial.println("Turning Left");
      moveMotors(-Speed, Speed);
      break;

    case 'R': // Turn Right
      Serial.println("Turning Right");
      moveMotors(Speed, -Speed);
      break;

    case 'S': // Stop
      Serial.println("Stopping");
      stopMotors();
      break;

    default:
      Serial.println("Invalid Command");
      stopMotors();
      break;
  }
}

// Function to control the motor driver
void moveMotors(int speedRight, int speedLeft) {
  if (speedRight >= 0) {
    analogWrite(RPWM, speedRight);
    analogWrite(LPWM, 0);
  } else {
    analogWrite(RPWM, 0);
    analogWrite(LPWM, -speedRight);
  }
  
  if (speedLeft >= 0) {
    analogWrite(LPWM, speedLeft);
    analogWrite(RPWM, 0);
  } else {
    analogWrite(LPWM, 0);
    analogWrite(RPWM, -speedLeft);
  }
}

// Function to stop the motor driver
void stopMotors() {
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}
