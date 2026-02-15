# Temperature Monitor ESP32-OLED-BMP280-AHT20

<img src="https://github.com/easai/temp-monitor-esp32/blob/main/IMG_2862.jpeg" width="300"/>

This project utilizes the ESP32 C3 Super Mini, equipped with AHT20 and BMP280 sensors, on a shared I2C bus. The project includes a PlatformIO unit test that verifies sensor communication using the pio test command.

## Pin Configuration

<img src="https://github.com/easai/temp-monitor-esp32/blob/main/IMG_2873.jpeg" width="300"/>

### BMP/AHT Sensor
| AHT Pin | ESP32 C3 Pin |
|---------|--------------|
| SDA     | GPIO 8       |
| SCL     | GPIO 9       |
| VCC     | 3V3          |
| GND     | GND          |

### OLED Display
| OLED Pin | ESP32 C3 Pin |
|----------|--------------|
| SDA      | GPIO 8       |
| SCL      | GPIO 9       |
| VCC      | 3V3          |
| GND      | GND          |

All devices share the same I2C bus.

## Unit Test Description

The unit test is located in the test directory and is executed using the pio test command. The test performs the following actions

1. Initializes the I2C bus on GPIO 8 and GPIO 9  
2. Attempts to initialize the AHT sensor  
3. Attempts to initialize the BMP sensor  
4. Reports a failure if either sensor does not respond  
5. Reports success if both sensors acknowledge communication  

The test is designed to run automatically without user interaction.

## Running the Test

Use the following command in the project directory

```bash
pio test
```

### Included Files
The `/stl` directory contains the printable case components (top cover and base plate).

Contents of the /stl directory:

• Top cover designed to fit the OLED module  
• Base plate with mounting points for the ESP32 C3 Super Mini  
• Internal clearances matched to the AHT20 and BMP280 sensors  
• Models prepared for standard FDM printing tolerances  
• Files exported in millimeter units for compatibility with common slicers
