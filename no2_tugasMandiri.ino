#include <RTClib.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x20,20,4);
DS1307 rtc;

int temp, celcius;
int tempPin = 0; 
int sampleTime = 100;

void setup() {
  // put your setup code here, to run once:
  lcd.init();                  
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("LCD 20x4 I2C TEST");
  lcd.setCursor(1,1);
  lcd.print("....................");

    if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    lcd.setCursor(0,0);lcd.print("RTC not Found");
    while (1);
    }
    if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    lcd.setCursor(0,0);lcd.print("RTC not running");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void loop() {
  // put your main code here, to run repeatedly:
{
  delay(100);
  lcd.clear();
  delay(100);
  lcd.setCursor(1,0);
   bacaSuhu();
  lcd.setCursor(1,1);
  //bacaSuhu();
  lcd.setCursor(1,2);
  waktu();
  lcd.setCursor(1,3);
  //waktu();
  delay(200);
  }
}

void bacaSuhu(){
    temp = analogRead(tempPin); 

    lcd.print("Suhu = ");
    celcius = temp * (0.48828125); 
    lcd.print(celcius); 
    lcd.println(" ^C ");
    delay(sampleTime);
   
  }

 void waktu(){
    DateTime now = rtc.now(); 
    
    lcd.print(now.year(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.day(), DEC);
    lcd.print(' ');
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
    lcd.print(' ');
  }
