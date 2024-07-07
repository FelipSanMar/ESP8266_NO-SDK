#include "esp_common.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "gpio.h"
#include "config.h"
#include "sdkconfig.h"


//--------------------------------------------------------------
// TASK PROTOTYPE 
//--------------------------------------------------------------
void led_on_task(void *pvParameters);
void led_off_task(void *pvParameters);
//--------------------------------------------------------------

void user_init(void)
{
    //----------------------- system Init ------------------------------
    uart_div_modify(0, UART_CLK_FREQ / 115200);
    os_printf("SDK version:%s\n", system_get_sdk_version());
    gpio_init();

    //--------------------------- Task creation ---------------------------
    typedef portBASE_TYPE BaseType_t;

    BaseType_t result;
    
    result = xTaskCreate(led_on_task, "led_on_task", CONFIG_TASK_LED_ON_STACK_SIZE, NULL, 2, NULL);
    if(result != pdPASS) {
        os_printf("Failed to create led_on_task\n");
    }
    result = xTaskCreate(led_off_task, "led_off_task", CONFIG_TASK_LED_OFF_STACK_SIZE, NULL, 2, NULL);
    if(result != pdPASS) {
        os_printf("Failed to create led_off_task\n");
    }

    //-------------------------------------------------------------------------------------------
}

void led_on_task(void *pvParameters)
{
    while (1)
    {
        //LED turn on
        gpio_output_set((1 << CONFIG_LED_PIN), 0, 0, 0);
        os_printf("LED encendido\n");
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

void led_off_task(void *pvParameters)
{
    while (1)
    {
        //LED turn off
        gpio_output_set(0, (1 << CONFIG_LED_PIN), 0, 0);
        os_printf("LED apagado\n");
        vTaskDelay(2100 / portTICK_RATE_MS);
    }
}
