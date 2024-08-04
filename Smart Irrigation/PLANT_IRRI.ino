// ----------------------Smart Irrigation system using Arduino with 2 soil moisture sensor--------------------------


#include <LiquidCrystal.h>     // importing libraries

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  // defining pins for lcd display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                 // defining instance



#define soil_sensor_1 A0             //defining pins for soil moisture sensor
#define soil_sensor_2 A1

#define water_pump 8                 // defining pin for relay/water pump
#define water_pump 9

int soil1 = 0;
int soil2 = 0;
//  intializing setup
void setup() {

  // setting baud rate for communication
  Serial.begin(9600);
  // initializing lcd
  lcd.begin(16, 2);

  // setting up pins

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  //  lcd.backlight();
  lcd.clear();

  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("IRRIGATION");
  lcd.setCursor(1, 1);
  lcd.print("SYSTEM ");
  for (int a = 12; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(1500);
  }} 
void loop() {
    // readin sensor input
lcd.clear();
    soil1 = analogRead(A0);
    soil2 = analogRead(A1);
   


    lcd.setCursor(0, 0);
    lcd.print("moist1 =");
    lcd.setCursor(10, 0);
    lcd.print(soil1);
    lcd.setCursor(0, 1);
    lcd.print("moist2 =");
    lcd.setCursor(10, 1);
    lcd.print(soil2);

    delay(5000);
    lcd.clear();

// pumping starting and ending limits

  if (soil1>800) {
    digitalWrite(8, LOW);
    lcd.setCursor(0, 0);
    lcd.print("MOTOR1 IS ON ");
 delay(5000); } 
 else {
    digitalWrite(8,HIGH);
    lcd.setCursor(0, 0);
    lcd.print("MOTOR1 IS OFF ");
  delay(5000);}

  
if (soil2>800) {
    digitalWrite(9, LOW);
    lcd.setCursor(1, 0);
    lcd.print("MOTOR2 IS ON ");
 delay(5000); } else  {
    digitalWrite(9, HIGH);
    lcd.setCursor(1, 0);
    lcd.print("MOTOR2 IS OFF");
  delay(5000);}
 }
