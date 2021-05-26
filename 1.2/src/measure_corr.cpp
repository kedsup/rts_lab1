#include "signal.h"

#include <iostream>

constexpr ulong low = 2;
constexpr ulong hi = 2 << 20;
constexpr ulong step = 2;

using namespace params;

int main() {
    std::cout << "# n\tO(n)\n";
    const auto signal = generate_signal(harm, freq, hi, dt);
    for (auto size = low; size < hi; size *= step) {
        auto dur = measure([size, &signal]() {
            auto a = std::span(signal).first(size);
            correlation(a, a);
        });
        std::cout << size << '\t' << dur << std::endl;
    }
}
