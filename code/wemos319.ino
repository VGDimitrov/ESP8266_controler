#if defined(ESP8266)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
//#define D0 3
//#define D1 1
//#define D2 16
//#define D3 5
//#define D4 4
//#define  D5 14
//#define  D6 12
//#define  D7 13
//#define  D8 0
//#define  D9 2
//#define  D10 15
//

//#ifndef UNIT_TEST
//#include <Arduino.h>
//#endif
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
boolean ON=0;
boolean OFF=1;

union {
    unsigned char Button_Byte;
    struct {

        unsigned B_Button1:1;
        unsigned B_Button2:1;
        unsigned B_Button3:1;
        unsigned B_Button4:1;
        unsigned B_Button5:1;
        unsigned B_Button6:1;
        unsigned B_Button7:1;
        unsigned B_Button8:1;
    } Button_Bits ;
} BUTTON_1 = {0};
//статус на бутони
#define Button1     BUTTON_1.Button_Bits.B_Button1
#define Button2     BUTTON_1.Button_Bits.B_Button2
#define Button3     BUTTON_1.Button_Bits.B_Button3
#define Button4     BUTTON_1.Button_Bits.B_Button4
#define Button5     BUTTON_1.Button_Bits.B_Button5
#define holdButton  BUTTON_1.Button_Bits.B_Button6
#define Buttread    BUTTON_1.Button_Bits.B_Button7
#define Buttonpush  BUTTON_1.Button_Bits.B_Button8


#define ButtonByte  BUTTON_1.Button_Byte

union {
    unsigned char Status_Byte;
    struct {

        unsigned F_Output1:1;
        unsigned F_Output2:1;
        unsigned F_Output3:1;
        unsigned F_Output4:1;
        unsigned F_Output5:1;
        unsigned F_Input1:1;
        unsigned F_Input2:1;
        unsigned F_Input3:1;
        
    } Status_Bits ;
} STATUS_1 = {0};
//статус на изходи входове
#define rstat1    STATUS_1.Status_Bits.F_Output1
#define rstat2    STATUS_1.Status_Bits.F_Output2
#define rstat3    STATUS_1.Status_Bits.F_Output3
#define rstat4    STATUS_1.Status_Bits.F_Output4
#define rstat5    STATUS_1.Status_Bits.F_Output5
#define input1   STATUS_1.Status_Bits.F_Input1
#define input2   STATUS_1.Status_Bits.F_Input2
#define input3   STATUS_1.Button_Bits.F_Input3

#define STATFByte  STATUS_1.Status_Byte

union {
    unsigned char ButStats_Byte;
    struct {

        unsigned F_ButStat1:1;
        unsigned F_ButStat2:1;
        unsigned F_ButStat3:1;
        unsigned F_ButStat4:1;
        unsigned F_ButStat5:1;
        unsigned F_ButStat11:1;
        unsigned F_ButStat21:1;
        unsigned F_ButStat31:1;
        
    } ButStats_Bits ;
} BUTSTATS_1 = {0};
//статус на отработени събития от бутони
#define butstat1   BUTSTATS_1.ButStats_Bits.F_ButStat1
#define butstat2   BUTSTATS_1.ButStats_Bits.F_ButStat2
#define butstat3   BUTSTATS_1.ButStats_Bits.F_ButStat3
#define butstat4   BUTSTATS_1.ButStats_Bits.F_ButStat4
#define butstat5   BUTSTATS_1.ButStats_Bits.F_ButStat5
#define butstat11   BUTSTATS_1.ButStats_Bits.F_ButStat11
#define butstat21   BUTSTATS_1.ButStats_Bits.F_ButStat21
#define butstat31   BUTSTATS_1.ButStats_Bits.F_ButStat31

#define ButStatsByte  BUTSTATS_1.ButStats_Byte

//union {
//    unsigned char MenuStat_Byte;
//    struct {
//
//        unsigned F_MenuStat1:1;
//        unsigned F_MenuStat2:1;
//        unsigned F_MenuStat3:1;
//        unsigned F_MenuStat4:1;
//        unsigned F_MenuStat5:1;
//        unsigned F_MenuStat11:1;
//        unsigned F_MenuStat21:1;
//        unsigned F_MenuStat31:1;
//        
//    } MenuStat_Bits ;
//} MenuStat = {0};
////статус на отработени събития от бутони
//#define menustat       MenuStat.MenuStat_Bits.F_MenuStat1
//#define butstat2        MenuStat.MenuStat_Bits.F_MenuStat2
//#define butstat3        MenuStat.MenuStat_Bits.F_MenuStat3
//#define butstat4        MenuStat.MenuStat_Bits.F_MenuStat4
//#define butstat5        MenuStat.MenuStat_Bits.F_MenuStat5
//#define butstat11       MenuStat.MenuStat_Bits.F_MenuStat11
//#define butstat21       MenuStat.MenuStat_Bits.F_MenuStat21
//#define menucalibrate   MenuStat.MenuStat_Bits.F_MenuStat31
//
//#define ButStatsByte  BUTSTATS_1.ButStats_Byte

