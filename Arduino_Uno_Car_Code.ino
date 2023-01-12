
int motor1pin1 = 5;
int motor1pin2 = 6;
int motor1speed = 3;
int motor2pin1 = 7;
int motor2pin2 = 8;
int motor2speed = 9;
// defines pins numbers
int trigPin = 10;
int echoPin = 11;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor1speed, OUTPUT);
  pinMode(motor2speed, OUTPUT);
  
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
   
 if (distance > 10){
 
  analogWrite(motor1speed, 255);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  analogWrite(motor2speed, 255);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

 }else{

   analogWrite(motor1speed, 255);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  analogWrite(motor2speed, 255);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

 delay(500);
 }

  
}
