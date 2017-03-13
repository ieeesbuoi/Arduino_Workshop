//Part 4

#define echoPin 6 // Echo Pin
#define trigPin 7 // Trigger Pin
#define LEDPin 13 // Onboard LED

int maximumRange = 100; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
  /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("Out of range");
 digitalWrite(LEDPin, HIGH);
 }

 else{
  /* Send the distance to computer and Turn LED OFF */
  Serial.println(distance + "cm");
  digitalWrite(LEDPin, LOW);
 }
 //Delay 50ms before next reading.
 delay(50);
}
