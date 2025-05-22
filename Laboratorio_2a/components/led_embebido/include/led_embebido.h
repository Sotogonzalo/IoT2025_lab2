#ifndef LED_EMBEBIDO_H
#define LED_EMBEBIDO_H

#include "esp_err.h"

esp_err_t led_embebido_iniciar(void);
esp_err_t led_embebido_set_color(uint8_t red, uint8_t green, uint8_t blue);
esp_err_t led_embebido_apagar(void);

#endif // LED_EMBEBIDO_H
