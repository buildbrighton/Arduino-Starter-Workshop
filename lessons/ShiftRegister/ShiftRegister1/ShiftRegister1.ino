const int PinShiftData = 10;
const int PinShiftClock = 11;
const int PinStoreClock = 12;

void setup()
{
  pinMode(PinShiftData, OUTPUT);
  pinMode(PinShiftClock, OUTPUT);
  pinMode(PinStoreClock, OUTPUT);
}

void loop()
{
  // set the data input HIGH for the first shift
  // to get the first light on
  digitalWrite(PinShiftData, HIGH);  
  for(int i=0; i<8; ++i)
  {  
    // pulse the shift clock
    digitalWrite(PinShiftClock, LOW);    
    digitalWrite(PinShiftClock, HIGH);    
    
    // pulse the store clock
    digitalWrite(PinStoreClock, LOW);
    digitalWrite(PinStoreClock, HIGH);

    // set input data low, so next shift is
    // an led OFF
    digitalWrite(PinShiftData, LOW);  
    
    delay(200);
  }  
}
