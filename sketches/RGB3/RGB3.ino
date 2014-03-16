
#define RED_PIN 11
#define GREEN_PIN 10
#define BLUE_PIN 9

///////////////////////////////////////////////////////
/// adapted from http://www.easyrgb.com/
double Hue_2_RGB( double v1, double v2, double vH )
{
   if ( vH < 0.0 ) vH += 1.0;
   if ( vH > 1.0 ) vH -= 1.0;
   if ( ( 6.0 * vH ) < 1.0 ) return v1 + ( v2 - v1 ) * 6.0 * vH;
   if ( ( 2.0 * vH ) < 1.0 ) return v2;
   if ( ( 3.0 * vH ) < 2.0 ) return v1 + ( v2 - v1 ) * ( ( 2.0 / 3.0 ) - vH ) * 6.0;
   return v1;
}

void HSL_2_RGB( double H, double S, double L, byte& R, byte& G, byte& B)
{
  if ( S == 0 )  
  {
     R = L * 255;
     G = L * 255;
     B = L * 255;
  }
  else
  {
     double var_2;
     if ( L < 0.5 ) 
       var_2 = L * ( 1 + S );
     else           
       var_2 = ( L + S ) - ( S * L );
  
     double var_1 = 2.0 * L - var_2;  
     R = 255 * Hue_2_RGB( var_1, var_2, H + ( 1.0 / 3.0 ) );
     G = 255 * Hue_2_RGB( var_1, var_2, H );
     B = 255 * Hue_2_RGB( var_1, var_2, H - ( 1.0 / 3.0 ) );
  }
}
///////////////////////////////////////////////////////


void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

double hue = 0;
void loop()
{
  
  byte red, green, blue;
  HSL_2_RGB(hue, 1.0, 0.5, red, green, blue);
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
  hue = hue + 0.00005;
  if(hue >= 1.0) 
    hue = 0;
  delay(1);
  
}



