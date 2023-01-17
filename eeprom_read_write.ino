void eepromwrite() {

  EEPROM.write(49, 1);
  EEPROM.write(0, bH1);
  EEPROM.write(1, bM1);
  EEPROM.write(2, bH2);
  EEPROM.write(3, bM2);
  EEPROM.write(4, bH3);
  EEPROM.write(5, bM3);
  EEPROM.write(6, bH4);
  EEPROM.write(7, bM4);

  EEPROM.write(8, Hummin);
  EEPROM.write(9, Hummax);
  EEPROM.write(10, Presence);
  EEPROM.write(11, FANtime);
  EEPROM.write(12, humoff);
  EEPROM.write(13, bTmin);
  EEPROM.write(14, bTmax);
  EEPROM.write(15, SMon);
  EEPROM.write(16, language);
  EEPROM.write(17, buttonset[0]/4);
  EEPROM.write(18, buttonset[1]/4);
  EEPROM.write(19, buttonset[2]/4);
  EEPROM.write(20, buttonset[3]/4);
  EEPROM.write(21, buttonset[4]/4);
  EEPROM.write(22, nightmode);
  EEPROM.write(23, night);
  EEPROM.write(24, nightend);
  EEPROM.write(25, movetime);
  EEPROM.write(26, refreshscreen);
  EEPROM.write(27, piraction);
  EEPROM.write(28, pirtime);
  EEPROM.write(29, pirHstart);
  EEPROM.write(30, pirHstop);
 
//  for (int k;k<20;k++)
//  {
//    EEPROM.write(20+k, ssid[k]);
//    EEPROM.write(40+k, password[k]);
//  }
  EEPROM.commit();

}
void eepromread() 
{
if (EEPROM.read(49)==1){
  bH1 = EEPROM.read(0);
  bM1 = EEPROM.read(1);
  bH2 = EEPROM.read(2);
  bM2 = EEPROM.read(3);
  bH3 = EEPROM.read(4);
  bM3 = EEPROM.read(5);
  bH4 = EEPROM.read(6);
  bM4 = EEPROM.read(7);

  Hummin = EEPROM.read(8);
  Hummax = EEPROM.read(9);
  Presence = EEPROM.read(10);
  FANtime = EEPROM.read(11);
  humoff = EEPROM.read(12);
  bTmin = EEPROM.read(13);
  bTmax = EEPROM.read(14);
  SMon = EEPROM.read(15);
  language = EEPROM.read(16);
  buttonset[0] = EEPROM.read(17);
  buttonset[1] = EEPROM.read(18);
  buttonset[2] = EEPROM.read(19);
  buttonset[3] = EEPROM.read(20);
  buttonset[4] = EEPROM.read(21);
  buttonset[0]=buttonset[0]*4;
  buttonset[1]=buttonset[1]*4;
  buttonset[2]=buttonset[2]*4;
  buttonset[3]=buttonset[3]*4;
  buttonset[4]=buttonset[4]*4;
  nightmode     = EEPROM.read(22);
  night         = EEPROM.read(23);
  nightend      = EEPROM.read(24);
  movetime      = EEPROM.read(25);
  refreshscreen = EEPROM.read(26);
  piraction     = EEPROM.read(27);
  pirtime       = EEPROM.read(28);
  pirHstart     = EEPROM.read(29);
  pirHstop      = EEPROM.read(30);
  
}
else
{
  constants();
  eepromwrite();
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Write constants");
  lcd.setCursor(0,2);
  lcd.print("to EEPROM");
  lcd.setCursor(0,3);
  lcd.print("REBOOT");
  ESP.restart();
}
//  for (int k;k<20;k++)
//  {
//    ssid[k]=EEPROM.read(20+k);
//    password[k]=EEPROM.read(40+k);
//    
//  }
  gattime();

}

void writeStringToEEPROM(int addrOffset, const String &strToWrite)
    {
      byte len = strToWrite.length();
      EEPROM.write(addrOffset, len);
      for (int i = 0; i < len; i++)
      {
        EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
      }
    }
   


void readStringFromEEPROM(int addrOffset, String &strToRead)
{
byte newStrLen = EEPROM.read(addrOffset);
char data[newStrLen + 1];
for (int i = 0; i < newStrLen; i++)
{
data[i] = EEPROM.read(addrOffset + 1 + i);
}
data[newStrLen] = '\0';
strToRead = String(data);
}
