#include <Arduino.h>
#line 1 "c:\\Users\\137151\\Documents\\GIT_PRIVATE\\Arduino\\Projects\\ESP32\\ESP32_MCPWM_Capture_Timer\\ESP32_MCPWM_Capture_Timer.ino"
// Reference: https://docs.espressif.com/projects/esp-idf/en/v4.2/esp32/api-reference/peripherals/mcpwm.html
#include "driver/mcpwm.h"
#define GPIO_CAP0_IN 25 //Set GPIO 25 as input CAP0
//=========================================================================
#line 5 "c:\\Users\\137151\\Documents\\GIT_PRIVATE\\Arduino\\Projects\\ESP32\\ESP32_MCPWM_Capture_Timer\\ESP32_MCPWM_Capture_Timer.ino"
void setup(void);
#line 21 "c:\\Users\\137151\\Documents\\GIT_PRIVATE\\Arduino\\Projects\\ESP32\\ESP32_MCPWM_Capture_Timer\\ESP32_MCPWM_Capture_Timer.ino"
void loop();
#line 5 "c:\\Users\\137151\\Documents\\GIT_PRIVATE\\Arduino\\Projects\\ESP32\\ESP32_MCPWM_Capture_Timer\\ESP32_MCPWM_Capture_Timer.ino"
void setup(void)
{
  Serial.begin(115200);
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(LED_BUILTIN, OUTPUT);

  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM_CAP_0, GPIO_CAP0_IN);
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM_CAP_1, GPIO_CAP0_IN);

  mcpwm_capture_enable(MCPWM_UNIT_0, MCPWM_SELECT_CAP0, MCPWM_POS_EDGE, 0);
  mcpwm_capture_enable(MCPWM_UNIT_0, MCPWM_SELECT_CAP1, MCPWM_NEG_EDGE, 0);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}
//=========================================================================
void loop()
{
  uint32_t LOW_VALUE = mcpwm_capture_signal_get_value(MCPWM_UNIT_0,MCPWM_SELECT_CAP0);
  uint32_t HIGH_VALUE = mcpwm_capture_signal_get_value(MCPWM_UNIT_0,MCPWM_SELECT_CAP1);
  Serial.printf("LOW_VALUE: %d\n", LOW_VALUE);
  Serial.printf("HIGH_VALUE: %d\n", HIGH_VALUE);
  vTaskDelay(pdMS_TO_TICKS(1000));
}
