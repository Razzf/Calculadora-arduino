#include <Arduino.h>
#include <Keypad.h>


const byte ROWS = 4; 
const byte COLS = 4;
String sValue = " "; //valor en formato string
int dValue; // valor en formato de digito (double)
double StoredValue1;
double StoredValue2;
char customKey;
String OperationName;
int i;


char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void serial_addChar(char _char) 
{
  if(sValue.substring(1,0) == 0)
  {
    sValue = sValue.substring(2);
    sValue = sValue + _char;
    Serial.print(sValue);
    dValue = sValue.toInt();
  }
  else
  {
    sValue = sValue + _char;
    Serial.print(sValue);
    dValue = sValue.toInt();
  }

  //for(i = 0,1 < sValue.length)
}

void setup(){
  Serial.begin(9600);
  Serial.print("0");
}
  
void loop(){

  customKey = customKeypad.getKey();
  
  if (customKey)
  {
    switch (customKey)
    {
    case '1':
    if (sValue.length() <= 10)
    {
      serial_addChar(customKey);
    }
      
      break;

    case '2':
    if (sValue.length() <= 10)
      {
        serial_addChar(customKey);
      }

      break;

    case '3':
    if (sValue.length() <= 10)
      {
        serial_addChar(customKey);
      }

      break;

    case '4':
    if (sValue.length() <= 10)
      {
        serial_addChar(customKey);
      }

      break;

    case '5':
    if (sValue.length() <= 10)
      {
        serial_addChar(customKey);
      }

      break;

    case '6':
    if (sValue.length() <= 10)
      {
        serial_addChar(customKey);
      }

      break;
    
    case '7':
    if (sValue.length() <= 10)
      {
        serial_addChar(customKey);
      }

      break;

    case '8':
    if (sValue.length() <= 10)
      {
        serial_addChar(customKey);
      }

      break;

    case '9':
    if (sValue.length() <= 10)
      {
        serial_addChar(customKey);
      }

      break;

    case '0':
    if (sValue.length() <= 10)
      {
        serial_addChar(customKey);
      }

      break;

    case 'A': //Addition case
    if (StoredValue1 != 0)
    {
      StoredValue2 = dValue;
      dValue = 0;
      sValue = String(dValue);
      Serial.print(sValue);
    }
    else
    {
      StoredValue1 = dValue;
      dValue = 0;
      sValue = String(dValue);
      Serial.print(sValue);
    }
      OperationName = "add";
      break;
    
    case 'B':
    if (StoredValue1 != 0)
    {
      StoredValue2 = dValue;
      dValue = 0;
      sValue = String(dValue);
      Serial.print(sValue);
    }
    else
    {
      StoredValue1 = dValue;
      dValue = 0;
      sValue = String(dValue);
      Serial.print(sValue);
    }
      OperationName = "sub";
      break;

    case 'C':
    if (StoredValue1 != 0)
    {
      StoredValue2 = dValue;
      dValue = 0;
      sValue = String(dValue);
      Serial.print(sValue);
    }
    else
    {
      StoredValue1 = dValue;
      dValue = 0;
      sValue = String(dValue);
      Serial.print(sValue);
    }
      OperationName = "mul";
      break;

    case 'D':
    if (StoredValue1 != 0)
    {
      StoredValue2 = dValue;
      dValue = 0;
      sValue = String(dValue);
      Serial.print(sValue);
    }
    else
    {
      StoredValue1 = dValue;
      dValue = 0;
      sValue = String(dValue);
      Serial.print(sValue);
    }
      OperationName = "div";
      break;

    case '*':
    dValue = 0;
    sValue = String(dValue);
    Serial.print(sValue);
      break;

    case '#':
      break;
    
    default:
      break;
    }
    
    
  }
}



