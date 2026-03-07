uint64_t lastSend = 0;
int motorPin = A0;
int ledPin = A1;

void setup() {
    Serial.begin(115200);
}

void loop() {
    unsigned long now = millis();
    
    if (now - lastSend >= 5) { 
        lastSend = now;

        const int strength = analogRead(motorPin);
        analogWrite(ledPin, strength);
        Serial.println(strength);
    }
}