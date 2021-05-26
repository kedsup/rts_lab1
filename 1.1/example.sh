#!/bin/bash

echo "Building the project.."
cd build
cmake ..
make

echo "Generating data..."
cd ..
mkdir -p example
build/signal > example/signal.dat &
build/measure > example/measure.dat &
build/correlation > example/correlation.dat &
build/auto_correlation > example/auto_correlation.dat &
build/measure_corr > example/measure_corr.dat &
wait

echo "Plotting charts..."
cd example
../plot.sh signal.dat "linespoints pointtype 7" "t" "X(t)" signal.png
../plot.sh measure.dat "linespoints pointtype 7" "n" "O(n)" measure.png
../plot.sh measure_corr.dat "linespoints pointtype 7" "n" "O(n)" measure_corr.png
../plot.sh correlation.dat "linespoints pointtype 7" "tau" "corr(tau)" correlation.png
../plot.sh auto_correlation.dat "linespoints pointtype 7" "tau" "corr(tau)" auto_correlation.png

echo -e "\x1b[32mSuccess. All files are located in the example directory.\x1b[m"
