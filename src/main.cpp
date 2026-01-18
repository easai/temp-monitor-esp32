#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_SSD1306.h>

#define SDA_PIN 8
#define SCL_PIN 9

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp(&Wire);

void setup() {
    Serial.begin(115200);
    delay(1500);

    Wire.begin(SDA_PIN, SCL_PIN);

    // OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("SSD1306 not found");
        while (1) delay(10);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Initializing...");
    display.display();

    // AHTX0
    if (!aht.begin(&Wire)) {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("AHTX0 not found");
        display.display();
        while (1) delay(10);
    }

    // BMP280
    if (!bmp.begin(0x77)) {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.println("BMP280 not found");
        display.display();
        while (1) delay(10);
    }

    bmp.setSampling(
        Adafruit_BMP280::MODE_NORMAL,
        Adafruit_BMP280::SAMPLING_X2,
        Adafruit_BMP280::SAMPLING_X16,
        Adafruit_BMP280::FILTER_X16,
        Adafruit_BMP280::STANDBY_MS_500
    );

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Sensors OK");
    display.display();
    delay(1000);
}

void loop() {
    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp);

    float bmpTemp = bmp.readTemperature();
    float pressure = bmp.readPressure() / 100.0; // hPa

    display.clearDisplay();
    display.setCursor(0, 0);

    display.println("ENVIRONMENT DATA");

    display.print("AHT Temp: ");
    display.print(temp.temperature);
    display.println(" C");

    display.print("AHT Hum:  ");
    display.print(humidity.relative_humidity);
    display.println(" %");

    display.print("BMP Temp: ");
    display.print(bmpTemp);
    display.println(" C");

    display.print("Pressure: ");
    display.print(pressure);
    display.println(" hPa");

    display.display();

    delay(1500);
}
