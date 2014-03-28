///////
// 
//  AAA
// F   B
//  GGG
// E   C
//  DDD   DP
const int PinA = 2;
const int PinB = 3;
const int PinC = 4;
const int PinD = 5;
const int PinE = 6;
const int PinF = 7;
const int PinG = 8;
const int PinDP = 9;

const int PinDisplay1 = 10;
const int PinDisplay2 = 11;
const int PinDisplay3 = 12;
const int PinDisplay4 = 13;

enum {
  SegA = 1,
  SegB = 2,
  SegC = 4,
  SegD = 8,
  SegE = 16,
  SegF = 32,
  SegG = 64,
  SegDP = 128
};

const int Digit0 = SegA | SegB | SegC | SegD | SegE | SegF;
const int Digit1 = SegB | SegC;
const int Digit2 = SegA | SegB | SegD | SegE | SegG;
const int Digit3 = SegA | SegB | SegC | SegD | SegG;
const int Digit4 = SegB | SegC | SegF | SegG;
const int Digit5 = SegA | SegC | SegD | SegF | SegG;
const int Digit6 = SegA | SegC | SegD | SegE | SegF | SegG;
const int Digit7 = SegA | SegB | SegC;
const int Digit8 = SegA | SegB | SegC | SegD | SegE | SegF | SegG;
const int Digit9 = SegA | SegB | SegC | SegD | SegF | SegG;

void setup()
{
  pinMode(PinA, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(PinC, OUTPUT);
  pinMode(PinD, OUTPUT);
  pinMode(PinE, OUTPUT);
  pinMode(PinF, OUTPUT);
  pinMode(PinG, OUTPUT);
  pinMode(PinDP, OUTPUT);
  
  pinMode(PinDisplay1,10);
  pinMode(PinDisplay2,11);
  pinMode(PinDisplay3,12);
  pinMode(PinDisplay4,13);  
}


void showDigit(int whichPosition, int whichSegments)
{
  // turn all the segments off
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
  digitalWrite(PinC, LOW);
  digitalWrite(PinD, LOW);
  digitalWrite(PinE, LOW);
  digitalWrite(PinF, LOW);
  digitalWrite(PinG, LOW);
  digitalWrite(PinDP, LOW);
  
  if(whichPosition == 1)
    digitalWrite(PinDisplay1, HIGH);
  else
    digitalWrite(PinDisplay1, LOW);
    
  if(whichPosition == 2)
    digitalWrite(PinDisplay2, HIGH);
  else
    digitalWrite(PinDisplay2, LOW);

  if(whichPosition == 3)
    digitalWrite(PinDisplay3, HIGH);
  else
    digitalWrite(PinDisplay3, LOW);

  if(whichPosition == 4)
    digitalWrite(PinDisplay4, HIGH);
  else
    digitalWrite(PinDisplay4, LOW);

  if((whichSegments & SegA)>0)
    digitalWrite(PinA, HIGH);
    
  if((whichSegments & SegB)>0)
    digitalWrite(PinB, HIGH);
    
  if((whichSegments & SegC)>0)
    digitalWrite(PinC, HIGH);
    
  if((whichSegments & SegD)>0)
    digitalWrite(PinD, HIGH);
    
  if((whichSegments & SegE)>0)
    digitalWrite(PinE, HIGH);
    
  if((whichSegments & SegF)>0)
    digitalWrite(PinF, HIGH);
    
  if((whichSegments & SegG)>0)
    digitalWrite(PinG, HIGH);
    
  if((whichSegments & SegDP)>0)
    digitalWrite(PinDP, HIGH);
    
}

void loop()
{
  int delayTime = 1;
  showDigit(1, Digit1);
  delay(delayTime);
  showDigit(2, Digit2);
  delay(delayTime);
  showDigit(3, Digit3);
  delay(delayTime);
  showDigit(4, Digit4);
  delay(delayTime);
}
