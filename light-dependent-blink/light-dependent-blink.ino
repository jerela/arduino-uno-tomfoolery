/*
  Read analog voltage using a light-dependent resistor to make a light blink quickly when it's dark and slowly when it's lit.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);


  bool lit = true;

  // if the in-built LED is lit, turn it off; otherwise, turn it on
  if (lit == true) {
    digitalWrite(LED_BUILTIN, LOW);
    lit = false;
  } else {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    lit = true;
  }

  // print the read voltage to serial monitor
  Serial.println(sensorValue);
  
  // wait according to the read voltage (in other words, the read voltage determines how quickly the in-built LED blinks)
  delay(50+4*sensorValue);
  

}
