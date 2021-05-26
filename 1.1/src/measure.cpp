#include "signal.h"

#include <iostream>

constexpr ulong harm_low = 2;
constexpr ulong harm_hi = 2 << 18;
constexpr ulong harm_step = 2;

int main() {
    std::cout << "# n\tO(n)\n";
    for (auto harm = harm_low; harm < harm_hi; harm *= harm_step) {
        auto dur = measure([harm]() {
            generate_signal(harm, params::freq, params::inter, params::dt);
        });
        std::cout << harm << '\t' << dur << '\n';
    }
}
