#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define LED_BUILTIN 2
char auth[] = "copy_it_from_email";
const char* ssid="username";
const char* pass="password";
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  Serial.println();
  Serial.println(ssid);
  WiFi.begin(ssid,pass);
  Blynk.begin(auth, ssid, pass);

   Serial.println("connecting");

   while(WiFi.status()!=WL_CONNECTED){
    delay(500);
     Serial.print(".");
   }
   digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Connected");
     Serial.println("Address :");
      Serial.print(WiFi.localIP());
}

// the loop function runs over and over again forever
void loop() {
Blynk.run();
}
