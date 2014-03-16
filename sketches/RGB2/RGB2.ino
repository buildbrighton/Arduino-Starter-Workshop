#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop()
{
  int i;
  
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);

  // RED  
  for(i=0; i<255; ++i)
  {
    analogWrite(RED_PIN, i);
    delay(10);
  }
  for(i=255; i>=0; --i)
  {
    analogWrite(RED_PIN, i);
    delay(10);
  }

  // GREEN
  for(i=0; i<255; ++i)
  {
    analogWrite(GREEN_PIN, i);
    delay(10);
  }
  for(i=255; i>=0; --i)
  {
    analogWrite(GREEN_PIN, i);
    delay(10);
  }

  // BLUE
  for(i=0; i<255; ++i)
  {
    analogWrite(BLUE_PIN, i);
    delay(10);
  }
  for(i=255; i>=0; --i)
  {
    analogWrite(BLUE_PIN, i);
    delay(10);
  }    
}

