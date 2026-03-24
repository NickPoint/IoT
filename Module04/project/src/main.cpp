#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
#include <Wire.h>
#include <U8g2lib.h>

const char* ssid = "IOT11";
const char* password = "iotempire";
const char* mqtt_server = "192.168.1.1";
const char* ota_password = "iotempower";

const char* hostname = "esp32-alarm";

WiFiClient espClient;
PubSubClient client(espClient);

String alarmMessage = "Waiting...";

U8G2_SSD1306_64X48_ER_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void connectWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.setHostname(hostname);
  WiFi.begin(ssid, password);

  Serial.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("WiFi connected, IP: ");
  Serial.println(WiFi.localIP());
}

void setupOta() {
  ArduinoOTA.setHostname(hostname);
  ArduinoOTA.setPassword(ota_password);

  ArduinoOTA.onStart([]() {
    Serial.println("OTA update started");
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA update finished");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("OTA progress: %u%%\r", (progress * 100U) / total);
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("OTA error[%u]\n", error);
  });

  ArduinoOTA.begin();
  Serial.print("OTA ready: ");
  Serial.println(hostname);
}

void callback(char* topic, byte* payload, unsigned int length) {
  (void)topic;

  alarmMessage = "";

  for (unsigned int i = 0; i < length; i++) {
    alarmMessage += (char)payload[i];
  }

  Serial.println("MQTT message:");
  Serial.println(alarmMessage);
}

void reconnect() {
  while (!client.connected()) {
    ArduinoOTA.handle();

    Serial.println("Connecting MQTT...");

    if (client.connect(hostname)) {
      client.subscribe("prison/alarm");
      Serial.println("MQTT connected");
    } else {
      Serial.print("MQTT failed, rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  u8g2.begin();
  connectWiFi();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  setupOta();
}

void loop() {
  ArduinoOTA.handle();

  if (!client.connected()) {
    reconnect();
  }

  client.loop();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(0, 10, "Security:");
  u8g2.drawStr(0, 25, alarmMessage.c_str());
  u8g2.sendBuffer();

  delay(200);
}
