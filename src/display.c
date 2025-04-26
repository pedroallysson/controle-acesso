#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "include/display.h"

// Definições dos pinos
const uint I2C_SDA = 14;
const uint I2C_SCL = 15;


// Função de inicialização do display OLED
void init_display_oled(void)
{
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_init();
}

static struct render_area frame_area = {
    .start_column = 0,
    .end_column = ssd1306_width - 1,
    .start_page = 0,
    .end_page = ssd1306_n_pages - 1
};

static uint8_t ssd[ssd1306_buffer_length];

void tela_inicial(void) {
    calculate_render_area_buffer_length(&frame_area);
    memset(ssd, 0, ssd1306_buffer_length);

    char *text[] = {
        "Digite sua ",
        "Matricula:      "};

    int y = 20;
    for (uint i = 0; i < sizeof(text) / sizeof(text[0]); i++) {
        ssd1306_draw_string(ssd, 16, y, text[i]);
        y += 12;
    }

    render_on_display(ssd, &frame_area);
}

void acesso_liberado(void) {
    memset(ssd, 0, ssd1306_buffer_length);
    ssd1306_draw_string(ssd, 5, 16, "Acesso Liberado");
    render_on_display(ssd, &frame_area);
}

void acesso_negado(void) {
    memset(ssd, 0, ssd1306_buffer_length);
    ssd1306_draw_string(ssd, 5, 16, "Acesso Negado");
    render_on_display(ssd, &frame_area);
}

void atualizar_display(const char *entrada) {
    memset(ssd, 0, ssd1306_buffer_length);
    if (strlen(entrada) == 0) {
        tela_inicial();  // reutiliza tela inicial
    } else {
        ssd1306_draw_string(ssd, 16, 30, entrada);
        render_on_display(ssd, &frame_area);
    }
}
