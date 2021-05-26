#ifndef CORR_COMMON_H
#define CORR_COMMON_H

#include "signal.h"

#include <iostream>
#include <span>
#include <vector>

using namespace params;

void print_correlation(const std::vector<double>& sig1,
                       const std::vector<double>& sig2) {

    auto mid = sig1.size() / 2;
    auto a = std::span(sig1).first(mid);
    std::cout << "# tau\tcorrelation\n";
    for (ulong i = 0; i < mid; i++) {
        auto b = std::span(sig2).subspan(i, mid);
        auto corr = correlation(a, b);
        std::cout << i << '\t' << corr << '\n';
    }
}

#endif // CORR_COMMON_H
