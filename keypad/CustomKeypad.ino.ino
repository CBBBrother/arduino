/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {8, 9, 10, 11}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

char code[4] = {' ',' ',' ',' '};;
char password[] = {'1','2','3','4'};

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  for (int i = 0; i < 4;)
  {
  
    char key = customKeypad.getKey();
    if (key)
    {
      if (key != '*')
      {
        code[i] = key;
        Serial.print(key);
        ++i;
      }
      else if (i > 0)
      {
        Serial.peek();
        --i;
      }
    }
    
  }
  
  if (strncmp(code, password, 4) == 0)
    Serial.println("Access granted");
  else
    Serial.println("Access denied");
}
