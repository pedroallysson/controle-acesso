#ifndef PINOS_H
#define PINOS_H

#include <stdint.h>

// Definições de pinos
extern const uint I2C_SDA;
extern const uint I2C_SCL;
extern const uint8_t LINHAS[4];
extern const uint8_t COLUNAS[4];
extern const uint BUZZER;
extern const uint LED_R;
extern const uint LED_G;

// Funções de inicialização
void init_teclado();
void init_display_oled();
void init_buzzer();
void init_leds();

#endif