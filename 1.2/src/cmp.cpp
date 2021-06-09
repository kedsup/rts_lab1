#include "signal.h"
#include <iostream>

using namespace params;

constexpr ulong upper_bound = 2 << 25;
constexpr ulong sample_number = 100;

int main() {
  std::cout << "# n\tdiff\tsame\n";
  for (ulong i = 1; i < upper_bound; i *= 2) {
    long diff_ns = 0;
    long same_ns = 0;
    for (ulong j = 0; j < sample_number; j++) {
      auto sig1 = generate_signal(harm, freq, inter, dt);
      auto sig2 = generate_signal(harm, freq, inter, dt);
      diff_ns += measure([&sig1, &sig2]() { correlation(sig1, sig2); });
      same_ns += measure([&sig1]() { correlation(sig1, sig1); });
    }
    std::cout << i << '\t' << (diff_ns / sample_number) << '\n';
    std::cerr << i << '\t' << (same_ns / sample_number) << '\n';
  }
}
