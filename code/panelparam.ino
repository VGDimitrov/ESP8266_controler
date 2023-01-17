void panelparam(){
 ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
  lcd.blink();
 
 
 switch (menutemp)
  {
    case 1:
     lcd.setCursor((converter.convert(menutextBG[13]).length()),0);
        
  if (butstat2==1)
  {
    //butstat2=0;
    if (language == 0) 
    {
      language = 4;
    } else 
    {
      language--;
    }
    
   }
  if (butstat3==1)
  {
    //butstat3=0;
    if (language >= 2) 
    {
      language = 0;
    } else 
    {
      language++;
    }
     
    }
  
  break;
   case 2:
     lcd.setCursor((converter.convert(menutextBG[46])).length()+1,1);
      
        if (butstat2==1)
          {
          // butstat2=0;
              if (HOUR == 0) 
                {
                  HOUR = 23;
                 } else 
                {
                 HOUR--;
                }
    
          }
        if (butstat3==1)
          {
          //  butstat3=0;
            if (HOUR >= 23) 
           {
            HOUR = 0;
            } else 
             {
             HOUR++;
             }
     
       }
    
    break;

   case 3:
     lcd.setCursor((converter.convert(menutextBG[46])).length()+4,1);
       
  if (butstat2==1)
  {
   // butstat2=0;
    if (MINUT == 0) 
    {
      MINUT = 59;
    } else 
    {
      MINUT--;
    }
    
   }
  if (butstat3==1)
  {
  //  butstat3=0;
    if (MINUT >= 59) 
    {
      MINUT = 0;
    } else 
    {
      MINUT++;
    }
     
    }
  
  break;
case 4:
     lcd.setCursor((converter.convert(menutextBG[46])).length()+7,1);
     
  if (butstat2==1)
  {
   // butstat2=0;
    if (DAY == 0) 
    {
      DAY = 31;
    } else 
    {
      DAY--;
    }
    
   }
  if (butstat3==1)
  {
  //  butstat3=0;
    if (DAY >= 31) 
    {
      DAY = 0;
    } else 
    {
      DAY++;
    }
     
    }
  
  break;
case 5:
     lcd.setCursor((converter.convert(menutextBG[46])).length()+10,1);
      
  if (butstat2==1)
  {
   // butstat2=0;
    if (MONTH == 0) 
    {
      MONTH = 12;
    } else 
    {
      MONTH--;
    }
    
   }
  if (butstat3==1)
  {
  //  butstat3=0;
    if (MONTH >= 12) 
    {
      MONTH = 0;
    } else 
    {
      MONTH++;
    }
     
    }
    
    break;
 case 6:
     lcd.setCursor((converter.convert(menutextBG[46])).length()+13,1);
       
  if (butstat2==1)
  {
  // butstat2=0;
    if (YEAR == 0) 
    {
      YEAR = 99;
    } else 
    {
      YEAR--;
    }
    
   }
  if (butstat3==1)
  {
  //  butstat3=0;
    if (YEAR >= 99) 
    {
      YEAR = 0;
    } else 
    {
      YEAR++;
    }
     
    }
  
 break;
 case 7:
     lcd.setCursor((converter.convert(menutextBG[47])).length(),2);
       
  if (butstat2==1)
  {
   // butstat2=0;
    nightmode=!nightmode;
   }
  if (butstat3==1)
  {
  //  butstat3=0;
    nightmode=!nightmode;
    }
  
 break;
 case 8:
  lcd.setCursor((converter.convert(menutextBG[47])).length()+6,2);   
  if (butstat2==1)
  {
   // butstat2=0;
    if (night == 0) 
    {
      night = 23;
    } else 
    {
      night--;
    }
    
   }
  if (butstat3==1)
  {
  //  butstat3=0;
    if (night >= 23) 
    {
      night = 0;
    } else 
    {
      night++;
    }
     
    }
  
 break;
 case 9:
   
   lcd.setCursor((converter.convert(menutextBG[47])).length()+9,2);
  if (butstat2==1)
  {
   // butstat2=0;
    if (nightend == 0) 
    {
      nightend = 23;
    } else 
    {
      nightend--;
    }
    
   }
  if (butstat3==1)
  {
   // butstat3=0;
    if (nightend >= 23) 
    {
      nightend = 0;
    } else 
    {
      nightend++;
    }
     
    }
  
 break;
 case 10:
   
   lcd.setCursor((converter.convert(menutextBG[19])).length(),3);
  if (butstat2==1)
  {
   // butstat2=0;
    if (movetime == 1) 
    {
      movetime = 9;
    } else 
    {
      movetime--;
    }
    
   }
  if (butstat3==1)
  {
   // butstat3=0;
    if (movetime >= 9) 
    {
      movetime = 1;
    } else 
    {
      movetime++;
    }
     
    }
  
 break;
 case 11: 
  lcd.setCursor((converter.convert(menutextBG[18])).length()+(converter.convert(menutextBG[19])).length()+2,3);
  if (butstat2==1)
  {
    if (refreshscreen == 1) 
    {
      refreshscreen = 9;
    } else 
    {
      refreshscreen--;
    }   
   }
  if (butstat3==1)
  {
    if (refreshscreen >= 9){
      refreshscreen = 1;
    } else {
      refreshscreen++;
    } 
    }
 break;
  }     
  if (butstat5==1){
    lcd.clear();
    lcd.noBlink();
    
    
    eepromwrite();
    menucount=20;
    menutemp=0;
    rtc.disableClock();
    rtc.setDateTime(SECOND, MINUT, HOUR, dw, DAY, MONTH, YEAR);
    rtc.enableClock();
    rtc.getDateTime(&S, &M, &H, &dw, &D, &MNT, &Y);
    lcd.setCursor(2,1);
    lcd.print("System Reboot... ");
    delay(2000);

    //Rtc.SetDateTime(compiled);RtcDateTime now = Rtc.GetDateTime();
    //NOWDateTime();


    
    ESP.restart();
   
  }   
  if (butstat1==1)
  {
    
   if (menutemp==1)
         {
           lcd.noBlink();
           lcd.clear();
           menucount=20;
           menutemp=0;
         }
   if (nightmode==0 && menutemp==10 ){
   menutemp=8;
   }
   menutemp--;
  }
  if (butstat4==1)
  {
    menutemp++;
    
    
    if (nightmode==0 && menutemp==8 ){menutemp=10;}
    if (menutemp>11){menutemp=1;}
   }   
  if (ButStatsByte != 0x00 || menutemp==0){
  if (menutemp==0 && menucount>20)
  {
    lcd.clear();
    
    menutemp=1;
    
      HOUR = H;
      MINUT = M;
      SECOND = S;
      DAY = D;
      MONTH = MNT;
      YEAR = Y; 
      //setTD = 2;
    
  }    
  ButStatsByte = 0x00;
  lcd.setCursor(0,0);
  lcd.print(converter.convert(menutextBG[13]));
  lcd.print(converter.convert(menutextBG[language+14]));
  lcd.setCursor(0,1);
  lcd.print(converter.convert(menutextBG[46]));
      if (HOUR < 10) {
      lcd.print("0");
      lcd.print(HOUR, DEC);
    } else {
      lcd.print(HOUR, DEC);
    } lcd.print(":");
    if (MINUT < 10) {
      lcd.print("0");
      lcd.print(MINUT, DEC);
    } else {
      lcd.print(MINUT, DEC);
    } 
    lcd.print(" ");
    if (DAY < 10) {
      lcd.print("0");
      lcd.print(DAY, DEC);
    } else {
      lcd.print(DAY, DEC);
    } lcd.print(".");
    if (MONTH < 10) {
      lcd.print("0");
      lcd.print(MONTH, DEC);
    } else {
      lcd.print(MONTH, DEC);
    } 
    lcd.print("."); 
    if (YEAR < 10) {
      lcd.print("0");
      lcd.print(YEAR, DEC);
    } else {
    lcd.print(YEAR, DEC);
    }
  lcd.setCursor(0,2);
  lcd.print(converter.convert(menutextBG[47]));
  lcd.print (converter.convert(menutextBG[5-nightmode]));
  if(nightmode==1)
  {
    lcd.setCursor((converter.convert(menutextBG[47])).length()+5,2);
  
   if (night < 10) {
    
      lcd.print("0");
      lcd.print(night, DEC);
    } else {
      lcd.print(night, DEC);
    }
  lcd.print("-");
  if (nightend < 10) {
      lcd.print("0");
      lcd.print(nightend, DEC);
    } else {
      lcd.print(nightend, DEC);
    }
  lcd.print("h");
  
  }else
  {
    int jjj=(converter.convert(menutextBG[47])).length();
    lcd.setCursor(jjj+3,2);
    jjj=17-jjj;
    while (jjj!=0){
      lcd.print(" ");
      jjj--;
    }
    
  }
  lcd.setCursor(0,3);
  lcd.print(converter.convert(menutextBG[19]));
  
  lcd.print(movetime);
  lcd.print(" ");
  lcd.print(converter.convert(menutextBG[18]));
  
  lcd.print(refreshscreen);
 }
}
