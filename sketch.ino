#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int button = 9;
const int button_P = 8;
int lcdAddress = 0x27;
LiquidCrystal_I2C lcd_1(lcdAddress, 16, 2);
bool campana = false;

int contador = 4;

int val = 0; // estado de "button"
int state = 0;
int old_val = 0; // Antiguo valor de "val"

void cuenta_regresiva () {
    for (contador = 0; contador <= 5; contador++) {
    lcd_1.setCursor(0, 1);        
    lcd_1.print(contador);
    delay(1000);

    if (contador == 5) {
      lcd_1.clear();
      lcd_1.setCursor(0 ,0);
    }
  }
}

void timbre () {
  campana = true;
  lcd_1.print("Timbreeeeeee...");
  lcd_1.setCursor(0, 0);
  delay(1000);
  lcd_1.clear();
  lcd_1.print("Espera...");
  delay(1000);
  cuenta_regresiva();
  
  
  if (digitalRead(button_P) == HIGH && campana) {
    campana = false; 
    digitalWrite(button_P, LOW);
    lcd_1.clear();
    lcd_1.print("Puerta Abierta");
    delay(3000);
    lcd_1.clear();
  }

  else if (campana == true) {
    lcd_1.clear();
    lcd_1.print("Puerta!!!");
    cuenta_regresiva();
  }
}

void setup () {
  Wire.begin();
  lcd_1.init();
  pinMode(button, INPUT);
  pinMode(button_P, INPUT);
  lcd_1.backlight();
  lcd_1.setCursor(0, 0);
}




void loop () {
  val = digitalRead(button);
  if (val == HIGH){
  state = 1-state;
  timbre();
  delay(10);
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