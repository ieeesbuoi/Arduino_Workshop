//Part 5

#define echoPin 6 // Echo Pin
#define trigPin 7 // Trigger Pin
#define LEDPin 13 // Onboard LED
#define LED1 10
#define LED2 11
#define LED3 12

int maximumRange = 100; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT);
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
}

void loop() {
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 Serial.println("Out of range");
 digitalWrite(LEDPin, HIGH);
 digitalWrite(LED1, LOW);
 digitalWrite(LED2, LOW);
 digitalWrite(LED3, LOW);
 }

 else if (distance > minimumRange && distance <= 10){
 Serial.println(distance + "cm");
 digitalWrite(LEDPin, LOW);
 digitalWrite(LED1, HIGH);
 digitalWrite(LED2, HIGH);
 digitalWrite(LED3, HIGH);
 }

 else if (distance > 10 && distance <= 20){
 Serial.println(distance + "cm");
 digitalWrite(LEDPin, LOW);
 digitalWrite(LED1, HIGH);
 digitalWrite(LED2, HIGH);
 digitalWrite(LED3, LOW);
 }

 else if (distance > 20 && distance <= 30){
 Serial.println(distance + "cm");
 digitalWrite(LEDPin, LOW);
 digitalWrite(LED1, HIGH);
 digitalWrite(LED2, LOW);
 digitalWrite(LED3, LOW);
 }

 else if (distance > 30 && distance < maximumRange){
 Serial.println(distance + "cm");
 digitalWrite(LEDPin, HIGH);
 digitalWrite(LED1, LOW);
 digitalWrite(LED2, LOW);
 digitalWrite(LED3, LOW);
 }
//Delay 50ms before next reading.
 delay(50);
}
