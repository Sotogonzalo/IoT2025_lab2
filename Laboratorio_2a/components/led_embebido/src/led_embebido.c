#include "led_embebido.h"
#include "led_strip.h"
#include "esp_log.h"

// Usamos funciones de led_strip_rmt_ws2812.c
extern esp_err_t led_rgb_init(led_strip_t **strip);
extern esp_err_t ws2812_set_pixel(led_strip_t *strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue);
extern esp_err_t ws2812_refresh(led_strip_t *strip, uint32_t timeout_ms);
extern esp_err_t ws2812_clear(led_strip_t *strip, uint32_t timeout_ms);

static const char *TAG = "led_embebido";
static led_strip_t *led_strip = NULL;

esp_err_t led_embebido_iniciar(void) {
    esp_err_t ret = led_rgb_init(&led_strip);
    if (ret != ESP_OK || !led_strip) {
        ESP_LOGE(TAG, "Fallo al inicializar el LED RGB");
        return ESP_FAIL;
    }
    return ESP_OK;
}

esp_err_t led_embebido_set_color(uint8_t red, uint8_t green, uint8_t blue) {
    if (!led_strip) {
        ESP_LOGE(TAG, "LED no inicializado");
        return ESP_ERR_INVALID_STATE;
    }

    esp_err_t ret = ws2812_set_pixel(led_strip, 0, red, green, blue);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Error al establecer el color");
        return ret;
    }

    return ws2812_refresh(led_strip, 100);
}

esp_err_t led_embebido_apagar(void) {
    if (!led_strip) {
        ESP_LOGE(TAG, "LED no inicializado");
        return ESP_ERR_INVALID_STATE;
    }

    return ws2812_clear(led_strip, 100);
}
