// Adding Switch with Pull Up resistor
void setup()
{
  pinMode(6, INPUT_PULLUP);
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

int whichPin = 7;
int whichDirection = 1;
void loop()
{
  
  // check the switch on pin 6
  if(digitalRead(6) == LOW)
  {
    // deal with first pin
    if(whichPin == 7) 
      digitalWrite(7, HIGH);
    else
      digitalWrite(7, LOW);
  
    // deal with second pin
    if(whichPin == 8) 
      digitalWrite(8, HIGH);
    else
      digitalWrite(8, LOW);
  
    // deal with third pin
    if(whichPin == 9) 
      digitalWrite(9, HIGH);
    else
      digitalWrite(9, LOW);
  
    // ...
    if(whichPin == 10) 
      digitalWrite(10, HIGH);
    else
      digitalWrite(10, LOW);
  
    // ...
    if(whichPin == 11) 
      digitalWrite(11, HIGH);
    else
      digitalWrite(11, LOW);
  
    // ...
    if(whichPin == 12) 
      digitalWrite(12, HIGH);
    else
      digitalWrite(12, LOW);
  
    // ...and the last one
    if(whichPin == 13) 
      digitalWrite(13, HIGH);
    else
      digitalWrite(13, LOW);
  
    // move to the next pin
    whichPin = whichPin + whichDirection;
    
    // if we reach the last pin, change direction
    // and come back again!
    if(whichPin >= 13)
      whichDirection = -1;
    else if(whichPin <= 7)
      whichDirection = 1;
  }
  
  
  delay(100);
}

