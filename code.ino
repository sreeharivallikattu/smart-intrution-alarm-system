/Declaration of pins

int sensorPin = 2;
int redLED = 3 ;
int greenLED = 4 ;
int blueLED= 5 ;
int buzzer= 6 ;
int relay= 7 ;

int lastState =HIGH;

void setup() {

  pinMode(sensorPin, INPUT_PULLUP);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);

  Serial.begin(9600);


  // Initial safe state
  digitalWrite(relay, LOW);
  digitalWrite(buzzer, LOW);

  // System armed indication
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, HIGH);
  digitalWrite(blueLED, HIGH);

  Serial.println("SYSTEM ARMED");
}

void loop() {

  int currentState = digitalRead(sensorPin);

  if(currentState == LOW && lastState == HIGH) {

    // Double check trigger
    if(digitalRead(sensorPin) == LOW && lastState == HIGH) {

      Serial.println("INTRUSION DETECTED!");

      // Turn OFF green LED
      digitalWrite(greenLED, HIGH);

      // Alarm sequence
      for(int i = 0; i < 10; i++) {

        // RED warning
        digitalWrite(redLED, LOW);

        // Blue flash
        digitalWrite(blueLED, LOW);

        // Activate buzzer
        digitalWrite(buzzer, HIGH);

        // Activate relay
        digitalWrite(relay, HIGH);

        delay(200);

        // Turn OFF
        digitalWrite(redLED, HIGH);
        digitalWrite(buzzer, LOW);
        digitalWrite(relay, LOW);

        delay(200);
      }

      // Return to armed state
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
      digitalWrite(blueLED, HIGH);

      Serial.println("SYSTEM RESET");
    }
  }
  lastState = currentState;
}
