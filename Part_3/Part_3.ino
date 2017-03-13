// Part 3

#define LED1 10
#define LED2 11
#define LED3 12

void setup() {
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
}

void loop() {
digitalWrite(LED1, HIGH);
delay(2000);
digitalWrite(LED1, LOW);
digitalWrite(LED2, HIGH);
delay(4000);
digitalWrite(LED2, LOW);
digitalWrite(LED3, HIGH);
delay(6000);
digitalWrite(LED3, LOW);
delay(1000);
}
