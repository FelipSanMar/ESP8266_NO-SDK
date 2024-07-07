#ifndef CONFIG_H
#define CONFIG_H

#include "esp_common.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"

uint32 user_rf_cal_sector_set(void);
void gpio_init();


#endif