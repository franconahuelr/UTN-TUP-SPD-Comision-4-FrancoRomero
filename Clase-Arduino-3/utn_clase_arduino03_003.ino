int Led_Pin = 3;
int Pot_Pin = A0;
int Int_Pin = 2;
int sensorValue = 0;
int outputValue = 0;
int inputValue = 0;
void setup()
{
pinMode(Led_Pin, OUTPUT);
pinMode(Int_Pin, INPUT);

}
void loop()
{
inputValue = digitalRead(Int_Pin);
if (inputValue == HIGH)
{
for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
analogWrite(Led_Pin, fadeValue);
delay(60);
}
for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
analogWrite(Led_Pin, fadeValue);
delay(60);
}
}
else
{
sensorValue = analogRead(Pot_Pin);
outputValue = map(sensorValue, 0, 1023, 0, 255);
analogWrite(Led_Pin, outputValue);
}
}