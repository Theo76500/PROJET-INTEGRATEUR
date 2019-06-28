  #include <Grove_I2C_Motor_Driver.h>
#include "Code_Direction.h"
#include "VecteursDeplacements.h"
#include "radio.h"
#include "tourSeconde.h"

uint8_t compteur2 = 0;
uint8_t nbTurn = 0;
boolean turn = false;
String nextMove = "";
String PathTemp; 

char tabOfChoices[TAILLE_TAB];
boolean turnLeft = false;
boolean turnRight = false;

//=========================================================================================================================|LIFE CYCLE CHOICE|========================================================================================================================== 

void LifeCycleChoice(uint8_t choice){
  if(choice == 1){
    LifeCyclePathFinding();
    }

  else if(choice == 2){
    LifeCycleDecided();
    }
    
  else{
    LifeCycleFree();
    }
}

  
//===========================================================================================================================|LIFE CYCLES|===============================================================================================================================

void LifeCyclePathFinding(){
  moveTo();
  }

void LifeCycleFree(){
  
  up(-50);
 checkCollisions();
  if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right) && turn == false) {
    checkCollisions();
    up(-38);
    checkCollisions();
  }
  
  if(1 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 1 == digitalRead(right) && turn == false) {
    //checkCollisions();
    int hasard = random(0,1);
    //checkCollisions();
    if (hasard == 0) {
      //checkCollisions();
      rightIntersectionPF();
      checkCollisions();
    }
    else {
      //checkCollisions();
      leftIntersectionPF();
      checkCollisions();
    }
   checkCollisions();
  }
  checkCollisions();
  
  if(1 == digitalRead(left) && 1 == digitalRead(middleL)) {
    //checkCollisions();
    leftIntersectionPF();
  }
  
  if(1 == digitalRead(right) && 1 == digitalRead(middleR)) {
    //checkCollisions();
    rightIntersectionPF();
  }
  //checkCollisions();


  
}

void LifeCycleDecided(){

  while(tabOfChoices[0] != NULL){
    checkCollisions();
    int i = 0;
    checkCollisions();
    upBeforeAll();
    checkCollisions();
    
    if(tabOfChoices[i] != NULL && tabOfChoices[i] == 'L' && (digitalRead(left) == 1 && digitalRead(middleL) == 1)){
      checkCollisions();
      leftIntersectionD();
      checkCollisions();
      
      nbTurn++;
      checkCollisions();
      changeTabOfChoices(TAILLE_TAB - nbTurn + 1);
      checkCollisions();
      upBeforeAll();
      checkCollisions();
      }
      
    checkCollisions();
    
    if(tabOfChoices[i] != NULL && tabOfChoices[i] == 'R' && (digitalRead(right) == 1 && digitalRead(middleR) == 1)){
      checkCollisions();
      rightIntersectionD();
      checkCollisions();
      
      nbTurn++;
      checkCollisions();
      changeTabOfChoices(TAILLE_TAB - nbTurn + 1);
      checkCollisions();
      upBeforeAll();
      checkCollisions();
      }
      
    checkCollisions();
    
    if(tabOfChoices[i] != NULL && tabOfChoices[i] == 'N'){
      checkCollisions();
      //up(-50);
      delay(30);
      checkCollisions();
      
      nbTurn++;
      checkCollisions();
      changeTabOfChoices(TAILLE_TAB - nbTurn + 1);
      checkCollisions();
      upBeforeAll();
      checkCollisions();
      }
    
    checkCollisions();
      }
      stopCar();
    }

//============================================================================================================================|DIRECTIONS|===============================================================================================================================

void Left(int speed) {
  Motor.speed(MOTOR1, 50);
  Motor.speed(MOTOR2, speed);
}

void Right(int speed) {
  Motor.speed(MOTOR2, 50);
  Motor.speed(MOTOR1, speed);
}

void up(int speed) {
  Motor.speed(MOTOR1, speed);
  Motor.speed(MOTOR2, speed);
  radio();
}

void stopCar() {
  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
}

void pause(int time) {
  Motor.speed(MOTOR1, 0);
  Motor.speed(MOTOR2, 0);
  delay(time);
}

