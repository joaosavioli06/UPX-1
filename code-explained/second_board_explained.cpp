// Inclui as bibliotecas necessárias para comunicação I2C e controle do display LCD.

#include <Wire.h>
#include <LiquidCrystal.h>

// ----------<>----------

// Cria um objeto LiquidCrystal chamado lcd e define os pinos de controle do display LCD.

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// ----------<>----------

/*
Define um caractere personalizado representando o símbolo de grau Celsius. 
Isso é necessário porque o display LCD não possui esse símbolo nativamente.
*/ 

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

// ----------<>----------

/*
Declaração de variáveis: 'temperatura' armazena a temperatura recebida e 
'dadosRecebidos' é uma flag || técnica para controlar o fluxo para indicar se todos os dados foram recebidos.
*/

String temperatura; 
bool dadosRecebidos = false; 

// ----------<>----------

/*
Função 'recebe(int bytes)': é chamada quando dados são recebidos pela comunicação I2C. 
Ela lê os dois bytes recebidos, os combina para formar o valor da temperatura e armazena na variável temperatura. 
A flag || técnica para controlar o fluxo 'dadosRecebidos' é definida como verdadeira.
*/

void recebe(int bytes) {
  if (bytes >= 2) { 
    int temperaturaInt = Wire.read() << 8; 
    temperaturaInt |= Wire.read(); 
    temperatura = String(temperaturaInt); 
    dadosRecebidos = true; 
  }
}

// ----------<>----------

/*
Função exibirTemperatura(): exibe a temperatura no display LCD. Se dadosRecebidos for verdadeiro, 
limpa o display, posiciona o cursor na primeira linha e exibe "Temperatura:". Em seguida, posiciona 
o cursor na segunda linha, exibe a temperatura seguida pelo símbolo de grau Celsius.
*/

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

// ----------<>----------

/*Configuração inicial:
* Cria o caractere personalizado para o símbolo de grau Celsius.
* Inicializa o display LCD com 16 colunas e 2 linhas.
* Inicia a comunicação I2C com endereço 10.
* Registra a função 'recebe()' para ser chamada quando dados são recebidos pela comunicação I2C.
*/

void setup()
{
  lcd.createChar(0, grauC);
  
  lcd.begin(16, 2);
  Wire.begin(10);
  Wire.onReceive(recebe);
}

// ----------<>----------

// Loop principal que chama continuamente a função 'exibirTemperatura()' para exibir a temperatura recebida no display LCD.

void loop()
{
  exibirTemperatura(); // Chama a função para exibir a temperatura
}
