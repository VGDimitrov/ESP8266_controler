void moveString()
{
  if ((millis() - mseconstemp) > (movetime*100)) {
    mseconstemp = millis();
    if (iaction < (charprint1 - 9))
    {
      lcd.setCursor(0, 0);
      for (int prn = 0; prn < 10; prn++)
      {
        lcd.print(mrow1[iaction + prn]);
      }
      iaction++;

    }
    else
    {
      iaction = 0;

    }
  }
}
