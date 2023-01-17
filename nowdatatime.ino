void NOWDateTime()
{
  ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
  //  H=dt.Hour();
  //  M=dt.Minute();
  //  S=dt.Second();
  //  D=dt.Day();
  //  MNT=dt.Month();
  //  Y=dt.Year();
  //  dw=dt.DayOfWeek();
  RTCh = H * 100 + M;
  //delay(20);
  if (S == 0 || initclock == 0) {

    //Serial.print(datestring);
    lcd.setCursor(10, 0);
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
    lcd.print(" ");
    lcd.print(daysOfTheWeek[dw]);  //- изписва ден от седмицата
    lcd.print(" ");
    lcd.setCursor(12, 0);
    if (D < 10) {
      lcd.print("0");
    }
    lcd.print(D, DEC);
    lcd.print('.');
    if (MNT < 10) {
      lcd.print("0");
    }
    lcd.print(MNT, DEC);
    lcd.print('.');
    lcd.print(Y, DEC);

    
  }
}
