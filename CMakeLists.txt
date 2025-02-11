cmake_minimum_required(VERSION 3.13)

# Configurações básicas de compilação
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ====================================================================================
# Configuração do Pico SDK (seção modificada)
# ====================================================================================

# 1. Defina explicitamente o caminho do SDK
set(PICO_SDK_PATH "$ENV{USERPROFILE}/pico-sdk" CACHE STRING "Pico SDK path") 

# 2. Inclua o arquivo de importação do SDK
include("${PICO_SDK_PATH}/external/pico_sdk_import.cmake")

# 3. Configuração da placa
set(PICO_BOARD pico_w CACHE STRING "Board type")

# 4. Inicialização do SDK ANTES do projeto
pico_sdk_init()

project(servo-pwm-control C CXX ASM)

# ====================================================================================
# Configuração do executável
# ====================================================================================

add_executable(servo-pwm-control 
    servo-pwm-control.c
)

# Metadados do programa
pico_set_program_name(servo-pwm-control "Servo PWM Control")
pico_set_program_version(servo-pwm-control "1.0")

# Configurações de I/O
pico_enable_stdio_uart(servo-pwm-control 0)
pico_enable_stdio_usb(servo-pwm-control 0)

# ====================================================================================
# Bibliotecas necessárias (seção crítica modificada)
# ====================================================================================
target_link_libraries(servo-pwm-control
    pico_stdlib
    hardware_pwm       # Adicionado para acesso ao PWM
    hardware_gpio      # Necessário para controle GPIO
    hardware_irq       # Para manipulação de interrupções
)

# ====================================================================================
# Configurações finais
# ====================================================================================
pico_add_extra_outputs(servo-pwm-control)