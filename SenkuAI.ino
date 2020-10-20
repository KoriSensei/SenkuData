
#include <L298N.h>
L298N Senku(3,5,9,10,12,13);

#include <NewPing.h>
NewPing sonar_L(6,7,50);  // trigger 6 y echo al pin 7, distancia máxima limitada a 50cm
NewPing sonar_R(3,4,50); // trigger 3 y echo al pin 4, distancia máxima limitada a 50cm

void setup() {}

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
