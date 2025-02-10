# Projeto RP2040 Serial

## Descrição
Este projeto tem como objetivo explorar a comunicação serial no microcontrolador RP2040 utilizando a placa de desenvolvimento BitDogLab. Ele inclui a manipulação de LEDs, leitura de botões com interrupções e a comunicação via UART.

## Funcionalidades
- Controle de LED RGB utilizando os botões A e B.
- Envio de mensagens ao Serial Monitor para indicar o estado dos LEDs.
- Implementação de interrupções para os botões, garantindo uma resposta rápida e precisa.
- Comunicação via UART para entrada e saída de dados.

## Hardware Utilizado
- **Placa BitDogLab** com RP2040.
- **Matriz 5x5 de LEDs WS2812** conectada à GPIO 7.
- **LED RGB** conectado às GPIOs 11, 12 e 13.
- **Botão A** conectado à GPIO 5.
- **Botão B** conectado à GPIO 6.
- **Comunicação UART** via pinos GPIO 0 e GPIO 1.

## Requisitos Técnicos
- Utilização do SDK oficial do Raspberry Pi RP2040.
- Implementação de interrupções para os botões.
- Debounce via software.
- Organização e clareza do código.

## Problema Encontrado
Durante o desenvolvimento, houve dificuldades na implementação da biblioteca `font.h`. Como resultado, a funcionalidade de exibição de caracteres foi descontinuada nesta versão. A avaliação do projeto será feita considerando essa limitação, e futuras versões podem incluir essa funcionalidade corrigida.

## Observações
- A comunicação I2C não está disponível no BitDogLab, portanto foi substituída pela UART.
- As funcionalidades foram ajustadas para se adequarem às capacidades do hardware.

## Execução
Compilar e carregar o código na placa RP2040 utilizando o SDK oficial do Raspberry Pi.
