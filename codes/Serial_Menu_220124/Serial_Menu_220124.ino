void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  delay(1000);
  Serial.print("Type \"Menu\" to see menu.\n");

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available ()> 0) {
    String input = Serial.readStringUntil('\n');
    if(input.equalsIgnoreCase("Menu")){
      Serial.print("Correct keyword. You have entered: ");
      Serial.println (input);
      do{
        Serial.println ("1.WiFi Credentials");
        Serial.println ("2.Broker Credentials");
        Serial.println ("3.Device ID");
        Serial.println ("4.Exit");
        Serial.print("Type 1, 2, 3 or 4 to select \n");
        
        while (Serial.available ()==0) {
        // statement(s)
        }
        input = Serial.readStringUntil('\n');
        //"1.Wifi Credentials" Section
        if(input == ("1")){
          do{
            Serial.println("1.SSID");
            Serial.println("2.Passward");
            Serial.println("3.Back");
            Serial.println("4.Exit");
            Serial.print("Type 1, 2, 3 or 4 to select \n");
            while (Serial.available ()==0) {
            // statement(s)
            }
            //SSID
            input = Serial.readStringUntil('\n');
            if(input == ("1")){
              Serial.println("Enter SSID");
              while (Serial.available ()==0) {
               // statement(s)
              }
              input = Serial.readStringUntil('\n');
              Serial.print("You have entered: ");
              Serial.println (input);
              Serial.println("Saved Successfully");
            }
            //Passward
            else if (input == ("2")){
              Serial.println ("Enter Passward");
              while (Serial.available ()==0){
                //statement(s)
              }
              input = Serial.readStringUntil('\n');
              Serial.print("You have entered: ");
              Serial.println (input);
              Serial.println("Saved Successfully");
            }
          }while(input != "3" && input != "4");
        }
        
            //"2.Broker Credentials Section"
          else if (input ==("2")){
            do{
              Serial.println("1.IP");
              Serial.println("2.Port");
              Serial.println("3.User name");
              Serial.println("4.Passward");
              Serial.println("5.Back");
              Serial.println("6.Exit");
              Serial.print("Type 1, 2, 3, 4, 5 or 6 to select \n");
              while (Serial.available ()==0) {
              // statement(s)
              }
              //IP Address
              input = Serial.readStringUntil('\n');
              if(input == ("1")){
                Serial.println("Enter IP Address");
                while (Serial.available ()==0) {
                 // statement(s)
                }
                input = Serial.readStringUntil('\n');
                Serial.print("You have entered: ");
                Serial.println (input);
                Serial.println("Saved Successfully");
              }
              else if (input == ("2")){
                Serial.println ("Enter Port");
                while (Serial.available ()==0){
                  //statement(s)
                }
                input = Serial.readStringUntil('\n');
                Serial.print("You have entered: ");
                Serial.println (input);
                Serial.println("Saved Successfully");
              }
              else if (input == ("3")){
                Serial.println ("Enter Username");
                while (Serial.available ()==0){
                  //statement(s)
                }
                input = Serial.readStringUntil('\n');
                Serial.print("You have entered: ");
                Serial.println (input);
                Serial.println("Saved Successfully");
              }
              else if (input == ("4")){
                Serial.println ("Enter Passward");
                while (Serial.available ()==0){
                  //statement(s)
                }
                input = Serial.readStringUntil('\n');
                Serial.print("You have entered: ");
                Serial.println (input);
                Serial.println("Saved Successfully");
              }
            }while(input != "5" && input != "6");
          }
    }while(input != "4" && input != "6");
    Serial.println("Exiting Menu");
    }
    else{
      Serial.print("Wrong keyword. You have entered: ");    
      Serial.println (input);
    }
    
  }
}
