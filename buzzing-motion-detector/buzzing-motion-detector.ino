// define pins for the LED light, motion detecting sensor, and a device that makes awful buzzing sounds
int ledPin = 4;
int detectorPin = 2;
int buzzerPin = 12;

int previousValue = LOW;
int currentValue;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(detectorPin, INPUT);
  Serial.begin(9600);
}
 
void loop(){
  // read whether we are currently detecting
  currentValue = digitalRead(detectorPin);

  // if we are, light the LED and start buzzing
  if (currentValue == HIGH) {
    digitalWrite(ledPin, HIGH);

    if (previousValue == LOW) {
      Serial.println("Detection started");
      previousValue = HIGH;
    }

    for (unsigned char i=0; i < 100; ++i) {
      digitalWrite(buzzerPin,HIGH);
      delay(1);
      digitalWrite(buzzerPin,LOW);
      delay(1);
    }

  // otherwise, turn the led OFF
  } else {
    digitalWrite(ledPin, LOW);

    if (previousValue == HIGH){
      Serial.println("Detection ended");
      previousValue = LOW;
    }
  }
}