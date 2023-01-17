void Boiler_Control ()
{
  ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
  //blinkCur();
  lcd.blink();

  switch (menutemp)
  {
    case 1:
    
      lcd.setCursor((converter.convert(menutextBG[34]).length())+1,0);
      
      
  if (butstat1==1){
    menucount=20;
    //butstat1=0;
    menutemp=0;
    lcd.noBlink();
    }
  if (butstat2==1)
  {
    if (bH1 == 0) 
    {
      bH1 = 23;
    } else 
    {
      bH1--;
    }
   // butstat2=0;
    }
  if (butstat3==1)
  {
    if (bH1 >= 23) 
    {
      bH1 = 0;
    } else 
    {
      bH1++;
    }
     //butstat3=0;
    }
  if (butstat4==1){
    menutemp++;
    //butstat4=0;
    }
    break;
    case 2:
      lcd.setCursor((converter.convert(menutextBG[34]).length())+4,0);
      
  if (butstat1==1){
    //butstat1=0;
    menutemp--;
    }
  if (butstat2==1)
  {
    if (bM1 == 0) 
    {
      bM1 = 59;
    } else 
    {
      bM1--;
    }
    //butstat2=0;
    }
  if (butstat3==1)
  {
    if (bM1 >= 59) 
    {
      bM1 = 0;
    } else 
    {
      bM1++;
    }
    //butstat3=0;
    }
  if (butstat4==1){
    menutemp++;
    //butstat4=0;
    }
    break;
    case 3:
      lcd.setCursor((converter.convert(menutextBG[34]).length())+9,0);
     
     // blinkCur();
  if (butstat1==1){
    //butstat1=0;
    menutemp--;
    }
  if (butstat2==1)
  {
    if (bH2 == 0) 
    {
      bH2 = 23;
    } else 
    {
      bH2--;
    }
    //butstat2=0;
    }
  if (butstat3==1)
  {
    if (bH2 >= 23) 
    {
      bH2 = 0;
    } else 
    {
      bH2++;
    }
   // butstat3=0;
    }
  if (butstat4==1){
    menutemp++;
    //butstat4=0;
    }
    break;
    case 4:
      lcd.setCursor((converter.convert(menutextBG[34]).length())+12,0);
      
  if (butstat1==1){
    //butstat1=0;
    menutemp--;
    }
  if (butstat2==1)
  {
     if (bM2 == 0) 
    {
      bM2 = 59;
    } else 
    {
      bM2--;
    }
    //butstat2=0;
    }
  if (butstat3==1)
  {
    if (bM2 >= 59) 
    {
      bM2 = 0;
    } else 
    {
      bM2++;
    }
   // butstat3=0;
    }
    
  if (butstat4==1){
    menutemp++;
    //butstat4=0;
    }
    break;

case 5:
    
      lcd.setCursor((converter.convert(menutextBG[35]).length())+1,1);
      
      
  if (butstat1==1){
    //butstat1=0;
    menutemp--;
    }
  if (butstat2==1)
  {
    if (bH3 == 0) 
    {
      bH3 = 23;
    } else 
    {
      bH3--;
    }
   // butstat2=0;
    }
  if (butstat3==1)
  {
    if (bH3 >= 23) 
    {
      bH3 = 0;
    } else 
    {
      bH3++;
    }
     //butstat3=0;
    }
  if (butstat4==1){
    menutemp++;
    //butstat4=0;
    }
    break;
    case 6:
      lcd.setCursor((converter.convert(menutextBG[35]).length())+4,1);
      
     
      
     // blinkCur();
  if (butstat1==1){
    //butstat1=0;
    menutemp--;
    }
  if (butstat2==1)
  {
    if (bM3 == 0) 
    {
      bM3 = 59;
    } else 
    {
      bM3--;
    }
    //butstat2=0;
    }
  if (butstat3==1)
  {
    if (bM3 >= 59) 
    {
      bM3 = 0;
    } else 
    {
      bM3++;
    }
    //butstat3=0;
    }
  if (butstat4==1){
    menutemp++;
    //butstat4=0;
    }
    break;
    case 7:
      lcd.setCursor((converter.convert(menutextBG[35]).length())+9,1);
     
     // blinkCur();
  if (butstat1==1){
    //butstat1=0;
    menutemp--;
    }
  if (butstat2==1)
  {
    if (bH4 == 0) 
    {
      bH4 = 23;
    } else 
    {
      bH4--;
    }
    //butstat2=0;
    }
  if (butstat3==1)
  {
    if (bH4 >= 23) 
    {
      bH4 = 0;
    } else 
    {
      bH4++;
    }
    //butstat3=0;
    }
  if (butstat4==1){
    menutemp++;
    //butstat4=0;
    }
    break;
    case 8:
      lcd.setCursor((converter.convert(menutextBG[35]).length())+12,1);
      
  if (butstat1==1){
    //butstat1=0;
    menutemp--;
    }
  if (butstat2==1)
  {
     if (bM4 == 0) 
    {
      bM4 = 59;
    } else 
    {
      bM4--;
    }
    //butstat2=0;
    }
  if (butstat3==1)
  {
    if (bM4 >= 59) 
    {
      bM4 = 0;
    } else 
    {
      bM4++;
    }
    //butstat3=0;
    }
    
  if (butstat4==1){
    menutemp++;
    //butstat4=0;
    }
    break;
    case 9:
      lcd.setCursor((converter.convert(menutextBG[36]).length())+1,2);
  if (butstat1==1){
    menutemp--;
    }
  if (butstat2==1)
  {if(bTmin==0)
  {
    bTmin=bTmax-1;
  }else
  {
    bTmin--;
  }
  }
  if (butstat3==1)
  {
    if(bTmin>=bTmax)
  {
    bTmin=0;
  }else
  {
    bTmin++;
  }
  }
  if (butstat4==1){
    menutemp++;
    }
    break;
    case 10:
  lcd.setCursor((converter.convert(menutextBG[34]).length()+converter.convert(menutextBG[37]).length())+5,2);
    
  if (butstat1==1){
    menutemp--;
    }
  if (butstat2==1)
  {if(bTmax<=bTmin)
  {
    bTmax=99;
  }else
  {
    bTmax--;
  }
  }
  if (butstat3==1)
  {
    if(bTmax>=99)
  {
    bTmax=bTmin+1;
  }else
  {
    bTmax++;
  }
  }
  
  if (butstat4==1){
    menutemp++;
    }
    break;
    case 11:
      lcd.setCursor((converter.convert(menutextBG[38]).length())+1,3);
  if (butstat1==1){
    menutemp--;
    }
 if (butstat2==1)
  {if(humoff==0)
  {
    humoff=99;
  }else
  {
    humoff--;
  }
  }
  if (butstat3==1)
  {
    if(humoff>=99)
  {
    humoff=0;
  }else
  {
    humoff++;
  }
  }
  if (butstat4==1){
    menutemp++;
  }
    break;
  
     case 12:
      lcd.setCursor((converter.convert(menutextBG[38]).length()+converter.convert(menutextBG[35]).length())+4,3);
  if (butstat1==1){
   // butstat1=0;
    menutemp--;
    }
 if (butstat2==1)
  {
  
    SMon^=1;
       
  }
  if (butstat3==1)
  {
    SMon^=1;
  }
  if (butstat4==1){
    menutemp++;
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
     
  if (menutemp>12){menutemp=1;}

  
 if (ButStatsByte != 0x00 || menutemp==0){
  if (menutemp==0 && menucount>20)
  {
    lcd.clear();
    menutemp=1;
  }    
  ButStatsByte = 0x00;
  lcd.setCursor(0,0);
      lcd.print(converter.convert(menutextBG[34]));
      if (bH1<10){lcd.print("0");}
      lcd.print(bH1);
      lcd.print(":");
      if (bM1<10){lcd.print("0");}
      lcd.print(bM1);
      lcd.print(" - ");
      if (bH2<10){lcd.print("0");}
      lcd.print(bH2);
      lcd.print(":");
      if (bM2<10){lcd.print("0");}
      lcd.print(bM2);
  lcd.setCursor(0,1);      
      lcd.print(converter.convert(menutextBG[35]));
      lcd.print(bH3);
      lcd.print(":");
      if (bM3<10){lcd.print("0");}
      lcd.print(bM3);
      lcd.print(" - ");
      lcd.print(bH4);
      lcd.print(":");
      if (bM4<10){lcd.print("0");}
      lcd.print(bM4);
  lcd.setCursor(0,2);      
      lcd.print(converter.convert(menutextBG[36])); 
      lcd.print(bTmin);
      lcd.write(char(223));
      lcd.print("C ");
      lcd.print(converter.convert(menutextBG[37]));
      lcd.print(bTmax);
      lcd.write(char(223));
      lcd.print("C ");
  lcd.setCursor(0,3);      
      lcd.print(converter.convert(menutextBG[38]));
      lcd.print(humoff); 
      lcd.print("% ");
      lcd.print(converter.convert(menutextBG[35]));
      lcd.print(converter.convert(menutextBG[5-SMon])); 
  }
}
