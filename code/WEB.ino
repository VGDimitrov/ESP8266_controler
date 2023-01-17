void WEB() {
  WiFiClient client = server.available();

  if (!client ) {
    client.print("<meta http-equiv=\"refresh\" content=\"20\">");
    return;
  }


  // Read the first line of the request
  String request = client.readStringUntil('\r');

  client.flush();

  // Match the request

  if (request.indexOf("/LED=ON") != -1) {
    bON = LOW;
    if (rstat1 == OFF) 
    {
      rstat1 = ON;
    }
  }
  if (request.indexOf("/LED=OFF") != -1) {
    bON = LOW;
    if (rstat1 == ON) {
      
      rstat1 = OFF;
    }
  }

  if (request.indexOf("/LED2=ON") != -1) {
    fanON = LOW;
    if (rstat2 == OFF) {
      
      rstat2 = ON;
    }
  }

  if (request.indexOf("/LED2=OFF") != -1) {
    fanON = LOW;
    if (rstat2 == ON) {
      
      rstat2 = OFF;
    }
  }

  if (request.indexOf("/HEATING=ON") != -1) {
    if (rstat4 == OFF) {
      
      rstat4 = ON;
//      lcd.setCursor(1, 3);
//      lcd.print("H");
    }
  }

  if (request.indexOf("/HEATING=OFF") != -1) {
    if (rstat4 == ON) {
      
      rstat4 = OFF;
//      lcd.setCursor(1, 3);
//      lcd.print(" ");
    }
  }
  if (request.indexOf("/LED3=ON") != -1) {
    pirON = LOW;
    if (rstat3 == OFF) {
      
      rstat3 = ON;
    }
  }

  if (request.indexOf("/LED3=OFF") != -1) {
    pirON = LOW;
    if (rstat3 == ON) {
     
      rstat3 = OFF;
    }
  }

  if (request.indexOf("/LED=AutoON") != -1) {
    if (bON == LOW && menucount==0) {
      bON =1;
      
    }
  }

  if (request.indexOf("/LED=AutoOFF") != -1) {
    if (bON == HIGH && menucount==0) {
      bON =0;
     
    }
  }
  if (request.indexOf("/LED2=AutoON") != -1) {
    if (fanON == LOW && menucount==0) {
      fanON = HIGH;
    
      
    }
  }

  if (request.indexOf("/LED2=AutoOFF") != -1) {
    if (fanON == HIGH && menucount==0) {
      fanON = 0;
     
    }
  }

  if (request.indexOf("/LED3=AutoON") != -1) {
    if (pirON == LOW && menucount==0) {
      pirON = HIGH;
      
    }
  }

  if (request.indexOf("/LED3=AutoOFF") != -1) {
    if (pirON == HIGH && menucount==0) {
      pirON = HIGH;
      
    }
  }

  if (request.indexOf("/SECOND+") != -1) {
    SECOND = SECOND + 1;
  }

  if (request.indexOf("/SECOND-") != -1) {
    SECOND = SECOND - 1;
  }

  if (request.indexOf("/MINUT+") != -1) {
    MINUT = MINUT + 1;
  }

  if (request.indexOf("/MINUT-") != -1) {
    MINUT = MINUT - 1;
  }

  if (request.indexOf("/HOUR+") != -1) {
    HOUR = HOUR + 1;
  }

  if (request.indexOf("/HOUR-") != -1) {
    HOUR = HOUR - 1;
  }

  if (request.indexOf("/DAY+") != -1) {
    DAY = DAY + 1;
  }

  if (request.indexOf("/DAY-") != -1) {
    DAY = DAY - 1;
  }

  if (request.indexOf("/MONTH+") != -1) {
    MONTH = MONTH + 1;
  }

  if (request.indexOf("/MONTH-") != -1) {
    MONTH = MONTH - 1;
  }

  if (request.indexOf("/YEAR+") != -1) {
    YEAR = YEAR + 1;
  }

  if (request.indexOf("/YEAR-") != -1) {
    YEAR = YEAR - 1;
  }

  if (SECOND > 59) {
    SECOND = 0;
    MINUT = MINUT + 1;
  }

  if (SECOND < 0) {
    SECOND = 59;
    MINUT = MINUT - 1;
  }

  if (MINUT > 59) {
    MINUT = 0;
    HOUR = HOUR + 1;
  }

  if (MINUT < 0) {
    MINUT = 59;
    HOUR = HOUR - 1;
  }

  if (HOUR > 23) {
    HOUR = 0;
    DAY = DAY + 1;
  }

  if (HOUR < 0) {
    HOUR = 23;
    DAY = DAY - 1;
  }

  if (DAY > 31) {
    DAY = 1;
    MONTH = MONTH + 1;
  }

  if (DAY < 1) {
    DAY = 31;
    MONTH = MONTH - 1;
  }

  if (MONTH > 12) {
    MONTH = 1;
    YEAR = YEAR + 1;
  }

  if (MONTH < 1) {
    MONTH = 12;
    YEAR = YEAR - 1;
  }

  if (request.indexOf("/clockOK") != -1) {
    setTD = 1;
    //compiled = ();
    rtc.disableClock();
    rtc.setDateTime(SECOND, MINUT, HOUR, dw, DAY, MONTH, YEAR);
    rtc.enableClock();
    rtc.getDateTime(&S, &M, &H, &dw, &D, &MNT, &Y);

    //Rtc.SetDateTime(compiled);RtcDateTime now = Rtc.GetDateTime();
    NOWDateTime();
  }

  if (request.indexOf("/MainMenu") != -1) {
    value7 = 1;
  }
  if (request.indexOf("/Settings") != -1) {
    value7 = 2;
  }
  if (request.indexOf("/BSettings") != -1) {
    value7 = 3;
  }
  if (request.indexOf("/Help") != -1) {
    value7 = 4;
  }
  if (request.indexOf("/setTD") != -1) {
    setTD = 1;
  }
  if (request.indexOf("/BG") != -1) {
    BG = 10;
  }
  if (request.indexOf("/EN") != -1) {
    BG = 0;
  }

  //menu system setins if's
  // --- BTIME1 (night mode)
  if (request.indexOf("/bM1-") != -1) {
    if (bM1 == 0) {
      bM1 = 59;
      bH1 = bH1 - 1;
    } else {
      bM1 = bM1 - 1;
    }
  }
  if (request.indexOf("/bM1+") != -1) {
    if (bM1 == 59) {
      bM1 = 0;
      bH1 = bH1 + 1;
    } else {
      bM1 = bM1 + 1;
    }
  }
  //if (bM1>59){bM1=0;bH1=bH1+1;}
  //if (bM1<0){bM1=59;bH1=bH1-1;}
  if (request.indexOf("/bH1-") != -1) {
    if (bH1 == 0) {
      bH1 = 23;
    } else {
      bH1 = bH1 - 1;
    }
  }
  if (request.indexOf("/bH1+") != -1) {
    if (bH1 == 23) {
      bH1 = 0;
    } else {
      bH1 = bH1 + 1;
    }
  }
  //if (bH1>23){bH1=0;}
  //if (bH1<0){bH1=23;}
  if (request.indexOf("/bM2-") != -1) {
    if (bM2 == 0) {
      bM2 = 59;
      bH2 = bH2 - 1;
    } else {
      bM2 = bM2 - 1;
    }
  }
  if (request.indexOf("/bM2+") != -1) {
    if (bM2 == 59) {
      bM2 = 0;
      bH2 = bH2 + 1;
    } else {
      bM2 = bM2 + 1;
    }
  }
  //if (bM2>59){bM2=0;bH2=bH2+1;}
  //if (bM2<0){bM2=59;bH2=bH2-1;}
  if (request.indexOf("/bH2-") != -1) {
    if (bH2 == 0) {
      bH2 = 23;
    } else {
      bH2 = bH2 - 1;
    }
  }
  if (request.indexOf("/bH2+") != -1) {
    if (bH2 == 23) {
      bH2 = 0;
    } else {
      bH2 = bH2 + 1;
    }
  }
  //if (bH2>23){bH2=0;}
  //if (bH2<0){bH2=23;}
  //--btime2 second mode
  if (request.indexOf("/SMon=OFF") != -1) {
    SMon = LOW;
  }
  if (request.indexOf("/SMon=ON") != -1) {
    SMon = HIGH;
  }
  if (request.indexOf("/bM3-") != -1) {
    if (bM3 == 0) {
      bM3 = 59;
      bH3 = bH3 - 1;
    } else {
      bM3 = bM3 - 1;
    }
  }
  if (request.indexOf("/bM3+") != -1) {
    if (bM3 == 59) {
      bM3 = 0;
      bH3 = bH3 + 1;
    } else {
      bM3 = bM3 + 1;
    }
  }
  //if (bM3>59){bM3=0;bH3=bH3+1;}
  //if (bM3<0){bM3=59;bH3=bH3-1;}
  if (request.indexOf("/bH3-") != -1) {
    if (bH3 == 0) {
      bH3 = 23;
    } else {
      bH3 = bH3 - 1;
    }
  }
  if (request.indexOf("/bH3+") != -1) {
    if (bH3 == 23) {
      bH3 = 0;
    } else {
      bH3 = bH3 + 1;
    }
  }
  //if (bH3>23){bH3=0;}
  //if (bH3<0){bH3=23;}
  if (request.indexOf("/bM4-") != -1) {
    if (bM4 == 0) {
      bM4 = 59;
      bH4 = bH4 - 1;
    } else {
      bM4 = bM4 - 1;
    }
  }
  if (request.indexOf("/bM4+") != -1) {
    if (bM4 == 59) {
      bM4 = 0;
      bH4 = bH4 + 1;
    } else {
      bM4 = bM4 + 1;
    }
  }
  //if (bM4>59){bM4=0;bH4=bH4+1;}
  //if (bM4<0){bM4=59;bH4=bH4-1;}
  if (request.indexOf("/bH4-") != -1) {
    if (bH4 == 0) {
      bH4 = 23;
    } else {
      bH4 = bH4 - 1;
    }
  }
  if (request.indexOf("/bH4+") != -1) {
    if (bH4 == 23) {
      bH4 = 0;
    } else {
      bH4 = bH4 + 1;
    }
  }
  //if (bH4>23){bH4=0;}
  //if (bH4<0){bH4=23;}

  // -- temperatur boiler set----
  if (request.indexOf("/bTmin-") != -1) {
    bTmin = bTmin - 1;
  }
  if (request.indexOf("/bTmin+") != -1) {
    bTmin = bTmin + 1;
  }
  if (bTmin > bTmax) {
    bTmin = 10;
  }
  if (bTmin < 10) {
    bTmin = bTmax;
  }
  if (request.indexOf("/bTmax-") != -1) {
    bTmax = bTmax - 1;
  }
  if (request.indexOf("/bTmax+") != -1) {
    bTmax = bTmax + 1;
  }
  if (bTmax > 90) {
    bTmax = bTmin;
  }
  if (bTmax < bTmin) {
    bTmax = 90;
  }
  //-humoff set
  if (request.indexOf("/humoff-") != -1) {
    humoff = humoff - 1;
  }
  if (request.indexOf("/humoff+") != -1) {
    humoff = humoff + 1;
  }
  if (humoff > 99) {
    humoff = 50;
  }
  if (humoff < 50) {
    humoff = 99;
  }

  //----константи помещение
  if (request.indexOf("/Hummin-") != -1) {
    Hummin = Hummin - 1;
  }
  if (request.indexOf("/Hummin+") != -1) {
    Hummin = Hummin + 1;
  }
  if (Hummin > Hummax) {
    Hummin = 2;
  }
  if (Hummin < 2) {
    Hummin = Hummax;
  }
  if (request.indexOf("/Hummax-") != -1) {
    Hummax = Hummax - 1;
  }
  if (request.indexOf("/Hummax+") != -1) {
    Hummax = Hummax + 1;
  }
  if (Hummax > (99 - humin)) {
    Hummax = Hummin;
  }
  if (Hummax < Hummin) {
    Hummax = (99 - humin);
  }

  //-humoff set
  if (request.indexOf("/Presence-") != -1) {
    Presence = Presence - 1;
  }
  if (request.indexOf("/Presence+") != -1) {
    Presence = Presence + 1;
  }
  if (Presence > 59) {
    Presence = 1;
  }
  if (Presence < 1) {
    Presence = 59;
  }
  if (request.indexOf("/FANtime-") != -1) {
    FANtime = FANtime - 1;
  }
  if (request.indexOf("/FANtime+") != -1) {
    FANtime = FANtime + 1;
  }
  if (FANtime > 10) {
    FANtime = 0;
  }
  if (FANtime < 0) {
    FANtime = 10;
  }
  if (request.indexOf("/Default") != -1) {
    constants();
  }
  if (request.indexOf("/Applay") != -1) {
    eepromwrite();gattime();
  }
  if (request.indexOf("/Reset") != -1) {
    constants();
    lcd.clear();
    lcd.setCursor(3, 1);
    lcd.print("Reset Constants");
    delay(1000);
    lcd.setCursor(5, 2);
    lcd.print("Rebooting!");
    delay(1000);
    lcd.setCursor(1, 3);
    lcd.print("Pleas Wait......");
    delay(5000);
    ESP.reset();
  }
  if (request.indexOf("/Reboot") != -1) {
    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print("Rebooting!");
    delay(1000);
    lcd.setCursor(1, 2);
    lcd.print("Pleas Wait......");
    delay(5000);
    ESP.restart();
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println("<HTML>\n<HEAD>");
  client.println("  <TITLE>HOME SYSTEM CONTROL</TITLE>");//

  client.println("<meta charset=UTF-8>");
  client.println("</HEAD><BODY style=background-color:LightSteelBlue>");
  client.println("<align=center><H1>HOME SYSTEM CONTROL</H1>");
  client.println("");

  if ((value7 + BG) == 1) {
    setTD = 0;

    client.print("<a href=\"/MainMenu\"><button style=background-color:LightSteelBlue>Menu</button></a><a href=\"/Settings\"><button style=background-color:LightGrey>Settings</button></a><a href=\"/BSettings\"><button style=background-color:LightGrey>Constants</button></a><a href=\"/Help\"><button style=background-color:LightGrey>Help</button></a>");
    if (BG == 0) {
      client.print("<a href=\"/BG\"><button style=background-color:LightGrey>Български</button></a> ");
    } else {
      client.print("<a href=\"/EN\"><button style=background-color:LightGrey>English</button></a> ");
    }
    client.print("<table border cellspacing=1 cellpadding=10><tr><td align=\"center\"><br>Boiler is now:");
    if (rstat1 == ON || butstat1 == HIGH) {
      client.print("<button style=background-color:LightGreen>ON&nbsp</button>");
    } else {
      client.print("<button style=background-color:OrangeRed>OFF</button>");
    }
    client.println("<br><br>Temperature:<button>"); client.println(tempC, 0); client.println("&nbsp&degC</button><br><br><br><a href=\"/LED=ON\"><button style=background-color:LightGrey>ON</button></a>&nbsp<a href=\"/LED=OFF\"><button style=background-color:LightGrey>OFF</button></a><br><br><br>");

    if (bON == HIGH) {
      client.println("<a href=\"/LED=AutoOFF\"><button style=background-color:LightSteelBlue>Click here to Auto OFF</button></a>");
    } else {
      client.println("<a href=\"/LED=AutoON\"><button style=background-color:LightGrey>Click here to Auto ON&nbsp</button></a>");
    }

    client.println("</td><td align=\"center\">Ventilation is now: ");

    if (rstat2 == ON || butstat2 == HIGH) {
      client.print("<button style=background-color:LightGreen>ON&nbsp</button>");
    } else {
      client.print("<button style=background-color:OrangeRed>OFF</button>");
    }
    client.print("<br>Heating &nbsp is &nbsp now:&nbsp&nbsp ");

    if (rstat4 == ON) {
      client.print("<button style=background-color:LightGreen>ON&nbsp</button>");
    } else {
      client.print("<button style=background-color:OrangeRed>OFF</button>");
    }
    client.println("<br><br>Bathroom &nbsp&nbspHumidity&nbsp&nbsp&nbsp:<button>"); client.print(hum); client.println("&nbsp%&nbsp</button><br>Bathroom Temperature:<button>"); client.print(tmp); client.println("&nbsp&degC</button><br><br>Ventilation:&nbsp&nbsp<a href=\"/LED2=ON\"><button style=background-color:LightGrey>ON</button></a>&nbsp<a href=\"/LED2=OFF\"><button style=background-color:LightGrey>OFF</button></a><br>&nbsp&nbspHeating:&nbsp&nbsp&nbsp&nbsp&nbsp<a href=\"/HEATING=ON\"><button style=background-color:LightGrey>ON</button></a>&nbsp<a href=\"/HEATING=OFF\"><button style=background-color:LightGrey>OFF</button></a><br><br>");
    if (fanON == HIGH) {
      client.println("<a href=\"/LED2=AutoOFF\"><button style=background-color:LightSteelBlue>Click here to Auto OFF</button></a>");
    } else {
      client.println("<a href=\"/LED2=AutoON\"><button style=background-color:LightGrey>Click here to Auto ON&nbsp</button></a>");
    }

    client.println("</td><td align=\"center\"><br>LED is now:");
    if (rstat3 == ON || butstat3 == HIGH) {
      client.print("<button style=background-color:LightGreen>ON&nbsp</button>");
    } else {
      client.print("<button style=background-color:OrangeRed>OFF</button>");
    }
    client.println("<br><br>Home&nbsp&nbsp&nbspHumidity&nbsp&nbsp&nbsp:<button>"); client.print(humin, 0); client.println("&nbsp%&nbsp</button><br>Home Temperature:<button>"); client.print(tempin, 0); client.println("&nbsp&degC</button><br><br><a href=\"/LED3=ON\"><button style=background-color:LightGrey>ON</button></a>&nbsp <a href=\"/LED3=OFF\"><button style=background-color:LightGrey>OFF</button></a><br><br><br>");
    if (pirON == HIGH) {
      client.println("<a href=\"/LED3=AutoOFF\"><button style=background-color:LightSteelBlue>Click here to Auto OFF</button></a> ");
    } else {
      client.println("<a href=\"/LED3=AutoON\"><button style=background-color:LightGrey>Click here to Auto ON&nbsp</button></a> ");
    }
    client.println("</td></tr></table>");
    //client.println("<br><br><br><br><br><br>Tova e systema za kontrol i upravlenie na DOMA</tr>");
  }


  if ((value7 + BG) == 2) {
    if (setTD == 1) {
      HOUR = H;
      MINUT = M;
      SECOND = S;
      DAY = D;
      MONTH = MNT;
      YEAR = Y; setTD = 2;
    }


    client.print("<a href=\"/MainMenu\"><button style=background-color:LightGrey>Menu</button></a><a href=\"/Settings\"><button style=background-color:LightSteelBlue>Settings</button></a><a href=\"/BSettings\"><button style=background-color:LightGrey>Constants</button></a><a href=\"/Help\"><button style=background-color:LightGrey>Help</button></a>");
    if (BG == 0) {
      client.print("<a href=\"/BG\"><button style=background-color:LightGrey>Български</button></a> ");
    } else {
      client.print("<a href=\"/EN\"><button style=background-color:LightGrey>English</button></a> ");
    }
    client.print("<table border cellspacing=2 cellpadding=4><tr align=center><td align=center>Gat<br>Data/Time</td><td><a href=\"/setTD\"><align=center><button style=background-color:LightGrey>");
    if (H < 10) {
      client.print("0");
      client.print(H, DEC);
    } else {
      client.print(H, DEC);
    } client.print(":");
    if (M < 10) {
      client.print("0");
      client.print(M, DEC);
    } else {
      client.print(M, DEC);
    } client.print(":");
    if (S < 10) {
      client.print("0");
      client.print(S, DEC);
    } else {
      client.print(S, DEC);
    } client.println("&nbsp");
    if (D < 10) {
      client.print("0");
      client.print(D, DEC);
    } else {
      client.print(D, DEC);
    } client.print(".");
    if (MNT < 10) {
      client.print("0");
      client.print(MNT, DEC);
    } else {
      client.print(MNT, DEC);
    } client.print("."); client.print(Y, DEC);
    client.println("</button></a><tr><td align=center><br>Hour:<br>Minute:<br>Second:<br><br>Day :<br>Month:<br>Year:<br><br></td><td align=center><a href=\"/HOUR-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (HOUR < 10) {
      client.print("0");
      client.print(HOUR, DEC);
    } else {
      client.print(HOUR, DEC);
    }
    client.print("&nbsp</button><a href=\"/HOUR+\"><button style=background-color:LightGrey>></button></a><br><a href=\"/MINUT-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (MINUT < 10) {
      client.print("0");
      client.print(MINUT, DEC);
    } else {
      client.print(MINUT, DEC);
    }
    client.print("&nbsp&nbsp</button><a href=\"/MINUT+\"><button style=background-color:LightGrey>></button></a><br><a href=\"/SECOND-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (SECOND < 10) {
      client.print("0");
      client.print(SECOND, DEC);
    } else {
      client.print(SECOND, DEC);
    }
    client.print("&nbsp&nbsp</button><a href=\"/SECOND+\"><button style=background-color:LightGrey>></button></a><br><br><a href=\"/DAY-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (DAY < 10) {
      client.print("0");
      client.print(DAY, DEC);
    } else {
      client.print(DAY, DEC);
    }
    client.print("&nbsp&nbsp</button>"); client.println("<a href=\"/DAY+\"><button style=background-color:LightGrey>></button></a><br><a href=\"/MONTH-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (MONTH < 10) {
      client.print("0");
      client.print(MONTH, DEC);
    } else {
      client.print(MONTH, DEC);
    }
    client.println("&nbsp&nbsp</button><a href=\"/MONTH+\"><button style=background-color:LightGrey>></button></a><br><a href=\"/YEAR-\"><button style=background-color:LightGrey><</button></a><button>");
    if (YEAR < 10) {
      client.print("0");
      client.print(YEAR, DEC);
    } else {
      client.print(YEAR, DEC);
    }
    client.print("</button><a href=\"/YEAR+\"><button style=background-color:LightGrey>></button></a><br></td></tr><tr><td></td><td align=center><a href=\"/clockOK\"><button style=background-color:LightGrey><center>OK</center></button></a> </td></tr></table>");//</tr></table>");//client.println("<br><br>");client.println("<br><br>");  //}
  }
  if ((value7 + BG) == 3) { //меню за корегиране на константите на програмата

    client.print("<a href=\"/MainMenu\"><button style=background-color:LightGrey>Menu</button></a><a href=\"/Settings\"><button style=background-color:LightGrey>Settings</button></a><a href=\"/BSettings\"><button style=background-color:LightSteelBlue>Constants</button></a><a href=\"/Help\"><button style=background-color:LightGrey>Help</button></a>");
    if (BG == 0) {
      client.print("<a href=\"/BG\"><button style=background-color:LightGrey>Български</button></a> ");
    } else {
      client.print("<a href=\"/EN\"><button style=background-color:LightGrey>English</button></a> ");
    }
    client.print("<table border cellspacing=2 cellpadding=4><tr align=center><td>Boiler Constants<br><br>Night Mode<br>Start Time&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspStop Time<br>Hour:<a href=\"/bH1-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bH1 < 10) {
      client.print("0");
      client.print(bH1, DEC);
    } else {
      client.print(bH1, DEC);
    }
    client.print("&nbsp</button><a href=\"/bH1+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbspHour:<a href=\"/bH2-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bH2 < 10) {
      client.print("0");
      client.print(bH2, DEC);
    } else {
      client.print(bH2, DEC);
    }
    client.print("&nbsp</button><a href=\"/bH2+\"><button style=background-color:LightGrey>></button></a><br>M<sub>inute</sub>:<a href=\"/bM1-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bM1 < 10) {
      client.print("0");
      client.print(bM1, DEC);
    } else {
      client.print(bM1, DEC);
    }
    client.print("&nbsp</button><a href=\"/bM1+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbspM<sub>inute</sub>:<a href=\"/bM2-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bM2 < 10) {
      client.print("0");
      client.print(bM2, DEC);
    } else {
      client.print(bM2, DEC);
    }
    client.print("&nbsp</button><a href=\"/bM2+\"><button style=background-color:LightGrey>></button></a><br><br>Second Time Mode&nbsp&nbsp");
    if (SMon == HIGH) {
      client.println("<a href=\"/SMon=OFF\"><button style=background-color:LightSteelBlue>&#9830</button></a>");
    } else {
      client.println("<a href=\"/SMon=ON\"><button style=background-color:LightGrey>&nbsp</button></a>");
    }
    client.print("<br>Start Time&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspStop Time<br>Hour:<a href=\"/bH3-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bH3 < 10) {
      client.print("0");
      client.print(bH3, DEC);
    } else {
      client.print(bH3, DEC);
    }
    client.print("&nbsp</button><a href=\"/bH3+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbsp&nbspHour:<a href=\"/bH4-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bH4 < 10) {
      client.print("0");
      client.print(bH4, DEC);
    } else {
      client.print(bH4, DEC);
    }
    client.print("&nbsp</button><a href=\"/bH4+\"><button style=background-color:LightGrey>></button></a><br>M<sub>inute</sub>:<a href=\"/bM3-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bM3 < 10) {
      client.print("0");
      client.print(bM3, DEC);
    } else {
      client.print(bM3, DEC);
    }
    client.print("&nbsp</button><a href=\"/bM3+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbspM<sub>inute</sub>:<a href=\"/bM4-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bM4 < 10) {
      client.print("0");
      client.print(bM4, DEC);
    } else {
      client.print(bM4, DEC);
    }
    client.print("&nbsp</button><a href=\"/bM4+\"><button style=background-color:LightGrey>></button></a><br><br>Boiler Temperature &nbsp&degC<br>T<sub>min</sub>&nbsp<a href=\"/bTmin-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bTmin < 10) {
      client.print("0");
      client.print(bTmin, DEC);
    } else {
      client.print(bTmin, DEC);
    }
    client.print("&nbsp</button><a href=\"/bTmin+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbspT<sub>max</sub>&nbsp<a href=\"/bTmax-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (bTmax < 10) {
      client.print("0");
      client.print(bTmax, DEC);
    } else {
      client.print(bTmax, DEC);
    }
    client.print("&nbsp</button><a href=\"/bTmax+\"><button style=background-color:LightGrey>></button></a><br><br>&nbsp&nbspHum<sub>off</sub>&nbsp<a href=\"/humoff-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (humoff < 10) {
      client.print("0");
      client.print(humoff, DEC);
    } else {
      client.print(humoff, DEC);
    }
    client.print("&nbsp%</button><a href=\"/humoff+\"><button style=background-color:LightGrey>></button></a></td><td align=center>Bathroom Constants <br><br><br>&#916Hum<sub>min</sub><br><a href=\"/Hummin-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (Hummin < 10) {
      client.print("0");
      client.print(Hummin, DEC);
    } else {
      client.print(Hummin, DEC);
    }
    client.print("&nbsp%</button><a href=\"/Hummin+\"><button style=background-color:LightGrey>></button></a><br>&#916Hum<sub>max</sub><br><a href=\"/Hummax-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (Hummax < 10) {
      client.print("0");
      client.print(Hummax, DEC);
    } else {
      client.print(Hummax, DEC);
    }
    client.print("&nbsp%</button><a href=\"/Hummax+\"><button style=background-color:LightGrey>></button></a><br><br>Presence<sub>time</sub><br><a href=\"/Presence-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (Presence < 10) {
      client.print("0");
      client.print(Presence, DEC);
    } else {
      client.print(Presence, DEC);
    }
    client.print("&nbspmin</button><a href=\"/Presence+\"><button style=background-color:LightGrey>></button></a><br><br><br>FAN<sub>time</sub><br><a href=\"/FANtime-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (FANtime < 10) {
      client.print("0");
      client.print(FANtime, DEC);
    } else {
      client.print(FANtime, DEC);
    }
    client.print("&nbspmin</button><a href=\"/FANtime+\"><button style=background-color:LightGrey>></button></a><br><br><br></td></tr><tr><td align=center><a href=\"/Reset\"><button style=background-color:LightGrey> Reset System</button></a>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<a href=\"/Reboot\"><button style=background-color:LightGrey> Reboot System</button></a></td><td align=center><a href=\"/Default\"><button style=background-color:LightGrey> Default</button></a>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<a href=\"/Applay\"><button style=background-color:LightGrey> Applay</button></a> </td></tr></table>");//</tr></table>");//client.println("<br><br>");client.println("<br><br>");  //}
  }
  if ((value7 + BG) == 4) {
    client.print("<a href=\"/MainMenu\"><button style=background-color:LightGrey>Menu</button></a><a href=\"/Settings\"><button style=background-color:LightGrey>Settings</button></a><a href=\"/BSettings\"><button style=background-color:LightGrey>Constants</button></a><a href=\"/Help\"><button style=background-color:LightSteelBlue>Help</button></a>");
    if (BG == 0) {
      client.print("<a href=\"/BG\"><button style=background-color:LightGrey>Български</button></a> ");
    } else {
      client.print("<a href=\"/EN\"><button style=background-color:LightGrey>English</button></a> ");
    }
    client.print("<table border cellspacing=2 cellpadding=4><tr align=center><td><br>Това е система за автоматизирано управление на Баня</td></tr></table>");
  }
  //----------------------------------------менюта на български език------------------------------
  if ((value7 + BG) == 11) {
    setTD = 0;

    client.print("<a href=\"/MainMenu\"><button style=background-color:LightSteelBlue>Меню</button></a><a href=\"/Settings\"><button style=background-color:LightGrey>Настройки</button></a><a href=\"/BSettings\"><button style=background-color:LightGrey>Константи</button></a><a href=\"/Help\"><button style=background-color:LightGrey>Помощ</button></a>");
    if (BG == 0) {
      client.print("<a href=\"/BG\"><button style=background-color:LightGrey>Български</button></a> ");
    } else {
      client.print("<a href=\"/EN\"><button style=background-color:LightGrey>English</button></a> ");
    }
    client.print("<table border cellspacing=1 cellpadding=10><tr><td align=\"center\"><br>Бойлера е :&nbsp");
    if (rstat1 == ON || butstat1 == HIGH) {
      client.print("<button style=background-color:LightGreen>ВКЛ.&nbsp</button>");
    } else {
      client.print("<button style=background-color:OrangeRed>ИЗКЛ.</button>");
    }
    client.println("<br><br>Приблизителна температура<br> на водата в Бойлера:<br><button>"); client.println(tempC, 0); client.println("&nbsp&degC</button><br><br><br><a href=\"/LED=ON\"><button style=background-color:LightGrey>ВКЛ.</button></a>&nbsp<a href=\"/LED=OFF\"><button style=background-color:LightGrey>ИЗКЛ.</button></a><br><br><br>");

    if (bON == HIGH) {
      client.println("<a href=\"/LED=AutoOFF\"><button style=background-color:LightSteelBlue>Изключи Автоматичен режим</button></a>");
    } else {
      client.println("<a href=\"/LED=AutoON\"><button style=background-color:LightGrey>Включи Автоматичен режим</button></a>");
    }

    client.println("</td><td align=\"center\"><br>Вентилацията е: ");

    if (rstat2 == ON || butstat2 == HIGH) {
      client.print("<button style=background-color:LightGreen>ВКЛ.&nbsp</button>");
    } else {
      client.print("<button style=background-color:OrangeRed>ИЗКЛ.</button>");
    }
    client.print("<br>Отоплението е:&nbsp&nbsp ");

    if (rstat4 == ON) {
      client.print("<button style=background-color:LightGreen>ВКЛ.&nbsp</button>");
    } else {
      client.print("<button style=background-color:OrangeRed>ИЗКЛ.</button>");
    }
    client.println("<br><br>&nbsp&nbspВлажност &nbspв&nbsp Банята&nbsp:&nbsp<button>"); client.print(hum); client.println("&nbsp%&nbsp</button><br>Температура в Банята:&nbsp<button>"); client.print(tmp); client.println("&nbsp&degC</button><br><br>Вентилация:&nbsp&nbsp<a href=\"/LED2=ON\"><button style=background-color:LightGrey>ВКЛ.</button></a>&nbsp<a href=\"/LED2=OFF\"><button style=background-color:LightGrey>ИЗКЛ.</button></a><br>&nbsp&nbspОтопление:&nbsp&nbsp<a href=\"/HEATING=ON\"><button style=background-color:LightGrey>ВКЛ.</button></a>&nbsp<a href=\"/HEATING=OFF\"><button style=background-color:LightGrey>ИЗКЛ.</button></a><br><br>");
    if (fanON == HIGH) {
      client.println("<a href=\"/LED2=AutoOFF\"><button style=background-color:LightSteelBlue>Изключи Автоматичен режим</button></a>");
    } else {
      client.println("<a href=\"/LED2=AutoON\"><button style=background-color:LightGrey>Включи Автоматичен режим&nbsp</button></a>");
    }

    client.println("</td><td align=\"center\"><br>Осветлението е:");
    if (rstat3 == ON || butstat3 == HIGH) {
      client.print("<button style=background-color:LightGreen>ВКЛ.&nbsp</button>");
    } else {
      client.print("<button style=background-color:OrangeRed>ИЗКЛ.</button>");//??????????????????????????????????????????????????????????????????????????????????????
    }
    client.println("<br><br>Влажност в Дома:<br><button>"); client.print(humin, 0); client.println("&nbsp%&nbsp</button><br>Температура в Дома:<br><button>"); client.print(tempin, 0); client.println("&nbsp&degC</button><br><br><a href=\"/LED3=ON\"><button style=background-color:LightGrey>ВКЛ.</button></a>&nbsp <a href=\"/LED3=OFF\"><button style=background-color:LightGrey>ИЗКЛ.</button></a><br><br><br>");
    if (pirON == HIGH) {
      client.println("<a href=\"/LED3=AutoOFF\"><button style=background-color:LightSteelBlue>Изключи Автоматичен режим</button></a> ");
    } else {
      client.println("<a href=\"/LED3=AutoON\"><button style=background-color:LightGrey>Включи Автоматичен режим&nbsp</button></a> ");
    }
    client.println("</td></tr></table>");
    //client.println("<br><br><br><br><br><br>Tova e systema za kontrol i upravlenie na DOMA</tr>");
  }


  if ((value7 + BG) == 12) {
    if (setTD == 1) {
      HOUR = H;
      MINUT = M;
      SECOND = S;
      DAY = D;
      MONTH = MNT;
      YEAR = Y; setTD = 2;
    }


    client.print("<a href=\"/MainMenu\"><button style=background-color:LightGrey>Меню</button></a><a href=\"/Settings\"><button style=background-color:LightSteelBlue>Настройки</button></a><a href=\"/BSettings\"><button style=background-color:LightGrey>Константи</button></a><a href=\"/Help\"><button style=background-color:LightGrey>Помощ</button></a>");
    if (BG == 0) {
      client.print("<a href=\"/BG\"><button style=background-color:LightGrey>Български</button></a> ");
    } else {
      client.print("<a href=\"/EN\"><button style=background-color:LightGrey>English</button></a> ");
    }
    client.print("<table border cellspacing=2 cellpadding=4><tr align=center><td align=center>Вземи <br> Дата/Час</td><td><a href=\"/setTD\"><align=center><button style=background-color:LightGrey>");
    if (H < 10) {
      client.print("0");
      client.print(H, DEC);
    } else {
      client.print(H, DEC);
    } client.print(":");
    if (M < 10) {
      client.print("0");
      client.print(M, DEC);
    } else {
      client.print(M, DEC);
    } client.print(":");
    if (S < 10) {
      client.print("0");
      client.print(S, DEC);
    } else {
      client.print(S, DEC);
    } client.println("&nbsp");
    if (D < 10) {
      client.print("0");
      client.print(D, DEC);
    } else {
      client.print(D, DEC);
    } client.print(".");
    if (MNT < 10) {
      client.print("0");
      client.print(MNT, DEC);
    } else {
      client.print(MNT, DEC);
    } client.print("."); client.print(Y, DEC);
    client.println("</button></a><tr><td align=center><br>Час:<br>Минута:<br>Секунда:<br><br><br>Ден :<br>Месец:<br>Година:<br><br></td><td align=center><a href=\"/HOUR-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (HOUR < 10) {
      client.print("0");
      client.print(HOUR, DEC);
    } else {
      client.print(HOUR, DEC);
    }
    client.print("&nbsp</button><a href=\"/HOUR+\"><button style=background-color:LightGrey>></button></a><br><a href=\"/MINUT-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (MINUT < 10) {
      client.print("0");
      client.print(MINUT, DEC);
    } else {
      client.print(MINUT, DEC);
    }
    client.print("&nbsp&nbsp</button><a href=\"/MINUT+\"><button style=background-color:LightGrey>></button></a><br><a href=\"/SECOND-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (SECOND < 10) {
      client.print("0");
      client.print(SECOND, DEC);
    } else {
      client.print(SECOND, DEC);
    }
    client.print("&nbsp&nbsp</button><a href=\"/SECOND+\"><button style=background-color:LightGrey>></button></a><br><br><a href=\"/DAY-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (DAY < 10) {
      client.print("0");
      client.print(DAY, DEC);
    } else {
      client.print(DAY, DEC);
    }
    client.print("&nbsp&nbsp</button>"); client.println("<a href=\"/DAY+\"><button style=background-color:LightGrey>></button></a><br><a href=\"/MONTH-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (MONTH < 10) {
      client.print("0");
      client.print(MONTH, DEC);
    } else {
      client.print(MONTH, DEC);
    }
    client.println("&nbsp&nbsp</button><a href=\"/MONTH+\"><button style=background-color:LightGrey>></button></a><br><a href=\"/YEAR-\"><button style=background-color:LightGrey><</button></a><button>");
    if (YEAR < 10) {
      client.print("0");
      client.print(YEAR, DEC);
    } else {
      client.print(YEAR, DEC);
    }
    client.print("</button><a href=\"/YEAR+\"><button style=background-color:LightGrey>></button></a><br></td></tr><tr><td></td><td align=center><a href=\"/clockOK\"><button style=background-color:LightGrey><center>OK</center></button></a> </td></tr></table>");//</tr></table>");//client.println("<br><br>");client.println("<br><br>");  //}
  }
  if ((value7 + BG) == 13) { //меню за корегиране на константите на програмата

    client.print("<a href=\"/MainMenu\"><button style=background-color:LightGrey>Меню</button></a><a href=\"/Settings\"><button style=background-color:LightGrey>Настройки</button></a><a href=\"/BSettings\"><button style=background-color:LightSteelBlue>Константи</button></a><a href=\"/Help\"><button style=background-color:LightGrey>Помощ</button></a>");
    if (BG == 0) {
      client.print("<a href=\"/BG\"><button style=background-color:LightGrey>Български</button></a> ");
    } else {
      client.print("<a href=\"/EN\"><button style=background-color:LightGrey>English</button></a> ");
    }
    client.println("<table border cellspacing=2 cellpadding=4><tr align=center><td>Константи за работата на Бойлера<br><br>Режим Нощна енергия<br><div align=justify>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspНачало&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspКрай<br>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspЧас:&nbsp<a href=\"/bH1-\"><button style=background-color:LightGrey><</button></a><button>");
    if (bH1 < 10) {
      client.print("0");
      client.print(bH1, DEC);
    } else {
      client.print(bH1, DEC);
    }
    client.print("</button><a href=\"/bH1+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspЧас:&nbsp<a href=\"/bH2-\"><button style=background-color:LightGrey><</button></a><button>");//работа
    if (bH2 < 10) {
      client.print("0");
      client.print(bH2, DEC);
    } else {
      client.print(bH2, DEC);
    }
    client.print("</button><a href=\"/bH2+\"><button style=background-color:LightGrey>></button></a><br>Минута:&nbsp<a href=\"/bM1-\"><button style=background-color:LightGrey><</button></a><button>");
    if (bM1 < 10) {
      client.print("0");
      client.print(bM1, DEC);
    } else {
      client.print(bM1, DEC);
    }
    client.print("</button><a href=\"/bM1+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbspМинута:&nbsp<a href=\"/bM2-\"><button style=background-color:LightGrey><</button></a><button>");
    if (bM2 < 10) {
      client.print("0");
      client.print(bM2, DEC);
    } else {
      client.print(bM2, DEC);
    }
    client.print("</button><a href=\"/bM2+\"><button style=background-color:LightGrey>></button></a></div><br><br>Втори Режим&nbsp&nbsp");
    if (SMon == HIGH) {
      client.println("<a href=\"/SMon=OFF\"><button style=background-color:LightSteelBlue>&#9830</button></a>");
    } else {
      client.println("<a href=\"/SMon=ON\"><button style=background-color:LightGrey>&nbsp</button></a>");
    }
    client.print("<br>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspНачало&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspКрай<br>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspЧас:&nbsp<a href=\"/bH3-\"><button style=background-color:LightGrey><</button></a><button>");
    if (bH3 < 10) {
      client.print("0");
      client.print(bH3, DEC);
    } else {
      client.print(bH3, DEC);
    }
    client.print("</button><a href=\"/bH3+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspЧас:&nbsp<a href=\"/bH4-\"><button style=background-color:LightGrey><</button></a><button>");
    if (bH4 < 10) {
      client.print("0");
      client.print(bH4, DEC);
    } else {
      client.print(bH4, DEC);
    }
    client.print("</button><a href=\"/bH4+\"><button style=background-color:LightGrey>></button></a><br>Минута:&nbsp<a href=\"/bM3-\"><button style=background-color:LightGrey><</button></a><button>");
    if (bM3 < 10) {
      client.print("0");
      client.print(bM3, DEC);
    } else {
      client.print(bM3, DEC);
    }
    client.print("</button><a href=\"/bM3+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbspМинута:&nbsp<a href=\"/bM4-\"><button style=background-color:LightGrey><</button></a><button>");
    if (bM4 < 10) {
      client.print("0");
      client.print(bM4, DEC);
    } else {
      client.print(bM4, DEC);
    }
    client.print("</button><a href=\"/bM4+\"><button style=background-color:LightGrey>></button></a><br><br>Температура на Бойлера &nbsp&degC<br>T<sub>min</sub>&nbsp<a href=\"/bTmin-\"><button style=background-color:LightGrey><</button></a><button>");
    if (bTmin < 10) {
      client.print("0");
      client.print(bTmin, DEC);
    } else {
      client.print(bTmin, DEC);
    }
    client.print("</button><a href=\"/bTmin+\"><button style=background-color:LightGrey>></button></a>&nbsp&nbspT<sub>max</sub>&nbsp<a href=\"/bTmax-\"><button style=background-color:LightGrey><</button></a><button>");
    if (bTmax < 10) {
      client.print("0");
      client.print(bTmax, DEC);
    } else {
      client.print(bTmax, DEC);
    }
    client.print("</button><a href=\"/bTmax+\"><button style=background-color:LightGrey>></button></a><br><br>&nbsp&nbspHum<sub>off</sub>&nbsp<a href=\"/humoff-\"><button style=background-color:LightGrey><</button></a><button>");
    if (humoff < 10) {
      client.print("0");
      client.print(humoff, DEC);
    } else {
      client.print(humoff, DEC);
    }
    client.print("</button><a href=\"/humoff+\"><button style=background-color:LightGrey>></button></a></td><td align=center>Константи за Банята<br><br><br>&#916Hum<sub>min</sub><br><a href=\"/Hummin-\"><button style=background-color:LightGrey><</button></a><button>");
    if (Hummin < 10) {
      client.print("0");
      client.print(Hummin, DEC);
    } else {
      client.print(Hummin, DEC);
    }
    client.print("</button><a href=\"/Hummin+\"><button style=background-color:LightGrey>></button></a><br>&#916Hum<sub>max</sub><br><a href=\"/Hummax-\"><button style=background-color:LightGrey><</button></a><button>&nbsp");
    if (Hummax < 10) {
      client.print("0");
      client.print(Hummax, DEC);
    } else {
      client.print(Hummax, DEC);
    }
    client.print("</button><a href=\"/Hummax+\"><button style=background-color:LightGrey>></button></a><br><br>Presence<sub>time</sub><br><a href=\"/Presence-\"><button style=background-color:LightGrey><</button></a><button>");
    if (Presence < 10) {
      client.print("0");
      client.print(Presence, DEC);
    } else {
      client.print(Presence, DEC);
    }
    client.print("&nbspmin</button><a href=\"/Presence+\"><button style=background-color:LightGrey>></button></a><br><br><br>FAN<sub>time</sub><br><a href=\"/FANtime-\"><button style=background-color:LightGrey><</button></a><button>");
    if (FANtime < 10) {
      client.print("0");
      client.print(FANtime, DEC);
    } else {
      client.print(FANtime, DEC);
    }
    client.print("&nbspmin</button><a href=\"/FANtime+\"><button style=background-color:LightGrey>></button></a><br><br><br></td></tr><tr><td align=center><a href=\"/Reset\"><button style=background-color:LightGrey> Reset System</button></a>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<a href=\"/Reboot\"><button style=background-color:LightGrey> Reboot System</button></a></td><td align=center><a href=\"/Default\"><button style=background-color:LightGrey> Default</button></a>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp<a href=\"/Applay\"><button style=background-color:LightGrey> Applay</button></a> </td></tr></table>");//</tr></table>");//client.println("<br><br>");client.println("<br><br>");  //}
  }
  if ((value7 + BG) == 14) {
    client.print("<a href=\"/MainMenu\"><button style=background-color:LightGrey>Меню</button></a><a href=\"/Settings\"><button style=background-color:LightGrey>Настройки</button></a><a href=\"/BSettings\"><button style=background-color:LightGrey>Константи</button></a><a href=\"/Help\"><button style=background-color:LightSteelBlue>Помощ</button></a>");
    if (BG == 0) {
      client.print("<a href=\"/BG\"><button style=background-color:LightGrey>Български</button></a> ");
    } else {
      client.print("<a href=\"/EN\"><button style=background-color:LightGrey>English</button></a> ");
    }
    client.println("<table border cellspacing=2 cellpadding=4><td><br><p><div align=justify><H4>Кратко Ръководство за работа със системата</H4></p><p>&nbsp&nbspТова е система за автоматично управление на ел. уреди в Баня.<br>Идеята е системата сама да следи за различни събития:<br>1.Намаляване на топлата вода в Бойлера;<br>2.Следене за влажността и температурата в помещението и автоматично пускане на вентилация и подгряване;<br>3. Автомативчно пускане на Бойлер при Преминаване на тарифа Нощна енергия,както и допълнителен режим на задаване на час на пускане и спиране от потребителя;<br>4. Следи за присъствие на т.чения и при зададено закъснение пуска вентилацията;<br>5. Следи за движение и при наличие пуска осветление;<br>6. Опция при достигане на зададена максимална влажност да спира Бойлер<br>7. Достъп през интернет до системата.<br><br>Принципът на работа на автоматичният режим е да следи параметрите на система, и в зависимост от предварително зададени променливи да сработва.<br>В прозореца /Константи/ ще намерите тези променливи. Символично са разделение на две. Константи за работа на бойлера там можете да зададете начален час на сработване на бойлера както и краен час на изключване. Режимите са два с цел по голямо удобство.<br>Под T<sub>min</sub> се разбира минималната температура под която да се пусне Бойлера.<br> Под T <sub>max</sub> се разбира максималната температура при която да се изключи бойлера(при задаване на темп близка или по-голямана от 70&degC най-вероятно ще сработи терморегулатора на бойлера)</p>");
    client.println("<p>Под Hum<sub>off</sub> се разбира максимално достигнатата влажност при която системата да изключи автоматичният режим. Тя се достига при ползване на помещението, ако искате да не се ползва задайте 99% това е и максималката стойност до която може да отчете датчика.</div></p></td></table>");
  }
  client.print("<h8>Програмата е създадена от Веселин Димитров 2018г. v."); client.println(ver);


}
