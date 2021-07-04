// C++ code
//
#include <Servo.h>

int servo = 0;
int contador = 0;
Servo barrera;

int entrada = 0;
int salida = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
void setup()
{
  Serial.begin(9600);
  barrera.attach(7);

}

void loop()
{
  Serial.println(contador);
  entrada = 0.01723 * readUltrasonicDistance(5, 6);
  salida  = 0.01723 * readUltrasonicDistance(10, 11);

  if (contador > 0 && contador < 5) {
    barrera.write(90);
    delay(10);
  }
  if (contador < 0 || contador > 5) {
   // barrera.write(0);
    Serial.println("No se permiten más personas");
    Serial.println(contador);

  }
  if (entrada < 50) {
    if (contador >= 5) {
  barrera.write(0); 

    }
    else {
      contador++;
      delay(1000);
    }
  }
  if (salida<50) {
    if (contador <= 0) {
      Serial.println("No hay nadie en el local");
    }
    else {
      contador--;
      delay(1000);
    }
  }
}
