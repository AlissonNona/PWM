#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_PIN 12

// Configurações PWM para 50Hz
const uint32_t WRAP_VALUE = 62499;
const float CLK_DIV = 40.0f;

void set_servo_position(uint pulse_width_us) {
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    uint channel = pwm_gpio_to_channel(SERVO_PIN);
    uint16_t level = (uint16_t)((pulse_width_us * (WRAP_VALUE + 1)) / 20000);
    pwm_set_chan_level(slice_num, channel, level);
}

int main() {
    stdio_init_all();
    
    // Configuração PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, CLK_DIV);
    pwm_config_set_wrap(&config, WRAP_VALUE);
    pwm_init(slice_num, &config, true);

    // Configuração LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(true) {
        // Requisito 2: 180° por 5s
        set_servo_position(2400);
        gpio_put(LED_PIN, 1);
        sleep_ms(5000);

        // Requisito 3: 90° por 5s
        set_servo_position(1470);
        gpio_put(LED_PIN, 0);
        sleep_ms(5000);

        // Requisito 4: 0° por 5s
        set_servo_position(500);
        gpio_put(LED_PIN, 1);
        sleep_ms(5000);

        // Requisito 5: Movimento suave
        uint16_t pulse = 500;
        int8_t step = 5;
        while(true) {
            pulse += step;
            if(pulse >= 2400 || pulse <= 500) step = -step;
            set_servo_position(pulse);
            gpio_put(LED_PIN, (pulse % 200) < 100); // Efeito de pulsação
            sleep_ms(10);
        }
    }
}