#include <IRremote.h>

int RECV_PIN = 11; 
int led1 = 2;
int led2 = 4;
int led3 = 7;
int itsONled[] = {0,0,0,0};

#define code1 18615 // code received from button no. 1
#define code2 34935 // code received from button no. 2
#define code3 2295 // code received from button no. 3

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
Serial.begin(9600); // 
irrecv.enableIRIn();
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
}

void loop() {
if (irrecv.decode(&results)) {
unsigned int value = results.value;
switch(value) {
case code1:
if(itsONled[1] == 1) { 
digitalWrite(led1, LOW);
itsONled[1] = 0;
} else { 
digitalWrite(led1, HIGH);
}
break;
case code2:
if(itsONled[2] == 1) {
digitalWrite(led2, LOW);
itsONled[2] = 0;
} else {
digitalWrite(led2, HIGH);
itsONled[2] = 1;
}
break;
case code3:
if(itsONled[3] == 1) {
digitalWrite(led3, LOW);
itsONled[3] = 0;
} else {
digitalWrite(led3, HIGH);
itsONled[3] = 1;
}
break;
}
Serial.println(value);
irrecv.resume();
}