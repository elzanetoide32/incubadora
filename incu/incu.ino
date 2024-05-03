#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

int SENSOR = 12;
DHT dht(SENSOR, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  lcd.init (); 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Incubadora 3k");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperature, 2); // Mostrar temperatura con 1 decimal
  lcd.print((char)223); // Grado Celsius
  
  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(humidity, 2); // Mostrar humedad con 1 decimal
  lcd.print("%");
  delay(100);
}
