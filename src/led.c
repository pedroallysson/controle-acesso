#include "pico/stdlib.h"

const uint LED_R = 13;
const uint LED_G = 11;

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

void led_red_on(){
    gpio_put(LED_R, 1);
}

void led_red_off(){
    gpio_put(LED_R, 0);
}

void led_green_on(){
    gpio_put(LED_G, 1);
};

void led_green_off(){
    gpio_put(LED_G, 0);
};