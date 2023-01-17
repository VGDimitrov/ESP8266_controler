void BME280GAT() {
  wdt_reset();
   if (bme1Detected) { 
    
    tmp=bme1.readTempC();
    hum=bme1.readHumidity();
//  BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
//   BME280::PresUnit presUnit(BME280::PresUnit_Pa);
//  uint8_t pressureUnit(3);                                           // unit: B000 = Pa, B001 = hPa, B010 = Hg, B011 = atm, B100 = bar, B101 = torr, B110 = N/m^2, B111 = psi
//  bme2.read(presin, tmp, hum, tempUnit, presUnit);
  
   delay(50);}
   else{
   hum=0;tmp=0; 
    
    lcd.setCursor(0,3);
lcd.print("NONE Sensor");

  }
  if (bme2Detected) { 
    
    tempin=bme2.readTempC();
    humin=bme2.readHumidity();
//  BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
//   BME280::PresUnit presUnit(BME280::PresUnit_Pa);
//  uint8_t pressureUnit(3);                                           // unit: B000 = Pa, B001 = hPa, B010 = Hg, B011 = atm, B100 = bar, B101 = torr, B110 = N/m^2, B111 = psi
//  bme2.read(presin, tmp, hum, tempUnit, presUnit);
  
   delay(50);}
   else{
   humin=0;tempin=0; 
    
    lcd.setCursor(0,3);
lcd.print("NONE Sensor");

  }
//   if (hum=='nan'){hum=0;}
//if (tmp<-20 || tmp>99){tmp=99;}
//lcd.setCursor(0,3);
//lcd.print(hum);
//lcd.print(tmp);
}
