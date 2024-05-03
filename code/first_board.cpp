#include <Wire.h> 
#include <Servo.h>

Servo servoMotor; 

#define Servo 7 
#define TMP A1

int temp = 0;
int buzzer = 10;
int btn = 6;
int btnIs;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(TMP, INPUT);
  servoMotor.attach(Servo);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  btnIs = digitalRead(btn);
  
 temp = analogRead(TMP);
  temp = map(temp, 20, 358, -40, 125);
  
  if (btnIs == LOW && temp >= 40) {
  	servoMotor.write(90);
    tone(buzzer, 2000, 50);
  } else {
  servoMotor.write(0);
  tone(buzzer, 0, 100);
  }
  
 Serial.println(temp);
 delay(1000);
  
  Wire.beginTransmission(10);
  Wire.write(temp >> 8);
  Wire.write(temp & 0xFF);
  Wire.endTransmission();
}
