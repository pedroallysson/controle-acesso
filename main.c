#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include <ctype.h>
#include "pico/binary_info.h"
#include "include/teclado.h"
#include "include/display.h"
#include "include/buzzer.h"
#include "include/led.h" 


char matricula[] = "1234";

int main()
{
    stdio_init_all();
    
    // Chamada para inicialização de pinos e periféricos
    init_teclado();
    init_display_oled();
    init_buzzer();
    init_leds();
    tela_inicial();
    
    char input_string[16] = {0};

    while (true) {
        char key = leitura_teclado();
        if (key != '\0') {
            int length = strlen(input_string);

            if (key == '*') {
                if (length > 0)
                    input_string[length - 1] = '\0';

            } else if (key == '#') {
                if (strcmp(input_string, matricula) == 0){
                    acesso_liberado();
                    led_green_on();
                    buzzer(1800, 800);
                    led_green_off();
                    
                }else{
                    acesso_negado();
                    led_red_on();
                    buzzer(250, 300);
                    sleep_ms(100);
                    buzzer(250, 800);
                    led_red_off();
                }
                memset(input_string, 0, sizeof(input_string));
                tela_inicial();

            } else if (length < sizeof(input_string) - 1) {
                input_string[length] = key;
                input_string[length + 1] = '\0';
            }

            atualizar_display(input_string);
            printf("Tecla pressionada: %c\n", key);
            sleep_ms(200);
        }
    }

    return 0;
}