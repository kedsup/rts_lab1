#ifndef SIGNAL_H
#define SIGNAL_H

#include <chrono>
#include <span>
#include <vector>

using ulong = unsigned long;

std::vector<double>
generate_signal(ulong harm, ulong freq, ulong inter, double dt);

template<class Fn> long measure(Fn f) {
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;
    using std::chrono::nanoseconds;

    auto start = high_resolution_clock::now();
    f();
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<nanoseconds>(end - start);
    return elapsed.count();
}

namespace params {
constexpr ulong harm = 14;
constexpr ulong freq = 1700;
constexpr ulong inter = 64;
constexpr double dt = 1.0;
} // namespace params

double correlation(std::span<const double> a, std::span<const double> b);

#endif // SIGNAL_H
