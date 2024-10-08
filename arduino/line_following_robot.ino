#define RIGHT_SENSOR_PIN A0
#define LEFT_SENSOR_PIN A1
#define RIGHT_MOTOR_FORWARD_PIN 9
#define RIGHT_MOTOR_BACKWARD_PIN 10
#define LEFT_MOTOR_FORWARD_PIN 6
#define LEFT_MOTOR_BACKWARD_PIN 5

int threshold = 500;

void setup() {
  pinMode(RIGHT_MOTOR_FORWARD_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_FORWARD_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD_PIN, OUTPUT);

  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  int rightSensorValue = analogRead(RIGHT_SENSOR_PIN);
  int leftSensorValue = analogRead(LEFT_SENSOR_PIN);

  Serial.print("Right Sensor: ");
  Serial.print(rightSensorValue);
  Serial.print(" | Left Sensor: ");
  Serial.println(leftSensorValue);

  if (rightSensorValue > threshold && leftSensorValue > threshold) {
    moveForward();
  }
  else if (rightSensorValue < threshold && leftSensorValue > threshold) {
    turnRight();
  }
  else if (rightSensorValue > threshold && leftSensorValue < threshold) {
    turnLeft();
  }
  else {
    stopRobot();
  }

  delay(10);  
}

void moveForward() {
  digitalWrite(RIGHT_MOTOR_FORWARD_PIN, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, LOW);
  digitalWrite(LEFT_MOTOR_FORWARD_PIN, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD_PIN, LOW);
}

void turnRight() {
  digitalWrite(RIGHT_MOTOR_FORWARD_PIN, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, HIGH);  
  digitalWrite(LEFT_MOTOR_FORWARD_PIN, HIGH);    
  digitalWrite(LEFT_MOTOR_BACKWARD_PIN, LOW);
}

void turnLeft() {
  digitalWrite(RIGHT_MOTOR_FORWARD_PIN, HIGH);   
  digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, LOW);
  digitalWrite(LEFT_MOTOR_FORWARD_PIN, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD_PIN, HIGH);   
}

void stopRobot() {
  digitalWrite(RIGHT_MOTOR_FORWARD_PIN, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, LOW);
  digitalWrite(LEFT_MOTOR_FORWARD_PIN, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD_PIN, LOW);
}
