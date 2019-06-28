#define I2C_ADDRESS 0x0f
#define TAILLE_TAB 11

void Left(int speed);
void Right(int speed);
void up(int speed);
void bigLeft();
void bigRight();
void stopCar();
void down(int wait);
void parkCar();

void upBeforeLeftTurn();
void upBeforeRightTurn();
void upBeforeIntersection();
void upBeforeAll();

void leftIntersectionPF();
void rightIntersectionPF();

void leftIntersectionD();
void rightIntersectionD();

void checkCollisions();

void LifeCycleChoice(int choice);

void LifeCyclePathFinding();
void LifeCycleFree();
void LifeCycleDecided();

void nextVector();

void changePath();
void setTabOfChoices(char choices[]);
void changeTabOfChoices(int newTailleTab);

void setCoords(char startPoint);
void setStartFree(String start);
char getPointFree(int nbPoint);

//char getPointPF();
