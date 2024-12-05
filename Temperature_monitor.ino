 #define sensorPin A0
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  
  Serial.begin(9600);
   lcd.begin(16,2);
   lcd.backlight();
}
 
void loop() {
  lcd.clear();
  int reading = analogRead(sensorPin);
 
  float voltage = reading * (5.0 / 1024.0);
 
  float temperatureC = voltage * 100;
 
  Serial.print("Temperature: ");
  
   lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(0,1);
  lcd.print(temperatureC);
  lcd.setCursor(6,1);
  lcd.print("C");
  
  
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  lcd.setCursor(8,1);
  lcd.print(temperatureF);
  lcd.setCursor(14,1);
  lcd.print("F");
  
  delay(1000);

  
}
