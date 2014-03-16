void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

int whichPin = 5;
void loop()
{
  if(whichPin == 5) 
    digitalWrite(5, HIGH);
  else
    digitalWrite(5, LOW);

  if(whichPin == 5) 
    digitalWrite(5, HIGH);
  else
    digitalWrite(5, LOW);

  if(whichPin == 6) 
    digitalWrite(6, HIGH);
  else
    digitalWrite(6, LOW);

  if(whichPin == 7) 
    digitalWrite(7, HIGH);
  else
    digitalWrite(7, LOW);

  if(whichPin == 8) 
    digitalWrite(8, HIGH);
  else
    digitalWrite(8, LOW);

  if(whichPin == 9) 
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);

  if(whichPin == 10) 
    digitalWrite(10, HIGH);
  else
    digitalWrite(10, LOW);

  if(whichPin == 11) 
    digitalWrite(11, HIGH);
  else
    digitalWrite(11, LOW);

  if(whichPin == 12) 
    digitalWrite(12, HIGH);
  else
    digitalWrite(12, LOW);

  if(whichPin == 13) 
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);

  whichPin = whichPin + 1;
  if(whichPin > 13)
    whichPin = 5;
    
  delay(100);
}

