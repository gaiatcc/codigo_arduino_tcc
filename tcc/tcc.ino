//Projeto medir a temperatura e a umidade com DHT11(sensor de umidade)
#include <DHT.h>//Inclui a biblioteca DHT Sensor Library
#define DHTPIN 2//Pino digital 2 conectado ao DHT11
#define DHTTYPE DHT11//DHT 11

DHT dht(DHTPIN, DHTTYPE);//Inicializando o objeto dht do tipo DHT passando como parâmetro o pino (DHTPIN) e o tipo do sensor (DHTTYPE)

void setup() {
  Serial.begin(9600);//Inicializa a comunicação serial
  dht.begin();//Inicializa o sensor
}

void loop() {
  delay(2000);//Intervalo de 2 segundos entre as medições

  float h = dht.readHumidity();//lê o valor da umidade e armazena na variável h do tipo float 
  float t = dht.readTemperature();//lê o valor da temperatura e armazena na variável t do tipo float 

  if (isnan(h) || isnan(t)) {//Verifica se a umidade ou temperatura são ou não um número
    return;//Caso não seja um número retorna
  }

  Serial.print("Umidade: ");//mostra no monitor serial a mensagem "Umidade: "
  Serial.print(h);//mostra na serial o valor da umidade
  Serial.println("%");//mostra na serial o caractere "%" e salta para a próxima linha
  Serial.print("Temperatura: ");//mostra no monitor serial a mensagem "Temperatura: "
  Serial.print(t);//mostra na serial o valor da temperatura
  Serial.println("°C ");//mostra no monitor serial "ºC" e salta para a próxima linha
}
