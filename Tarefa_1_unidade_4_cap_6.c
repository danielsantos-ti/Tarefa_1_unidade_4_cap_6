#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "pico/time.h"

#define LED_RGB_VERMELHO 11
#define LED_RGB_VERDE 12
#define LED_RGB_AZUL 13

#define BOTAO_A 5
#define BOTAO_B 6

#define MATRIZ_LED_PINO 7
#define TAMANHO_MATRIZ_LED 25

#define UART_ID uart0
#define PINO_TX 0
#define PINO_RX 1

volatile bool alternar_verde = false;
volatile bool alternar_azul = false;

void tratarBotaoA(uint gpio, uint32_t eventos) {
    alternar_verde = !alternar_verde;
}

void tratarBotaoB(uint gpio, uint32_t eventos) {
    alternar_azul = !alternar_azul;
}

void configurar() {
    stdio_init_all();
    
    gpio_init(LED_RGB_VERMELHO);
    gpio_set_dir(LED_RGB_VERMELHO, GPIO_OUT);
    gpio_init(LED_RGB_VERDE);
    gpio_set_dir(LED_RGB_VERDE, GPIO_OUT);
    gpio_init(LED_RGB_AZUL);
    gpio_set_dir(LED_RGB_AZUL, GPIO_OUT);
    
    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);
    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &tratarBotaoA);
    
    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B, GPIO_IN);
    gpio_pull_up(BOTAO_B);
    gpio_set_irq_enabled_with_callback(BOTAO_B, GPIO_IRQ_EDGE_FALL, true, &tratarBotaoB);
    
    uart_init(UART_ID, 115200);
    gpio_set_function(PINO_TX, GPIO_FUNC_UART);
    gpio_set_function(PINO_RX, GPIO_FUNC_UART);
    
    printf("Configuração concluída\n");
}

void loop() {
    if (alternar_verde) {
        gpio_put(LED_RGB_VERDE, 1);
        printf("LED Verde Ligado\n");
    } else {
        gpio_put(LED_RGB_VERDE, 0);
        printf("LED Verde Desligado\n");
    }
    
    if (alternar_azul) {
        gpio_put(LED_RGB_AZUL, 1);
        printf("LED Azul Ligado\n");
    } else {
        gpio_put(LED_RGB_AZUL, 0);
        printf("LED Azul Desligado\n");
    }
    
    sleep_ms(100);
}

int main() {
    configurar();
    while (1) {
        loop();
    }
}
