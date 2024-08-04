#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math
#include <PulseSensorPlayground.h>  

 const int PulseWire = 0;       // 'S' Signal pin connected to A0
const int LED13 = 13;          // The on-board Arduino LED
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore
                               
PulseSensorPlayground pulseSensor; 

void setup() {
  	Serial.begin(9600);
   // initialize the lcd 
  lcd.init();
 lcd.backlight();
 lcd.setCursor(3,0);
  lcd.print("BPM Meter");
 
  lcd.setCursor(2, 1);
  lcd.print("AR RoboTics");
  //lcd.display();
 
   delay(1500);
  
  lcd.clear();
  // Configure the PulseSensor object, by assigning our variables to it
	pulseSensor.analogInput(PulseWire);   
	pulseSensor.blinkOnPulse(LED13);       // Blink on-board LED with heartbeat
	pulseSensor.setThreshold(Threshold);   

	// Double-check the "pulseSensor" object was created and began seeing a signal
	if (pulseSensor.begin()) {
		Serial.println("PulseSensor object created!");
	}
}
 
void loop()
{
int myBPM = pulseSensor.getBeatsPerMinute();      // Calculates BPM

	if (pulseSensor.sawStartOfBeat()) {     
 

lcd.setCursor(0,5);
lcd.print("BPM :");
lcd.print(myBPM);

  }delay(20);
}