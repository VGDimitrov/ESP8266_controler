void blinkCur()
{  
  if (millis()%1000==0){
    waitc^=1;
  }
  if(waitc == 0)
    {
      lcd.blink();
     // waitc = 1;
      //delay(50);
    }
    else
    {
      lcd.noBlink();
      //waitc = 0;
     // delay(50);
    }
}
void blinkpok()
{byte waitc;
  if(waitc == 0)
    {
      lcd.blink();
      waitc = 1;
      delay(80);
    }
    else
    {
      lcd.noBlink();
      waitc = 0;
//      delay(80);
    }
}
void testinterrup()
{
  rstat3=!rstat3;
}
