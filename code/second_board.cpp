#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte grauC[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};

String temperatura; 
bool dadosRecebidos = false; 

void recebe(int bytes) {
  if (bytes >= 2) { 
    int temperaturaInt = Wire.read() << 8; 
    temperaturaInt |= Wire.read(); 
    temperatura = String(temperaturaInt);
    dadosRecebidos = true;
  }
}

void exibirTemperatura() {
  if (dadosRecebidos) {
   
    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print("Temperatura:"); 
    
    lcd.setCursor(0, 1);
    lcd.print(temperatura);
    lcd.write(byte(0));
  	lcd.print("C");
    
    dadosRecebidos = false;
  }
}

void setup()
{
  lcd.createChar(0, grauC);
  
  lcd.begin(16, 2);
  Wire.begin(10);
  Wire.onReceive(recebe);
}

void loop()
{
  exibirTemperatura(); // Chama a função para exibir a temperatura
}
