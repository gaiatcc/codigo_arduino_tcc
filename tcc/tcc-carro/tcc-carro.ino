/*******************************************************************************
* Modulo L298N Primeiros Passos (v1.0)
* 
* Rampa de aceleracao e desaceleracao de dois motores utilizando o driver L298N.
* Os motores irao acelerar de 0 rpm ate a sua rotacao maxima e entao reduzir a 
* velocidade ate parar, com o mesmo intervalo de tempo. Entao os motores irao 
* rotacionar no sentido contrario com a mesma aceleracao e desaceleracao.
* 
* Copyright 2019 RoboCore.
* Escrito por Giovanni de Castro (05/04/2019).
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version (<https://www.gnu.org/licenses/>).
*******************************************************************************/

//declaracao dos pinos utilizados para controlar a velocidade de rotacao
const int PINO_ENA = 6; 
const int PINO_ENB = 5;

//declaracao dos pinos utilizados para controlar o sentido do motor
const int PINO_IN1 = 4; 
const int PINO_IN2 = 3;
const int PINO_IN3 = 8;
const int PINO_IN4 = 7;

int i = 0; //declaracao da variavel para as rampas

const int TEMPO_ESPERA = 1000; //declaracao do intervalo de 1 segundo entre os sentidos de rotacao do motor

const int TEMPO_RAMPA = 30; //declaracao do intervalo de 30 ms para as rampas de aceleracao e desaceleracao

void setup() {

  //configuração dos pinos como saida
  pinMode(PINO_ENA, OUTPUT); 
  pinMode(PINO_ENB, OUTPUT);
  pinMode(PINO_IN1, OUTPUT);
  pinMode(PINO_IN2, OUTPUT);
  pinMode(PINO_IN3, OUTPUT);
  pinMode(PINO_IN4, OUTPUT);

  //inicia o codigo com os motores parados
  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN2, LOW);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, LOW);
  digitalWrite(PINO_ENA, LOW);
  digitalWrite(PINO_ENB, LOW);

}

void loop() {

  //configura os motores para o sentido horario
  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN2, HIGH);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, HIGH);

  //rampa de aceleracao
  for (i = 0; i < 256; i=i+10){ 
    analogWrite(PINO_ENA, i);
    analogWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  }

  //rampa de desaceleracao
  for (i = 255; i >= 0; i=i-10){ 
    analogWrite(PINO_ENA, i);
    analogWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  }

  delay(TEMPO_ESPERA); //intervalo de um segundo

  //configura os motores para o sentido anti-horario
  digitalWrite(PINO_IN1, HIGH); 
  digitalWrite(PINO_IN2, LOW);
  digitalWrite(PINO_IN3, HIGH);
  digitalWrite(PINO_IN4, LOW);

  //rampa de aceleracao
  for (i = 0; i < 256; i=i+10){ 
    analogWrite(PINO_ENA, i);
    analogWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  }

  //rampa de desaceleracao
  for (i = 255; i >= 0; i=i-10){ 
    analogWrite(PINO_ENA, i); 
    analogWrite(PINO_ENB, i);
    delay(TEMPO_RAMPA); //intervalo para incrementar a variavel i
  }

  delay(TEMPO_ESPERA); //intervalo de um segundo
  
}
