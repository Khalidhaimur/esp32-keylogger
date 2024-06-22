#include <WiFi.h>

const char* ssid = "HUAWEI Y9a";
const char* password = "23456781";

void setup() {
  Serial.begin(115200);

  // الاتصال بشبكة WiFi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("الاتصال بالشبكة...");
  }

  // عرض عنوان IP على المسلسل
  Serial.println("تم الاتصال بشبكة WiFi");
  Serial.print("عنوان IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // لا يوجد شيء هنا
}
