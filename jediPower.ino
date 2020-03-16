
//criando variáveis dos leds
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;

//criando variáveis constantes 
const int trigPin = 3;
const int echoPin = 2;
int dist = 0;

//iniciando variáveis
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

//criação de uma função para medir a distância
int mede() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned long duracao = pulseIn(echoPin, HIGH);
  int distancia = duracao / 58;
  Serial.print("Calculado cm: ");
  Serial.println(distancia);
  return distancia;
}

// processo de análise da distância
void loop(){
  dist = mede(); //variavel 'dist' para recebe a medição dos valores da função
  Serial.print("Distancia = ");
  Serial.print(dist);
  
  if (dist <= 50 && dist >= 41){ // caso a distância seja longa entre menor ou igual a 50 e maior ou igual a 41
    digitalWrite(led1,LOW); // os 4 primeiro leds ficam acesso em nível baixo e somente o 5º alto
    digitalWrite(led2,LOW); // ou seja sua mão (ou que você aproxima do sensor) ainda esta 'longe' e não tem força para ascender mais leds
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,HIGH);
  } else if(dist <=40 && dist >=31){// caso a distância seja pouco longa entre menor ou igual a 40 e maior ou igual a 31
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH); 
  } else if(dist <=30 && dist >=21){// caso a distância seja média entre menor ou igual a 30 e maior ou igual a 21
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH); 
  } else if(dist <=20 && dist >=11){ // caso a distância seja curta entre menor ou igual a 20 e maior ou igual a 11
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH); 
  } 
  else if(dist <=10){ // caso a distância seja muito próxima, menor ou igual 10
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH); 
  } 
else {
   digitalWrite(led1,LOW);// caso a distância seja grande ao ponto de não identificar nada. 
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
   digitalWrite(led4,LOW);
   digitalWrite(led5,LOW);  
}
}
