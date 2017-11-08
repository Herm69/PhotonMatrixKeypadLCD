#include "Keypad_I2C.h"

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char* I2CTYPE = "Adafruit_MCP23017";

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {6, 5, 4, 3}; //row pins
byte colPins[COLS] = {2, 1, 0}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CTYPE );

void setup() {
    Serial.begin(9600);
    Serial.println("Started");
}

void loop() {
    char key = keypad.getKey();
    if (key) {
        Serial.println(key);
    }
}
