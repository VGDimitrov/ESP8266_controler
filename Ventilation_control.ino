void Ventilation_Control ()
{
  ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
  lcd.blink();
  switch (menutemp)
  {
    case 1:   
      lcd.setCursor((converter.convert(menutextBG[41]).length())+1,0);
 
  if (butstat1==1){
    menucount=20;
    menutemp=0;
    lcd.noBlink();
    }
  if (butstat2==1){
    if (Hummin == 0) {
      Hummin = Hummax;
     } else {
      Hummin--;
     }  
    }
  if (butstat3==1)
  {
    if (Hummin >= Hummax) 
    {
      Hummin = 0;
    } else 
    {
      Hummin++;
    } 
    }
  if (butstat4==1){menutemp++;butstat4=0;}
    break;
    case 2:
      lcd.setCursor((converter.convert(menutextBG[42]).length())+1,1);
     
  if (butstat1==1){
    menutemp--;
    }
  if (butstat2==1)
  {
    if (Hummax <= Hummin) 
    {
      Hummax = 99;
    } else 
    {
      Hummax--;
    }  
    }
  if (butstat3==1)
  {
    if (Hummax >= 99) 
    {
      Hummax = Hummin;
    } else 
    {
      Hummax++;
    }   
    }
  if (butstat4==1){
    menutemp++;
  }
    break;
    case 3:
      lcd.setCursor((converter.convert(menutextBG[43]).length())+1,2);
  if (butstat1==1){
   menutemp--;
   }
  if (butstat2==1)
  {
    if (Presence == 0) 
    {
      Presence = 99;
    } else 
    {
      Presence--;
    }   
    }
  if (butstat3==1)
  {
    if (Presence >= 99) 
    {
      Presence = 0;
    } else 
    {
      Presence++;
    }
    
    }
  if (butstat4==1){
    menutemp++;
   }
    break;
    case 4:
      lcd.setCursor((converter.convert(menutextBG[44])).length()+1,3);
      
  if (butstat1==1){
   menutemp--;
   }
  if (butstat2==1)
  {
     if (FANtime == 0) 
    {
      FANtime = 59;
    } else 
    {
      FANtime--;
    }  
    }
  if (butstat3==1)
  {
    if (FANtime >= 59) 
    {
      FANtime = 0;
    } else 
    {
      FANtime++;
    }
    
    }
    
  if (butstat4==1){
    menutemp=1;
    }
    break;
  }     
  if (butstat5==1){
    lcd.clear();
    lcd.noBlink();
    ButStatsByte = 0x00;
    eepromwrite();
    menucount=20;
    menutemp=0;
    gattime();
  }   
     
  if (menutemp>4){menutemp=1;}

  if (ButStatsByte != 0x00 || menutemp==0){
  if (menutemp==0 && menucount>20)
  {
    lcd.clear();
    menutemp=1;
  }    
   ButStatsByte = 0x00;
  lcd.setCursor(0,0);
      lcd.print(converter.convert(menutextBG[41]));
      if (Hummin<10){lcd.print("0");}
      lcd.print(Hummin);
      lcd.print("%");
  lcd.setCursor(0,1);      
      lcd.print(converter.convert(menutextBG[42]));
      if (Hummax<10){lcd.print("0");}
      lcd.print(Hummax);
      lcd.print("%");
      
  lcd.setCursor(0,2);      
      lcd.print(converter.convert(menutextBG[43]));
      if (Presence<10){lcd.print("0");}
      lcd.print(Presence);
      lcd.print(converter.convert(menutextBG[48]));
      
  lcd.setCursor(0,3);      
      lcd.print(converter.convert(menutextBG[44]));
      if (FANtime<10){lcd.print("0");}
      lcd.print(FANtime); 
      lcd.print(converter.convert(menutextBG[45]));   
  }
}
