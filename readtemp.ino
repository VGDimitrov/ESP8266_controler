void readtemp() {
int VRT;
sensors.requestTemperatures();
tempC = sensors.getTempCByIndex(0);

if (tempC < 0){
  digitalWrite(setT,1);
  delay(10);
  VRT = analogRead(k1);
  tempC = (1 / (((log((((3.3 / 1023.00) * VRT) / ((3.3 - ((3.3 / 1023.00) * VRT)) / 10000)) / 10000)) / 3977) + (1 / 298.15))) - 273.15;
  digitalWrite(setT,0);
delay (10); 
}
}
