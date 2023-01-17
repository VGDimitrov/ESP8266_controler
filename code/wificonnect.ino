void inicialization ()
{
  ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
  byte con;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(converter.convert (menutextBG[50]));
  lcd.setCursor(0, 1);
  lcd.print(converter.convert (menutextBG[51]));
  lcd.setCursor(0, 3);
  lcd.print(converter.convert (menutextBG[59]));

  
  

  
  
  lcd.setCursor(0, 2);
  lcd.print(ssid);
  lcd.print("...");

  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_STA);
    delay(2000);  
  
if (WiFi.waitForConnectResult() == WL_CONNECTED) {
  server.begin();
  //lcd.clear();
//  lcd.clear();
//  lcd.setCursor(0, 0); lcd.print("********************");
//  lcd.setCursor(0, 1); lcd.print("*"); lcd.setCursor(19, 1); lcd.print("*");
//  lcd.setCursor(0, 2); lcd.print("*"); lcd.setCursor(19, 2); lcd.print("*");
//  lcd.setCursor(0, 3); lcd.print("********************");
  lcd.setCursor(0, 2);
  lcd.print(converter.convert(menutextBG[52]));
  //lcd.setCursor(3, 2); lcd.print("Server started");
  ////Serial.println("Server started");
  delay(2000);
  // Print the IP address
//  lcd.clear();
//  lcd.setCursor(0, 0); lcd.print("********************");
//  lcd.setCursor(0, 1); lcd.print("*"); lcd.setCursor(19, 1); lcd.print("*");
//  lcd.setCursor(0, 2); lcd.print("*"); lcd.setCursor(19, 2); lcd.print("*");
//  lcd.setCursor(0, 3); lcd.print("********************");
  lcd.setCursor(0, 1); 
  lcd.print("                    ");
  lcd.setCursor(3, 1);
  lcd.print(converter.convert(menutextBG[54]));
  lcd.setCursor(0, 2); 
  lcd.print("                    ");
  lcd.setCursor(2, 2);
   lcd.print(WiFi.localIP());
  delay(3000);
}
else
{
  lcd.setCursor(0, 1); 
  lcd.print("                    ");
  lcd.setCursor(0, 1); 
  lcd.print(converter.convert (menutextBG[53]));
  delay(2000);
}
}
