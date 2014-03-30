/*
  Truth or Dare
  This sketch demonstrates:
  Choosing a random number (using A0 as a seed)
  Moving a servo
  Lighting LEDs
  Button press input (with debouncing)
  Using a state machine
 */
 
#include <Servo.h> 

int led_red = 13;
int led_green=12;
int input_pin=11;
int servo_pin=10;
int state=0;
int num_players=4;
int button_state;
int random_number;
int servo_angle=0;
int last_servo_angle=0;
int counter;
Servo myservo;  // create servo object to control a servo 
          
// the setup routine runs once when you press reset:
void setup() {    
  // set up the appropriate pins as inputs/outputs  
  pinMode(led_red, OUTPUT);     
  pinMode(led_green, OUTPUT); 
  pinMode(input_pin, INPUT_PULLUP); 
 
  // attach the servo object to the signal pin 
  myservo.attach(servo_pin);  
  
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
  
  digitalWrite(led_red,HIGH);
  digitalWrite(led_green,HIGH);
  delay(1000);
  digitalWrite(led_red,LOW);
  digitalWrite(led_green,LOW);
  
}

// the loop routine runs over and over again forever:
void loop() {
  
    // decide what to do, based on the current value of the state machine
    switch(state){
       case 0:
       // wait for a button press to run the sequence again
       button_state=digitalRead(input_pin);
       if(button_state==LOW){
         // debounce the button press by waiting a few milliseconds
         // and making sure the button is still pressed
         delay(50);
         button_state=digitalRead(input_pin);
         
         if(button_state==LOW){
           // wait until the button is released
           digitalWrite(led_red,HIGH);
           digitalWrite(led_green,HIGH);
  
           while(button_state==LOW){
             button_state=digitalRead(input_pin);
           }
           counter=0;  // we'll use this counter in a minute
           state=1;    // move the state machine on to the next step
           
           digitalWrite(led_red,LOW);
           digitalWrite(led_green,LOW);

         }
       }
       break; 
       
       
       case 1:
       // this bit chooses a random number and flashes one of the two LEDs
       random_number = random(1,11);  // pick a random number between 1 and 10
       if(random_number <= 5){
         // if we've chosen a "low" number (1,2,3,4,5) flash the red led
         digitalWrite(led_red,HIGH);
         digitalWrite(led_green,LOW);
       }else{
         // if we've chosen a "low" number (6,7,8,9,10) flash the green led
         digitalWrite(led_red,LOW);
         digitalWrite(led_green,HIGH);
       }
       
       // wait a few milliseconds while the led is lit
       delay(50);
       
       // turn off both leds
       digitalWrite(led_red,LOW);
       digitalWrite(led_green,LOW);
       
       // wait a few more milliseconds with both leds off
       delay(50);
       
       // add one to our counter. So far we've waited 100ms (1/10th second)
       // so once the counter reaches 40, we've waited 4 seconds
       counter++;
       if(counter>=20){
         state=2;
       }
       break;
       
       case 2:
       // our random number is already chosen; light up the last led
       if(random_number <= 5){
         // if we've chosen a "low" number (1,2,3,4,5) flash the red led
         digitalWrite(led_red,HIGH);
         digitalWrite(led_green,LOW);
       }else{
         // if we've chosen a "low" number (6,7,8,9,10) flash the green led
         digitalWrite(led_red,LOW);
         digitalWrite(led_green,HIGH);
       }
       
       // choose and random number which indicates the person to point to.
       // if it happens to be the same person as last time, choose again and keep 
       // choosing until a different person is selected
       while(servo_angle==last_servo_angle){
         // choose a random player and point to them
         random_number = random(1,num_players+1);  
         // the servo takes a value of 0-180 but we want player 1 to be at zero
         // and player two to be at 180 - any other players are spread between these
         // two extremes: so divide 180 by (the number of players - 1)
         if(random_number==1){
           servo_angle=0;
         }else if(random_number==num_players){
           servo_angle=180;
         }else{
            // lets say we have three players and we've chosen number two: 180/2 * 1 = 90
            // or maybe four players and we've chosen three: 180/3 * 2 = 120
            servo_angle=(180/(num_players-1))*(random_number-1);
         }
       }
       
       // move the servo to the appropriate angle
       myservo.write(servo_angle);
       last_servo_angle=servo_angle;
       
       // now we've flashed an led and moved the servo, wait a second (to give the servo
       // time to move to it's final position) then go back to waiting for a button press
       delay(1000);
       state=0;
       
    }
}
