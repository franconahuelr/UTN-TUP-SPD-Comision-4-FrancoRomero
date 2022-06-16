// C++ code
//
int Led_Pin = 3;
int Led_PinB = 2;
int Fot_Pin = A0;
int sensorValue = 0;
int outputValue = 0;
void setup()
{
Serial.begin(9600);
pinMode(Led_Pin, OUTPUT);
  pinMode(Led_PinB, OUTPUT);
}
void loop()
{
 digitalWrite(Led_Pin, HIGH);
 digitalWrite(Led_PinB, LOW);
 sensorValue = analogRead(Fot_Pin);
 outputValue = map(sensorValue, 0, 1023, 0, 255);
 analogWrite(Led_Pin, outputValue);
 analogWrite(Led_PinB, outputValue);
 Serial.print("Lectura: ");
 Serial.println(sensorValue);
 Serial.print("Mapeado: ");
 Serial.println(outputValue);
 delay(400);
 digitalWrite(Led_Pin, LOW);
 digitalWrite(Led_PinB, HIGH);
 delay(400);
}