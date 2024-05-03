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

String temperatura; // Variável para armazenar a temperatura recebida
bool dadosRecebidos = false; // Flag para indicar se todos os dados foram recebidos

void recebe(int bytes) {
  if (bytes >= 2) { // Verifica se pelo menos dois bytes foram recebidos
    int temperaturaInt = Wire.read() << 8; // Lê o byte mais significativo
    temperaturaInt |= Wire.read(); // Lê o byte menos significativo e combina com o byte mais significativo
    temperatura = String(temperaturaInt); // Converte a temperatura para uma string
    dadosRecebidos = true; // Define a flag como true para indicar que todos os dados foram recebidos
  }
}

void exibirTemperatura() {
  if (dadosRecebidos) {
    // Exibe a temperatura no LCD
    lcd.clear(); // Limpa o LCD para remover leituras anteriores
    lcd.setCursor(0, 0); // Move o cursor para o início da primeira linha
    lcd.print("Temperatura:"); // Exibe "Temperatura:"
    
    lcd.setCursor(0, 1);
    lcd.print(temperatura); // Exibe a temperatura recebida
    lcd.write(byte(0)); // Escreve o caractere personalizado para o símbolo de grau Celsius
  	lcd.print("C"); // Exibe o símbolo de grau Celsius
    
    dadosRecebidos = false; // Reseta a flag para a próxima leitura
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
