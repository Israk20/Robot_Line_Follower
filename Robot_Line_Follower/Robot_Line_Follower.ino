#include <Wire.h>

//Sensor Kiri
const int IN_A0 = A0;
const int IN_D0 = 3;

//Sensor Kanan
const int IN_A1 = A1;
const int IN_D1 = 2;

//Dinamo Kiri
#define IN1 8
#define IN2 7  

//Dinamo Kanan
#define IN3 6 
#define IN4 5 

//Kecepatan Kanan
#define ENA 9 

//Kecepatan Kiri
#define ENB 4  

int value_A0;
bool value_D0;
int value_A1;
bool value_D1;

void setup() {
  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
  pinMode (IN_A1, INPUT);
  pinMode (IN_D1, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  value_A0 = analogRead(IN_A0);
  value_D0 = digitalRead(IN_D0);
  value_A1 = analogRead(IN_A1);
  value_D1 = digitalRead(IN_D1);
  Serial.print("A0: ");
  Serial.println(value_A0);
  Serial.print("D0: ");
  Serial.println(value_D0);
  Serial.print("A1: ");
  Serial.println(value_A1);
  Serial.print("D1: ");
  Serial.println(value_D1);
  if (value_D0 == 1 and value_D1 == 1){
    Serial.println("Lurus");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(ENA, 255); //255 = 100% {Kecepatan}
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(ENB, 255); 
    delay(1000); 
  }

  else if(value_D0 == 1 and value_D1 == 0){
    Serial.println("Kanan");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(ENA, 255); //255 = 100% {Kecepatan}
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(ENB, 255); 
    delay(1000); 
  }
  else if(value_D0 == 0 and value_D1 == 1){
    Serial.println("Kiri");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(ENA, 255); //255 = 100% {Kecepatan}
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(ENB, 255); 
    delay(1000); 
  }
  else{
    Serial.println("Berhenti");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(ENA, 255); //255 = 100% {Kecepatan}
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    digitalWrite(ENB, 255); 
    delay(1000); 
  }
  delay(500);
}