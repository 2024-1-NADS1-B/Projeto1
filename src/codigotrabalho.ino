#define BLYNK_TEMPLATE_ID           "TMPL2HKR03-9w"
#define BLYNK_TEMPLATE_NAME         "PROJETO AVICULTURA"
#define BLYNK_AUTH_TOKEN            "Jsuay_1YnFLYQXHAeP4iBWB3VNKaV_YK"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN D4 
#define DHTTYPE DHT11
#define POT_PIN A0

#define RED_LED_PIN D2
#define YELLOW_LED_PIN D3
#define GREEN_LED_PIN D1

DHT dht(DHTPIN, DHTTYPE);

float humidityAdjustment = 0.0;
float temperatureAdjustment = 0.0;

void setup() {
  Serial.begin(115200); 
  lcd.init();
  lcd.setBacklight(HIGH);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
}

void loop() {
  Blynk.run(); 
  delay(2000); 
  readAndDisplaySensorData();
  controlLEDsBasedOnTemperature();
  delay(1000);
}

void readAndDisplaySensorData() {
  float humidity = dht.readHumidity() + humidityAdjustment;
  float temperature = dht.readTemperature() + temperatureAdjustment;

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Erro ao ler o sensor!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor");
    
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("U: ");
    lcd.print(humidity);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("T: ");
    lcd.print(temperature);
    lcd.print(" C");
    
    Blynk.virtualWrite(V0, temperature); 
    Blynk.virtualWrite(V1, humidity); 
  }
}

void controlLEDsBasedOnTemperature() {
  float temperature = dht.readTemperature() + temperatureAdjustment;

  if (temperature >= 31 && temperature <= 35) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else if (temperature >= 28 && temperature <= 30) {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
  } else if (temperature >= 25 && temperature <= 27) {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
  } else {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
  }

  int potValue = analogRead(POT_PIN);
  temperatureAdjustment = map(potValue, 0, 1023, -5, 5);
}