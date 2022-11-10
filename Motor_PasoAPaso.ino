#include <Stepper.h>
#define STEPS 100
Stepper stepper(2048, 8, 9, 10, 11);

int previous = 0;
const int pinon = 2;
const int pinoff = 3;
const int pinled = 13;
int estaon = HIGH;
int estaoff = LOW;
bool MotorEstado = false;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(3);
  // CONFIGURAR PINES COMO ENTRADAS
  pinMode(pinon, INPUT);
  pinMode(pinoff, INPUT);
  // CONFIGURAR PIN DE LED COMO SALIDA
  pinMode(pinled, OUTPUT);
}

void loop() {
   // LEER EL ESTADO DE PINES DE BOTON A VARIABLES
  estaon = digitalRead(pinon);
  estaoff = digitalRead(pinoff);
 
  // SE OPRIMIO EL BOTON DE ENCENDIDO?
  if (estaon == LOW) {
    digitalWrite(pinled, HIGH);
    MotorEstado = true;
  }
 
  // SE OPRIMIO EL BOTON DE APAGADO?
  if (estaoff == LOW) {
    digitalWrite(pinled, LOW);
    MotorEstado=false;
  }
  
  if(MotorEstado ==true){
    stepper.step(10);
    }
}
