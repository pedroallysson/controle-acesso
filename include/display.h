#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include "inc/ssd1306.h" // necessário para struct render_area

void init_display_oled(void);
void tela_inicial(void);
void acesso_liberado(void);
void acesso_negado(void);
void atualizar_display(const char *entrada);

#endif
