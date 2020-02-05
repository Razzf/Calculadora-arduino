#include <Arduino.h>
#include <Keypad.h>


const byte ROWS = 4; 
const byte COLS = 4;
String sValue = " "; //valor en formato string
double dValue; // valor en formato de digito (double)
double StoredValue1;
double StoredValue2;
char customKey;
String OperationName;
int i;
double resultado;


char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void serial_addChar(char _char) //funcion que anade numero
{
  // falta mejorar con un for para que ignore ceros a la izquierda
  if(sValue.substring(1,0) == 0) 
  {
    sValue = sValue.substring(2);
    sValue = sValue + _char;
    Serial.println(sValue);
    dValue = sValue.toInt();
  }
  else
  {
    sValue = sValue + _char;
    Serial.println(sValue);
    dValue = sValue.toInt();
  }

  //for(i = 0,1 < sValue.length)
}

void StoreValue(double value){
  if (StoredValue1 != 0)
  {
    StoredValue2 = value;
    value = 0;
    sValue = "";
    Serial.println(sValue);
  }
  else
  {
    StoredValue1 = value;
    value = 0;
    sValue = "";
    Serial.println(sValue);
  }
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
    if (sValue.length() <=  10)
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
    StoreValue(dValue);
    OperationName = "add";
      break;
    
    case 'B':
    StoreValue(dValue);
    OperationName = "sub";
      break;

    case 'C':
    StoreValue(dValue);
    OperationName = "mul";
      break;

    case 'D':
    StoreValue(dValue);
    OperationName = "div";
      break;

    case '*':
    StoredValue1 = 0;
    StoredValue2 = 0;
    dValue = 0;
    sValue = String(0);
    Serial.print(sValue);
      break;

    case '#':
    StoreValue(dValue);

    if (OperationName == "add"){
      resultado = StoredValue1 + StoredValue2;
    }
    else if (OperationName == "sub"){
      resultado = StoredValue1 - StoredValue2;
    }
    else if (OperationName == "mul"){
      resultado = StoredValue1*StoredValue2;
    }
    else if (OperationName == "div"){
      
      resultado = StoredValue1 / StoredValue2;
    }
    else{
      Serial.print("Unknown operation");
    }

    Serial.println(String(resultado));

    StoredValue1 = 0;
    StoredValue1 = 0;

    dValue = resultado;

      break;
    
    default:
      break;
    }
    
    
  }
}