//-----BME280---


//#include <BME280.h>
//#include <BME280I2C.h>
//#include <BME280Spi.h>
//#include <BME280SpiSw.h>




#include <LiquidCrystal_I2C.h>
#include "CyrLCDconverter.h"
LiquidCrystal_I2C lcd(0x27, 20, 4);
String menutextBG[100];
String TEXTBG[100] = {
  "  Бойлер  ",
  "Вентилация",
  " Отопление",
  "Осветление",
  "ВКЛ.",
  "ИЗКЛ",
  "АВТО",
  " Заето! ",
  "Свободно",
  "Душ",
  //10
  "   Нощ    ",
  "2-РИ РЕЖИМ",
  " Движение ",
  "Език:",
  "English  ",
  "Български",
  "Руски    ",
  "Друг     ",
  "Refresh:",
  "ДвжTXT:",
  //20
  "1 Параметри Панел ",
  "2 Упр  на Бойлер  ",
  "3 Конст Вентилация",
  "4 Конст Отопление ",
  "5 Конст Осветление",
  "6 Настр Свързаност",
  "7 Други настройки ",
  " ",
  " ",
  " ",
   //30
  "  Име на мрежата  ",
  " Парола на мрежата",
  "     Записване?    ",
  " НЕ              ДА",
  "Режим1:",
  "Режим2:",
  "Tmin=",
  "Tmax=",
  "Humf=",
  "до ",
  " ",
  //40
  "Мин  Влажност:",
  "Макс Влажност:",
  " T Присъствие:",
  " T Вентилажия:",
  " мин",
  "Време:",
  "РежимНОЩ:", 
  " сек",
  "",
  //50
  "   ВАВ Електроникс  ",
  " Закачане към мрежа ",
  " Установена връзка  ",
  "Няма достъп до Мрежа",
  "Мрежов Адрес:",
  "",
  "",
  "",
  "",
  "Firmware v:2.15.20bg",
  "",
  //60
  "Активност:   ",
  "Режим от/до: ",
  "Начален Час: ",
  "Краен Час:   ",
  ""
};

String TEXTEN[100] = {
  "  Boiler  ",
  "Ventilation",
  "  Heating ",
  " Lighting ",
  "ON ",
  "OFF",
  "АUTO",
  " Busy! ",
  "Free",
  "Busy shower",
  //10
  "   NIGHT    ",
  "2nd Mode",
  " Motion ",
  "Language:",
  "English  ",
  "Български",
  "Руски    ",
  "Друг     ",
  "Refresh:",
  "MoveTXT:",
  //20
  "1 Panel Settings  ",
  "2 Boiler Control  ",
  "3 Const Ventilation",
  "4 Const Heating   ",
  "5 Const Lighting  ",
  "6 Connection set  ",
  "7 Other settings ",
  " ",
  " ",
  " ",
   //30
  "  Network name: ",
  " Network password",
  "     Save:   ",
  " Б1             Б5",
  "Mode1:",
  "Mode2:",
  "Tmin=",
  "Tmax=",
  "Humf=",
  "to ",
  " ",
  //40
  "Min Hummidity:",
  "Max Hummidity:",
  "T  Pressend  :",
  "T Ventilation:",
  "min",
  "Clock:",
  "Time:", 
  "Connect to:",
  "Cannection",
  "WIFI IP:"
};

short buttonset[5]={
  750,
  660,
  560,
  400,
  50
};

// Construct an LCD object and pass it the
// I2C address, width (in characters) and
// height (in characters). Depending on the
// Actual device, the IC2 address may change.

////-----------------------
////IR приемник
//#ifndef UNIT_TEST
//#include <Arduino.h>
//#endif
//
//#include <IRremoteESP8266.h>
//#include <IRrecv.h>
//#include <IRutils.h>
//
//// An IR detector/demodulator is connected to GPIO pin 14(D5 on a NodeMCU
//// board).
////uint16_t RECV_PIN = D4;
//
////IRrecv irrecv(RECV_PIN);
//
////decode_results results;
///*-----( Declare Constants )-----*/
int receiver = D9; // pin 9 of IR receiver to Arduino digital pin 9 gpio2
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results result;          // create instance of 'decode_results'

/*-----( Declare Variables )-----*/
//използвани библиотеки за термодатчик Dallas 18b20
//#include <OneWire.h>
#include <Wire.h>
//#include <OneWire.h>
#include <DallasTemperature.h>

