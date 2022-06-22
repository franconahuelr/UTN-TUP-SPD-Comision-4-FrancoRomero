//Agregar libreria Ultrasonic para su funcionamiento

#include <Ultrasonic.h>
#define LED 11
#define TRIM 9
#define ECHO 10

Ultrasonic ultrasonic(TRIM,ECHO);

void setup(){

pinMode(LED,OUTPUT);
Serial.begin(9600);
}

void loop(){
  
  float distance=ultrasonic.Ranging(CM); //obtencion de distancia en CM

  if(distance < 21.0){

digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }

Serial.println("La distancia es =");
Serial.println(distance);
Serial.println("cm");
delay(150);
}
