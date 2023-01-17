void mainbuttons() {

  ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);


  
  if ( RTCh/100 > night || RTCh/100 < nightend) {
    if (nightmode==1)
      {
//    if (rstat3 == ON || ButtonByte != 0x00 ) {
//      RTCm = M;  //превключване нощен и дневен режим на дисплея
//      lcd.backlight();
//    } else {
//      if (M - RTCm == lcdofftime) {
//        lcd.noBacklight();
//        //delay(12);
//      }
// }
      lcd.noBacklight();
     }
  } else {
    lcd.backlight();
  }
  
  //отработване на събитие на бутон 1 БОЙЛЕР
//  if (butstat1 == 1 && rstat1 == LOW) {
//    digitalWrite(r1, HIGH);
//    rstat1 = HIGH;
//    butstat1 = 0;
//    bON = LOW;
//  }
//  if (butstat1 == 1 && rstat1 == HIGH) {
//    digitalWrite(r1, LOW);
//    rstat1 = LOW;
//    butstat1 = 0;
//    bON = LOW;
//  }
//  if (butstat11=1 && bON == LOW) {
//    bON = HIGH;  //butstat1=LOW;
//    butstat11=0;
//
//    digitalWrite(r1, LOW);
//    rstat1 = LOW;
//  }
//  if (butstat11=1 && bON == HIGH) {
//    bON = LOW;  //butstat1=LOW;
//    butstat11=0;
//    digitalWrite(r1, LOW);
//    rstat1 = LOW;
//  }

  if (BoilerTime1 > BoilerTime2 ) {
    if (RTCh > BoilerTime2 && RTCh < BoilerTime1 ) {
      r226 = LOW;
    } else {
      r226 = HIGH;
    }
  }
  if (BoilerTime1 < BoilerTime2 ) {
    if (RTCh >= BoilerTime1 && RTCh < BoilerTime2 ) {
      r226 = HIGH;
    } else {
      r226 = LOW;
    }
  }
  if (r226 == LOW && SMon == HIGH) {
    if (BoilerTime3 > BoilerTime4 ) {
      if (RTCh > BoilerTime4 && RTCh < BoilerTime3 ) {
        secondmod = LOW;
      } else {
        secondmod = HIGH;
      }
    }
    if (BoilerTime3 < BoilerTime4 ) {
      if (RTCh >= BoilerTime3 && RTCh < BoilerTime4 ) {
        secondmod = HIGH;
      } else {
        secondmod = LOW;
      }
    }
  } else {
    secondmod = LOW;
  }
  if (hum > humoff) {
    offmod = HIGH;
  } else {
    offmod = LOW;
  }

  if (bON == HIGH) {
    if (r226 == HIGH && offmod == LOW) {
      if (rstat1 == OFF) {
        rstat1 = ON;
      } 
      automod = LOW;
      lcd.setCursor(4, 3);
      lcd.print("N");
      lcd.setCursor(3, 3);
      lcd.print(" ");
    }//else{if(rstat1==HIGH){digitalWrite(r1, LOW);rstat1=LOW;}lcd.setCursor(3,3);lcd.print("   ");lcd.setCursor(14,3);lcd.print("Shower");}}
    //if (r226 == LOW && offmod == LOW){if(rstat1==HIGH){digitalWrite(r1, LOW);rstat1=LOW;}lcd.setCursor(4,3);lcd.print(" ");}

    if (secondmod == HIGH && offmod == LOW) {
      if (rstat1 == OFF) {
        rstat1 = ON;
      }
      automod = LOW;
      lcd.setCursor(3, 3);
      lcd.print("S ");
    }
    if (secondmod == LOW && r226 == LOW && automod == LOW && offmod == LOW) {
      if (rstat1 == ON) {
     //   digitalWrite(r1, LOW);
        rstat1 = OFF;
        automod = HIGH;
      } lcd.setCursor(3, 3);
      lcd.print("  ");
    }

    if (r226 == LOW && secondmod == LOW && automod == HIGH && offmod == LOW) {
      lcd.setCursor(4, 3);
      lcd.print(" A");
      if (tempC < bTmin && RTCh < (BoilerTime1 - 300)) {
        if (rstat1 == OFF) {
        //  digitalWrite(r1, HIGH);
          rstat1 = ON;
        }
      }
    }
    if (r226 == LOW && secondmod == LOW && automod == HIGH && offmod == LOW) {
      if (tempC >= bTmax) {
        if (rstat1 == ON) {
          rstat1 = OFF;
        }
      }
    }
    //if (offmod == HIGH){if (rstat1==HIGH){digitalWrite(r1, LOW);rstat1=LOW;}lcd.setCursor(3,3);lcd.print("   ");lcd.setCursor(14,3);lcd.print("Shower");}//else{lcd.setCursor(14,3);lcd.print("      ");}

  }
  

  //отработване на събитие от бутон 2 Вентилация
