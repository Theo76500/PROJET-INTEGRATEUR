#include <Grove_I2C_Motor_Driver.h>
#include "Code_Direction.h"
#include "VecteursDeplacements.h"

int hasard = 2;
int direction = 2;
int limitValue = 0;
int compteur = 0;
int compteur2 = 0;
int nbTurn = 0;
int nbPoint;
boolean turn = false;
boolean parked = false;
String nextMove = "";
String PathTemp; 
char tabOfChoices[TAILLE_TAB];
char startPoint;
char test = 's';
boolean turnRight = false;
boolean turnLeft = false;

//=========================================================================================================================|LIFE CYCLE CHOICE|========================================================================================================================== 

void LifeCycleChoice(int choice){
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

    while(Path != NULL){
  
      moveToAB();
      moveToAD();
      moveToAF();
  
      moveToBA();
      moveToBC();
  
      moveToCB();
      moveToCD();
      moveToCK();
      
      moveToDA();
      moveToDC();
      moveToDE();
  
      moveToEF();
      moveToED();
   
      moveToFA();
      moveToFE();
      moveToFG();
      
      moveToGF();
      moveToGH();
      moveToGJ();
  
      moveToHG();
      moveToHI();
  
      moveToIH();
      moveToIJ();
      moveToIP();
  
      moveToJG();
      moveToJI();
      moveToJK();
      moveToJL();
  
      moveToKC();
      moveToKN();
      moveToKJ();
  
      moveToLJ();
      moveToLM();
  
      moveToML();
      moveToMO();
  
      moveToNK();
      moveToNO();
  
      moveToOM();
      moveToON();
      moveToOP();
  
      moveToPI();
      moveToPO();
    }
  
  stopCar();
  Serial.println("Voici le Path final : " +Path);
  }

void LifeCycleFree(){
  
  up(-50);
  checkCollisions();
  if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right)) {
    checkCollisions();
    up(-50);
    checkCollisions();
    turnRight = false;
    turnLeft = false;
  }
  
  if(1 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 1 == digitalRead(right)) {
    int hasard = random(0,1);
    if (hasard == 0) {
      rightIntersectionPF();
      checkCollisions();
    }
    else {
      leftIntersectionPF();
      checkCollisions();
    }
   checkCollisions();
  }
  checkCollisions();
  
  if(1 == digitalRead(left) && 1 == digitalRead(middleL)) {
    leftIntersectionPF();
    checkCollisions();
  }
  
  if(1 == digitalRead(right) && 1 == digitalRead(middleR)) {
    rightIntersectionPF();
    checkCollisions();
  }
  checkCollisions();
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
  turn = true;
  direction = 1;
  limitValue = limitedValue();
}

void bigRight() {
  Right(-100);
  turn = true;
  direction = 0;
  limitValue = limitedValue();
}

int limitedValue() {
  int hasard = random(0,1);
  if (hasard == 0) {
    return 50;
  }
  else {
    return 0;
  }
}

void checkCollisions(){
  
   if(1 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 0 == digitalRead(right)) {
    Left(-50);
    }

   if(0 == digitalRead(left) && 1 == digitalRead(middleL) && 1 == digitalRead(middleR) && 1 == digitalRead(right)) {
    Right(-50);
    }

   if(1 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right)) {
    Right(-50);
    }

   if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 0 == digitalRead(middleR) && 1 == digitalRead(right)) {
    Left(-50);
    }
    
   if(0 == digitalRead(left) && 0 == digitalRead(middleL) && 1 == digitalRead(middleR) && 0 == digitalRead(right)) {
    Right(-50);
    }

   if(0 == digitalRead(left) && 1 == digitalRead(middleL) && 0 == digitalRead(middleR) && 0 == digitalRead(right)) {
    Left(-50);
    }
}



//============================================================================================================================|VECTEURS|=================================================================================================================================


void moveToAB(){
  if(Path.substring(0, 2) == "AB"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();
    test = 'B';
    nextVector();
    
    if(nextMove != NULL){
      leftIntersectionPF();
    }
    
    changePath();
  }
}

