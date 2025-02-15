# Embarcatech - Controle de Acesso

## Descrição

O **Sistema de Controle de Acesso** foi desenvolvido como projeto final do **EmbarcaTech** e tem como principal objetivo garantir a segurança de ambientes, através da verificação de matrículas previamente cadastradas para autorizar o acesso. 

Quando o sistema identifica a matrícula correta, o acesso é **autorizado**, acionando um LED verde e emitindo um som (buzzer) como sinal. Caso a matrícula seja **inválida**, um LED vermelho é acionado, acompanhado de um som de alerta e a exibição de uma mensagem no display OLED, indicando o erro. 

Esse sistema também foi projetado com acessibilidade em mente, utilizando o som do buzzer e o alerta luminoso do LED para facilitar o acesso de pessoas com deficiência visual ou auditiva.

## Funcionalidades

- **Verificação de Matrícula:** O sistema verifica se a matrícula inserida corresponde a um valor previamente cadastrado.
- **Acesso Autorizado:** Se a matrícula for válida, o sistema autoriza o acesso e acende um LED verde.
- **Acesso Negado:** Se a matrícula for inválida, o sistema exibe uma mensagem de erro no display OLED, acende um LED vermelho e emite um som de alerta.
- **Acessibilidade:** Sons (buzzer) e alertas luminosos (LEDs) são usados para fornecer feedback para deficientes visuais.

## Componentes Utilizados

- **Teclado Matricial (4x4)**
- **Placa de Desenvolvimento BitDogLab**

## Bibliotecas Necessárias

Para o funcionamento adequado do software, as seguintes bibliotecas são necessárias:

- `#include <stdio.h>`
- `#include "pico/stdlib.h"`
- `#include <string.h>`
- `#include <stdlib.h>`
- `#include <ctype.h>`
- `#include "pico/binary_info.h"`
- `#include "inc/ssd1306.h"`
- `#include "hardware/i2c.h"`
- `#include "hardware/pwm.h"`

## Funcionalidade do Sistema

1. **Captura da Matrícula:** O usuário insere sua matrícula no teclado matricial.
2. **Validação da Matrícula:** A matrícula inserida é comparada com a matrícula previamente cadastrada.
   - Se a matrícula for válida, o sistema libera o acesso, acionando um LED verde, emitindo um som de sucesso e exibindo a mensagem "Acesso Liberado" no display OLED.
   - Se a matrícula for inválida, o sistema negará o acesso, acionando um LED vermelho, emitindo um som de erro e exibindo a mensagem "Mat. Invalida" no display OLED.
3. **Acessibilidade:** O buzzer emite sons que ajudam deficientes visuais a perceber o status do sistema (sucesso ou erro).


## Componentes Necessários

- Raspberry Pi Pico W 
- Teclado Matricial
- Display Oled 0.96 polegadas I2C 128x64
- Led RGB SMD5050
- Buzzers

**Desenvolvido por Pedro Alysson durante o projeto EmbarcaTech.**
