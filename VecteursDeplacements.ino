#include "VecteursDeplacements.h"

void moveTo(){
  if(Path != NULL){
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

  else{
    stopCar();
  }
}

void moveToAB(){
  if(Path.substring(0, 2) == "AB"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "AB";
    upBeforeLeftTurn();
    checkCollisions();
    nextVector();
    if(nextMove == "BC"){
      leftTurnPF();
    }

    changePath();
    
  }
}

void moveToAD(){
  if(Path.substring(0, 2) == "AD"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "AD";
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
    up(-38);
    checkCollisions();
    msgPos = "AF";
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
    up(-38);
    checkCollisions();
    msgPos = "BA";
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
    up(-38);
    checkCollisions();
    msgPos = "BC";
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
    up(-38);
    checkCollisions();
    msgPos = "CB";
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "BA"){
      rightTurnPF();
      }
    
    changePath();
  }
}

void moveToCD(){
  if(Path.substring(0, 2) == "CD"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "CD";
    upBeforeLeftTurn();
    //(15);
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
    up(-38);
    checkCollisions();
    msgPos = "CK";
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
    up(-38);
    checkCollisions();
    msgPos = "DA";
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
    up(-38);
    checkCollisions();
    msgPos = "DC";
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
    up(-38);
    checkCollisions();
    msgPos = "DE";
    upBeforeLeftTurn();
    nextVector();
    
    if(nextMove == "EF"){
      leftTurnPF();
      }
    
    changePath();
  }
}

void moveToEF(){
  if(Path.substring(0, 2) == "EF"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "EF";
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
    up(-38);
    checkCollisions();
    msgPos = "ED";
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
    up(-38);
    checkCollisions();
    msgPos = "FA";
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
    up(-38);
    checkCollisions();
    msgPos = "FE";
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "ED"){
      rightTurnPF();
      }
    
    changePath();
  }
}

void moveToFG(){
  if(Path.substring(0, 2) == "FG"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "FG";
    upBeforeRightTurn();
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
    up(-38);
    checkCollisions();
    msgPos = "GF";
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
    up(-38);
    checkCollisions();
    msgPos = "GH";
    checkCollisions();
    upBeforeRightTurn();
    nextVector();
    checkCollisions();
      
    if(nextMove == "HI"){
      rightTurnPF();
      }
    checkCollisions();
    
    changePath();
  }
}

void moveToGJ(){
  if(Path.substring(0, 2) == "GJ"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "GJ";
    upBeforeIntersection();
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
    up(-38);
    checkCollisions();
    msgPos = "HG";
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
    up(-38);
    checkCollisions();
    msgPos = "HI";
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
    up(-38);
    checkCollisions();
    msgPos = "IH";
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove == "HG"){
      leftTurnPF();
      }
    
    changePath();
  }
}

void moveToIJ(){
  if(Path.substring(0, 2) == "IJ"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "IJ";
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
    up(-38);
    checkCollisions();
    msgPos = "IP";
    upBeforeRightTurn();
    nextVector();
      
    if(nextMove == "PO"){
      rightTurnPF();
     }
    
    changePath();
  }
}

void moveToJG(){
  if(Path.substring(0, 2) == "JG"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "JG";
    checkCollisions();
    upBeforeIntersection();
    nextVector();
    
    if(nextMove == "GF"){
      leftIntersectionPF();
      }

    else if(nextMove == "GH"){
      rightIntersectionPF();
      }
    checkCollisions();
    changePath();
  }
}

void moveToJI(){
  if(Path.substring(0, 2) == "JI"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "JI";
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
    up(-38);
    checkCollisions();
    msgPos = "JK";
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
    up(-38);
    checkCollisions();
    msgPos = "JL";
    upBeforeRightTurn();
    nextVector();
    
    if(nextMove == "LM"){
      rightTurnPF();
      }
    
    changePath();
  }
}

void moveToKC(){
  if(Path.substring(0, 2) == "KC"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "KC";
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
    up(-38);
    checkCollisions();
    msgPos = "KN";
    upBeforeLeftTurn();
    nextVector();
    
    if(nextMove == "NO"){
      leftTurnPF();
    }
    
    checkCollisions();
    
    changePath();
  }
}

void moveToKJ(){
  if(Path.substring(0, 2) == "KJ"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "KJ";
    checkCollisions();
    upBeforeIntersection();
    nextVector();
    if(nextMove == "JG"){
      leftIntersectionPF();
      }

    else if(nextMove == "JL"){
      rightIntersectionPF();
      }
    checkCollisions();
    changePath();
  }
}

void moveToLJ(){
  if(Path.substring(0, 2) == "LJ"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "LJ";
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
    up(-38);
    checkCollisions();
    msgPos = "LM";
    upBeforeLeftTurn();
    nextVector();
    
    if(nextMove == "MO"){
      leftTurnPF();
      }
    
    changePath();
  }
}

void moveToML(){
  if(Path.substring(0, 2) == "ML"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "ML";
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove == "LJ"){
      leftTurnPF();
      }
    
    changePath();
  }
}

void moveToMO(){
  if(Path.substring(0, 2) == "MO"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "MO";
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
    up(-38);
    checkCollisions();
    msgPos = "NK";
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
    up(-38);
    checkCollisions();
    msgPos = "NO";
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
    up(-38);
    checkCollisions();
    msgPos = "OM";
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "ML"){
      rightTurnPF();
      }
    changePath();
    }
}

void moveToON(){
  if(Path.substring(0, 2) == "ON"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "ON";
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "NK"){
      rightTurnPF();
      }
    changePath();
  }
}

void moveToOP(){
    if(Path.substring(0, 2) == "OP"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "OP";
    upBeforeLeftTurn();

    nextVector();
    
    if(nextMove == "PI"){
      leftTurnPF();
    }   
    changePath();
  }
}

void moveToPI(){
    if(Path.substring(0, 2) == "PI"){
    checkCollisions();
    up(-38);
    checkCollisions();
    msgPos = "PI";
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
    up(-38);
    checkCollisions();
    msgPos = "PO";
    upBeforeRightTurn();

    nextVector();
    
    if(nextMove == "OM"){
      rightIntersectionPF();
      }
    
    changePath();
  }
}
