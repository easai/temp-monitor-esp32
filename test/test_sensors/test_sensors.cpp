#include <Arduino.h>
#include <unity.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>

#define SDA_PIN 8
#define SCL_PIN 9

Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp(&Wire);

void test_aht_connection() {
    bool ok = aht.begin(&Wire);
    TEST_ASSERT_TRUE_MESSAGE(ok, "AHTX0 not detected on I2C");
}

void test_bmp_connection() {
    bool ok = bmp.begin(0x77);   
    TEST_ASSERT_TRUE_MESSAGE(ok, "BMP280 not detected on I2C");
}

void setup() {
    delay(1500); 
    Wire.begin(SDA_PIN, SCL_PIN);

    UNITY_BEGIN();

    RUN_TEST(test_aht_connection);
    RUN_TEST(test_bmp_connection);

    UNITY_END();
}

void loop() {}
