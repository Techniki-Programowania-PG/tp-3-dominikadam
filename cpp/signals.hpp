#ifndef SIGNALS_HPP
#define SIGNALS_HPP

#include <vector>
#include <complex>

std::vector<double> generate_sin(double frequency, double amplitude, double phase, double sampling_rate, int samples);
std::vector<double> generate_cos(double frequency, double amplitude, double phase, double sampling_rate, int samples);
std::vector<double> generate_square(double frequency, double amplitude, double sampling_rate, int samples);
std::vector<double> generate_sawtooth(double frequency, double amplitude, double sampling_rate, int samples);

std::vector<std::complex<double>> dft(const std::vector<double>& signal);
std::vector<double> idft(const std::vector<std::complex<double>>& spectrum);

void plot_signal(const std::vector<double>& signal);

#endif