#include "SparkFunHTU21D.h"
//#include <BME280I2C.h>



#include "BlueDot_BME280.h"

BlueDot_BME280 bme1;                                     //Object for Sensor 1
BlueDot_BME280 bme2;                                     //Object for Sensor 2

int bme1Detected = 0;                                    //Checks if Sensor 1 is available
int bme2Detected = 0;                                    //Checks if Sensor 2 is available

//#include <AM2320.h>
HTU21D myHumidity;
//AM2320 sensor2;
//--------------------------
#define ONE_WIRE_BUS D5 //използван 8пин от ардуино за термодатчика да се свържи към 3.3v
OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

//край на дефинирането на термодатчик 18b20
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <EEPROM.h>
#include "MCP7941x.h" //clock library 
MCP7941x rtc = MCP7941x();
//#include "RTClib.h"
//#include <RtcDS1307.h>
//RtcDS1307<TwoWire> Rtc(Wire);
// Create new instance of class:
//String data[];
byte language=0;
boolean nightmode=1;
byte night=21,nightend=6;
//String rowbuff[4];
unsigned char menucount=0,nbut;
unsigned long mswrite=0;
unsigned char countholdkey;
boolean refresh;
int menutemp=0;
byte movetime=4;
byte refreshscreen=3;
unsigned short charcount=0;
byte waitc;
//#define SSIDName "Thunder"
//#define SSIDPassword "VeselinGD"

String  ssid = "abc";// "Thunder";//"Thunder";//type your ssid
String password = "12345678";//"VeselinGD";//type your password
String ssid1,password1;
//char* ssid2;
//char* password2;

//unsigned char *pRowBuff;
//int TempAsci_P;
//int TempAsci;
//   unsigned char TempAsci_P;
int value7 = 1 ;//определя менютата на сайта
byte setTD;//режим корекция на часовник
//int ledPin = D5; // GPIO2 of ESP8266
int k1 = A0;
/*-----( Declare Variables )-----*/
int pirPin = D7;               // choose the input pin9 (for PIR sensor)
int tuch = D2; //ir tuch
bool metric = true; 
float presin(NAN), humin(NAN), tempin(NAN),tmp(NAN), hum(NAN);
//дефиниране на пинове за използвани релета
int r1 = D0;
int r2 = D1;
int r3 = D10;
int setT = D6;
int r4 = D8;
//int light = D5;
int button = 1000;
int buttemp;
int DAY = 2, MONTH = 11, YEAR = 2017, HOUR = 10, MINUT = 0, SECOND = 0;
byte S, M, H, dw, D, MNT, Y;
float tempC;
int btime;
int npir;
int BG = 10;
float ver = 1.20; //versia kompilaciq



int i8 = 0, curentposit;
int charprint;
String  mrow1, mrow21, mrow22, mrow23, temp = ""; 
int iaction, iaction21, iaction22, iaction23;
float mseconstemp;
char charprint1, charprint21, charprint22, charprint23;
int pointer; 


boolean piraction;
byte pirtime;
byte pirHstart;
byte pirHstop;








WiFiServer server(80);
//------------------------promenlivi----------------------
//дефиниране на променливи за четене и определяне статуса на бутоните

byte setconst;

//boolean butstat1 = LOW;
////holdButton = 1;
//boolean butstat2 = LOW;
//boolean butstat21 = HIGH;
//boolean butstat3 = LOW;
//boolean butstat31 = HIGH;
//boolean butstat4 = LOW;
boolean fanstat = LOW;
boolean fanON = HIGH;
boolean bON = HIGH;
boolean pirON = HIGH;
boolean heatn = HIGH;
//boolean bonstat = LOW;
//boolean rstat1 = LOW;
//boolean rstat2 = LOW;
//boolean rstat3 = LOW;
//boolean rstat4 = LOW;
boolean initclock = LOW;
boolean r226 = LOW;
boolean offmod = LOW;
boolean secondmod = LOW;
boolean automod = HIGH;
boolean rstat1fix = LOW;

boolean pirstat = LOW;

//променливи за корегиране на константи през web

int Mread = 0;
int n = 0;
//long unsigned int mill;
//long unsigned int mill2;

//--------дефиниране на константи за систематаза/ време --------
int BoilerTime1;//2320
int BoilerTime2;
int BoilerTime3;
int BoilerTime4;
byte bH11 = 23, bH21 = 6, bM11 = 20, bM21 = 0, SMon1 = 1; //задаване на константи по подразбиране
byte bH12 = 18, bH22 = 20, bM12 = 00, bM22 = 0; //задаване на константи по подразбиране


byte Hummin1 = 2, Hummax1 = 5, Presence1 = 1, FANtime1 = 2, humoff1 = 185; //da se korigira


