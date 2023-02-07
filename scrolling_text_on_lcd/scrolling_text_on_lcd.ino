#include <SD.h>

#include <Adafruit_FRAM_SPI.h>

#include <MD_MAX72xx_lib.h>
#include <MD_MAX72xx.h>

#include <MD_Parola_lib.h>
#include <MD_Parola.h>

// https://www.engineersgarage.com/moving-text-on-16x2-lcd-with-arduino/
                                                                  
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);      //INITIALIZING LCD IN $_BIT MODE
char c[15]={"teiResa.github.io"};
String s;
void setup()
{
lcd.begin(16 , 2);
lcd.clear();
}
void loop()
{
int i,j,k=0,l=0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Wisit my Site");
delay(1000);
for(i=14;i>=0;i--)
{
  k=0;
  for(j=i;j<=13;j++)
  {
  lcd.setCursor(j,1);
  lcd.print(c[k]);
  delay(70);
  k++;
  if(i==0 && j==13)
  goto xyz;                  //IF string reaches the first matrix drop each character one by one
                             //so it feels that the string is terminating
  
  }
  
}
xyz:
if(i==0 && j==13)
      {
        while(k!=0)
           {
        lcd.setCursor(0,1);
        for(i=k;i>=2;i--)
        {
          l=15-i;
        lcd.print(c[l]);
        delay(70);
        }
        lcd.setCursor(0,0);
        lcd.clear();
        lcd.print("Theresa Balsdon");
          k--;
        }
      }
}
