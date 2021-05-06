#include <MQUnifiedsensor.h>

#include <LiquidCrystal_I2C.h>
#include<Wire.h>

#define placa "Arduino UNO"
#define Voltage_Resolution 5
#define pin A0
#define type "MQ-135"
#define ADC_Bit_Resolution 10
#define RatioMQ135CleanAir 3.6

LiquidCrystal_I2C lcd(0x27,16,2);
MQUnifiedsensor MQ135(placa, Voltage_Resolution, ADC_Bit_Resolution, pin, type );


void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.home();

  MQ135.setRegressionMethod(1);
  MQ135.init();

  Serial.print("Calibrage...");
  float calcR0 = 0;
  for(int i = 1; i<=10; i++){
    MQ135.update();
    calcR0 += MQ135.calibrate(RatioMQ135CleanAir);
    Serial.print(".");
  }
   MQ135.setR0(calcR0/10);
   Serial.println("Done!.");
}

void loop() {
MQ135.update();
MQ135.setA(110.47); MQ135.setB(-2.862);
float CO2 = MQ135.readSensor();

lcd.clear();
lcd.print("Taux CO2 :");
lcd.setCursor(0,1);
lcd.print(CO2);
lcd.print(" PPM");

delay(2000);
}
