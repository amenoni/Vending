#include <SoftwareSerial.h>
#include "bv20.h"
#include "config.h"

SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX

// Available money balance
int balance = 0; 

boolean enable_dispenser = false;


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  /*while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Goodnight moon!");*/
  
  //Disabling all invalid notes
  int i;
  for(i = 0; i < INVALID_NOTES_SIZE; i++){
      Serial.println("Invalidating note: " + String(INVALID_NOTES[i]));
      mySerial.write(INVALID_NOTES[i] + 130);
  }

  //Enabling all valid notes
  for(i = 0; i < NOTE_CODES_SIZE; i++){
      Serial.println("enabling note: " + String(NOTE_CODES[i]));
      mySerial.write(NOTE_CODES[i] + 150);
  }
  
}

void loop() { // run over and over
  if (mySerial.available() > 0) { //Check if theres a new message from the validator
    Serial.print("new code: ");
    int code = int(mySerial.read());
    Serial.println(code);
    
    if (is_valid_note(code)){ //New valid note
      Serial.println("valid note");
      switch(code){
        case NOTE_20:
          balance += 20;
          break;
        case NOTE_50:
          balance += 50;
          break;
        case NOTE_100:
          balance += 100;
          break;
        case NOTE_200:
          balance += 200;
          break;
        case NOTE_500:
          balance += 500;
          break;
        case NOTE_1000:
          balance += 1000;
          break;
      }
      Serial.println("Current Balance: " + String(balance));

      if (balance >= TARGET_BALANCE){
        enable_dispenser = true;
        Serial.println("Dispenser enabled");
      }
     
      
    }else if(is_invalid_note(code)){ // Invalid Note
      Serial.println("INVALID NOTE");
      //TODO Take action! Reject the note
    }else if(is_error_code(code)){ // Validator error
      Serial.println("IS ERROR CODE");
      //TODO Take action
    }
  }


  
 
  if (mySerial.overflow()) {
      Serial.println("SoftwareSerial overflow!"); 
  }


  

}
