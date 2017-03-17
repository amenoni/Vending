//---------------BV20 Codes ---------
#define BUSY 120
#define NOT_BUSY 121
#define NOTE_20 1
#define NOTE_50 2
#define NOTE_100 3
#define NOTE_200 4
#define NOTE_500 5
#define NOTE_1000 6
#define NOTE_NOT_RECOGNICED 20
#define ERROR_MECHANISM_SLOW 30
#define ERROR_STRIMMING_ATTEMPTED 40
#define ERROR_NOTE_REJECTED_FRAUD 50
#define ERROR_STACKER_FULL 60
#define ERROR_ABORT_DURING_ESCROW 70
#define ERROR_NOTE_TAKEN_TO_CLEAR_JAM 80
#define ERROR_COMMAND_ERROR 255
//---------------BV20 Codes ---------


int NOTE_CODES[] = {NOTE_20,NOTE_50,NOTE_100,NOTE_200,NOTE_500,NOTE_1000};
int NOTE_CODES_SIZE = 7;
int INVALID_NOTES[] = {7,8,9,10,11,12,13,14,15,16};
int INVALID_NOTES_SIZE = 10;
int ERROR_CODES[] = {NOTE_NOT_RECOGNICED,ERROR_MECHANISM_SLOW,ERROR_STRIMMING_ATTEMPTED,ERROR_NOTE_REJECTED_FRAUD,ERROR_STACKER_FULL,ERROR_ABORT_DURING_ESCROW,ERROR_NOTE_TAKEN_TO_CLEAR_JAM,ERROR_COMMAND_ERROR};
int ERROR_CODES_SIZE = 8;

boolean is_valid_note(int code){
  int i;
  boolean result = false;
  for(i = 0; i < NOTE_CODES_SIZE; i++){
    if(NOTE_CODES[i] == code){
      result = true;
    }
  }
  return result;
}


boolean is_invalid_note(int code){
  int i;
  boolean result = false;
  for(i = 0; i < INVALID_NOTES_SIZE; i++){
    if(INVALID_NOTES[i] == code){
      result = true;
    }
  }
  return result;
}

boolean is_error_code(int code){
  int i;
  boolean result = false;
  for(i = 0; i < ERROR_CODES_SIZE; i++){
    if(ERROR_CODES[i] == code){
      result = true;
    }
  }
  return result;
}


void disable_invalid_notes(){
  
}

