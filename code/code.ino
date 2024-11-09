#include <ESP32Servo.h>

const int trig = 27;
const int echo = 26;
#define led 2

#define servopin 12
Servo myservo;

#define SOUND_SPEED 0.034

long duration;
float distanceCm;
void setup() {
  Serial.begin(9600); 
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  myservo.attach(servopin);
  // digitalWrite(led, LOW);
}

void loop() {
  distance();
  if(distanceCm<=10){
    digitalWrite(led, HIGH);
    myservo.write(180);
  }
  else{
    digitalWrite(led, LOW);
    myservo.write(0);
  }
}

void distance(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  //Perhitungan Jarak
  distanceCm = duration * SOUND_SPEED/2;
  //Menampilkan data
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  delay(1000);
}
