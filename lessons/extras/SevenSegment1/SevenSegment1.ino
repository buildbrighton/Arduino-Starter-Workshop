///////
// 
//  AAA
// F   B
//  GGG
// E   C
//  DDD   DP
const int SegA = 2;
const int SegB = 3;
const int SegC = 4;
const int SegD = 5;
const int SegE = 6;
const int SegF = 7;
const int SegG = 8;
const int SegDP = 9;


void setup()
{
  pinMode(SegA, OUTPUT);
  pinMode(SegB, OUTPUT);
  pinMode(SegC, OUTPUT);
  pinMode(SegD, OUTPUT);
  pinMode(SegE, OUTPUT);
  pinMode(SegF, OUTPUT);
  pinMode(SegG, OUTPUT);
  pinMode(SegDP, OUTPUT);
}

void showDigit(int digit)
{
  switch(digit)
  {
    case 0:
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, LOW);
      digitalWrite(SegDP, LOW);
      break;
      
    case 1:
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      digitalWrite(SegDP, LOW);
      break;

    case 2:
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      digitalWrite(SegDP, LOW);
      break;

    case 3:
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      digitalWrite(SegDP, LOW);
      break;

    case 4:
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      digitalWrite(SegDP, LOW);
      break;

    case 5:
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      digitalWrite(SegDP, LOW);
      break;

    case 6:
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      digitalWrite(SegDP, LOW);
      break;

    case 7:
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, LOW);
      digitalWrite(SegDP, LOW);
      break;

    case 8:
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, HIGH);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      digitalWrite(SegDP, LOW);
      break;

    case 9:
      digitalWrite(SegA, HIGH);
      digitalWrite(SegB, HIGH);
      digitalWrite(SegC, HIGH);
      digitalWrite(SegD, HIGH);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, HIGH);
      digitalWrite(SegG, HIGH);
      digitalWrite(SegDP, LOW);
      break;    
  
    default:
      digitalWrite(SegA, LOW);
      digitalWrite(SegB, LOW);
      digitalWrite(SegC, LOW);
      digitalWrite(SegD, LOW);
      digitalWrite(SegE, LOW);
      digitalWrite(SegF, LOW);
      digitalWrite(SegG, HIGH);
      digitalWrite(SegDP, LOW);
      break;
      
  }
}
void loop()
{
  for(int i=0; i<=9; ++i)
  {
    showDigit(i);
    delay(500);
  }
}
