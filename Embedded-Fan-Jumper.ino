// #include <AlashIRControlRX.h>

const int RECIEVER_PIN = 7;
const int FAN_PIN = A0;
const int JOYSTICK_PIN = A1;

const int FAN_TOLERANCE = 1;
const int JOYSTICK_TOLERANCE = 1;

uint64_t lastPoll = 0;

int fanPower = -1;
int joystickMovement = -1;
uint64_t button = 0;



// AlashIRControlRX irReceiver(7);

int buttonCodeToNum(int code);
bool withinTolerance(int newVal, int old, int tolerance);

void setup() {
    Serial.begin(115200);
    // irReceiver.begin();
}

void loop() {

  uint64_t now = millis();
  if(now - lastPoll < 50) {
      return;
  }
  lastPoll = now;
 

  bool change = false;

  const int newFanPower = analogRead(FAN_PIN);
  if(!withinTolerance(newFanPower, fanPower, FAN_TOLERANCE)) {
    fanPower = newFanPower;
    change = true;
  }

  const uint64_t newJoystickMovement = analogRead(JOYSTICK_PIN);
  if(!withinTolerance(newJoystickMovement, joystickMovement, JOYSTICK_TOLERANCE)) {
    change = true;
    joystickMovement = newJoystickMovement;
  }

  // if (irReceiver.check()) {
  //   change = true;
  //   button = irReceiver.data;
  // }


  if(change) {
    Serial.print("{ \"x\": ");
    Serial.print(joystickMovement);
    Serial.print(", \"y\": ");
    Serial.print(fanPower);
    Serial.print(", \"button\": ");
    Serial.print(buttonCodeToNum(button));
    Serial.println(" }");
  }
}

bool withinTolerance(int newVal, int old, int tolerance) {
    return newVal <= old + tolerance && newVal >= old - tolerance;
}

int buttonCodeToNum(int buttonCode) {
    switch (buttonCode) {
        case 16738455:
            return 0;
        case 16724175:
            return 1;
        case 16718055:
            return 2;
        case 16743045:
            return 3;
        case 16716015:
            return 4;
        case 16726215:
            return 5;
        case 16734885:
            return 6;
        case 16728765:
            return 7;
        case 16730805:
            return 8;
        case 16732845:
            return 9;
    }
}
