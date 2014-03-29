/*
 Game States
     0  start - display welcome message
             - led breating
        user presses button
     1  game start
             - countdown on LCD
             - LED flashing
     2  countdown reaches zero
             - Led turns out
     3  Wait for a random time
             - if button pressed player looses
             - time elapses 
             - turn light on
             - if button pressed player wins
     4  winning message      
             - display winner on lcd
        wait fixed time
     5  wait time elapsed
            - display score
            - led breathing
       user presses button - return to game start
     6  loosing message
 */

// include the library code:
#include <LiquidCrystal.h>

#define BUTTON1 9
#define BUTTON2 8

#define LED 6

#define DEBOUNCE_COUNTER 3
#define FLASH_TIMEOUT 10
#define COUNTDOWN_START 5
#define COUNTDOWN_TIMEOUT 25
#define MAX_PAUSE 200
#define PAUSE_TIMEOUT 10
#define MESSAGE_PAUSE 10

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ledLevel = 0;
int button1Debounce = 0;
int button2Debounce = 0;
boolean button1State = false;
boolean button2State = false;

int looser = 0;
int winner = 0;

int p1Score = 0;
int p2Score = 0;

String lcd1="Quick Draw      ";
String lcd2="Press a button  "; 

int countdownCounter;

int pauseTime;
  
int gameState = 0;

void setup() {
  // configure buttons and LEDs
  pinMode(LED, OUTPUT);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
}

//calculate the current led level when in breath mode
void ledBreath()
{
  static int breathDir = 1;
  if (ledLevel == 255 )
  {
    breathDir = -1;
  }
  else if (ledLevel == 0 )
  {
    breathDir = 1;
  }
  ledLevel += breathDir;
}

void ledFlash()
{
  static int flashTimer = 0;
  if (flashTimer++ == FLASH_TIMEOUT)
  {
    ledLevel=(ledLevel == 0)?255:0;
    flashTimer = 0;
  }
}

void countdown()
{
  static int countdownTimer = 0;
  if (countdownTimer++ == COUNTDOWN_TIMEOUT)
  {
    countdownCounter--;
    countdownTimer = 0;
  }
}

boolean longPause()
{
  static int pauseTimer = 0;
  if (pauseTimer++ == PAUSE_TIMEOUT)
  {
    pauseTime--;
    pauseTimer = 0;
  }
  return(pauseTime==0);
}



void loop() {
  // led state
  analogWrite(LED, ledLevel);
  
  // process buttons
  if( not digitalRead(BUTTON1) )
  {
    if(button1Debounce < DEBOUNCE_COUNTER)
    {
      button1Debounce++;
    }
  }
  else
  {
    button1Debounce=0;
  }
  if(button1Debounce == DEBOUNCE_COUNTER)
  {
    button1State = true;
  }
  else
  {
    button1State = false;
  }
  
  if( not digitalRead(BUTTON2) )
  {
    if(button2Debounce < DEBOUNCE_COUNTER)
    {
      button2Debounce++;
    }
  }
  else
  {
    button2Debounce=0;
  }
  if(button2Debounce == DEBOUNCE_COUNTER)
  {
    button2State = true;
  }
  else
  {
    button2State = false;
  }
  
  // update display
    // Print a startup message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print(lcd1);
  lcd.setCursor(0, 1);
  lcd.print(lcd2);
  
  
  // update game state
  
  switch(gameState)
  {
    case 0 :
      ledBreath();
       if(button1State || button2State)
      {
        gameState = 1;
        countdownCounter = COUNTDOWN_START;
      }
      break;
      
    case 1 :
      lcd1 = "   Get Ready    ";
      lcd2 = "       " + String(countdownCounter)+"       ";
      countdown();
      ledFlash();
      if(countdownCounter==0 )
      {
        gameState = 2;
        pauseTime = random(MAX_PAUSE);
        ledLevel = 0;
        lcd1 = "                ";
        lcd2 = "                ";
      }
      break;
    case 2 :
        if (longPause())
        {
          gameState = 3;
        }
        if (button1State)
        {
        gameState = 6;
        looser = 1;
        pauseTime = MESSAGE_PAUSE;
        }
        if (button2State)
        {
        gameState = 6;
        looser = 2;
        pauseTime = MESSAGE_PAUSE;
        }
      break;
    case 3 :
        lcd1 = "      GO!       ";
        lcd2 = "                ";
        ledLevel = 255;
        if (button1State)
        {
        gameState = 4;
        winner = 1;
        pauseTime = MESSAGE_PAUSE;
        }
        if (button2State)
        {
        gameState = 4;
        winner = 2;
        pauseTime = MESSAGE_PAUSE;
        }
      break;
    case 4 :
        if(winner == 1)
          lcd1 = "Player 1        ";
        else
          lcd1 = "Player 2        ";
        lcd2 = "           Wins!";
        if (longPause())
        {
          gameState = 5;
          if(winner == 1)
            p1Score++;
          else
            p2Score++;
        }
      break;
    case 5 :
        lcd1 = "Player 1   " + p1Score;
        lcd2 = "Player 2   " + p2Score;
        gameState = 0;
      break;
    case 6 :
        if(looser == 1)
          lcd1 = "Player 1        ";
        else
          lcd1 = "Player 2        ";
        lcd2 = "         Looses!";
        if (longPause())
        {
          gameState = 5;
          if(looser == 1)
            p1Score--;
          else
            p2Score--;        }
        
      break;
  }
  delay(5);
}