//  if (butstat2 == 1 && rstat2 == LOW) {
//    digitalWrite(r2, HIGH);
//    fanON = LOW;
//    rstat2 = HIGH;
//    butstat2 = 0;
//  }
//  if (butstat2 == 1 && rstat2 == HIGH) {
//    digitalWrite(r2, LOW);
//    fanON == LOW;
//    rstat2 = LOW;
//    butstat2 = 0;
//  }
//  if (butstat21 == 1 &&  fanON == LOW) {
//    fanON = HIGH;  //butstat2=LOW;digitalWrite(r2, LOW);rstat2=LOW;
//    butstat21 = 0;
////    lcd.setCursor(0, 1);
////    lcd.print("Auto");
//  }
//  if (butstat21 == 1 &&  fanON == HIGH) {
//    fanON = LOW;  //butstat2=LOW;
//    butstat21 = 0;
//    digitalWrite(r2, LOW);
//    rstat2 = LOW;
//    digitalWrite(r4, LOW);
//    rstat4 = LOW;
////    lcd.setCursor(1, 3);
////    lcd.print(" ");
////    lcd.setCursor(7, 1);
////    lcd.print("2:OFF ");
//  }


  //дефиниране на четене на термо датвик и влажност при натиснат бутон 2 Вентилация
  if (fanON == HIGH) {
    if (hum > (humin + Hummax) && rstat2 == OFF) {
     // digitalWrite(r2, HIGH);
      rstat2 = ON;
      fanstat = HIGH;
      if (rstat4 == OFF && tempC < 22) {
      //  digitalWrite(r4, LOW);
        rstat4 = ON;
        lcd.setCursor(1, 3); lcd.print("H");
      }
    }

    if (fanstat == HIGH) {
      if (hum < (humin + Hummin) && rstat2 == ON) {
       // digitalWrite(r2, LOW);
        rstat2 = OFF;
        fanstat = OFF;
        if (rstat4 == ON) {
         // digitalWrite(r4, HIGH);
          rstat4 = OFF;
          lcd.setCursor(1, 3); lcd.print(" ");
        }
      }
    } else {
      if (digitalRead(tuch) == 1) {                                         //да се коригира ниско и високо ниво
        m = millis();
//        lcd.setCursor(14, 3);
//        lcd.print("Svob.!");
      }
//      if (digitalRead(tuch) == LOW) {
//        lcd.setCursor(14, 3);
//        lcd.print("Zaeto!");
//      }
      if (digitalRead(tuch) == 0 && (millis() - m) / 1000 > Presence ) {//Presence * 60
       // digitalWrite(r2, HIGH);
        rstat2 = ON;
        m2 = millis();
//        lcd.setCursor(0,3);
//        lcd.print(rstat2);
      }
      if (rstat2 == ON && digitalRead(tuch) == 1 && (millis() - m2) / 1000 > FANtime * 60) {
     //   digitalWrite(r2, LOW);
        rstat2 = OFF;
//        lcd.setCursor(0,3);
//        lcd.print(rstat2);
//        lcd.setCursor(14, 3);
//        lcd.print("Svob.!");
      }
    }
    //if (fanON == HIGH && tmp < 18){if(rstat4==LOW && tmp!=0){digitalWrite(r4,LOW);rstat4=HIGH;}lcd.setCursor(1,3);lcd.print("H");}else{if(rstat4==HIGH && tmp>=28){digitalWrite(r4,HIGH);rstat4=LOW;lcd.setCursor(1,3);lcd.print(" ");}}//heating
  }
  //отработване на събитие прочетено от бутон3 Осветление
