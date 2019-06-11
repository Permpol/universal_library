#include <EEPROM.h>

#define FIRST_ADDRESS 0
int firstState;

void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);

  firstState = EEPROM.read(FIRST_ADDRESS);
  Serial.print("Now: ");
  Serial.println(firstState);
  if (firstState == 3) {
    firstState = EEPROM.read(FIRST_ADDRESS);
    Serial.print("use again: ");
    Serial.println(firstState);
  } else {
    Serial.println("write new");
    EEPROM.write(FIRST_ADDRESS, 3);
    EEPROM.commit();
  }
}

void loop() {
  /** Empty loop. **/
}
