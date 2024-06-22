#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

const char* ssid = "HUAWEI Y9a";
const char* password = "23456781";
WiFiServer server(12345);

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");

  // Start the TCP server
  server.begin();
  Serial.println("TCP server started");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");

    while (client.connected()) {
      if (client.available() > 0) {
        char incomingByte = client.read();
        Serial.print("Received: ");
        Serial.println(incomingByte);
        // هنا يمكنك إضافة أي عمليات معالجة إضافية للبيانات المستقبلة
      }
    }

    Serial.println("Client disconnected");
  }
}
