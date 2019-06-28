#include <Grove_I2C_Motor_Driver.h>
#include "Code_Direction.h"
#include "PathFinding.h"

uint8_t left =  2;
uint8_t middleL = 8;
uint8_t middleR = 3;
uint8_t right = 6;

unsigned long debut = millis();

// param = 0 ===> Free
// param = 1 ===> Path Finding
// param = 2 ===> You decide the directions (l for "left" or r for "right" or n for "nothing")
uint8_t param = 0;


void setup() {
  
  Motor.begin(I2C_ADDRESS);
  pinMode(left, INPUT);
  pinMode(middleL, INPUT);               
  pinMode(middleR, INPUT);
  pinMode(right, INPUT);
  
  Serial.begin(9600);
 
  if(param == 2){
    char choices[TAILLE_TAB] = {'N', 'L', 'N', 'N', 'L', 'N', 'L', 'N', 'L', 'L', 'N', 'R', 'L', 'R', 'R', 'N', 'R', 'N', 'L'};
    setTabOfChoices(choices); 
    }
    
  else if(param == 1){ 
    Path = pathFinding('A', 'P');
    
  }

Serial.println("Voici le Path : " +Path);

pathIndex = Path.length();

startLetter = Path[0];

lastLetter = Path[pathIndex-1];

 
}

void loop() {
  LifeCycleChoice(param);
}
