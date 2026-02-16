#include <periphery/Led.h>

using g_OnboardLed = Led<GPIOD, GPIO15, RCC_GPIOD>;

inline void delay(volatile uint32_t cycles) {
    while (cycles--);
}

void init() {
    g_OnboardLed::init();
}

void update() {
    g_OnboardLed::toggle();
    delay(1'000'000);
}

[[noreturn]]
int main() {
    init();
    while (true) {
        update();
    }
}
