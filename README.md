# Controle de Servomotor com Raspberry Pi Pico W via PWM

Este projeto utiliza o módulo PWM do microcontrolador RP2040 para simular o controle do ângulo de um servomotor (utilizando o simulador Wokwi) com a ferramenta Pico SDK. Além disso, um LED RGB na GPIO 12 é empregado (via BitDogLab) para indicar visualmente a execução do código.

## Requisitos

- Raspberry Pi Pico W (simulado no Wokwi)
- Servo motor (micro servo padrão do Wokwi)
- LED RGB (GPIO 12) – para experimentos com BitDogLab
- Ambiente de desenvolvimento VS Code integrado ao Pico SDK
- Repositório GitHub para versionamento

## Funcionalidades

1. Configuração do PWM na GPIO 22 para 50 Hz (20 ms de período).
2. Envio de pulsos de 2.400 μs, 1.470 μs e 500 μs para posicionar o servo em 180°, 90° e 0°, respectivamente (com 5 s de espera em cada posição).
3. Rotina de varredura suave do servo entre 0° e 180° com incremento de 5 μs a cada 10 ms.
4. Indicação visual por meio do LED na GPIO 12.

## Compilação e Simulação

1. Configure o VS Code com o Pico SDK.
2. Importe o projeto e abra o código fonte (`main.c`).
3. Compile o projeto e, se necessário, faça upload para o simulador Wokwi.
4. Verifique a execução do código e a resposta do LED (via BitDogLab).

## Instruções de Uso

- Para testar os diferentes posicionamentos do servo, o código inicializa primeiro as posições fixas (180°, 90° e 0°) com pausas de 5 s.
- Em seguida, o servo realiza uma varredura contínua entre 0° e 180°.
- O LED na GPIO 12 alterna seu estado para indicar a atividade do sistema.

