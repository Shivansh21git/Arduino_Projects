#include <Wire.h>
#include <Adafruit_ADS1X15.h>

#define ADS1015_ADDRESS 0x48  // I2C address of the ADS1015 module

// Create an instance of the ADS1015 class
Adafruit_ADS1015 ads;

// Analog input channels for the sensors
const int pHSensorPin = 0;        // Analog input pin for the pH sensor
const int moistureSensorPin = 1;  // Analog input pin for the moisture sensor

void setup() {
  Serial.begin(9600);
  
  // Initialize the ADS1015 module
  ads.begin(ADS1015_ADDRESS);
  
  // Set the gain (PGA) for the analog inputs (adjust according to your sensor requirements)
  ads.setGain(GAIN_TWOTHIRDS);  // +/- 6.144V range, good for 3.3V boards
  
  delay(1000);
}

void loop() {
  // Read the pH sensor value
  int pHValue = ads.readADC_SingleEnded(pHSensorPin);
  
  // Read the moisture sensor value
  int moistureValue = ads.readADC_SingleEnded(moistureSensorPin);
  
  // Convert the pH sensor value to pH level (adjust conversion formula according to your sensor)
  float pHLevel = map(pHValue, 0, 1023, 0, 14);  // Assuming pH range from 0 to 14
  
  // Convert the moisture sensor value to percentage (adjust conversion formula according to your sensor)
  float moisturePercentage = map(moistureValue, 0, 1023, 0, 100);
  
  // Print the sensor readings
  Serial.print("pH Level: ");
  Serial.println(pHLevel);
  
  Serial.print("Moisture Percentage: ");
  Serial.print(moisturePercentage);
  Serial.println("%");
  
  delay(1000);  // Delay between readings
}
