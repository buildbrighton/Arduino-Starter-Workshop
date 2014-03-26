void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  // make the LED on the first pin come on
  digitalWrite(7, HIGH);  
  delay(100);
  
  // turn first one off, second one on
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(100);
  
  // turn second one off, third on...
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(100);
  
  // and so on..
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(100);
  
  // and so on..
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  
  // and so on..
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(100);
  
  // and so on..
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(100);
  
  // turn the last one off... and round we go again!
  digitalWrite(13, LOW);
}

