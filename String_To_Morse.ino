String toMorse(String inputString) {
  inputString.toUpperCase();
  inputString.trim(); 

    struct CharPair{
    char character;
    String morse;
  };

  CharPair charToMorseArray[] = {
    {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},  {'D', "-.."},   {'E', "."},
    {'F', "..-."},  {'G', "--."},   {'H', "...."},  {'I', ".."},    {'J', ".---"},
    {'K', "-.-"},   {'L', ".-.."},  {'M', "--"},    {'N', "-."},    {'O', "---"},
    {'P', ".--."},  {'Q', "--.-"},  {'R', ".-."},   {'S', "..."},   {'T', "-"},
    {'U', "..-"},   {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},  {'Y', "-.--"},
    {'Z', "--.."},  {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
    {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {'0', "-----"}, {' ',"/"}
  };
  
  int arrayLength = sizeof(charToMorseArray) / sizeof(charToMorseArray[0]);
  int stringLength = inputString.length();

  String morseReturn = "";
  for(int i = 0; i < stringLength; i++){ // iterates each character in the input
    for(int m = 0; m < arrayLength; m++){ //loops through charToMorseArray to find the letter that matches and its associated morse code
      if(charToMorseArray[m].character == inputString[i]){
        morseReturn = morseReturn + charToMorseArray[m].morse + " ";
        break;
      }
      if (m + 1 >= arrayLength){
        Serial.print("No morse code found for character '");
        Serial.print(inputString[i]);
        Serial.println("'");
        while(true){}
      }
    }
  }

  return  morseReturn;
};