void bigLeft() {
  Left(-100);
}

void bigRight() {
  Right(-100);
}

void checkCollisions(){
  
   if(1 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 0 == digitalRead(right)) {
    Left(-100);
    }

   if(0 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 1 == digitalRead(right)) {
    Right(-100);
    }

   if(1 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right)) {
    Right(-100);
    }

   if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 1 == digitalRead(right)) {
    Left(-100);
    }
    
   if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 1 == digitalRead(middleR) && 0 == digitalRead(right)) {
    Right(-100);
    }

   if(0 == digitalRead(left) && 1 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right)) {
    Left(-100);
    }

    delay(5);
}



//============================================================================================================================|VECTEURS|=================================================================================================================================



//=======================================================================================================================================================================================================================================================================


void nextVector(){
  if(Path.substring(2, 4) == NULL){
   nextMove = "";
    }

  else{
   nextMove = Path.substring(2, 4);
    }
  }


void upBeforeLeftTurn(){
  while(digitalRead(left) == 0 || digitalRead(middleL) == 0) {
    checkCollisions();
    up(-38);
    checkCollisions();
    }
  }
  
void upBeforeRightTurn(){
    while(digitalRead(right) == 0 || digitalRead(middleR) == 0) {
      checkCollisions();
      up(-38);
      checkCollisions();
      }
  }
  
void upBeforeIntersection(){
  while(digitalRead(left) == 0 || digitalRead(middleL) == 0 || digitalRead(right) == 0 || digitalRead(middleR) == 0) {
      checkCollisions();
      up(-38);
      checkCollisions();
      }
  }

void upBeforeAll(){
  while((digitalRead(left) == 0 || digitalRead(middleL) == 0 || digitalRead(right) == 0 || digitalRead(middleR) == 0) && (digitalRead(left) == 0 || digitalRead(middleL) == 0) && (digitalRead(right) == 0 || digitalRead(middleR) == 0)) {
    checkCollisions();
    up(-38);
    checkCollisions();
    }
  }

void leftTurnPF(){
  while(digitalRead(middleR) == 0){
    bigLeft();
    }

  //while(digitalRead(left) == 1 || digitalRead(middleL) == 1 || digitalRead(middleR) == 1 || digitalRead(right) == 1){
    bigRight();
 // }
 delay(100);
}
  
void rightTurnPF(){
  while(digitalRead(middleL) == 0){
   bigRight();
    }

  //while(digitalRead(left) == 1 || digitalRead(middleL) == 1 || digitalRead(middleR) == 1 || digitalRead(right) == 1){
    bigLeft();
  //}
  delay(100);
}

void leftIntersectionPF(){
  bigLeft();
  delay(450);
   while(digitalRead(middleR) == 0){
    bigLeft();
    }
    bigRight();
    delay(125);
}
  
void rightIntersectionPF(){
  bigRight();
  delay(450);
  while(digitalRead(middleL) == 0){
   bigRight();
    }
    bigLeft();
    delay(125);
}

void leftIntersectionD(){
  /*delay(65);
  compteur2 = 0;
  while(compteur2 < 32){
    bigLeft();
    compteur2++;
   }*/

   while(digitalRead(middleR) == 0){
    bigLeft();
    }
    bigRight();
    delay(50);
}
  
void rightIntersectionD(){
  /*delay(65);
  compteur2 = 0;
  while(compteur2 < 40){
    bigRight();
    compteur2++;
  }*/

  while(digitalRead(middleL) == 0){
    bigRight();
    }
    bigLeft();
    delay(50);
}

void changePath(){
  PathTemp = Path.substring(2, Path.length());
  Path = PathTemp;
  }

void setTabOfChoices(char choices[]){

  for(int i = 0; i < TAILLE_TAB; i++){
    tabOfChoices[i] = choices[i];
    }
  }

void changeTabOfChoices(uint8_t newTailleTab){

  if(newTailleTab == 0){
    tabOfChoices[0] = NULL;
    }

  else{
    for(int i = 1; i < newTailleTab; i++){
      tabOfChoices[i - 1] = tabOfChoices[i];
      }
  }
}
