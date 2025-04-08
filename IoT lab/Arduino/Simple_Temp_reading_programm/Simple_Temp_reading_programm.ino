#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2      // DHT11 connected to D2
#define DHTTYPE DHT11 // Specify sensor type
#define BUZZER 7      // Buzzer connected to pin 7
#define TEMP_THRESHOLD 28 // Temperature limit for buzzer

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(BUZZER, OUTPUT); // Set buzzer pin as output
    digitalWrite(BUZZER, LOW); // Keep buzzer off initially
}

void loop() {
    float temperature = dht.readTemperature();

    if (isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
    } else {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");

        // Buzzer logic
        if (temperature > TEMP_THRESHOLD) {
            digitalWrite(BUZZER, HIGH); // Turn buzzer ON
            delay(500); // Keep it on for 0.5 sec
            digitalWrite(BUZZER, LOW);  // Turn buzzer OFF
        }
    }

    delay(2000); // 2-second delay
}
