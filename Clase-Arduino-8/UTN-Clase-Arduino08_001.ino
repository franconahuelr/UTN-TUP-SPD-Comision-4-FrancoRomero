// incluir librería del LCD:
#include <LiquidCrystal.h>

// inicializar la librería con los números de los pines de interfaz
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // configurar el número de columnas y filas de la pantalla LCD:
  lcd.begin(16, 2);
 
  // Imprimir un mensaje en la pantalla LCD.
  lcd.print("Hola mundo!");
}

void loop() {
  // coloca el cursor en la columna 0, línea 1
  // (nota: la línea 1 es la segunda fila, ya que el conteo comienza con 0):
  lcd.setCursor(0, 1);
  // imprimir cantidad de segundos:
  lcd.print(millis() / 1000);
}