/*
Rainbow colour mixer
This sketch demonstrates:
Digital inputs
Simple funtion calls
Simulating analogue output using PWM (analogWrite)
Creating colours using RGB
Playing sounds using a piezo buzzer
Arrays to store multiple values
Random numbers
Simple state machine
*/

int led_red=11;
int led_green=10;
int led_blue=9;

int button1=2;
int button2=3;
int button3=4;
int button4=5;

int buzzer=6;
int button_state;

int state=0;
int sequence[50];
int note_count=0;
int note_to_play;
int note_duration=300;             // this is the number of milliseconds each note will last for
int pause_between_notes=100;       // so we can hear two notes of the same pitch, one after the other
int notes[5]={0,440,554,659,784};  // table of notes in an A7 major chord
int trill[8]={1046,1174,1319,1397,1568,1760,1976,2093};
int frequency;
int random_number;                 // temporary variable for random number selection
int index;                         // used to store the current note playing
int i;                             // just some multi-purpose variables for loops etc.

void setup(){
  pinMode(led_red, OUTPUT);  
  pinMode(led_green, OUTPUT);  
  pinMode(led_blue, OUTPUT);  

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
  resetGame();
  
}

void resetGame(){
  // reset the random number sequence using noise from a floating analogue input
  randomSeed(analogRead(0));  
  
  // set all the values in the sequence array to zero
  for(i=0; i<50; i++){
    sequence[i]=0;
  }
  
  // set the index to zero (first note in the sequence)
  index=0;
  note_count=0;
}


void setColour(int col){
  // ordinarily we'd use RGB values to mix colours, but in real life, some elements
  // of the RGB led are brighter than others (e.g. green is brighter than red)
  switch(col){
    
     case 0:  // turn off all the leds
     analogWrite(led_red,0);
     analogWrite(led_green,0);
     analogWrite(led_blue,0);
     break;
     
     case 1:  // make the led red (255,0,0)
     analogWrite(led_red,255);
     analogWrite(led_green,0);
     analogWrite(led_blue,0);
     break; 
     
     case 2:  // make the led green (0,255,0)
     analogWrite(led_red,0);
     analogWrite(led_green,200);
     analogWrite(led_blue,0);
     break;
     
     case 3:  // make the led blue (0,0,255)
     analogWrite(led_red,0);
     analogWrite(led_green,0);
     analogWrite(led_blue,255);
     break;
     
     case 4:  // make the led violet (255,0,255)
     analogWrite(led_red,255);
     analogWrite(led_green,0);
     analogWrite(led_blue,255);
     break;
  }
}

void playNote(){
  // change the LED to the colour to match the note being played
  setColour(note_to_play);
  // set the frequency depending on the note to play
  frequency=notes[note_to_play];
  // start the piezo buzzer vibrating
  tone(buzzer, frequency, note_duration);
}

void loop(){
  switch(state){
    
    //------------------------------------------------------
    case 0:
    // pick a random number (1-4) and add it to the sequence
    //------------------------------------------------------    
    random_number = random(1,5);
    sequence[note_count]=random_number;
    
    // increate the number of notes in the sequence
    note_count++;
    // if we've hit 50 or more notes, abort the game
    // (our array can only hold 50 notes)
    if(note_count > 49){
      state=99;
    }else{
      // less than 50 notes in the sequence? 
      // start playing it then!
      index=0;
      state=1;
    }
    break;
    
    //-------------------------------------------
    case 1:
    // play the next note in the current sequence 
    //-------------------------------------------    
    note_to_play=sequence[index];    
    if(note_to_play==0){
      // end of sequence
      index=0;
      state=2;
    }else{
      
       playNote();
       // wait 'til the end of the note
       delay(note_duration);
       // turn the LED off (colour zero = off)
       setColour(0);
       // wait for a little while, after the piezo has played and 
       // while the led is switched off
       delay(pause_between_notes);
       // increase the index, so next time around we'll play the next 
       // note in the sequence (or move the state machine on to the next step)
       index++;
       
    }
    break;
    
    // -----------------------------------------------------------------
    case 2:
    // wait for a button press and compare which button has been pressed
    // to the note in the sequence
    // -----------------------------------------------------------------
    note_to_play=sequence[index];
    if(note_to_play==0){
      // you've played back all the notes in the sequence
      // play a little well done trill, then reset the state machine
      state=5;
    }else{
      state=3;
    }
    break;
    
    
    case 3:
    // wait for the user to press a button, and compare it to which button we're waiting for
    for(i=0; i<4; i++){
      button_state=digitalRead(button1+i);
          
      if(button_state==LOW){
        // debounce the input
        delay(20);
        button_state=digitalRead(button1+i);
        if(button_state==LOW){
          if(note_to_play==i+1){
            playNote();
            // wait 'til the button is released
            while(button_state==LOW){
              button_state=digitalRead(button1+i);
            }
            // move on to the next note in the sequence
            index++; 
            state=2;
             
            if(index>=50){
              // this is the end of the sequence, you win!
              state=99;
            }
          }else{
            // oh no! you've hit the wrong note. Abort
            state=4;
          }
        } 
      }
    }
    break;

    //---------------------------------------------------------------------
    case 4:
    // you've hit the wrong note - play the "error" sequence and try again!
    //---------------------------------------------------------------------    
    setColour(0);
    frequency=220;
    tone(buzzer, frequency, 500);
    delay(500);
    frequency=147;
    tone(buzzer, frequency, 1000);
    delay(1000);
    resetGame();
    delay(2000);
    state=0;
    break;

    //-----------------------------------------    
    case 5:
    // ta-da! You played the sequence correctly
    //-----------------------------------------    
    // turn the led off
    setColour(0);
    // wait one second
    delay(1000);
    // make the LED go white
    analogWrite(led_red,255);
    analogWrite(led_green,255);
    analogWrite(led_blue,255);
    
    // play a little trill 
    for(i=0; i<8; i++){
      frequency=trill[i];
      tone(buzzer, frequency, 50);
      delay(55);
    }
    
    // turn the led off
    setColour(0);
    // wait one second
    delay(1000);
    state=0;
    break;
    
    case 99:
    // end of game 
    break;
    
  }    
}

