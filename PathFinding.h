#ifndef PathFinding.h // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define PathFinding.h // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

String primaryPath = "ABAFADBABCCBCDCKDCDEDAEDEFFAFEFGGFGJGHHGHIIHIJIPJGJGJKJLKCKJKNLJLMMLMONKNOONOPPOPI";
boolean success = false;
String Path = "";
String LetterToTest = "";
char beginLetter;
char endLetter;
int pathIndex;
char startLetter;
char lastLetter;
  


String pathFinding(char beginParam, char endParam);

#endif
