#define _USE_MATH_DEFINES
#include <cmath>
#include <complex>
#include <vector>
#include "signals.hpp"
#include <matplot/matplot.h>

std::vector<double> generate_sin(double frequency, double amplitude, double phase, double sampling_rate, int samples) {
    std::vector<double> signal(samples);
    for (int i = 0; i < samples; ++i) {
        double t = i / sampling_rate;
        signal[i] = amplitude * std::sin(2 * M_PI * frequency * t + phase);
    }
    return signal;
}

std::vector<double> generate_cos(double frequency, double amplitude, double phase, double sampling_rate, int samples) {
    std::vector<double> signal(samples);
    for (int i = 0; i < samples; ++i) {
        double t = i / sampling_rate;
        signal[i] = amplitude * std::cos(2 * M_PI * frequency * t + phase);
    }
    return signal;
}

std::vector<double> generate_square(double frequency, double amplitude, double sampling_rate, int samples) {
    std::vector<double> signal(samples);
    for (int i = 0; i < samples; ++i) {
        double t = i / sampling_rate;
        signal[i] = (std::fmod(frequency * t, 1.0) < 0.5) ? amplitude : -amplitude;
    }
    return signal;
}

std::vector<double> generate_sawtooth(double frequency, double amplitude, double sampling_rate, int samples) {
    std::vector<double> signal(samples);
    for (int i = 0; i < samples; ++i) {
        double t = i / sampling_rate;
        signal[i] = 2 * amplitude * (t * frequency - std::floor(t * frequency + 0.5));
    }
    return signal;
}

std::vector<std::complex<double>> dft(const std::vector<double>& signal) {
    size_t N = signal.size();
    std::vector<std::complex<double>> result(N);
    for (size_t k = 0; k < N; ++k) {
        std::complex<double> sum(0.0, 0.0);
        for (size_t n = 0; n < N; ++n) {
            double angle = -2 * M_PI * k * n / N;
            sum += signal[n] * std::exp(std::complex<double>(0.0, angle));
        }
        result[k] = sum;
    }
    return result;
}

std::vector<double> idft(const std::vector<std::complex<double>>& spectrum) {
    size_t N = spectrum.size();
    std::vector<double> result(N);
    for (size_t n = 0; n < N; ++n) {
        std::complex<double> sum(0.0, 0.0);
        for (size_t k = 0; k < N; ++k) {
            double angle = 2 * M_PI * k * n / N;
            sum += spectrum[k] * std::exp(std::complex<double>(0.0, angle));
        }
        result[n] = sum.real() / N;
    }
    return result;
}

void plot_signal(const std::vector<double>& signal) {
    using namespace matplot;
    std::vector<double> x(signal.size());
    for (size_t i = 0; i < signal.size(); ++i)
        x[i] = static_cast<double>(i);

    plot(x, signal);
    title("Signal Visualization");
    xlabel("Sample");
    ylabel("Amplitude");
    show();
}