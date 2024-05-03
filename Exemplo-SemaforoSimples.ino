/**
   ---------------------------------------------
   -- AUTOR: Mauricio de Oliveira Dian ---------
   -- Faculdade de Tecnologia de Taquaritinga --
   ---------------------------------------------

   Exemplo - Semáforo Simples com Arduino

   Descrição:
      - Programação que ilustra o funcionamento de um semáforo em Arduino.
      - Referência: https://www.makerhero.com/blog/como-criar-um-semaforo-com-arduino/.

*/

// Definições iniciais dos componentes utilizados
#define USE_SERIAL Serial

// Declaração de variáveis
int led_vermelho = 10;
int led_amarelo = 9;
int led_verde = 8;


//------- Bloco das Configurações Iniciais --------
void setup() {

  // Inicializa e limpa serial
  USE_SERIAL.begin(9600);
  USE_SERIAL.flush();

  // Configura quais portas do Arduino vamos usar
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);

 
  // Inicializando com todos desligados
  Serial.println(" ");
  Serial.println("Inicializando com os LEDs desligados...");
  Serial.println(" ");
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_verde, LOW);
  delay(5000);

}


//-------- Função do Semáforo --------
void semaforo() {

  Serial.println("-------------------------------");
  Serial.println("*** Novo ciclo do Semáforo! ***");

  // Inicia o semáforo com amarelo ligado
  Serial.println("Amarelo... ");
  digitalWrite(led_amarelo, HIGH);
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_verde, LOW);
 
   // esperamos 5s com o sinal no amarelo
  delay(5000);
 
  // apagamos o amarelo e ligamos o vermelho, verde já está desligado
  Serial.println("Vermelho... ");
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, HIGH);
 
  // esperamos 5s com o sinal fechado
  delay(5000);  
 
  // apagamos o vermelho e ligamos o verde, amarelo já está desligado
  Serial.println("Verde... ");
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_verde, HIGH);
 
  // esperamos 5s com o sinal aberto
  delay(5000);

  // apagamos o verde para reiniciar a lógica, amarelo e vermelho já desligados
  digitalWrite(led_verde, LOW);

}




//------ Bloco Principal ------
void loop() {

  semaforo();

}
 

