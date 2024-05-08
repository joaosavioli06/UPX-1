![Logo do Git](https://sujeitoprogramador.com/wp-content/uploads/2021/04/gitimage.png)  

[Bem-vindo](#usina-de-projetos-experimentais-1---grupo-techurban) | [Integrantes](#integrantes) | [Sobre](#sobre-o-projeto) | [Tecnologias](#tecnologias-utilizadas) | [Bibliotecas](#bibliotecas-utilizadas-no-desenvolvimento) | [Funcionamento](#funcionamento-dos-equipamentos) |

# Usina de Projetos Experimentais 1 - Grupo TechUrban
Neste repositório você encontrará o projeto do 1º semestre da disciplina de UPX - 1 (Usina de Projetos Experimentais 1) do grupo TechUrban da turma A de Análise e Desenvolvimento de Sistemas EAD do Centro Universitário Facens.

## Integrantes
* Guilherme Gravalos Morais - RA: 249588
* João Gabriel Savioli - RA: 247617
* Luiz Fernando Brisola - RA: 249429

## Sobre o Projeto

O projeto foca na criação de um sistema de combate a incêndios, utilizando tecnologia Arduino em conjunto com componentes eletrônicos, como sensores de temperatura, displays LCD, servomotores e alarmes sonoros. A nossa abordagem visa não apenas detectar incêndios, mas também agir proativamente para conter e minimizar danos.

Nossa equipe dedicou esforços para selecionar cuidadosamente os equipamentos e definir suas funções, com base em simulações realistas de cenários de incêndio. Optamos por explorar ao máximo as capacidades oferecidas pela plataforma Tinkercad, aproveitando sua variedade de recursos para garantir a eficácia e a versatilidade do sistema.

Neste projeto utilizamos 3 placas Arduino e duas placas Protoboard para realizar o nosso sistema de combate a incêndios. Na 1ª placa, inserimos o TMP || sensor de temperatura para poder captar a temperatura do ambiente, buzzer para emitir um som de alarme caso a temperatura esteja acima de 40º C, servomotor para poder ativar um dispositivo de segurança, como uma válvula gás ou uma torneira de água. Também utilizamos um push button para que, quanto a temperatura estiver acima dos 40º C e o buzzer estiver emitindo som, alguém pode pressionar o botão para desativá-lo.

Na 2ª placa, incorporamos um LCD 16x2 para exibir a temperatura ambiente e um potenciômetro para ajustar a luminosidade do display. Utilizamos a biblioteca Wire.h para estabelecer comunicação entre a 1ª e a 2ª placa, permitindo que esta última receba informações do sensor de temperatura TMP da primeira e as exiba no LCD.

Já na 3ª placa Arduino, sua função é específica: contém um resistor projetado para aumentar a luminosidade do LCD, permitindo que o potenciômetro ajuste a luminosidade conforme necessário.

## Tecnologias Utilizadas

* Linguagem de Programação: C++
* Ambiente de Simulação: Tinkercad

## Bibliotecas Utilizadas no Desenvolvimento
* Wire.h
* Servo.h
* LiquidCrystal.h

## Funcionamento dos Equipamentos 

<div align="center"; font-weight="bold";>

Funcionamento dos Equipamentos na 1ª Placa 

![](/gif/gif_placaum.gif) 

Funcionamento dos Equipamentos nas 2 placas 

![](/gif/gif_placadois.gif) 

Funcionamento dos Equipamentos em Todas as Placas  

</div>

![](/gif/gif_3placas_juntas.gif) 
