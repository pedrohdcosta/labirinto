#include <SharpIR.h>

#define QTR1 A0
#define QTR2 A1

#define INFRA A2
#define GTX 1080 

#define PININ1 2
#define PININ2 4
#define PININ3 5
#define PININ4 7
#define PINENA 3
#define PINENB 6

#define TRESHOLD


SharpIR SharpIR(INFRA,GTX);


void setup() {
  Serial.begin(9600);
}

void loop() {
  //mostrarDistancia();
  int distancia = SharpIR.distance();

  Serial.print("a distancia e: ");
  Serial.println(distancia);
  delay(500);
  
}

void controleMotor(int motorL, int motorR){
  pinMode(PININ1, OUTPUT);
  pinMode(PININ2, OUTPUT);
  pinMode(PININ3, OUTPUT);
  pinMode(PININ4, OUTPUT);
  pinMode(PINENA, OUTPUT);
  pinMode(PINENB, OUTPUT);

  if(motorL < 0){
  motorL = -motorL;
  digitalWrite(PININ1, LOW);
  digitalWrite(PININ2, HIGH);
  }
  else{
    digitalWrite(PININ1, HIGH);
    digitalWrite(PININ2, LOW);
  }

  if(motorR < 0){
    motorR = -motorR;
    digitalWrite(PININ3, HIGH);
    digitalWrite(PININ4, LOW);
  }
  else{
    digitalWrite(PININ3, LOW);
    digitalWrite(PININ4, HIGH);
  }
  analogWrite(PINENA, motorL);
  analogWrite(PINENB, motorL);
}



void opcaoMotor(char opcao, int motorL, int motorR){

  switch(opcao){

    case '8': 
      controleMotor(motorL,motorR);
      break;

    case '2':
      controleMotor(-motorL,-motorR);
      break;

    case '4':
      controleMotor(-motorL,motorR);
      break;

    case '6':
      controleMotor(motorL,-motorR);
      break;
      
    case '0':
      controleMotor(0,0);
      break;
  }
}

void mostrarDistancia(){
  int distancia = SharpIR.distance();

  Serial.print("a distancia e: ");
  Serial.println(distancia);
  delay(500);
}
