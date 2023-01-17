void wifiaccess(){
   ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
char latter[]={'0','1','2','3','4','5','6','7','8','9',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','-','_','+', '-','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ',' ',' ', ' '};
 if (millis()%50==0 || menutemp==0){
  if (menutemp==0)
  {
//    ssid1=" ";
//    password1=" ";
    lcd.clear();
    
    menutemp=1;
    charcount=0;
    lcd.setCursor(0,1);
  lcd.print(ssid1);
  lcd.setCursor(0,3);
  lcd.print(password1);
  }    
  lcd.setCursor(0,0);
  lcd.print(converter.convert(menutextBG[30]));
  
  lcd.setCursor(0,2);
  lcd.print(converter.convert(menutextBG[31]));
  
  
      
 }


 
 
  switch (menutemp){
   
    case 1:
     lcd.noCursor();
     lcd.setCursor(pointer,1);
     lcd.print(latter[charcount]); 
     if (butstat4==1){ssid1=ssid1+String(latter[charcount]);}
     if (butstat1==1){ssid1[pointer]=0;lcd.print(" ");}
     lcd.setCursor(pointer,1);
     lcd.cursor();  
    break;
    case 2:
     lcd.noCursor();
     lcd.setCursor(0,1);
     lcd.print(ssid1);
     lcd.setCursor(pointer,3);
     lcd.print(latter[charcount]);     
     if (butstat4==1){password1=password1+String(latter[charcount]);}
     if (butstat1==1){password1[pointer]=0;lcd.print(" ");}
     lcd.setCursor(pointer,3);
     lcd.cursor();
    break;
     case 3:
     lcd.setCursor(0,0);
     lcd.print(converter.convert(menutextBG[32]));
     lcd.setCursor(0,2);
     lcd.print(converter.convert(menutextBG[33]));
     delay(10);
     
     
     
    break;

  }

  if (butstat1==1){if (pointer==0){menucount=20;menutemp=0;lcd.clear();}else{pointer--;}butstat1=0;}
  if (butstat2==1){charcount--;butstat2=0;}
  if (butstat3==1){charcount++;butstat3=0;}
  if (butstat4==1){if (pointer<19){pointer++;}else{menutemp++;pointer=0;}butstat4=0;}
  if (butstat5==1){
    if (menutemp!=3){
    menutemp++;pointer=0;}
    else{
    writeStringToEEPROM(30,ssid1);
    writeStringToEEPROM(50,password1);
    lcd.clear();
    lcd.setCursor(0, 1); lcd.print("SSID1=");lcd.print(ssid1);
    lcd.setCursor(0, 2);  lcd.print("pas1=");lcd.print(password1);
    delay(5000);
    readStringFromEEPROM(50,ssid);
    readStringFromEEPROM(70,password);
    lcd.clear();
    lcd.setCursor(0, 1); lcd.print(ssid);
    lcd.setCursor(0, 2); lcd.print(password);
    delay(5000);
    menucount=0;
    menutemp=0;
    WiFi.begin(ssid1, password1);
    WiFi.mode(WIFI_STA);
  // WiFi.begin(ssid1, password);//да се отмаркира и измисли как да се въведе име и парола за връзка към рутер
  
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    lcd.clear();
    lcd.setCursor(0, 2); lcd.print("     Errore ");
    lcd.setCursor(3, 3); lcd.print("NAME or Password !!!");
    delay(1000);
  menucount=26;
  return;
  //  ESP.restart();
  }else{
    writeStringToEEPROM(50,ssid);
    writeStringToEEPROM(70,password);
    //eepromwrite();
    server.begin();
  //lcd.clear();
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("********************");
  lcd.setCursor(0, 1); lcd.print("*"); lcd.setCursor(19, 1); lcd.print("*");
  lcd.setCursor(0, 2); lcd.print("*"); lcd.setCursor(19, 2); lcd.print("*");
  lcd.setCursor(0, 3); lcd.print("********************");
  lcd.setCursor(3, 1);
  lcd.print(converter.convert(F("WiFi установена")));
  lcd.setCursor(3, 2); lcd.print("Server started");
  }
  }
  butstat5=0;
  lcd.clear();
  }
 
}
