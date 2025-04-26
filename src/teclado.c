#include "pico/stdlib.h"
#include "include/teclado.h"

// Definições dos pinos
const uint8_t LINHAS[4] = {16, 17, 18, 19};
const uint8_t COLUNAS[4] = {4, 8, 9, 20};
 

// Função de inicialização dos pinos Gpios do teclado
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