#include <SoftwareSerial.h>

#include <LiquidCrystal.h>

#include <dht.h>   // include dht sensor library

LiquidCrystal lcd(10, 9, 5, 4, 3, 2);

dht DHT;

float t=0;

float h=0;

#define DHT11_PIN 8

#define LDR_PIN A1

#define MQ3_PIN A0

char data = 0;

int ldr_read = 0;

int gas_read = 0;


void setup()

{                

  // enable software serial

  Serial.begin(9600);

  lcd.begin(16,2);


 

 // pinMode(LDR_PIN, INPUT);

  //pinMode(MQ3_PIN, INPUT);


 

  lcd.setCursor(1,0);

  lcd.print("Food Spoilage");

  lcd.setCursor(3,1);

  lcd.print("Detection");

  Serial.begin(9600);
  delay(1000);




 }

// the loop

void loop()

{

  lcd.clear();

   lcd.setCursor(0,1);

  lcd.print("MQ3-");

  gas_read = analogRead(MQ3_PIN);

  lcd.setCursor(4,1);

  lcd.print(gas_read);


 


 

  //lcd.clear();



  if (gas_read<1000)
  {    lcd.setCursor(0,0);
    lcd.print("non spoiled food");
  }
  else
  {     lcd.setCursor(0,0);
    lcd.print("spoiled food");
  }
 


 
  




 

 

  //esp_8266();
  delay(3000);

}

/*void esp_8266()

{

   // TCP connection AT+CIPSTART=4,"TCP","184.106.153.149",80

    String cmd = "AT+CIPSTART=4,\"TCP\",\"";

    cmd += "184.106.153.149"; // api.thingspeak.com

    cmd += "\",80";

    ser.println(cmd);

    Serial.println(cmd);

    if(ser.find("Error"))

    {

      Serial.println("AT+CIPSTART error");

      return;

    }


 

  // prepare GET string GET https://api.thingspeak.com/update?api_key=LHAG4NSIYJ5UWS6U&field1=0rnrn

  String getStr = "GET /update?api_key=";

  getStr += apiKey;

  getStr +="&field1=";

  getStr +=String(t);

  getStr +="&field2=";

  getStr +=String(h);

  getStr +="&field3=";

  getStr +=String(ldr_read);

  getStr +="&field4=";

  getStr +=String(gas_read);

  getStr += "rnrn";

  // send data length

  cmd = "AT+CIPSEND=4,";

  cmd += String(getStr.length());

  ser.println(cmd);

  Serial.println(cmd);

  delay(1000);

  ser.print(getStr);

  Serial.println(getStr);


   

  // thingspeak needs 15 sec delay between updates

  delay(3000);  

}*/
