#ifndef __SDKCONFIG_H__
#define __SDKCONFIG_H__

// Definiciones del tamaño de las pilas de tareas
#define CONFIG_TASK_LED_ON_STACK_SIZE (1024 * 2)
#define CONFIG_TASK_LED_OFF_STACK_SIZE (1024 * 2)

// Definición del pin del LED
#define CONFIG_LED_PIN 2  // GPIO2, generalmente el LED integrado en el ESP8266-12E

#endif // __SDKCONFIG_H__
