void am2320get() {

  humin = myHumidity.readHumidity();
  tempin = myHumidity.readTemperature();
//if (humin==998 || tempin==998){lcd.setCursor(0,3);lcd.print("ERROR I2C");}

}
