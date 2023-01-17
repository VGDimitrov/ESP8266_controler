void lighting(){
 /*
  *  "Активност:",61
  "Режим от/до:",62
  "Начален Час:",63
  "Краен Час:",64
  */
  ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
  lcd.blink();
  switch (menutemp)
  {
    case 1:   
      lcd.setCursor((converter.convert(menutextBG[61]).length())+2,0);
 
  if (butstat1==1){
    menucount=20;
    menutemp=0;
    lcd.noBlink();
    }
  if (butstat2==1){
    if (pirtime == 0) {
      pirtime = 180;
     } else {
      pirtime--;
     }  
    }
  if (butstat3==1)
  {
    if (pirtime >= 180) 
    {
      pirtime = 0;
    } else 
    {
      pirtime++;
    } 
    }
  if (butstat4==1){menutemp++;butstat4=0;}
    break;
    case 2:
      lcd.setCursor((converter.convert(menutextBG[62]).length())+3,1);
     
  if (butstat1==1){
    menutemp--;
    }
  if (butstat2==1){
    piraction=!piraction;
  }
  if (butstat3==1){
    piraction=!piraction;
    }
  if (butstat4==1){
    menutemp++;
  }
    break;
    case 3:
      lcd.setCursor((converter.convert(menutextBG[63]).length())+1,2);
  if (butstat1==1){
   menutemp--;
   }
  if (butstat2==1)
  {
    if (pirHstart == 0) 
    {
      pirHstart = 23;
    } else 
    {
      pirHstart--;
    }   
    }
  if (butstat3==1)
  {
    if (pirHstart >= 23) 
    {
      pirHstart = 0;
    } else 
    {
      pirHstart++;
    }
    
    }
  if (butstat4==1){
    menutemp++;
   }
    break;
    case 4:
      lcd.setCursor((converter.convert(menutextBG[64])).length()+1,3);
      
  if (butstat1==1){
   menutemp--;
   }
  if (butstat2==1)
  {
     if (pirHstop == 0) 
    {
      pirHstop = 23;
    } else 
    {
      pirHstop--;
    }  
    }
  if (butstat3==1)
  {
    if (pirHstop >= 23) 
    {
      pirHstop = 0;
    } else 
    {
      pirHstop++;
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
      lcd.print(converter.convert(menutextBG[61]));
      if (pirtime<100){
      if (pirtime<10){
        lcd.print("00");
        }else{
          lcd.print("0");
        }
      }
      lcd.print(pirtime);
      lcd.print(converter.convert(menutextBG[48]));
  lcd.setCursor(0,1);      
      lcd.print(converter.convert(menutextBG[62]));
      lcd.print(converter.convert(menutextBG[4+piraction]));
      
      
  lcd.setCursor(0,2);      
      lcd.print(converter.convert(menutextBG[63]));
      if (pirHstart<10){lcd.print("0");}
      lcd.print(pirHstart);
      lcd.print(":00 h");
      //lcd.print(converter.convert(menutextBG[45]));
      
  lcd.setCursor(0,3);      
      lcd.print(converter.convert(menutextBG[64]));
      if (pirHstop<10){lcd.print("0");}
      lcd.print(pirHstop); 
      lcd.print(":00 h");
      //lcd.print(converter.convert(menutextBG[45]));   
  }
}
