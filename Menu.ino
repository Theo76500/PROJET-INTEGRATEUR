#include <Grove_I2C_Motor_Driver.h>
#include "Code_Direction.h"
#include "PathFinding.h"
#include <SharpIR.h>

SharpIR sensor(SharpIR::GP2Y0A21YK0F, A1);

int dis = 0;
int dis2 = 0;
String distance;
boolean check = false;

int left =  2;
int middleL = 3;
int middleR = 8;
int right = 6;

// param = 0 ===> Free
// param = 1 ===> Path Finding
// param = 2 ===> You decide the directions (l for "left" or r for "right" or n for "nothing")
int param = 1;


void setup() {

  Motor.begin(I2C_ADDRESS);
  pinMode(left, INPUT);
  pinMode(middleL, INPUT);               
  pinMode(middleR, INPUT);
  pinMode(right, INPUT);
  
  Serial.begin(9600);

  String start = "AB";
  setStartFree(start);

  char choices[TAILLE_TAB] = {'N', 'N', 'L', 'N', 'L', 'N', 'L', 'N', 'N', 'N'};
  setTabOfChoices(choices);
  
  Path = pathFinding("O", "P");
  Serial.println("Voici le Path : " +Path);  
}

void loop() {
  //LifeCycleChoice(param);
  //Serial.println(getPoint2());
  //parkCar();
  //int coords = setCoords('A');
  //Serial.println(getPoint(coords));

  if(check == false){
  
    up(-40);
    dis = sensor.getDistance();
    distance = String(dis);
    distance = "Distance: "+distance+"cm";
    Serial.println(check);
  
    if(dis2 > 25 && dis < 20){
      parkCar();
      Serial.println("Je me gare !");
      check = true;
      }
    
    Serial.println(distance);
    dis2 = dis;
    delay(250);
}

}
