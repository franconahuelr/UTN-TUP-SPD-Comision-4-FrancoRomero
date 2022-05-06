// Código Ejemplo
int buttonState = 0;
void setup()
{
// Configurar Pin como Entrada
pinMode(2, INPUT);
// Configurar Pines como Salida
pinMode(6, OUTPUT);
pinMode(13, OUTPUT);
}
void loop()
{
// Leer Estado del Puerto de Entrada 2
  buttonState = digitalRead(2);
// Actual Segun el Estado de la Lectura
if (buttonState == HIGH){
// Apagar Led en Puerto 6
    digitalWrite(6, LOW);
    // Encender Led en Puerto 13
    digitalWrite(13, LOW);
    // Esperar 1 Segundo
    delay(500);
    // Encender Led en Puerto 6
    digitalWrite(6, HIGH);
    // Apagar Led en Puerto 13
    digitalWrite(13, HIGH);
    // Esperar 1 Segundo
    delay(500);
  } else {
// Apagar Leds en Puertos 6 y 13
    digitalWrite(6, LOW);
    digitalWrite(13, LOW);
  }
}