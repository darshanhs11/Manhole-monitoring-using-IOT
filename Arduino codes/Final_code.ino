// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLh3RGqBrt"
#define BLYNK_DEVICE_NAME "EC520"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI
 
#include "BlynkEdgent.h"
#include<SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial gsm(4,5); // D2-RX , D1-TX

static const int RXPin = 13, TXPin = 15; // D7, D8 
static const uint32_t GPSBaud = 9600; 

float latitude;
float longitude; 

int smokeA0 = 16 ; // D0
int sensorThreshold = 200;

int tiltSensor1 = 14; // D5
int tiltSensor2 = 12; // D6

const int trigP = 2;  //D4 Or GPIO-2 of nodemcu
const int echoP = 0;  //D3 Or GPIO-0 of nodemcu

long duration;
int distance;

int temp;
String textForSMS;

TinyGPSPlus gps; // The TinyGPS++ object
WidgetMap myMap(V0);  // V0 for virtual pin of Map Widget

SoftwareSerial ss(RXPin, TXPin);  // The serial connection to the GPS device

BlynkTimer timer;

float spd;       //Variable  to store the speed
float sats;      //Variable to store no. of satellites response
String bearing;  //Variable to store orientation or direction of GPS

//unsigned int move_index;         // moving index, to be used later
unsigned int move_index = 1;       // fixed location for now
  
void setup()
{ 
    Serial.begin(115200);
  Serial.println();
  ss.begin(GPSBaud);
  pinMode(smokeA0, INPUT);
  pinMode(trigP, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoP, INPUT);   // Sets the echoPin as an Input
  pinMode (tiltSensor1,INPUT);
  pinMode (tiltSensor2,INPUT);
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
}

void checkGPS(){
  if (gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
  }
}

void loop() {

  while (ss.available() > 0) 
    {
      // sketch displays information every time a new sentence is correctly encoded.
      if (gps.encode(ss.read()))
        displayInfo();
  }

  timer.run();
  
  digitalWrite(trigP, LOW);   // Makes trigPin low
delayMicroseconds(2);       // 2 micro second delay 

digitalWrite(trigP, HIGH);  // tigPin high
delayMicroseconds(10);      // trigPin high for 10 micro seconds
digitalWrite(trigP, LOW);   // trigPin low

duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
distance= duration*0.026/2;        //Calculating actual/real distance

Serial.print("Distance = ");        //Output distance on arduino serial monitor 
Serial.println(distance);
delay(3000); 
  Blynk.virtualWrite(V2,distance); 

   while(distance<10)
  {     Blynk.logEvent("distance");
        textForSMS =  "\nWater Level is High in \n";
        textForSMS = textForSMS +  "https://www.google.com/maps/search/?api=1&query="; 
        textForSMS = textForSMS + latitude; 
        textForSMS = textForSMS + ","; 
        textForSMS = textForSMS + longitude;
        sendSMS(textForSMS);
        break;
  }

 int val1 = digitalRead(tiltSensor1);
 int val2 = digitalRead(tiltSensor2);

  if (val1==LOW||val2==LOW)
  {
     Blynk.virtualWrite(V3,"Cap is Perfect");
     Serial.println("Cap is Perfect");
    
  }
  else
  {  
     Blynk.logEvent("tilt");
     Blynk.virtualWrite(V3,"Cap is Tilted");
     Serial.println("Cap is Tilted");
      while(1)
     {  
        textForSMS =  "\nCap is Tilted in \n";
        textForSMS = textForSMS +  "https://www.google.com/maps/search/?api=1&query="; 
        textForSMS = textForSMS + latitude; 
        textForSMS = textForSMS + ","; 
        textForSMS = textForSMS + longitude;
        sendSMS(textForSMS);
        break;
     }
  }

float  analogSensor = digitalRead(smokeA0);
   Serial.println(analogSensor);
   while(analogSensor>sensorThreshold)
  {     
        Blynk.virtualWrite(V4,"Smoke is detected");
        textForSMS =  "\nSmoke detected in \n";
        textForSMS = textForSMS +  "https://www.google.com/maps/search/?api=1&query="; 
        textForSMS = textForSMS + latitude; 
        textForSMS = textForSMS + ","; 
        textForSMS = textForSMS + longitude;
        sendSMS(textForSMS);
        break;
        
  }
 
  temp= analogRead(A0)*0.28;  
   Serial.println(temp);  
   delay(1000); 
  Blynk.virtualWrite(V1, temp);
   while(temp>40)
  {
        textForSMS =  "\nFire detected in \n";
        textForSMS = textForSMS +  "https://www.google.com/maps/search/?api=1&query="; 
        textForSMS = textForSMS + latitude; 
        textForSMS = textForSMS + ","; 
        textForSMS = textForSMS + longitude;
        sendSMS(textForSMS);
        break;
  }
  
while (ss.available() > 0) 
    {
      // sketch displays information every time a new sentence is correctly encoded.
      if (gps.encode(ss.read()))
        displayInfo();
  }

  timer.run();
   BlynkEdgent.run();
}

void displayInfo()
{ 
  if (gps.location.isValid() ) 
  {    
    latitude = (gps.location.lat());     //Storing the Lat. and Lon. 
    longitude = (gps.location.lng()); 
    
    Serial.print("LAT:  ");
    Serial.println(latitude, 6);  // float to x decimal places
    Serial.print("LONG: ");
    Serial.println(longitude, 6);
    Blynk.virtualWrite(V5, String(latitude, 6));   
    Blynk.virtualWrite(V6, String(longitude, 6));                    
  }
  
 Serial.println();
}

void sendSMS(String message)
{
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+919019799629\"\r"); 
  delay(1000);
  gsm.println(message);
  delay(100);
  gsm.println((char)26);
  delay(1000);                                
}
