#include <LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Ca marche !");
  
  for(int i=0;i<15;i++){
    lcd.setCursor(i,1);
    lcd.print("-");
    delay(100);
  }
  lcd.clear();
  lcd.print("Opérationnel ! :D");
}

void loop() {
  lcd.cursor();
  delay(500);
  lcd.noCursor();
  delay(500); 
}