byte BoilerTemp1 = 25; //дефиниране на мин. температура за пускане на бойлер
byte BoilerTemp2 = 55; //дефиниране на макс достигната температура на бойлер в режим хл.вода

byte tempH=22;

int lcdofftime = 1;//време след което изключва подсветката на екрана за нощен режим 22-6 в мин.

//--константи използвани от системата прочетени от еепром
byte bH1, bH2, bM1, bM2, bH3, bH4, bM3, bM4, SMon, bTmin, bTmax, humoff, Hummin, Hummax, Presence, FANtime;

int RTCdata;
int RTCh;
int RTCm;
int RTCs;
//byte dw;
String daysOfTheWeek[7];

int RTCfan;
long unsigned int m2 = 0;
long unsigned int m = 0, m3 = 0;

//------КОНСТАНТИ---------



int b = 0;


//-----------------------символи за екран---------------
byte termometar[8] = //icon for termometer
{
  B00100,
  B01010,
  B01010,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

byte kapka[8] = //icon for water droplet
{
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110,
};
byte shift[8] = //icon Shift
{
  B00100,
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100
};
byte V1[8] = //icon for termometer
{
  B01001,
  B01001,
  B01010,
  B01011,
  B01010,
  B01110,
  B00100,
  B00000
};

byte V2[8] = //icon for water droplet
{
  B10010,
  B10010,
  B01010,
  B11010,
  B01010,
  B01110,
  B00100,
  B00000
};
byte line1[8] = //icon вертикална линия раделител(6)
{
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte wifi[8] = //icon вертикална линия раделител(6)
{
  
  B10101,
  B10101,
  B01110,
  B01110,
  B00100,
  B00100,
  B00100,
  B00000
};
boolean wificon=0;
void setup() {  // -------------------------------SETUP-------------------------
  wdt_enable(WDTO_8S);
  //digitalWrite(D8,HIGH);
  ButStatsByte=0x2F;
 //wdt_disable();
  ESP.wdtEnable(8000);
 // ButStatsByte=0x07;
  ConvertToCyrLCD converter = ConvertToCyrLCD(UTF8);
  daysOfTheWeek[1] = converter.convert(F("Неделя"));
  daysOfTheWeek[2] = converter.convert(F("Понеделник"));
  daysOfTheWeek[3] = converter.convert(F("Вторник"));
  daysOfTheWeek[4] = converter.convert(F("Сряда"));
  daysOfTheWeek[5] = converter.convert(F("Четвъртък"));
  daysOfTheWeek[6] = converter.convert(F("Петък"));
  daysOfTheWeek[0] = converter.convert(F("Събота"));
  Wire.begin();
  myHumidity.begin();
 
  //bme2.begin();delay(500);

  irrecv.enableIRIn();  // Start the receiver
  
  EEPROM.begin(512);
  eepromread();
  lcd.begin(20, 4);
  lcd.init();
  lcd.createChar(1, termometar);
  lcd.createChar(2, kapka);
  lcd.createChar(3, V1);
  lcd.createChar(4, V2);
  lcd.createChar(5, shift);
  lcd.createChar(6, line1);
  lcd.createChar(7, wifi);

  //end display setup
  // Turn on the backlight.
  lcd.backlight();
  // Move the cursor characters to the right and
  // zero characters down (line 1).
  


  //дефиниране на пиновете на релетата
 // pinMode(light, INPUT);
  pinMode(pirPin, INPUT_PULLUP); // declare sensor as input
  pinMode(tuch, INPUT_PULLUP); //стартови дефиниции детектор тъч
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(setT, OUTPUT);
  pinMode(k1, INPUT_PULLUP);
  digitalWrite(k1, HIGH); //  Да се провери нивото при прочитане на акалогов сигнал!!!!!
  
  //начално инициализиране на релета  //OFF=1;ON=0;
  rstat1=rstat2=rstat3=rstat4=1;
  digitalWrite(r1, rstat1 );
  digitalWrite(r2, rstat2);
  digitalWrite(r3, rstat3);
  digitalWrite(r4, rstat4);
  digitalWrite(pirPin, LOW);
  digitalWrite(tuch, LOW);
  /*za display 2004
    lcd.setCursor(6,1);lcd.print("|");lcd.setCursor(13,1);lcd.print("|");
    lcd.setCursor(6,2);lcd.print("|");lcd.setCursor(6,3);lcd.print("|");
    lcd.setCursor(13,2);lcd.print("|");lcd.setCursor(13,3);lcd.print("|");
    lcd.setCursor(14,3);lcd.print("Svob. ");
    lcd.setCursor(10,0);lcd.write(3);lcd.write(4);*/
  //clock setup
//Serial.begin(115200);
  //Serial.print("compiled: ");
  //Serial.print(__DATE__);
  //Serial.println(__TIME__);



  //--------RTC SETUP ------------

  rtc.enableClock();
// rtc.setDateTime(DateTime(__DATE__, __TIME__) );
  rtc.getDateTime(&S, &M, &H, &dw, &D, &MNT, &Y);
  //RtcDateTime now = Rtc.GetDateTime();
  RTCh = H * 100 + M;
  // if you are using ESP-01 then uncomment the line below to reset the pins to
  // the available pins for SDA, SCL
  // Wire.begin(0, 2); // due to limited pins, use pin 0 and 2 for SDA, SCL

  //Rtc.Begin();    //delay(500);

  //    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  //    NOWDateTime(compiled);
  ////Serial.println();

  //    if (!Rtc.IsDateTimeValid())
  //    {
  //        // Common Cuases:
  //        //    1) first time you ran and the device wasn't running yet
  //        //    2) the battery on the device is low or even missing
  //
  //        ////Serial.println("RTC lost confidence in the DateTime!");
  //        lcd.clear();
  //lcd.setCursor(0, 0);lcd.print("RTC lost confid.");lcd.setCursor(0, 1);lcd.print("in the DateTime!");
  //        // following line sets the RTC to the date & time this sketch was compiled
  //        // it will also reset the valid flag internally unless the Rtc device is
  //        // having an issue
  //
  //        Rtc.SetDateTime(compiled);
  //    }

  //    if (!Rtc.GetIsRunning())
  //    {
  //       // //Serial.println("RTC was not actively running, starting now");
  //         lcd.clear();
  //        lcd.setCursor(0, 0);lcd.print("RTC not actively");lcd.setCursor(0, 1);lcd.print("starting now");
  //        Rtc.SetIsRunning(true);
  //    }

  //  RtcDateTime now = Rtc.GetDateTime();
  //    if (now < compiled)
  //    {
  //        ////Serial.println("RTC is older than compile time!  (Updating DateTime)");
  //          lcd.clear();
  //        lcd.setCursor(0, 0);lcd.print("RTC is older");lcd.setCursor(0, 1);lcd.print("Updating...");
  //        rtc.setDateTime(compiled);
  //    }
  //    else if (now > compiled)
  //    {
  //        ////Serial.println("RTC is newer than compile time. (this is expected)");
  //          lcd.clear();
  //        lcd.setCursor(0, 0);lcd.print("RTC is newer");
  //    }
  //    else if (now == compiled)
  //    {
  //        ////Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  //          lcd.clear();
  //        lcd.setCursor(0, 0);lcd.print("RTC is OK");
  //    }

  // never assume the Rtc was last configured by you, so
  // just clear them to your needed state
  //    Rtc.SetSquareWavePin(DS1307SquareWaveOut_Low);





  

  textmasiv();
  inicialization();
////wifi connection
//  lcd.clear();
//  lcd.setCursor(0, 0); lcd.print("********************");
//  lcd.setCursor(0, 1); lcd.print(converter.convert (F("*   Закачане към   *")));
//  lcd.setCursor(19, 2); lcd.print("*"); lcd.setCursor(0, 2); lcd.print("*");
//  lcd.setCursor(5, 2); lcd.print(ssid);
//  lcd.setCursor(0, 3);  lcd.print("********************");
//
//  WiFi.begin(ssid, password);
//  //lcd.setCursor(0, 1);lcd.print("                ");
//  /*int teltje = 0;
//
//    while (WiFi.status()!= WL_CONNECTED) {
//      teltje++;
//      Serial.print(".");
//      if (teltje>20) {
//        //Serial.println("Connection Failed! Rebooting...");
//        delay(500);
//        ESP.restart();
//      }
//    }
//  */
//  WiFi.mode(WIFI_STA);
//  // WiFi.begin(ssid, password);//да се отмаркира и измисли как да се въведе име и парола за връзка към рутер
//  byte con;
//  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
//    
//    con++;
//    //lcd.clear();
//    lcd.setCursor(0+con, 2); lcd.print(".");
//    //lcd.setCursor(3, 3); lcd.print("Rebooting...");
//    delay(1000);
//  //menucount=26;
//  if (con>18){break;}
// //  ESP.restart();
//  }
////  delay(1000);
//  ////Serial.println("");
//  //Serial.println("WiFi connected");
//  server.begin();
//  //lcd.clear();
//  lcd.clear();
//  lcd.setCursor(0, 0); lcd.print("********************");
//  lcd.setCursor(0, 1); lcd.print("*"); lcd.setCursor(19, 1); lcd.print("*");
//  lcd.setCursor(0, 2); lcd.print("*"); lcd.setCursor(19, 2); lcd.print("*");
//  lcd.setCursor(0, 3); lcd.print("********************");
//  lcd.setCursor(3, 1);
//  lcd.print(converter.convert(F("WiFi установена")));
//  lcd.setCursor(3, 2); lcd.print("Server started");
//  ////Serial.println("Server started");
// // delay(1000);
//  // Print the IP address
//  lcd.clear();
//  lcd.setCursor(0, 0); lcd.print("********************");
//  lcd.setCursor(0, 1); lcd.print("*"); lcd.setCursor(19, 1); lcd.print("*");
//  lcd.setCursor(0, 2); lcd.print("*"); lcd.setCursor(19, 2); lcd.print("*");
//  lcd.setCursor(0, 3); lcd.print("********************");
//  lcd.setCursor(6, 1); lcd.print("WiFi IP:");
//  lcd.setCursor(3, 2); lcd.print(WiFi.localIP()); //delay(1000); //lcd.clear();
//  //Serial.print("IP:");Serial.println(WiFi.localIP());
//  // END CONNECTING WIFI

  //ota
  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);
  // Hostname defaults to esp8266-[ChipID]
  // ArduinoOTA.setHostname("myesp8266");
  // No authentication by default
  // ArduinoOTA.setPassword((const char *)"123");

  ArduinoOTA.onStart([]() {
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("********************");
    lcd.setCursor(0, 1); lcd.print("*"); lcd.setCursor(19, 1); lcd.print("*");
    lcd.setCursor(0, 2); lcd.print("*"); lcd.setCursor(19, 2); lcd.print("*");
    lcd.setCursor(0, 3); lcd.print("********************");
    lcd.setCursor(4, 1); lcd.print("Start Flash");
  });
  ArduinoOTA.onEnd([]() {
    lcd.setCursor(4, 1); lcd.print(" End  Flash");
    ////Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    lcd.setCursor(2, 2); lcd.printf("Progress: %u%%\r", (progress / (total / 100)));
    // Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    lcd.setCursor(1, 2); lcd.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      lcd.setCursor(0, 1);
      lcd.print("Auth Failed");
    }
    else if (error == OTA_BEGIN_ERROR) {
      lcd.setCursor(0, 1);
      lcd.print("Begin Failed");
    }
    else if (error == OTA_CONNECT_ERROR) {
      lcd.setCursor(0, 1);
      lcd.print("Connect Failed");
    }
    else if (error == OTA_RECEIVE_ERROR) {
      lcd.setCursor(0, 1);
      lcd.print("Receive Failed");
    }
    else if (error == OTA_END_ERROR) {
      lcd.setCursor(0, 1);
      lcd.print("End Failed");
    }
  });
  ArduinoOTA.begin();


  // BME 1 & 2 start

 bme1.parameter.communication = 0;                    //I2C communication for Sensor 1 (bme1)
 bme2.parameter.communication = 0;                    //I2C communication for Sensor 2 (bme2)
    

  
  //*********************************************************************
  //*************BASIC SETUP - SAFE TO IGNORE****************************
    
  //Set the I2C address of your breakout board  

    bme1.parameter.I2CAddress = 0x77;                    //I2C Address for Sensor 1 (bme1)onbord
    bme2.parameter.I2CAddress = 0x76;                    //I2C Address for Sensor 2 (bme2)

    
  
  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************
    
  //Now choose on which mode your device will run
  //On doubt, just leave on normal mode, that's the default value

  //0b00:     In sleep mode no measurements are performed, but power consumption is at a minimum
  //0b01:     In forced mode a single measured is performed and the device returns automatically to sleep mode
  //0b11:     In normal mode the sensor measures continually (default value)
  
    bme1.parameter.sensorMode = 0b11;                    //Setup Sensor mode for Sensor 1
    bme2.parameter.sensorMode = 0b11;                    //Setup Sensor mode for Sensor 2 


                  
  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************
  
  //Great! Now set up the internal IIR Filter
  //The IIR (Infinite Impulse Response) filter suppresses high frequency fluctuations
  //In short, a high factor value means less noise, but measurements are also less responsive
  //You can play with these values and check the results!
  //In doubt just leave on default

  //0b000:      factor 0 (filter off)
  //0b001:      factor 2
  //0b010:      factor 4
  //0b011:      factor 8
  //0b100:      factor 16 (default value)

    bme1.parameter.IIRfilter = 0b100;                   //IIR Filter for Sensor 1
    bme2.parameter.IIRfilter = 0b100;                   //IIR Filter for Sensor 2

    

  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************

    //Next you'll define the oversampling factor for the humidity measurements
  //Again, higher values mean less noise, but slower responses
  //If you don't want to measure humidity, set the oversampling to zero

  //0b000:      factor 0 (Disable humidity measurement)
  //0b001:      factor 1
  //0b010:      factor 2
  //0b011:      factor 4
  //0b100:      factor 8
  //0b101:      factor 16 (default value)

    bme1.parameter.humidOversampling = 0b101;            //Humidity Oversampling for Sensor 1
    bme2.parameter.humidOversampling = 0b101;            //Humidity Oversampling for Sensor 2

    

  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************
  
  //Now define the oversampling factor for the temperature measurements
  //You know now, higher values lead to less noise but slower measurements
  
  //0b000:      factor 0 (Disable temperature measurement)
  //0b001:      factor 1
  //0b010:      factor 2
  //0b011:      factor 4
  //0b100:      factor 8
  //0b101:      factor 16 (default value)

    bme1.parameter.tempOversampling = 0b101;              //Temperature Oversampling for Sensor 1
    bme2.parameter.tempOversampling = 0b101;              //Temperature Oversampling for Sensor 2

    

  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************
  
  //Finally, define the oversampling factor for the pressure measurements
  //For altitude measurements a higher factor provides more stable values
  //On doubt, just leave it on default
  
  //0b000:      factor 0 (Disable pressure measurement)
  //0b001:      factor 1
  //0b010:      factor 2
  //0b011:      factor 4
  //0b100:      factor 8
  //0b101:      factor 16 (default value)  

    bme1.parameter.pressOversampling = 0b101;             //Pressure Oversampling for Sensor 1
    bme2.parameter.pressOversampling = 0b101;             //Pressure Oversampling for Sensor 2 

     
  
  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE*************************
  
  //For precise altitude measurements please put in the current pressure corrected for the sea level
  //On doubt, just leave the standard pressure as default (1013.25 hPa);
  
    bme1.parameter.pressureSeaLevel = 994;            //default value of 1013.25 hPa (Sensor 1)
    bme2.parameter.pressureSeaLevel = 1013.25;            //default value of 1013.25 hPa (Sensor 2)

  //Also put in the current average temperature outside (yes, really outside!)
  //For slightly less precise altitude measurements, just leave the standard temperature as default (15°C and 59°F);
  
    bme1.parameter.tempOutsideCelsius = 15;               //default value of 15°C
    bme2.parameter.tempOutsideCelsius = 15;               //default value of 15°C
  
    bme1.parameter.tempOutsideFahrenheit = 59;            //default value of 59°F
    bme2.parameter.tempOutsideFahrenheit = 59;            //default value of 59°F

    
  
  //*********************************************************************
  //*************ADVANCED SETUP - SAFE TO IGNORE!************************

  //The Watchdog Timer forces the Arduino to restart whenever the program hangs for longer than 8 seconds.
  //This is useful when the program enters an infinite loop and stops giving any feedback on the serial monitor.
  //However the Watchdog Timer may also be triggered whenever a single program loop takes longer than 8 seconds.
  //Per default the Watchdog Timer is turned off (commented out).
  //Do you need to run the Arduino for a long time without supervision and your program loop takes less than 8 seconds? Then remove the comments below!
    
  //wdt_enable(WDTO_8S);                                 //Watchdog Timer counts for 8 seconds before starting the reset sequence
      

  
  //*********************************************************************
  //*************ADVANCED SETUP IS OVER - LET'S CHECK THE CHIP ID!*******
bme1.init();
bme2.init();
  if (bme1.init() != 0x60)
  {    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("1 BME280 not found!");
    bme1Detected = 0;
   
  }

  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("1 BME280 detected!");
    bme1Detected = 1;
    
  }

  if (bme2.init() != 0x60)
  {    
    
    lcd.setCursor(0,1);
    lcd.print("2 BME280 not found!");
    bme2Detected = 0;
    delay(1000);
  }

  else
  {
    
    lcd.setCursor(0,1);
    lcd.print("2 BME280 detected!");
    bme2Detected = 1;
    delay(1000);
  }

  if ((bme1Detected == 0)&(bme2Detected == 0))
  {
//    Serial.println();
//    Serial.println();
//    Serial.println(F("Troubleshooting Guide"));
//    Serial.println(F("*************************************************************"));
//    Serial.println(F("1. Let's check the basics: Are the VCC and GND pins connected correctly? If the BME280 is getting really hot, then the wires are crossed."));
//    Serial.println();
//    Serial.println(F("2. Did you connect the SDI pin from your BME280 to the SDA line from the Arduino?"));
//    Serial.println();
//    Serial.println(F("3. And did you connect the SCK pin from the BME280 to the SCL line from your Arduino?"));
//    Serial.println();
//    Serial.println(F("4. One of your sensors should be using the alternative I2C Address(0x76). Did you remember to connect the SDO pin to GND?"));
//    Serial.println();
//    Serial.println(F("5. The other sensor should be using the default I2C Address (0x77. Did you remember to leave the SDO pin unconnected?"));
//
//    Serial.println();
    
    while(1);
  }
    
