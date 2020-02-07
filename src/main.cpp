#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

LiquidCrystal_I2C lcd(0x3F,20, 4);

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
int StoredValues[] = {1,2,3};


char hexaKeys[ROWS][COLS] = { //declaracion de caracteres con respectiva tecla
                              //represenado por una matriz
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void serial_addChar(char _char) //función que añade numero
{
  if(sValue.substring(1,0) == 0) //en caso de haber un cero a la izquierda lo ignora
  {
    sValue = sValue.substring(2);
    sValue = sValue + _char;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(sValue);
    dValue = sValue.toInt();
  }
  else
  {
    sValue = sValue + _char;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(sValue);
    dValue = sValue.toInt();
  }
}

void StoreValue(double value){ // función que guarda los valores con los que se hara la operación
  if (StoredValue1 != 0)
  {
    StoredValue2 = value;
    value = 0;
    sValue = "";
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(sValue);
  }
  else
  {
    StoredValue1 = value;
    value = 0;
    sValue = "";
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(sValue);
  }
}

void setup(){
  lcd.init(); //se inicializa el lcd
  lcd.backlight();
}
  
void loop(){
  customKey = customKeypad.getKey(); //se lee el caracter de la tecla presionada
  
  if (customKey)
  {
    switch (customKey)//se determina que caracter se presiono
                      //en caso de ser un número, lo imprime en el lcd
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

    case 'A': //Addition Case
    StoreValue(dValue);
    OperationName = "add";
      break;
    
    case 'B': //Substraction Case
    StoreValue(dValue);
    OperationName = "sub";
      break;

    case 'C':
    StoreValue(dValue); //Multiplication Case
    OperationName = "mul";
      break;

    case 'D': //Division Case
    StoreValue(dValue);
    OperationName = "div";
      break;

    case '*': //caracter definido para limpiar pantalla y memoria
    StoredValue1 = 0;
    StoredValue2 = 0;
    dValue = 0;
    sValue = String(0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(sValue);
      break;

    case '#': // caracter definido para realizar operacion aritmetica e imprimirla
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
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("unknown");   
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(String(resultado));
    StoredValue1 = 0;
    StoredValue2 = 0;
    dValue = resultado;
      break;
    default:
      break;
    }
  }
}



