enum State {
  IDLE,
  MENU,
  WIFI_CREDENTIALS,
  WIFI_SSID,
  WIFI_PASSWORD,
  BROKER_CREDENTIALS,
  BROKER_IP,
  BROKER_PORT,
  BROKER_USERNAME,
  BROKER_PASSWORD
};
String input = "";

// constants won't change. Used here to set a pin number:
const int ledPin =  2;// the number of the LED pin
State currentState = IDLE;
unsigned long previousMillis = 0;
const long interval = 1000; // 1 second interval

void setup() {
  Serial.begin(9600);
  Serial.print("Type \"Menu\" to see menu.\n");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Non-blocking delayaa
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    switch (currentState) {
      case IDLE:
        if (Serial.available() > 0) {
          input = Serial.readStringUntil('\n');
          if (input.equalsIgnoreCase("Menu")) {
            Serial.print("Correct keyword. You have entered: ");
            Serial.println(input);
            Serial.println("1.WiFi Credentials");
            Serial.println("2.Broker Credentials");
            Serial.println("3.Device ID");
            Serial.println("4.Exit");
            Serial.print("Type 1, 2, 3 or 4 to select \n");
            currentState = MENU;
          } else {
            Serial.print("Wrong keyword. You have entered: ");
            Serial.println(input);
          }
        }
        break;

      case MENU:
        input = Serial.readStringUntil('\n');
        if (input == "1") {
          currentState = WIFI_CREDENTIALS;
          Serial.println ("You Have Entered: ");
          Serial.print (input);
        }
        
        currentState = IDLE; // Reset state to IDLE after displaying menu
        break;

      case WIFI_CREDENTIALS:
        handleSubMenu("WiFi Credentials", WIFI_SSID, "SSID");
        break;

      case WIFI_SSID:
        handleInput("Enter SSID", WIFI_PASSWORD);
        break;

      case WIFI_PASSWORD:
        handleInput("Enter Password", MENU);
        break;

      case BROKER_CREDENTIALS:
        handleSubMenu("Broker Credentials", BROKER_IP, "IP Address");
        break;

      case BROKER_IP:
        handleInput("Enter IP Address", BROKER_PORT);
        break;

      case BROKER_PORT:
        handleInput("Enter Port", BROKER_USERNAME);
        break;

      case BROKER_USERNAME:
        handleInput("Enter Username", BROKER_PASSWORD);
        break;

      case BROKER_PASSWORD:
        handleInput("Enter Password", MENU);
        break;

      default:
        currentState = IDLE;
        break;
    }
  }
  ledBlinker();
}

void handleSubMenu(const char* menuTitle, State nextState, const char* prompt) {
  Serial.println(menuTitle);
  Serial.println("1. " + String(prompt));
  Serial.println("2. Back");
  Serial.println("3. Exit");
  Serial.print("Type 1, 2, or 3 to select \n");

  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input == "1") {
      Serial.println(prompt);
      currentState = nextState;
    } else if (input == "2") {
      currentState = MENU;
    } else if (input == "3") {
      currentState = IDLE;
      Serial.println("Exiting Menu");
    }
  }
}

void handleInput(const char* prompt, State nextState) {
  Serial.println(prompt);
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    Serial.print("You have entered: ");
    Serial.println(input);
    Serial.println("Saved Successfully");
    currentState = nextState;
  }
}
void ledBlinker(){
//  // constants won't change. Used here to set a pin number:
//  const int ledPin =  2;// the number of the LED pin
  
  // Variables will change:
  static int ledState = LOW;             // ledState used to set the LED
  
  // Generally, you should use "unsigned long" for variables that hold time
  // The value will quickly become too large for an int to store
  static unsigned long previousMillis2 = 0;        // will store last time LED was updated
  
  // constants won't change:
  const long interval2 = 250;           // interval at which to blink (milliseconds)
  unsigned long currentMillis2 = millis();
  
  if (currentMillis2 - previousMillis2 >= interval2) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis2;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