void moveToAD(){
  if(Path.substring(0, 2) == "AD"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "DE"){
      leftIntersectionPF();
      }

    else if(nextMove == "DC"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToAF(){
  if(Path.substring(0, 2) == "AF"){
    checkCollisions();
    up(-50);
    checkCollisions();
    
    upBeforeRightTurn();
    nextVector();
      
    if(nextMove == "FE"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToBA(){
  if(Path.substring(0, 2) == "BA"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "AD"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToBC(){
  if(Path.substring(0, 2) == "BC"){
    checkCollisions();
    up(-50);
    checkCollisions();
    
    upBeforeLeftTurn();
    checkCollisions();
    
    nextVector();
    checkCollisions();

  if(nextMove == "CD"){
    leftIntersectionPF();
  }
  checkCollisions();

  changePath();
  }
}

void moveToCB(){
  if(Path.substring(0, 2) == "CB"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove != NULL){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToCD(){
  if(Path.substring(0, 2) == "CD"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove == "DA"){
      leftIntersectionPF();
      }
    
    changePath();
  }
}

void moveToCK(){
  if(Path.substring(0, 2) == "CK"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();
    
    nextVector();

    if(nextMove == "KJ"){
      leftIntersectionPF();
      }
    
    checkCollisions();
    changePath();
  }
}

void moveToDA(){
  if(Path.substring(0, 2) == "DA"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "AB"){
      leftIntersectionPF();
      }

    else if(nextMove == "AF"){
      rightIntersectionPF();
      }
    
    changePath();
  }
  }

void moveToDC(){
  if(Path.substring(0, 2) == "DC"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "CK"){
      leftIntersectionPF();
      }

    else if(nextMove == "CB"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToDE(){
  if(Path.substring(0, 2) == "DE"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove != NULL){
      leftIntersectionPF();
      }
    
    changePath();
  }
}

void moveToEF(){
  if(Path.substring(0, 2) == "EF"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "FA"){
      leftIntersectionPF();
      }

    else if(nextMove == "FG"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToED(){
  if(Path.substring(0, 2) == "ED"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "DA"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToFA(){
  if(Path.substring(0, 2) == "FA"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove == "AD"){
      leftIntersectionPF();
      }
    
    changePath();
  }
}

void moveToFE(){
  if(Path.substring(0, 2) == "FE"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove != NULL){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToFG(){
  if(Path.substring(0, 2) == "FG"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();
    Serial.println("Je suis en FG");
    nextVector();
      
    if(nextMove == "GJ"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToGF(){
  if(Path.substring(0, 2) == "GF"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove == "FE"){
      leftIntersectionPF();
      }
      
    changePath();
  }
}

void moveToGH(){
  if(Path.substring(0, 2) == "GH"){
    checkCollisions();
    up(-50);
    checkCollisions();
    
    upBeforeRightTurn();
    nextVector();
      
    if(nextMove == "HI"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToGJ(){
  if(Path.substring(0, 2) == "GJ"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();
    Serial.println("Je suis en GJ");
    nextVector();
    
    if(nextMove == "JI"){
      leftIntersectionPF();
      }

    else if(nextMove == "JK"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToHG(){
  if(Path.substring(0, 2) == "HG"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove == "GJ"){
      leftIntersectionPF();
      }
    
    changePath();
  }
}

void moveToHI(){
  if(Path.substring(0, 2) == "HI"){
    checkCollisions();
    up(-50);
    checkCollisions();
    
    upBeforeRightTurn();
    nextVector();
      
    if(nextMove == "IJ"){
      rightIntersectionPF();
      }

  changePath();
  }
}

void moveToIH(){
  if(Path.substring(0, 2) == "IH"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove == "HG"){
      leftIntersectionPF();
      }
    
    changePath();
  }
}

void moveToIJ(){
  if(Path.substring(0, 2) == "IJ"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "JL"){
      leftIntersectionPF();
      }

    else if(nextMove == "JG"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToIP(){
  if(Path.substring(0, 2) == "IP"){
    checkCollisions();
    up(-50);
    checkCollisions();
    
    upBeforeRightTurn();
    nextVector();
      
    if(nextMove != NULL){
      rightIntersectionPF();
     }
    
    changePath();
  }
}

void moveToJG(){
  if(Path.substring(0, 2) == "JG"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "GF"){
      leftIntersectionPF();
      }

    else if(nextMove == "GH"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToJI(){
  if(Path.substring(0, 2) == "JI"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "IH"){
      leftIntersectionPF();
      }

    else if(nextMove == "IP"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToJK(){
  if(Path.substring(0, 2) == "JK"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "KN"){
      leftIntersectionPF();
      }

    else if(nextMove == "KC"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToJL(){
  if(Path.substring(0, 2) == "JL"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();
    Serial.println("Je suis en JL");
    nextVector();
    
    if(nextMove == "LM"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToKC(){
  if(Path.substring(0, 2) == "KC"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "CD"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToKN(){
  if(Path.substring(0, 2) == "KN"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();
    
    nextVector();
    
    if(nextMove != NULL){
      leftIntersectionPF();
    }
    
    checkCollisions();
    
    changePath();
  }
}

void moveToKJ(){
  if(Path.substring(0, 2) == "KJ"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "JG"){
      leftIntersectionPF();
      }

    else if(nextMove == "JL"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToLJ(){
  if(Path.substring(0, 2) == "LJ"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "JK"){
      leftIntersectionPF();
      }

    else if(nextMove == "JI"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToLM(){
  if(Path.substring(0, 2) == "LM"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();
    Serial.println("Je suis en LM");
    nextVector();
    
    if(nextMove != NULL){
      leftIntersectionPF();
      }
    
    changePath();
  }
}

void moveToML(){
  if(Path.substring(0, 2) == "ML"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove != NULL){
      leftIntersectionPF();
      }
    
    changePath();
  }
}

void moveToMO(){
  if(Path.substring(0, 2) == "MO"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeIntersection();

    nextVector();
    
    if(nextMove == "OP"){
      leftIntersectionPF();
      }

    else if(nextMove == "ON"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToNK(){
  if(Path.substring(0, 2) == "NK"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "KJ"){
      rightIntersectionPF();
      }
      
    changePath();
  }
}

void moveToNO(){
  if(Path.substring(0, 2) == "NO"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();
    checkCollisions();
    
    nextVector();
    
    if(nextMove == "OM"){
      leftIntersectionPF();
    }
  
  checkCollisions();

  changePath();
  }
}

void moveToOM(){
  if(Path.substring(0, 2) == "OM"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "ML"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}

void moveToON(){
  if(Path.substring(0, 2) == "ON"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "NK"){
      rightIntersectionPF();
      }

    
    changePath();
  }
}

void moveToOP(){
    if(Path.substring(0, 2) == "OP"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove != NULL){
      leftIntersectionPF();
    }
    
    changePath();
  }
}

void moveToPI(){
    if(Path.substring(0, 2) == "PI"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove == "IJ"){
      leftIntersectionPF();
      }
    
    changePath();
  }
}

void moveToPO(){
  if(Path.substring(0, 2) == "PO"){
    checkCollisions();
    up(-50);
    checkCollisions();
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "OM"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}


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
    up(-50);
    checkCollisions();
    }
    delay(50);
  }
  
void upBeforeRightTurn(){
    while(digitalRead(right) == 0 || digitalRead(middleR) == 0) {
      checkCollisions();
      up(-50);
      checkCollisions();
      }
  }
  
void upBeforeIntersection(){
  while(digitalRead(left) == 0 || digitalRead(middleL) == 0 || digitalRead(right) == 0 || digitalRead(middleR) == 0) {
      checkCollisions();
      up(-50);
      checkCollisions();
      }
  }

void upBeforeAll(){
  while((digitalRead(left) == 0 || digitalRead(middleL) == 0 || digitalRead(right) == 0 || digitalRead(middleR) == 0) && (digitalRead(left) == 0 || digitalRead(middleL) == 0) && (digitalRead(right) == 0 || digitalRead(middleR) == 0)) {
    checkCollisions();
    up(-50);
    checkCollisions();
    }
  }

void leftTurnPF(){
  stopCar();
  while(digitalRead(middleR) == 0){
    bigLeft();
    }
  }
  
void rightTurnPF(){
  stopCar();
  while(digitalRead(middleL) == 0){
    bigRight();
    }
  }

void leftIntersectionPF(){
  //delay(80);
    compteur2 = 0;
    // 28
    while(compteur2 < 30){
      bigLeft();
      compteur2++;
    }

    turnRight = false;
    turnLeft = true;
}
  
void rightIntersectionPF(){
  compteur2 = 0;
  while(compteur2 < 25){
    bigRight();
    compteur2++;
  }

    turnLeft = false;
    turnRight = true;
}

void leftIntersectionD(){
  delay(65);
  compteur2 = 0;
  while(compteur2 < 32){
    bigLeft();
    compteur2++;
   }
}
  
void rightIntersectionD(){
  delay(65);
  compteur2 = 0;
  while(compteur2 < 40){
    bigRight();
    compteur2++;
  }
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

void changeTabOfChoices(int newTailleTab){

  if(newTailleTab == 0){
    tabOfChoices[0] = NULL;
    }

  else{
    for(int i = 1; i < newTailleTab; i++){
      tabOfChoices[i - 1] = tabOfChoices[i];
      }
    }
  }

void down(int wait){
  Motor.speed(MOTOR1, 50);
  Motor.speed(MOTOR2, 50);
  delay(wait);
  }

void parkCar(){

  while(parked == false){
    down(750);
    leftIntersectionPF();
    stopCar();
    down(1000);
    stopCar();
    rightIntersectionPF();
    stopCar();
    down(75);
    parked = true;
  }

  stopCar();
}

void setStartFree(String start){
  
  }

char getPointFree(int nbPoint){
  
  }

/*char getPointPF(){
  return test;
  }*/
