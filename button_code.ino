/*
 * This sketch implements the button
 *
 */
// Some code here...
#define buttonPin 5 // Connect the button to digital pin 5
// Some code here...

// In the setup function add the INPUT instance of the button
pinMode(buttonPin, INPUT);

// Some code here...

// In the loop somewhere or in some function() add the following code

// Assuming that we want to read the button state (pressed/releashed)
int value = digitalRead(buttonPin);

if( value == LOW ) { // If the button is pressed
    digitalWrite(LED1, HIGH);   // Turn LED1 on
    delay(2000);
    digitalWrite(LED2, HIGH);   // Turn LED2 on
    delay(2000);
    digitalWrite(LED3, HIGH);   // Turn LED3 on
    delay(2000);
}else { // If the button is releashed
    digitalWrite(LED1, LOW);    // Turn LED1 off
    digitalWrite(LED2, LOW);    // Turn LED2 off
    digitalWrite(LED3, LOW);    // Turn LED3 off
}
