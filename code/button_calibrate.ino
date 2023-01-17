void buttoncalibrate(){
  unsigned long delaytemp;
 
  lcd.setCursor(0, 0);
  lcd.print("Calibration Buttons");
  lcd.setCursor(4, 2);
  lcd.print("PLEASE PRESS");
 for (int j=0;j<5;j++){
  while (buttonset[j]==0){
          wdt_reset();
          
          lcd.setCursor(6, 3);
          lcd.print("BUTTON ");
//         Serial.print("Button ");
//          Serial.println(j+1);
          lcd.print(j+1);
            if (analogRead(k1)<1000 ) {
                buttemp=0;
                  for( byte nkay=0; nkay<8; nkay++){
                      buttemp+=analogRead(k1);
                    }
                 buttemp=buttemp/8;
            buttonset[j]=buttemp+40;
            
              }   
     }
//     lcd.setCursor(15,3);
//      lcd.print(buttonset[j]);
      
//    while ((millis()-delaytemp)<200){
//      
//    }
delay(250);
 } 
if (buttonset[0]>buttonset[1] && buttonset[1]>buttonset[2] && buttonset[2]>buttonset[3] && buttonset[3]>buttonset[4]){
  lcd.clear();
  //wdt_reset();
  ButtonByte=0x00;holdButton=0;
  menucount=0;
  eepromwrite();
  }else{
    ButtonByte=0x30;
    holdButton=1;
    }
}
