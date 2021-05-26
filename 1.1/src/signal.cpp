#include "signal.h"

#include <algorithm>
#include <bits/c++config.h>
#include <random>

std::vector<double>
generate_signal(ulong harm, ulong freq, ulong inter, double dt) {
    std::random_device r;
    std::default_random_engine rng(r());
    std::uniform_real_distribution<double> dist;
    std::vector<double> signal(inter, 0.0);
    const auto dw = static_cast<double>(freq) / static_cast<double>(harm);
    auto w = dw;
    for (ulong h = 0; h < harm; h++) {
        const auto a = dist(rng);
        const auto phi = dist(rng);
        for (ulong t = 0; t < inter; t++) {
            const auto x = a * std::sin(w * static_cast<double>(t) * dt + phi);
            signal[t] += x;
        }
        w += dw;
    }

    return signal;
}

static double average(std::span<const double> a) {
    return std::accumulate(a.begin(), a.end(), 0.0) / a.size();
}

double correlation(std::span<const double> a, std::span<const double> b) {
    auto ma = average(a);
    auto mb = average(b);
    double sum = 0.0;
    for (std::size_t i = 0; i < a.size(); i++) {
        sum += (a[i] - ma) * (b[i] - mb);
    }
    return sum / a.size();
}
