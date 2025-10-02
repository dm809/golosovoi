#include <Wire.h>
#include "DFRobot_DF2301Q.h"

DFRobot_DF2301Q_I2C voiceModule;

void setup() {
  Serial.begin(115200);
  
  if (!voiceModule.begin()) {
    Serial.println("Ошибка модуля!");
    while(1);
  }
  
  voiceModule.setVolume(5);
  voiceModule.setWakeTime(0);
  voiceModule.setMuteMode(0);
  
  Serial.println("╔════════════════════════════════════╗");
  Serial.println("║    ОПРЕДЕЛЕНИЕ ID КОМАНД           ║");
  Serial.println("╠════════════════════════════════════╣");
  Serial.println("║ Произноси команды по порядку:      ║");
  Serial.println("║                                    ║");
  Serial.println("║ 1.  Звук выключить                 ║");
  Serial.println("║ 2.  Звук включить                  ║");
  Serial.println("║ 3.  Температура восемнадцать       ║");
  Serial.println("║ 4.  Температура двадцать           ║");
  Serial.println("║ 5.  Температура двадцать два       ║");
  Serial.println("║ 6.  Температура двадцать четыре    ║");
  Serial.println("║ 7.  Температура двадцать шесть     ║");
  Serial.println("║ 8.  Включи кондиционер             ║");
  Serial.println("║ 9.  Включи обогрев                 ║");
  Serial.println("║ 10. Выключи климат                 ║");
  Serial.println("║ 11. Включи магнитолу               ║");
  Serial.println("║ 12. Выключи магнитолу              ║");
  Serial.println("║ 13. Открой окна                    ║");
  Serial.println("║ 14. Майя кто ты                    ║");
  Serial.println("║ 15. Какая температура              ║");
  Serial.println("║ 16. Статус системы                 ║");
  Serial.println("╚════════════════════════════════════╝");
  Serial.println();
}

void loop() {
  uint8_t cmdID = voiceModule.getCMDID();
  
  if (cmdID != 0) {
    Serial.println("╔════════════════════════════════════╗");
    Serial.print("║ КОМАНДА ID: ");
    if (cmdID < 10) Serial.print(" ");
    Serial.print(cmdID);
    Serial.println("                         ║");
    Serial.println("╚════════════════════════════════════╝");
    Serial.println();
    
    delay(3000);
  }
  
  delay(100);
}
