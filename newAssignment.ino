#include <math.h>

double finalArray[7][3] = 
{
    {42,0.8993,-72.03},
    {252,0.17,-34.056},
    {463,0.102,-1.0823},
    {771,0.12,18.9},
    {820,0.184,56.76},
    {900,0.261,65.1},
    {1023,1.357,53.9}
    };

    
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(A0, INPUT);

} 

double Temprature(int RawADC, double a, double b) {
   double Temp;
   Temp = a*RawADC + b;
   Serial.println(a);
   Serial.println(b);
   return Temp;
}
  


int increment = 0;
int i = 0;
bool value = true;
int v = 0;

void loop() {
  i = -1;
  value = true;
  v = analogRead(A0);
  Serial.print(int(v));
  Serial.print("  Measure ");
  Serial.print(int(increment));
  Serial.print(" : ");
  while((i<=6) && (value))
  {
    i++;
    if(v <= finalArray[i][0])
    {
      value = false;
      Serial.println(i);
    }
  }
  Serial.println(int (Temprature(v,finalArray[i][1], finalArray[i][2])));  // display Celsius
  increment++;
  delay(5000);

}

