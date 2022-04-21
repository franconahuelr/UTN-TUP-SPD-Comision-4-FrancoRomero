// Clase Arduino 1
//

int led_pin1 = 13;
int led_pin2 = 12;

void setup()
{
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
}

void loop()
{
  digitalWrite(led_pin1, HIGH);
  digitalWrite(led_pin2, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(led_pin1, LOW);
  digitalWrite(led_pin2, LOW);
  delay(2000); // Wait for 1000 millisecond(s)
}
