#include "corr_common.h"
#include "signal.h"
#include <iostream>

using namespace params;

int main() {
    auto sig1 = generate_signal(harm, freq, inter, dt);
    print_correlation(sig1, sig1);
}