//  if (butstat3 == 1 && rstat3 == LOW) {
//    digitalWrite(r3, HIGH);
//    pirON = LOW;
//    rstat3 = HIGH;
//    butstat3 = 0;
//  }
//  if (butstat3 == 1 && rstat3 == 1) {
//    digitalWrite(r3, LOW);
//    pirON = LOW;
//    rstat3 = LOW;
//    butstat3 = 0;
////    lcd.setCursor(14, 1);
////    lcd.print("3:OFF ");
////    lcd.setCursor(2, 3);
////    lcd.print(" ");
//  }
//  if (butstat31 == 1 && pirON == 0) {
//    pirON = HIGH;
//    butstat31 = 0;
////    lcd.setCursor(0, 1);
////    lcd.print("Auto");
//  }
//  if (butstat31 == 1 && pirON == HIGH) {
//    pirON = LOW; butstat31 = 0; digitalWrite(r3, HIGH); rstat3 = LOW; butstat3 = LOW; 
////    lcd.setCursor(14, 1); lcd.print("3:OFF ");
//    //butstat3=HIGH;
//  }

  //сработване на ПИР с 10сек. закъснение при изключване (избягване на неактивно време на модула)


  if (pirON == HIGH) {
    if (digitalRead(pirPin) == LOW ) {
      npir = npir + 1;
      if (npir > 10) {
        if (piraction==1){
        if (RTCh > pirHstart*100 || RTCh < pirHstop*100) {
         rstat4 = ON;
         lcd.setCursor(2, 3);
         lcd.print("M");
         m3 = millis();
        }
        }else{
          lcd.setCursor(2, 3);
          lcd.print("M");
          rstat4 = ON;
          m3 = millis();
          
        }
      }
    } else {
      npir = 0;
    }
    //&& RTCh<900|| digitalRead(pirPin) == HIGH && RTCh>1700){digitalWrite(r3, LOW);lcd.setCursor(2,3);lcd.print("M");rstat3=HIGH;m3=millis();}
    // ){digitalWrite(r3, HIGH);lcd.setCursor(2,3);lcd.print("M");rstat3fix = HIGH;rstat3=HIGH;}
    if (digitalRead(pirPin) == HIGH && rstat4 == ON && (millis() - m3) > (pirtime*1000+7000) ) {
      
      lcd.setCursor(2, 3);
      lcd.print(" ");
      rstat4 = OFF;
      
    }
  }
  // ------------LCD PRINT FUNCtion-------------
//  if (rstat1 == HIGH && bON == LOW) {
//    lcd.setCursor(11, 1);
//    lcd.print(" ON ");
//    mrow21 = converter.convert(F("         Бойлера е Включен         "));
//    charprint21 = mrow22.length();
//  }
//  if (rstat1 == LOW && bON == LOW) {
//    lcd.setCursor(11, 1);
//    lcd.print("OFF ");
//    mrow21 = converter.convert(F("         Бойлера е Изключен         "));
//    charprint21 = mrow22.length();
//  }
//  if (rstat2 == HIGH && fanON == LOW) {
//    lcd.setCursor(7, 1);
//    lcd.print("2:ON  ");
//    mrow22 = converter.convert(F("         Вентилацията е Включена         "));
//    charprint22 = mrow22.length();
//  }
//  if (rstat2 == LOW && fanON == LOW) {
//    lcd.setCursor(7, 1);
//    lcd.print("2:OFF ");
//    mrow22 = converter.convert(F("         Вентилацията е Изключена         "));
//    charprint22 = mrow22.length();
//  }
//  if (rstat3 == HIGH && pirON == LOW) {
//    lcd.setCursor(14, 1);
//    lcd.print("3:ON  ");
//    mrow21 = converter.convert(F("         Осветлението е Включено         "));
//    charprint21 = mrow22.length();
//  }
//  if (rstat3 == LOW && pirON == LOW) {
//    lcd.setCursor(14, 1);
//    lcd.print("3:OFF ");
//    mrow21 = converter.convert(F("         Осветлението е Включено         "));
//    charprint21 = mrow22.length();
//  }
}
