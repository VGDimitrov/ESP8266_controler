 
void translateIR() 
{
 // ButStatsByte=0x00;
  switch(result.value)
 {
   case 0xFF30CF:  //бойлер
   // Serial.println(" DIY1            "); 
    butstat1=1;//bipn=1;
   break;
   case 0x400401000E0F:  //бойлер
     if (menucount==0){
     rstat1=OFF;
     bON=!bON;
     }else{
      butstat1=1;
      }//Serial.println(" RED            "); 
    
   break;
   
   case 0xFFB04F:  //вентилация
   //Serial.println(" DIY2            ");
   butstat2=1;//bipn=2;
   break;
   case 0x400401008E8F:  //вентилация
   if (menucount==0){
    rstat2=OFF;
   fanON=!fanON;
   }else{
    butstat2=1;
    }
    //Serial.println(" Green           "); 
  
   break;
   
   case 0xFF708F:  //осветление
    //Serial.println(" DIY3              ");
    butstat4=1;//bipn=3;
   break;
   case 0x400401004E4F:  //осветление
  if (menucount==0){ 
    rstat4=OFF;
    pirON=1;
    }else{
      butstat3=1;
      } //Serial.println(" Yelow             "); 
  
   break;

    case 0xFF10EF:  //автоматичен режим бойлер
    //Serial.println(" DIY4              ");
   if (menucount==0){ 
    rstat1=OFF;
    bON=!bON;
    }else{
      butstat1=1;
      }
   break;

   case 0xFF906F:  //автоматичен режим вентилация отопление
    //Serial.println(" DIY5            "); 
     if (menucount==0){
      rstat2=OFF;
   fanON=!fanON;
   }else{
    butstat2=1;
    }
   break;

   case 0xFF50AF:  //автоматичен режим осветление
   //Serial.println(" DIY6             "); 
   if (menucount==0){
    rstat2=OFF;
   fanON=!fanON;
   }else{
    butstat3=1;
    }
   break;

   case 0xFFF00F:  
     butstat5=1;
                                       //bipn=4;
   break;

   case 0x400401005253:  //up(b1)
    butstat3=1;//bipn=1;
   break;
    case 0x40040100D2D3:  //douwn(b2)
    butstat2=1;
   break;
   case 0x400401007273:  //left (b1)
    butstat1=1;
   break;
   case 0x40040100F2F3:  //right (b4)
   
    butstat4=1;//bipn=1;
   break;
   case 0x400401009293:  //OK(b5)
   //lcd.setCursor(3,0);lcd.print("OK");
    
    if (menucount<20){menucount=20;}else{butstat5=1;}
   break;
  }
  delay(20);
  if (menucount==0){
  if (butstat1==1){rstat1=!rstat1;butstat1=0;}
  if (butstat2==1){rstat2=!rstat2;butstat2=0;}
  if (butstat3==1){rstat3=!rstat3;butstat3=0;}
  if (butstat4==1){rstat4=!rstat4;butstat4=0;}
  }
}
