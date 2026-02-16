#pragma once

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

//TODO: mb rename this to Togglable or smth like that, cuz the logic is not LED specific
template<uint32_t PORT, uint16_t PIN, rcc_periph_clken RCC_PORT>
class Led {
public:
    static void init() {
        rcc_periph_clock_enable(RCC_PORT);
        gpio_mode_setup(PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN);
    }

    static void on() {
        gpio_set(PORT, PIN);
    }

    static void off() {
        gpio_clear(PORT, PIN);
    }

    static void toggle() {
        gpio_toggle(PORT, PIN);
    }
};
