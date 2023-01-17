void menu(){

  ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
  
  if (millis()%20==0 || menutemp==0){
  if (menutemp==0)
  {
    lcd.clear();
    menutemp=1;
  }    
  
  if (menutemp<4){lcd.setCursor(0,menutemp-1);}else{lcd.setCursor(0,3);}
  lcd.print(">");
  for (int row=0;row<4;row++){
    lcd.setCursor(1,row);
    if (menutemp<5){
      lcd.print(converter.convert(menutextBG[20+row]));
      }
      else
      {
        lcd.print(converter.convert(menutextBG[16+menutemp+row]));
        }
  }
  }
  if (butstat1==1)
  {
    lcd.clear();
    menucount=0;
    butstat1=0;
    menutemp=0;
    
    }
  if (butstat2==1)
  {
    lcd.clear();
    butstat2=0;
    if (menutemp==1)
    {
      menutemp=7;
    }else
      {
        menutemp--;
      }
    }
  if (butstat3==1)
  {
    lcd.clear();
    butstat3=0;
    if (menutemp==7)
    {
      menutemp=1;
      }else
      {
        menutemp++;
      }
   }
  if (butstat4==1){
    lcd.clear();
    butstat4=0;
    menucount=menucount+menutemp;
    menutemp=0;
  } 
  
  if (butstat5==1){
    lcd.clear();
    butstat5=0;
    menucount=menucount+menutemp;
    menutemp=0;
  } 

  
}
