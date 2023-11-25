#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int boton = 7;
int lcdAddress = 0x27;
LiquidCrystal_I2C lcd_1(lcdAddress, 16, 2);
int contador = 4;


void setup () {
  Wire.begin();
  lcd_1.init();
  pinMode(boton, INPUT);
  lcd_1.backlight();
  lcd_1.setCursor(0, 0);

}

void loop () {
  if (boton == HIGH) {
    lcd_1.setCursor(0, 1);
    lcd_1.print("Hola...");
  }
  
}

/*

Contador de Timbre y de Tiempo de espera:
Esto va en el void loop.

lcd_1.setCursor(0, 1);
  delay(1000);
  while (contador != -1) {
    lcd_1.setCursor(0,1);
    lcd_1.print(contador);
    contador -= 1;
    delay(1000);

    if (contador == 0) {
      lcd_1.setCursor(0, 0);
      lcd_1.clear();
      lcd_1.print("Espera...");
      lcd_1.setCursor(0, 1);
      for (contador = 0; contador >= 0; contador++) {
        lcd_1.setCursor(0, 1);        
        lcd_1.print(contador);
        delay(1000);
      }
    }
  }
*/