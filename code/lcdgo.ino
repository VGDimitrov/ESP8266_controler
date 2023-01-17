void lcdgo ()
{
  ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);

  if (menucount==0){

     lcd.setCursor(11, 0);
    if (H < 10) {
      lcd.print("0");
    }
    lcd.print(H);
    lcd.print(":");
    if (M < 10) {
      lcd.print("0");
    }
    lcd.print(M);
    lcd.print(":");
    if (S < 10) {
      lcd.print("0");
    }
    lcd.print(S);
    
    
    
    mrow1="          "+daysOfTheWeek[dw]+" ";
    if (D < 10) {
      mrow1=mrow1+"0";
      }
      mrow1=mrow1+D+".";
      if (MNT < 10) {
      mrow1=mrow1+"0";
      }
      mrow1=mrow1+MNT+".20"+Y;
      //tmp=(tmp,0);humin=(humin,0);
      
      mrow1=mrow1+" "+char(1)+"T="+abs(tempin)+char(223)+"C "+char(2)+"="+abs(humin)+"%           ";
      
//      if (out2==1){
//      mrow22="         "+converter.convert(menutextBG[1])+converter.convert(" Включен T=")+abs(tmp)+char(223)+"C hum="+abs(hum)+"%        ";
//      
//      }else{
//        mrow22="         "+converter.convert(menutextBG[1])+converter.convert(" Изключен T=")+abs(tmp)+char(223)+"C hum="+abs(hum)+"%        ";
//      }
//      if (out1==1){
//      mrow21="         "+converter.convert(menutextBG[0])+converter.convert(" Включен T=")+abs(tempC)+char(223)+"C        ";
//      
//      }else{
//        mrow21="         "+converter.convert(menutextBG[0])+converter.convert(" Изключен T=")+abs(tempC)+char(223)+"C        ";
//      }
      charprint1 = mrow1.length();
//      charprint21 = mrow21.length();
//      charprint22 = mrow22.length();
      moveString();
//      lcd.setCursor(0,3);
//      lcd.print(ButtonByte,HEX);
      if ((millis()-mswrite)>(refreshscreen*1000) || refresh==1){
        mswrite=millis();
        
        if (n>3){n=0;}
        //Serial.println(n);
        //lcd.setCursor(10,2);
        //lcd.print(converter.convert(menutextBG[n+1]));
        lcd.setCursor(0,1);lcd.print("                    ");
        lcd.setCursor(1,1);lcd.print(converter.convert(menutextBG[n]));       
        
        if (rstat1==ON && n==0){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[4]));}
        if (rstat1==OFF && n==0){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[5]));}
        if (bON==1 && n==0){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[6]));}
        if (rstat2==ON && n==1){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[4]));}
        if (rstat2==OFF && n==1){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[5]));}
        if (fanON==1 && n==1){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[6]));}
        if (rstat3==ON && n==2){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[4]));}
        if (rstat3==OFF && n==2){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[5]));}
        if (fanON==1 && n==2){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[6]));}
        if (rstat4==ON && n==3){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[4]));}
        if (rstat4==OFF && n==3){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[5]));}
        if (pirON==1 && n==3){lcd.setCursor(16,1);lcd.print(converter.convert(menutextBG[6]));}
        if (refresh==0){n++;}
        
        refresh=0;
        
if (offmod == HIGH)
  {
    if (rstat1 == ON)
    {
     
      rstat1 = OFF;
      //корегиране на автоматично изключване при висока влажност
    }
    lcd.setCursor(1,3);lcd.print(converter.convert(menutextBG[9]));
    lcd.setCursor(3, 3);
    lcd.print("  ");
//    lcd.setCursor(14, 3);
//    lcd.print("Shower");
  }

  lcd.setCursor(0, 2); lcd.write(1); lcd.print(" "); lcd.setCursor(2, 2); lcd.print(abs(tempC)); lcd.setCursor(4, 2); lcd.print((char)223); lcd.print("C ");
  lcd.setCursor(7, 2); lcd.write(2); lcd.print(" "); lcd.setCursor(9, 2); lcd.print(abs(hum)); lcd.setCursor(11, 2); lcd.print(" % ");
  //lcd.setCursor(7, 3); lcd.write(1); lcd.print(" "); lcd.setCursor(9, 3); lcd.print(tmp); lcd.setCursor(11, 3); lcd.print((char)223); lcd.print("C"); //отпечатване на влажност и температура на дисплей}
  lcd.setCursor(14, 2); lcd.write(1); lcd.print(" "); lcd.setCursor(16, 2); lcd.print(abs(tmp)); lcd.setCursor(18, 2);  lcd.print((char)223); lcd.print("C"); //отпечатване на флажност в коридор поз 3
      if (digitalRead(tuch) == LOW) {//следи и извежда на дисплея Заето/Свободно
        lcd.setCursor(11, 3);
        lcd.print(converter.convert(menutextBG[7]));
      } else{
        lcd.setCursor(11, 3);
        lcd.print(converter.convert(menutextBG[8]));
      }
        //if (n==1){lcd.setCursor(0,1);lcd.print(converter.convert(menutextBG[1]));}
//        if (out4==1&& n==3){lcd.setCursor(10,1);lcd.print(converter.convert(" е ВКЛ.   "));}
//        if (out4==0&& n==3){lcd.setCursor(10,1);lcd.print(converter.convert(" е ИЗКЛ.  "));}
//         if (out3==1&& n==3){lcd.setCursor(0,1);lcd.print(converter.convert(" е ВКЛ.   "));}
//        if (out3==0&& n==3){lcd.setCursor(0,1);lcd.print(converter.convert(" е ИЗКЛ.  "));}
        
      }
      
    }
     
    else{
//     if (language==1){
//    
//  daysOfTheWeek[0] = converter.convert(F("    Неделя    "));
//  daysOfTheWeek[1] = converter.convert(F("    Понеделник     "));
//  daysOfTheWeek[2] = converter.convert(F("    Вторник     "));
//  daysOfTheWeek[3] = converter.convert(F("    Сряда     "));
//  daysOfTheWeek[4] = converter.convert(F("    Четвъртък     "));
//  daysOfTheWeek[5] = converter.convert(F("    Петък     "));
//  daysOfTheWeek[6] = converter.convert(F("    Събота     "));
//  }
//  for (char y=0;y<4;y++){
//
//    
//  rowbuff[y]=menutextBG[y];
////  Serial.println(rowbuff[y]);
//  rowbuff[y]=converter.convert(rowbuff[y]);
//  lcd.setCursor(2,y);
//  lcd.print(rowbuff[y]);
// // delay(1000);
//  }

  }
}
