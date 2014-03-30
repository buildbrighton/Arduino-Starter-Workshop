/*
Rainbow colour mixer
This sketch demonstrates:
Reading analogue input signals
Simple funtion calls
Simulating analogue output using PWM (analogWrite)
Creating colours using RGB
*/

int led_red=11;
int led_green=10;
int led_blue=9;
int input_pin=1;  // analogue pins are labelled A0-A5
int analogue_value;


void setup(){
  pinMode(led_red, OUTPUT);  
  pinMode(led_green, OUTPUT);  
  pinMode(led_blue, OUTPUT);  

}


void setColour(int col){
  // ordinarily we'd use RGB values to mix colours, but in real life, some elements
  // of the RGB led are brighter than others (e.g. green is brighter than red)
  switch(col){
     case 1:  // make the led red (255,0,0)
     analogWrite(led_red,255);
     analogWrite(led_green,0);
     analogWrite(led_blue,0);
     break; 
     
     case 2:  // make the led orange (255,128,0)
     analogWrite(led_red,200);
     analogWrite(led_green,40);
     analogWrite(led_blue,0);
     break;
     
     case 3:  // make the led yellow (255,255,0)
     analogWrite(led_red,200);
     analogWrite(led_green,100);
     analogWrite(led_blue,0);
     break;
     
     case 4:  // make the led green (0,255,0)
     analogWrite(led_red,0);
     analogWrite(led_green,200);
     analogWrite(led_blue,0);
     break;
     
     case 5:  // make the led blue (0,0,255)
     analogWrite(led_red,0);
     analogWrite(led_green,0);
     analogWrite(led_blue,255);
     break;
     
     case 6:  // make the led indigo (128,0,255)
     analogWrite(led_red,80);
     analogWrite(led_green,0);
     analogWrite(led_blue,255);
     break;
     
     case 7:  // make the led violet (255,0,255)
     analogWrite(led_red,150);
     analogWrite(led_green,0);
     analogWrite(led_blue,255);
     break;
  }
}

void loop(){
  // we're going to read the input value, then apply it to a range
  // to display the appopriate rainbow colour:
  // 0-146    = red
  // 147-292  = orange
  // 293-438  = yellow
  // 439-584  = green
  // 585-730  = blue
  // 731-876  = indigo
  // 877-1024 = violet
  
  analogue_value = analogRead(input_pin);   // read the input pin
  if(analogue_value<=146){
     setColour(1);
  }else if (analogue_value<=292){
     setColour(2);
  }else if (analogue_value<=438){
     setColour(3);
  }else if (analogue_value<=584){
     setColour(4);
  }else if (analogue_value<=730){
     setColour(5);
  }else if (analogue_value<=876){
     setColour(6);
  }else if (analogue_value<=1024){
     setColour(7);
  }
     
}

