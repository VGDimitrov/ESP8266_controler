void readbuttons() {
  byte oldbuton;
if (analogRead(k1)<1000 ) {
    buttemp=0;
    for( byte nkay=0; nkay<2; nkay++)
    {
      buttemp+=analogRead(k1);
    }
    buttemp=buttemp/2  ;
 // Serial.println(buttemp);//за калибриране на бутоните
 
  if (buttemp < buttonset[0] ) {
      ButtonByte=0x01;
      if (buttemp < buttonset[1] ) {
           ButtonByte=ButtonByte<<1;
           if (buttemp < buttonset[2]) {
              ButtonByte=ButtonByte<<1;
              if (buttemp < buttonset[3]) {
                   ButtonByte=ButtonByte<<1;
                   if (buttemp < buttonset[4]) {
                       ButtonByte=ButtonByte<<1;
                       }
                }
           }
       }
   }
   
if (countholdkey>50){
   holdButton=1;
   }else{if (menucount==0){
         countholdkey++;
   }else{countholdkey=0;}
        }
        
   if(menucount==0){Buttread=1;}   
}else{
  
    switch (ButtonByte){
   case 0x01: //прочита бутон 1
    butstat1=!butstat1;
    if (menucount==0){
      bON=0;
    }
    n=0;refresh=1;
   break;
   case 0x41: //прочита бутон 1
    butstat1=!butstat1;
    rstat1=butstat1;
    if (menucount==0){
      bON=0;
    }
    n=0;refresh=1;
   break;
   case 0x02: //прочита бутон 2
    butstat2=!butstat2;
    if (menucount==0){
      fanON=0;
    }
    n=1;refresh=1;
   break;
   case 0x42: //прочита бутон 2
    butstat2=!butstat2;
    rstat2=butstat2;
    if (menucount==0){
      fanON=0;
    }
    n=1;refresh=1;
   break;
   case 0x04: //прочита бутон 3
    if (menucount==0){
      fanON=0;
    }
    butstat3=!butstat3;
    n=2;refresh=1;
    
   break;
   case 0x44: //прочита бутон 3
    if (menucount==0){
      fanON=0;
    }
    butstat3=!butstat3;
    rstat3=butstat3;
    n=2;refresh=1;
    
   break;
   case 0x08: //прочита бутон 4
    butstat4=!butstat4;
    if (menucount==0){
      pirON=0;
    }
    n=3;refresh=1;
   break;
   case 0x48: //прочита бутон 4
    butstat4=!butstat4;
    rstat4=butstat4;
    if (menucount==0){
      pirON=0;
    }
    n=3;refresh=1;
   break;
   case 0x10: //прочита бутон 5
   
   butstat5=!butstat5;
  // ButStatsByte=0x00;
   if (menucount<20){menucount=20;butstat5=0;}
//   bON=1;
//   fanON=1;
//   pirON=1;
   break; 
   case 0x50: //прочита бутон 5
   
   butstat5=!butstat5;
   ButStatsByte=0x00;
   if (menucount<20){menucount=20;butstat5=0;}
//   bON=1;
//   fanON=1;
//   pirON=1;
   break; 
   case 0x21: //задържан бутон 1
    butstat11=!butstat11;
    bON=!bON;
    if(bON==1)
    {
      rstat1=OFF;
    }
    n=0;refresh=1;holdButton=0;
   break;
   case 0x61: //задържан бутон 1
    butstat11=!butstat11;
    if (menucount==0){
      bON=!bON;
    if(bON==1)
    {
      rstat1=OFF;
    }
    }
    n=0;refresh=1;holdButton=0;
   break;
   case 0x22://задържан бутон 2
    butstat21=!butstat21;
    //rstat2=butstat2;
    if (menucount==0){
      fanON=!fanON;
      if(fanON==1)
        {
         rstat2=OFF;
         rstat3=OFF;
       }
    }
    n=1;refresh=1;holdButton=0;
   break;
   case 0x62://задържан бутон 2
    butstat21=!butstat21;
    if (menucount==0){
      //rstat2=butstat2;
      fanON=!fanON;
      if(fanON==1)
       {
         rstat2=OFF;
         rstat3=OFF;
        }
      }
    n=1;refresh=1;holdButton=0;
   break;
   case 0x24://задържан бутон 3
   butstat21=!butstat21;
    if (menucount==0){
      fanON=!fanON;
      if(fanON==1){
       rstat2=OFF;
       rstat3=OFF;
      }
    }
    n=2;refresh=1;holdButton=0;
   break;
   case 0x64://задържан бутон 3
   butstat21=!butstat21;
    if (menucount==0){
      fanON=!fanON;
      if(fanON==1){
         rstat2=OFF;
         rstat3=OFF;
       }
    }
    n=2;refresh=1;holdButton=0;
   break;
   case 0x28://задържан бутон 4
   butstat31=!butstat31;
    if (menucount==0){
      pirON=!pirON;
      if(pirON==1){
      rstat4=OFF;
      }
    }
    n=3;refresh=1;holdButton=0;
    
   break;
    case 0x68://задържан бутон 4
   butstat31=!butstat31;
    if (menucount==0){
      pirON=!pirON;
       if(pirON==1)
    {
      rstat4=OFF;
    }
    }
    
    n=3;refresh=1;holdButton=0;
    
   break;
   case 0x30: //задържан бутон 5 калибровка
   
   butstat5=!butstat5;
   if(holdButton==1){
    menucount=5;
    lcd.clear();
    buttonset[0]=0;
    buttonset[1]=0;
    buttonset[2]=0;
    buttonset[3]=0;
    buttonset[4]=0;
    holdButton=0;
    }
   break;
   case 0x70: //задържан бутон 5 калибровка
   
   butstat5=!butstat5;
   if(holdButton==1){
    menucount=5;
    lcd.clear();
    buttonset[0]=0;
    buttonset[1]=0;
    buttonset[2]=0;
    buttonset[3]=0;
    buttonset[4]=0;
    holdButton=0;
    }
   break;
   case 0x2F: //Автоматично установяване на режим ауто
   butstat11=1;
   butstat21=1;
   butstat31=1;
   lcd.print("AUTO");delay(4000);
   break;
  }
  countholdkey=0;
  ButtonByte=0x00;
 }
}
