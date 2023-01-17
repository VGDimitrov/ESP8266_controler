void Heading ()
{
  lcd.setCursor(0,0);
  lcd.print(" B1-");
  lcd.print(buttonset[0]);
  lcd.print(" B2-");
  lcd.print(buttonset[1]);
  lcd.setCursor(0,1);
  lcd.print(" B3-");
  lcd.print(buttonset[2]);
  lcd.print(" B4-");
  lcd.print(buttonset[3]);
  lcd.setCursor(0,2);
  lcd.print(" B5-");
  lcd.print(buttonset[4]);
  lcd.setCursor(0,3);
  lcd.print("KAY- ");
  lcd.print("     ");
  lcd.setCursor(5,3);
  lcd.print(analogRead(k1));
    if(butstat5==1){menucount=0;butstat5=0;}
}
