const int PinShiftData = 10;
const int PinShiftClock = 11;
const int PinStoreClock = 12;

void setup()
{
  pinMode(PinShiftData, OUTPUT);
  pinMode(PinShiftClock, OUTPUT);
  pinMode(PinStoreClock, OUTPUT);
}

void loadLEDs(int whichLED)
{
  for(int i=0; i<8; ++i)
  {
    if(whichLED == i)
      digitalWrite(PinShiftData, HIGH);
    else
      digitalWrite(PinShiftData, LOW);
      
    digitalWrite(PinShiftClock, LOW);    
    digitalWrite(PinShiftClock, HIGH);        
  }
  
  digitalWrite(PinStoreClock, LOW);
  digitalWrite(PinStoreClock, HIGH);        
}


void loop()
{
  int i;
  for(i=0; i<7; ++i)
  {
    loadLEDs(i);
    delay(100);
  }
  for(i=7; i>0; --i)
  {
    loadLEDs(i);
    delay(100);
  }
}
