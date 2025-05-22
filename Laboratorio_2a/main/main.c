#include <stdio.h>
#include "led_embebido.h"
#include "esp_rom_delay_ms.h"

void app_main(void)
{
    // Inicializo LED
    if (led_embebido_iniciar() != ESP_OK) {
        printf("Error al inicializar el LED embebido\n");
        return;
    }

    while (1) {
        // Rojo
        led_embebido_set_color(255, 0, 0);
        esp_rom_delay_ms(1000);
        led_embebido_apagar();
        esp_rom_delay_ms(500);

        // // Verde
        // led_embebido_set_color(0, 255, 0);
        // esp_rom_delay_ms(1000);
        // led_embebido_apagar();
        // esp_rom_delay_ms(500);

        // // Azul
        // led_embebido_set_color(0, 0, 255);
        // esp_rom_delay_ms(1000);
        // led_embebido_apagar();
        // esp_rom_delay_ms(500);
    }
}
