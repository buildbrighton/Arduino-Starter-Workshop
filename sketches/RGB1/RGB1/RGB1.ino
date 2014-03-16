
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

// This is our own function to set up the
// red, green and blue LED outputs
void setRGB(int redState, int greenState, int blueState)
{
  digitalWrite(RED_PIN, redState);
  digitalWrite(GREEN_PIN, greenState);
  digitalWrite(BLUE_PIN, blueState);  
}

void loop()
{
  // RED
  setRGB(HIGH, LOW, LOW);
  delay(1000);
  
  // GREEN
  setRGB(LOW, HIGH, LOW);
  delay(1000);

  // BLUE
  setRGB(LOW, LOW, HIGH);
  delay(1000);

  // RED + BLUE = MAGENTA
  setRGB(HIGH, LOW, HIGH);
  delay(1000);

  // RED + GREEN = YELLOW
  setRGB(HIGH, HIGH, LOW);
  delay(1000);

  // GREEN + BLUE = CYAN
  setRGB(LOW, HIGH, HIGH);
  delay(1000);

  // RED + GREEN + BLUE = WHITE
  setRGB(HIGH, HIGH, HIGH);
  delay(1000);  
}

