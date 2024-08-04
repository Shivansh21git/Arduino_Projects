//------------------------ how to print dht sensor data to oled dispaly------------------------------------------------

#include <DHT.h>
#include <U8g2lib.h>
#include <Wire.h>

#define DHTPIN 4          // Pin where the DHT11 sensor is connected
#define DHTTYPE DHT11     // DHT sensor type
#define OLED_SDA 21       // Pin for OLED display's SDA
#define OLED_SCL 22       // Pin for OLED display's SCL

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor object
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, OLED_SCL, OLED_SDA);  // Initialize U8g2 display object

void setup() {
  Serial.begin(9600);
  dht.begin();
  u8g2.begin();
}

void loop() {
  delay(2000);  // Wait for 2 seconds

  // Read temperature and humidity values from DHT11 sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Print temperature and humidity values to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Display temperature and humidity on OLED display
  u8g2.clearBuffer();  // Clear the display buffer
  u8g2.setFont(u8g2_font_6x10_tf);  // Set the font size
  u8g2.setCursor(0, 10);  // Set the cursor position
  u8g2.print("Humidity: ");
  u8g2.print(humidity);
  u8g2.print("%");
  u8g2.setCursor(0, 30);
  u8g2.print("Temperature: ");
  u8g2.print(temperature);
  u8g2.print("C");
  u8g2.sendBuffer();  // Send the buffer to the display
}