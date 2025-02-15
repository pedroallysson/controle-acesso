#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "inc/ssd1306.h"
#include "./bibliotecas/pinos.h"

// Definições dos pinos
const uint I2C_SDA = 14;
const uint I2C_SCL = 15;
const uint8_t LINHAS[4] = {16, 17, 18, 19};
const uint8_t COLUNAS[4] = {4, 8, 9, 20};
const uint BUZZER = 10;
const uint LED_R = 13;
const uint LED_G = 11;
uint32_t clock_freq = 125000000;  

// Função de inicialização do teclado
void init_teclado()
{
    for (int i = 0; i < 4; i++)
    {
        gpio_init(LINHAS[i]);
        gpio_set_dir(LINHAS[i], GPIO_OUT);
        gpio_put(LINHAS[i], 0);
    }

    for (int i = 0; i < 4; i++)
    {
        gpio_init(COLUNAS[i]);
        gpio_set_dir(COLUNAS[i], GPIO_IN);
        gpio_pull_down(COLUNAS[i]);
    }
}

// Função de inicialização do display OLED
void init_display_oled()
{
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_init();
}

// Função de inicialização do buzzer
void init_buzzer()
{
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
}

// Função de inicialização dos LEDs
void init_leds()
{
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_pull_up(LED_R);
    gpio_pull_up(LED_G);
}
