#include "signal.h"

#include <iostream>

using namespace params;

int main() {
    auto signal = generate_signal(harm, freq, inter, dt);
    ulong i = 0;
    std::cout << "# t\tX(t)\n";
    for (auto s : signal) {
        std::cout << static_cast<double>(i) * dt << "\t" << s << '\n';
        i++;
    }
}
