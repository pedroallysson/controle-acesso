#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pico/binary_info.h"
#include "inc/ssd1306.h"
#include "hardware/i2c.h"
#include "hardware/pwm.h"
#include "bibliotecas/pinos.h" 
#include "bibliotecas/funcoes.h" 


char matricula[] = "1234";

char teclas[4][4] = {
    {'*', '2', '3', 'A'},
    {'1', '5', '6', 'B'},
    {'4', '8', '9', 'C'},
    {'7', '0', '#', 'D'}};

char leitura_teclado()
{
    for (int row = 0; row < 4; row++)
    {
        gpio_put(LINHAS[row], 1);
        for (int col = 0; col < 4; col++)
        {
            if (gpio_get(COLUNAS[col]))
            {
                gpio_put(LINHAS[row], 0);
                return teclas[row][col];
            }
        }
        gpio_put(LINHAS[row], 0);
    }
    return '\0';
}

int main()
{
    stdio_init_all();
    
    // Chamada para inicialização de pinos e periféricos
    init_teclado();
    init_display_oled();
    init_buzzer();
    init_leds();

    struct render_area frame_area = {
        start_column : 0,
        end_column : ssd1306_width - 1,
        start_page : 0,
        end_page : ssd1306_n_pages - 1
    };

    calculate_render_area_buffer_length(&frame_area);

    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);

    char *text[] = {
        "Digite sua ",
        "Matricula:      "};

    int y = 20;
    for (uint i = 0; i < count_of(text); i++)
    {
        ssd1306_draw_string(ssd, 16, y, text[i]);
        y += 12;
    }

    render_on_display(ssd, &frame_area);

    char input_string[16] = {0};

    while (true)
    {
        char key = leitura_teclado();
        if (key != '\0')
        {
            int length = strlen(input_string);

            if (key == '*')
            {
                if (length > 0) {
                    input_string[length - 1] = '\0';
                }
            }
            else if (key == '#')
            {
                memset(ssd, 0, ssd1306_buffer_length);
                if (strcmp(input_string, matricula) == 0)
                {
                    ssd1306_draw_string(ssd, 5, 16, "Acesso Liberado");
                    render_on_display(ssd, &frame_area);
                    gpio_put(LED_G, 1);
                    buzzer(1800, 800);
                    sleep_ms(1000);
                    gpio_put(LED_G, 0);
                }
                else
                {
                    ssd1306_draw_string(ssd, 5, 16, "Acesso Negado");
                    render_on_display(ssd, &frame_area);
                    gpio_put(LED_R, 1);
                    buzzer(250, 300);
                    sleep_ms(100);
                    buzzer(250, 800);
                    sleep_ms(1000);
                    gpio_put(LED_R, 0);
                }
                memset(ssd, 0, ssd1306_buffer_length);
                render_on_display(ssd, &frame_area);
                memset(input_string, 0, sizeof(input_string));
            }
            else if (length < sizeof(input_string) - 1)
            {
                input_string[length] = key;
                input_string[length + 1] = '\0';
            }

            memset(ssd, 0, ssd1306_buffer_length);
            if (strlen(input_string) == 0)
            {
                y = 20;
                for (uint i = 0; i < count_of(text); i++)
                {
                    ssd1306_draw_string(ssd, 16, y, text[i]);
                    y += 12;
                }
            }
            else
            {
                ssd1306_draw_string(ssd, 16, 30, input_string);
            }
            render_on_display(ssd, &frame_area);
            printf("Tecla pressionada: %c\n", key);
            sleep_ms(200);
        }
    }

    return 0;
}