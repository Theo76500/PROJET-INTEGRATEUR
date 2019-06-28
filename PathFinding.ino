String pathFinding(char beginParam, char endParam) {
  beginLetter = beginParam;
  endLetter = endParam;
  String path;
  String newBeginLetter;
  String StringTotal;
 
  for (int i = 0; i < primaryPath.length(); i+=2) {
    if (primaryPath.substring(i,i+2) == String(beginParam+endParam)) {
      return String(beginParam+endParam);
    }
  }
  
  StringTotal = FindThePath(String(beginLetter),StringTotal);

  if (success == false) {
    for (int i = 0; i < LetterToTest.length(); i++) {
      newBeginLetter = LetterToTest.substring(0+i,1+i);
      StringTotal = FindThePath(newBeginLetter,StringTotal);
      if (success == true) {
        break;
      }
    }
  }
  path = GiveThePath(StringTotal);
  return path;
}

String GiveThePath(String StringTotal) {
  String strPiece;
  String path = "";
  String firstLetter = "";
  String lastLetter = String(endLetter);

  while (firstLetter != String(beginLetter)) {
    for (int i = 0; i < StringTotal.length(); i+=2) {
      strPiece = StringTotal.substring(i,i+2);
      if (lastLetter == strPiece.substring(1,2)) {
        firstLetter = strPiece.substring(0,1);
        lastLetter = firstLetter;
        path = strPiece + path;
        break;
      }   
    }
  }
  return path;
}

String FindThePath(String beginParam, String StringTotal) {
  String str = seePossibleCase(beginParam);
  StringTotal = addToTotalList(str,StringTotal);
  if (verifyIfDone(StringTotal) == true) {
    success = true;
  }
  else {
    success = false;
  } 
  return StringTotal;
}

boolean verifyIfDone(String str) {
  String strPiece;
  String lastLetter;
  
  for (int i = 0; i < str.length(); i+=2) {
    strPiece = str.substring(i,2+i);
    lastLetter = strPiece.substring(1,2);
    if (lastLetter == String(endLetter)) {
      return true; 
    }
  }
  return false;
}

String addToTotalList(String str, String StringTotal) {
  String strReturn = StringTotal;
  String strPiece1;
  String strPiece2;
  String firstLetter;
  String lastLetter;
  String bannedLetters = "";
  boolean verify = false;

  if (StringTotal.length() < 2) {
    for (uint8_t j = 0; j < str.length(); j+=2) {
      strPiece2 = str.substring(j,2+j);
      strReturn = strReturn + strPiece2;
    }
  }
  
  else {
    for (uint8_t i = 0; i < str.length(); i+=2) {
      verify = false;
      strPiece1 = str.substring(i,2+i);
      lastLetter = strPiece1.substring(1,2);
      for (uint8_t j = 0; j < StringTotal.length(); j+=2) {
        strPiece2 = StringTotal.substring(j,2+j);
        firstLetter = strPiece2.substring(0,1);
        bannedLetters = bannedLetters + firstLetter;
        if (bannedLetters.indexOf(lastLetter) == -1) {
          verify = true;
        }
      }
      if (verify == true) {
        strReturn = strReturn + strPiece1;
      }
    }
  }
  return strReturn;
}

String seePossibleCase(String letter) {
  String firstLetter;
  String lastLetter;
  String str = "";
  
  for (int i = 0; i < primaryPath.length(); i+=2) {
    firstLetter = primaryPath.substring(i,i+1);
    if(firstLetter == letter) {
      str = str + primaryPath.substring(i,i+2);
      lastLetter = primaryPath.substring(i+1,i+2);
      if (LetterToTest.indexOf(lastLetter) == -1 && lastLetter != String(beginLetter)) {
        LetterToTest = LetterToTest + lastLetter;
      }
    }
  }
  return str;
}
