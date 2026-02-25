const int buttonPin = 2; 
const int greenPin = 11;
const int yellowPin = 12;
const int redPin = 13;

enum State {
  CARS_GO,       
  CARS_SLOWING,   
  PEDESTRIANS_GO, 
  CARS_PREPARING  
};

volatile bool buttonPressed = false; 
State currentState = CARS_GO;
unsigned long lastStateChange = 0; 

void setup() {

  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);
  
  setLights(HIGH, LOW, LOW); 
}

void loop() {
  unsigned long currentMillis = millis();

  switch (currentState) {
    case CARS_GO:
      if (buttonPressed) {
        currentState = CARS_SLOWING;
        setLights(LOW, HIGH, LOW);
        lastStateChange = currentMillis;
        buttonPressed = false;
      }
      break;

    case CARS_SLOWING:
      if (currentMillis - lastStateChange >= 2000) {
        currentState = PEDESTRIANS_GO;
        setLights(LOW, LOW, HIGH);
        lastStateChange = currentMillis;
      }
      break;

    case PEDESTRIANS_GO:
      if (currentMillis - lastStateChange >= 5000) {
        currentState = CARS_PREPARING;
        setLights(LOW, HIGH, HIGH);
        lastStateChange = currentMillis;
      }
      break;

    case CARS_PREPARING:
      if (currentMillis - lastStateChange >= 1000) {
        currentState = CARS_GO;
        setLights(HIGH, LOW, LOW);
        lastStateChange = currentMillis;
      }
      break;
  }
}

void setLights(int green, int yellow, int red) {
  digitalWrite(greenPin, green);
  digitalWrite(yellowPin, yellow);
  digitalWrite(redPin, red);
}

void buttonISR() {
  buttonPressed = true;
}
