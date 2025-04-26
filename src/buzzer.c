#include "pico/stdlib.h"
#include "./hardware/pwm.h"
#include <string.h>
#include <stdio.h>
#include "include/buzzer.h"

const uint BUZZER = 10;
uint32_t clock_freq = 125000000;  

// Função de inicialização do buzzer
void init_buzzer()
{
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);
    gpio_set_function(BUZZER, GPIO_FUNC_PWM);
}

// Função de som do buzzer
void buzzer(uint freq, uint timer)
{
    uint slice_num = pwm_gpio_to_slice_num(BUZZER);
    uint32_t divider = clock_freq / freq / 65536 + 1; 
    uint32_t top = clock_freq / (divider * freq);
    pwm_set_clkdiv(slice_num, divider); 
    pwm_set_wrap(slice_num, top - 1);
    pwm_set_gpio_level(BUZZER, top / 2);
    pwm_set_enabled(slice_num, true);
    sleep_ms(timer);
    pwm_set_enabled(slice_num, false);
}