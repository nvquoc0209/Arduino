# 1 "c:\\Users\\137151\\Documents\\GIT_PRIVATE\\Arduino\\Projects\\ESP32\\ESP32_MCPWM_Capture_Timer\\ESP32_MCPWM_Capture_Timer.ino"
// Reference: https://docs.espressif.com/projects/esp-idf/en/v4.2/esp32/api-reference/peripherals/mcpwm.html
# 3 "c:\\Users\\137151\\Documents\\GIT_PRIVATE\\Arduino\\Projects\\ESP32\\ESP32_MCPWM_Capture_Timer\\ESP32_MCPWM_Capture_Timer.ino" 2

//=========================================================================
void setup(void)
{
  Serial.begin(115200);
  digitalWrite(LED_BUILTIN, 0x0);
  pinMode(LED_BUILTIN, 0x03);

  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM_CAP_0, 25 /*Set GPIO 25 as input CAP0*/);
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM_CAP_1, 25 /*Set GPIO 25 as input CAP0*/);

  mcpwm_capture_enable(MCPWM_UNIT_0, MCPWM_SELECT_CAP0, MCPWM_POS_EDGE, 0);
  mcpwm_capture_enable(MCPWM_UNIT_0, MCPWM_SELECT_CAP1, MCPWM_NEG_EDGE, 0);
  digitalWrite(LED_BUILTIN, 0x1);
  delay(500);
  digitalWrite(LED_BUILTIN, 0x0);
}
//=========================================================================
void loop()
{
  uint32_t LOW_VALUE = mcpwm_capture_signal_get_value(MCPWM_UNIT_0,MCPWM_SELECT_CAP0);
  uint32_t HIGH_VALUE = mcpwm_capture_signal_get_value(MCPWM_UNIT_0,MCPWM_SELECT_CAP1);
  Serial.printf("LOW_VALUE: %d\n", LOW_VALUE);
  Serial.printf("HIGH_VALUE: %d\n", HIGH_VALUE);
  vTaskDelay(( ( TickType_t ) ( ( ( TickType_t ) ( 1000 ) * ( TickType_t ) ( 
# 27 "c:\\Users\\137151\\Documents\\GIT_PRIVATE\\Arduino\\Projects\\ESP32\\ESP32_MCPWM_Capture_Timer\\ESP32_MCPWM_Capture_Timer.ino" 3 4
            1000 
# 27 "c:\\Users\\137151\\Documents\\GIT_PRIVATE\\Arduino\\Projects\\ESP32\\ESP32_MCPWM_Capture_Timer\\ESP32_MCPWM_Capture_Timer.ino"
            ) ) / ( TickType_t ) 1000U ) ));
}
