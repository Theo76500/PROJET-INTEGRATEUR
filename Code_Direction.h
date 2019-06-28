#define I2C_ADDRESS 0x0f
#define TAILLE_TAB 20

void Left(int speed);
void Right(int speed);
void up(int speed);
void bigLeft();
void bigRight();
void stopCar();

void upBeforeLeftTurn();
void upBeforeRightTurn();
void upBeforeIntersection();
void upBeforeAll();

void leftTurnPF();
void rightTurnPF();

void leftIntersectionPF();
void rightIntersectionPF();

void leftIntersectionD();
void rightIntersectionD();

void checkCollisions();

void LifeCycleChoice(uint8_t choice);

void LifeCyclePathFinding();
void LifeCycleFree();
void LifeCycleDecided();

void nextVector();

void changePath();
void setTabOfChoices(char choices[]);
void changeTabOfChoices(uint8_t newTailleTab);
