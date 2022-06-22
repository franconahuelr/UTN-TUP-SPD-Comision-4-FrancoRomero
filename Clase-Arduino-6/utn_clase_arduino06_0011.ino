const int sensor = 0; // entrada del sensor 
const int ledVerde = 3; // pin del LED rojo
const int ledRojo = 5; // pin del LED azul

long miliVolts;
long temperatura;
int brillo;

long calctemp(int datosSensor){
  /*Calculamos los mV en la entrada*/
  miliVolts = (analogRead(datosSensor) * 5000L) / 1023; 
  /* Calculamos la temperatura*/
  temperatura = miliVolts / 10;
  /*Regresamos el valor de temperatura*/
  return temperatura;
}

void setup () {
  Serial.begin(9600); // iniciamos la comunicacion serial
  /*Declaramos los LEDs como salida*/
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop () {
  /*Llamamos a la función para calcular temperatura
   y guardamos el valor*/
  temperatura = calctemp(sensor);

  /*Ajustamos la escala de temperatura para poder usar analoWrite*/
  brillo = map(temperatura, 10, 40, 0, 255);
  /*Restringimos el rango de brillo entre 0 y 255*/
  brillo = constrain(brillo, 0, 255);

  /*Ajustamos el color de los LED*/
  analogWrite(ledVerde, brillo);
  analogWrite(ledRojo, 250-brillo);

  /*Mandamos el valor de la temperatura al monitor serial
   y agregamos un delay para no saturar el monitor*/
  Serial.print("Temperatura: "); 
  Serial.print(temperatura);
  Serial.println("grados");
  delay(200);
}