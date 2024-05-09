// Este trecho inclui duas bibliotecas: "Wire.h" para comunicação I2C e "Servo.h" para controle de servo motor.

#include <Wire.h> 
#include <Servo.h>

// ----------<>----------

// Cria um objeto do tipo Servo chamado "servoMotor".

Servo servoMotor; 

// ----------<>----------

// Define os pinos para o servo motor (pino 7) e para o sensor de temperatura (pino analógico A1).

#define Servo 7 
#define TMP A1

// ----------<>----------

/* Declaração das variáveis utilizadas no código: "temp" para armazenar a temperatura lida pelo sensor, 
"buzzer" para controlar o buzzer, "btn" para o botão, e "btnIs" para armazenar o estado do botão. */

int temp = 0;
int buzzer = 10;
int btn = 6;
int btnIs;

// ----------<>----------

/* 
Configuração inicial:
* Inicia a comunicação I2C (Biblioteca Wire.h) com "Wire.begin()".
* Inicia a comunicação serial com "Serial.begin(9600)".
* Define o pino do sensor de temperatura como entrada.
* Anexa o objeto do servo motor ao pino definido anteriormente.
* Define o pino do buzzer como saída.
*/ 

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(TMP, INPUT);
  servoMotor.attach(Servo);
  pinMode(buzzer, OUTPUT);
}

// ----------<>----------

// Lê o estado do botão e armazena na variável "btnIs".

void loop()
{
  btnIs = digitalRead(btn);

// ----------<>----------

/*
Lê a temperatura do sensor analógico e a converte para graus Celsius utilizando a função "map", 
que faz uma correspondência linear entre a faixa de valores lidos pelo sensor e a faixa de temperatura desejada.
*/
  
temp = analogRead(TMP);
temp = map(temp, 20, 358, -40, 125);

// ----------<>----------

/*
Verifica se o botão está pressionado ("LOW") e se a temperatura é maior ou igual a 40°C. 
Se ambas as condições forem atendidas, o servo motor é posicionado em 90 graus e o buzzer emite um som com uma frequência de 2000 Hz por 50 milissegundos. 
Caso contrário, o servo motor é desligado (posição 0) e o buzzer é silenciado.
*/
  
if (btnIs == LOW && temp >= 40) {
  	servoMotor.write(90);
    tone(buzzer, 2000, 50);
} else {
  servoMotor.write(0);
  tone(buzzer, 0, 100);
}

// ----------<>----------

// Imprime a temperatura lida no monitor serial e aguarda 1 segundo antes de continuar.

 Serial.println(temp);
 delay(1000);

// ----------<>----------

/*Inicia uma transmissão I2C para o endereço 10 (2ª placa conectada ao barramento I2C). 
Os 16 bits da variável "temp" são enviados em dois bytes separados. O primeiro byte contém os 8 bits mais significativos (MSB) 
e o segundo byte contém os 8 bits menos significativos (LSB).
*/
  
  Wire.beginTransmission(10);
  Wire.write(temp >> 8);
  Wire.write(temp & 0xFF);
  Wire.endTransmission();
}