//  Serial.println();
//  Serial.println();



  //*********************************************************************
  //*************NOW LET'S START MEASURING*******************************


  // BME END

  
  delay(500);
  sensors.begin();//стартиране на термодатчик 18b20 dallas
sensors.requestTemperatures();
tempC = sensors.getTempCByIndex(0);
  
  //sensor2.begin();
  am2320get();
  BME280GAT(); 
  //---------изписване на рамка и начални символи ------------------
  lcd.clear();
  lcd.setCursor(6, 1); lcd.write(6);
  lcd.setCursor(13, 1); lcd.write(6);
  lcd.setCursor(6, 2); lcd.write(6);
  lcd.setCursor(6, 3); lcd.write(6);
  lcd.setCursor(13, 2); lcd.write(6);
  lcd.setCursor(13, 3); lcd.write(6);
  //lcd.setCursor(9,0);lcd.write(3);lcd.write(4);//lcd.setCursor(0,3);lcd.write(5); // -------------VAV---
  if (tempC == 165) {
    tempC = 88;
  }
  if (hum > 99) {
    hum = 99;
  }
  if (tmp > 99) {
    tmp = 99;
  }
  lcd.setCursor(0, 2); lcd.write(1); lcd.print(" "); lcd.setCursor(2, 2); lcd.print(tempC); lcd.setCursor(4, 2); lcd.print((char)223); lcd.print("C");
  lcd.setCursor(7, 2); lcd.write(2); lcd.print(" "); lcd.setCursor(9, 2); lcd.print(hum); lcd.setCursor(12, 2); lcd.print("%");
  lcd.setCursor(7, 3); lcd.write(1); lcd.print(" "); lcd.setCursor(9, 3); lcd.print(tmp); lcd.setCursor(11, 3); lcd.print((char)223); lcd.print("C"); //отпечатване на влажност и температура на дисплей}
  lcd.setCursor(14, 2); lcd.write(2); lcd.print(" "); lcd.setCursor(16, 2); lcd.print(humin); lcd.setCursor(19, 2); lcd.print("%"); //отпечатване на флажност в коридор поз 3
  lcd.clear();

  menucount=0;
  readtemp();
