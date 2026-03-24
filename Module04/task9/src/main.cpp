#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <FastLED.h>
#include <Wire.h>
#include <U8g2lib.h>

#define LED_PIN 25
#define NUM_LEDS 30

const char* ssid = "IOT11";
const char* password = "iotempire";
const char* mqtt_server = "192.168.1.1";

WiFiClient espClient;
PubSubClient client(espClient);

CRGB leds[NUM_LEDS];

String alarmState="all_clear";

U8G2_SSD1306_64X48_ER_F_HW_I2C u8g2(U8G2_R0,U8X8_PIN_NONE);

void callback(char* topic, byte* payload, unsigned int length){

  alarmState="";

  for(int i=0;i<length;i++){
    alarmState += (char)payload[i];
  }

  Serial.println(alarmState);

}

void reconnect(){

  while(!client.connected()){

    if(client.connect("esp32alarm")){
      client.subscribe("prison/alarm");
    }
    else{
      delay(2000);
    }
  }
}

void setup(){

  Serial.begin(115200);

  Wire.begin(21,22);

  u8g2.begin();

  FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,NUM_LEDS);

  WiFi.begin(ssid,password);

  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
  }

  client.setServer(mqtt_server,1883);
  client.setCallback(callback);
}

void loop(){

  if(!client.connected()){
    reconnect();
  }

  client.loop();

  // LED behaviour
  if(alarmState=="all_clear"){

    for(int i=0;i<NUM_LEDS;i++){
      leds[i]=CRGB::Green;
    }

    FastLED.show();
  }

  if(alarmState=="possible_threat"){

    static int b=0;
    static int dir=5;

    b+=dir;

    if(b>255 || b<0)
      dir=-dir;

    for(int i=0;i<NUM_LEDS;i++){
      leds[i]=CRGB(b,0,0);
    }

    FastLED.show();
  }

  if(alarmState=="lockdown"){

    static bool state=false;

    state=!state;

    for(int i=0;i<NUM_LEDS;i++){
      leds[i]= state ? CRGB::Red : CRGB::Black;
    }

    FastLED.show();

    delay(200);
  }

  // OLED display
  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_5x7_tr);

  u8g2.drawStr(0,10,"Security:");

  u8g2.drawStr(0,30,alarmState.c_str());

  u8g2.sendBuffer();

  delay(50);
}