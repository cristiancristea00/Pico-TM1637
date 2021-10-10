#include <pico/binary_info/code.h>
#include <pico/time.h>
#include "../TM1637.hpp"
#include <memory>

int main()
{

    constexpr auto DIO = 27;
    constexpr auto CLK = 28;
    auto * pio = pio0;

    bi_decl(bi_1pin_with_name(DIO, "[DIO] LED segments data pin"))
    bi_decl(bi_1pin_with_name(CLK, "[CLK] LED segments clock pin"))

    auto led_segments = std::make_unique<TM1637>(DIO, CLK, pio);

    static constexpr size_t PAUSE_MS = 5000;
    static constexpr size_t COUNT_STEP_MS = 100;

    for (int16_t i = 0; i <= 100; ++i)
    {
        led_segments->Display(i);
        sleep_ms(COUNT_STEP_MS);
    }

    sleep_ms(PAUSE_MS);

    for (int16_t i = 0; i <= 0x100; ++i)
    {
        led_segments->DisplayHex(i, true);
        sleep_ms(COUNT_STEP_MS);
    }

    sleep_ms(PAUSE_MS);

    led_segments->ColonOn();
    led_segments->DisplayLeft(15);
    led_segments->DisplayRight(45);
}

