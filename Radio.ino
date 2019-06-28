#include <VirtualWire.h>
#include <SharpIR.h>
#include <Grove_I2C_Motor_Driver.h>

#include "Radio.h"
#include "VecteursDeplacements.h"
#include "tourSeconde.h"
#include "PathFinding.h"


#define I2C_ADDRESS 0x0f

  
float trous;
uint8_t dis;
uint8_t fourchePin = A0; 


 
SharpIR sensor(SharpIR::GP2Y0A21YK0F, A1);            //Initialisation du module capteur de distance SharpIR de 10cm à 80cm en A1


void radio(){

  
  
  
  String currentVector;
  
  uint8_t etat;
  
  float tourSeconde;
  float tourMinute;
  float vitesse;
  char msg[4];
  char msgF[50];
  char msgFinal[50];
  String check;
  uint8_t check1;
  uint8_t check2;
  float rayon = 0.0325;                                 //Rayon d'une roue
  
  vw_setup(2000);                                     // Initialisation de la bibliothèque VirtualWire à une vitesse de 2000bits/s
  vw_set_tx_pin(5);

  if((millis() - debut) > 1000UL){                    //Boucle qui attend une seconde


    tourSeconde = trous/20; //Calcul de tour par seconde
    tourMinute = tourSeconde * 60;                    //Passage de tour seconde en tour minute
    vitesse = rayon * ((2*3.14)/60)*tourMinute;       //Calcul de la vitesse
    
  
    dtostrf(vitesse, 4,4, msg );
    check =  (String) msgF;
    check1 = checksum(check);

    

    currentVector = msgPos;
    
    sprintf(msgF, "8%d/%s/%c%c%c%c#", dis,msg,startLetter,lastLetter,currentVector[0],currentVector[1],check1);
    
    int j;
    for(j=0;j<strlen(msgF);j++)
    {
        msgF[j]=msgF[j]^'256';
    }

    debut = millis();
    trous =0 ;
    
    
    
    }

    etat = digitalRead(fourchePin);
    if(etat == LOW){
          trous ++;
    }

    dis = sensor.getDistance();

    vw_send((uint8_t *)msgF, strlen(msgF));                   //Envoie du message par un pointeur et la taille du message
    vw_wait_tx();
}

uint8_t checksum(String message){

  uint8_t result = 0;   // Resultat sur 8 bits
    //--- Calcul de la somme, le premier caractère est en position 1
    for (int i = 1; i <= message.length(); i++)
        result += message[i];
    //--- Modulo Valeur Maxi sur 8 Bits
    return (result %= 0xFF);
  
}
