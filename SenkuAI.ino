
#include <L298N.h>
int ENA = 10;  // ENA conectada al pin 10 / SIN EL JUMPER EN ENA
int ENB = 11;  // ENB conectada al pin 11 / SIN EL JUMPER EN ENB
int MO1 = 13;  // Input4 conectada al pin 13
int MO2 = 7;  // Input3 conectada al pin 7
int MO3 = 8;  // Input4 conectada al pin 8
int MO4= 12;  // Input3 conectada al pin 12
L298N Senku(MO1,MO2,MO3,MO4,ENA,ENB)    //Pines descritos de izquierda a derecha en el L298N excluyendo ENA

#include <NewPing.h> // Codigo No Operativo Bajo Revisión
NewPing sonar_L(6,7,50);  // trigger 6 y echo al pin 7, distancia máxima limitada a 50cm 
NewPing sonar_R(3,4,50); // trigger 3 y echo al pin 4, distancia máxima limitada a 50cm

void setup() {
pinMode(ENA, OUTPUT);  // ENA                                                    
pinMode(ENB, OUTPUT);  // ENB
pinMode(MO1, OUTPUT);  // Input13
pinMode(MO2, OUTPUT);  // Input7
pinMode(MO3, OUTPUT);  // Input8
pinMode(MO4, OUTPUT);  // Input12
digitalWrite(ENA,HIGH);  // ALTO habilita la salida A / SIN EL JUMPER EN ENA
digitalWrite(ENB,HIGH);  // ALTO habilita la salida B / SIN EL JUMPER EN ENB
}

void loop()
{
  
// lee los sensores HC-SR04

  delay(30);  // necesario para que el sensor espere el eco del pulso
  float dist_L = sonar_L.ping_cm();
  if (dist_L==0) {dist_L=50;}  // corrige las distancias mayores de 50cm que dan lectura 
  
  delay(30);
  float dist_R = sonar_R.ping_cm();
  if (dist_R==0) {dist_R=50;}
  
  float dist=min(dist_L,dist_R);

// gira para evitar obstaculos
  if (dist<20)
  {
    if (dist_L>dist_R) Senku.rotate(128,250);
    else Senku.rotate(128,-250);
  }
  else Senku.forward(40,40,1000);
  
}