//  for (int ts=0;ts<100;ts++){
//  if (language==0)
//  {
//    
//      menutextBG[ts]=TEXTEN[ts];
//      }else{menutextBG[ts]=TEXTBG[ts];}
//  }
////attachInterrupt(k1, testinterrup, RISING);
lcd.clear();
}
void loop()  //---------------------------------------------LOOP-----------------

{
 ArduinoOTA.handle();
 

 if (irrecv.decode(&result)) 
  {
    translateIR();
  
    irrecv.resume(); // receive the next value
  }else
  {
  readbuttons();
  }
  WEB(); 
  switch (menucount){
    case 0:
    
    mainbuttons();
    lcdgo();
    break;
    case 5:
     buttoncalibrate();
    break;
    case 20:
     menu();
    break;
    case 21:
     panelparam ();
    break;
    case 22:
     Boiler_Control ();
     break;
    case 23:
    Ventilation_Control ();
    break; 
    case 24:
    Heading ();
    break;
    case 25:
    lighting();
    break;
    case 26://смяна име и парола WIFI
     wifiaccess();
    break;
    case 27:
    
    if (butstat5==1){menucount=0;butstat5=0;}
    break;
    case 28:
     menucount=0;
    break;
  }

  // wdt_reset();
if (menucount==0)
{
if (WiFi.waitForConnectResult() == WL_CONNECTED) 
 {
  if (wificon==1)
  {
    server.begin();
    wificon=0;
  }
  
  lcd.setCursor(19,0);
  lcd.write(7);
 }
 else
 {
  wificon=1;
  lcd.setCursor(19,0);
  lcd.print(" ");
 }
  
  if (RTCh == 0 && S == 0) {
    lcd.clear(); lcd.setCursor(3, 1); lcd.print("Reset Constants"); delay(1000); lcd.setCursor(5, 2); lcd.print("Rebooting!"); delay(1000); lcd.setCursor(1, 3); lcd.print("Pleas Wait......"); delay(5000);
    //ESP.reset();
  }
 
  
  
 
  rtc.getDateTime(&S, &M, &H, &dw, &D, &MNT, &Y);//опресняване на часовника
  //RtcDateTime now = Rtc.GetDateTime();
  
  if (S == 10 ) //прочитане на данни на всчка минута
  {
    am2320get();
    BME280GAT();
    if (humin==999 || tempin==999){lcd.setCursor(0,3);lcd.print("NONE Sensor1");}
    readtemp();
    
  }
  
digitalWrite(r1,rstat1);
digitalWrite(r2,rstat2);
digitalWrite(r3,rstat3);
digitalWrite(r4,rstat4); 
}

}
