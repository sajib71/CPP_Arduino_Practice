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
  BROKER_PASSWORD,
  DEVICE_ID
};
String input = "";

// constants won't change. Used here to set a pin number:
const int ledPin =  2;  // the number of the LED pin
State currentState = IDLE;
unsigned long previousMillis = 0;
const long interval = 1000; // 1 second interval
static byte menuPrintLock = 0;
void setup() {
  Serial.begin(9600);
  Serial.print("Type \"Menu\" to see menu.\n");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // Non-blocking delay
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    switch (currentState) {
      case IDLE:
//        if (Serial.available() > 0) {
//          input = Serial.readStringUntil('\n');
//          if (input.equalsIgnoreCase("Menu")) {
            Serial.print("Correct keyword. You have entered: ");
            Serial.println(input);
//            Serial.println("1.WiFi Credentials");
//            Serial.println("2.Broker Credentials");
//            Serial.println("3.Device ID");
//            Serial.println("4.Exit");
//            Serial.print("Type 1, 2, 3 or 4 to select \n");
            currentState = MENU;
//          } else {
//            Serial.print("Wrong keyword. You have entered: ");
//            Serial.println(input);
//          }
//        }
        break;

      case MENU:
        if (menuPrintLock == 0){
          Serial.println("1.WiFi Credentials");
          Serial.println("2.Broker Credentials");
          Serial.println("3.Device ID");
          Serial.println("4.Exit");
          Serial.print("Type 1, 2, 3 or 4 to select \n");
          menuPrintLock = 1;
        }
        if (Serial.available() > 0) {
          input = Serial.readStringUntil('\n');
          if (input == "1") {
            currentState = WIFI_CREDENTIALS;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          } 
          else if (input == "2"){
            currentState = BROKER_CREDENTIALS;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else if (input == "3"){
            currentState = DEVICE_ID;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else if (input == "4"){
            currentState = IDLE;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else {
            Serial.print("Wrong keyword. You have entered: ");
            Serial.println(input);
          }
          menuPrintLock = 0;
        }
        break;

      case WIFI_CREDENTIALS:
//        handleSubMenu("WiFi Credentials", WIFI_SSID, "SSID");
        if (menuPrintLock == 0){
          Serial.println("1.WiFi SSID");
          Serial.println("2.WiFi Passward");
          Serial.println("3.Back");
          Serial.println("4.Exit");
          Serial.print("Type 1, 2, 3 or 4 to select \n");
          menuPrintLock = 1;
        }
        if (Serial.available() > 0) {
          input = Serial.readStringUntil('\n');
          if (input == "1") {
            currentState = WIFI_SSID;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          } 
          else if (input == "2"){
            currentState = WIFI_PASSWORD;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else if (input == "3"){
            currentState = MENU;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else if (input == "4"){
            currentState = IDLE;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else {
            Serial.print("Wrong keyword. You have entered: ");
            Serial.println(input);
          }
          menuPrintLock = 0;
        }
        break;

      case WIFI_SSID:
        handleInput("Enter SSID", WIFI_CREDENTIALS);
        break;

      case WIFI_PASSWORD:
        handleInput("Enter Password", WIFI_CREDENTIALS);
        break;

      case BROKER_CREDENTIALS:
        if (menuPrintLock == 0){
          Serial.println("1.IP Address");
          Serial.println("2.BROKER_PORT");
          Serial.println("3.BROKER_USERNAME");
          Serial.println("4.BROKER_PASSWORD");
          Serial.println("5.Back");
          Serial.println("6.Exit");
          Serial.print("Type 1, 2, 3 or 4 to select \n");
          menuPrintLock = 1;
        }
        if (Serial.available() > 0) {
          input = Serial.readStringUntil('\n');
          if (input == "1") {
            currentState = BROKER_IP;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          } 
          else if (input == "2"){
            currentState = BROKER_PORT;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else if (input == "3"){
          currentState = BROKER_USERNAME;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else if (input == "4"){
          currentState = BROKER_PASSWORD;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else if (input == "5"){
          currentState = MENU;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else if (input == "6"){
            currentState = IDLE;
            Serial.print("You Have Entered: ");
            Serial.println(input);
          }
          else {
            Serial.print("Wrong keyword. You have entered: ");
            Serial.println(input);
          }
          menuPrintLock = 0;
        }
//        handleSubMenu("Broker Credentials", BROKER_IP, "IP Address");
        break;

      case BROKER_IP:
        handleInput("Enter IP Address", BROKER_CREDENTIALS);
        break;

      case BROKER_PORT:
        handleInput("Enter Port", BROKER_CREDENTIALS);
        break;

      case BROKER_USERNAME:
        handleInput("Enter Username", BROKER_CREDENTIALS);
        break;

      case BROKER_PASSWORD:
        handleInput("Enter Password", BROKER_CREDENTIALS);
        break;
      case DEVICE_ID:
        handleInput("Enter Device ID", MENU);
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
  if (menuPrintLock == 0){
    Serial.println(prompt);
    menuPrintLock = 1;
  }
  
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    Serial.print("You have entered: ");
    Serial.println(input);
    Serial.println("Saved Successfully");
    currentState = nextState;
    menuPrintLock = 0;
  }
}

void ledBlinker() {
  static int ledState = LOW;
  static unsigned long previousMillis2 = 0;
  const long interval2 = 250;
  unsigned long currentMillis2 = millis();
  
  if (currentMillis2 - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis2;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
}
