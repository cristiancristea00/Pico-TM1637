#include <pico/binary_info/code.h>
#include "../TM1637.hpp"
#include <memory>
#include <pico/time.h>

int main()
{

    constexpr auto DIO = 27;
    constexpr auto CLK = 28;
    auto * pio = pio0;

    bi_decl(bi_1pin_with_name(DIO, "[DIO] Scoreboard data pin"))
    bi_decl(bi_1pin_with_name(CLK, "[CLK] Scoreboard clock pin"))

    auto led_segments = std::make_unique<TM1637>(DIO, CLK, pio);
    led_segments->Display(-612, false, true);
}

