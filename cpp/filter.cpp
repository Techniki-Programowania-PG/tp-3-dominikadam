// filter.cpp
#include "filter.hpp"
#include <vector>
#include <cstddef>

std::vector<double> filter_1d(const std::vector<double>& signal, const std::vector<double>& kernel) {
    int n = signal.size();
    int k = kernel.size();
    int half_k = k / 2;
    std::vector<double> output(n, 0.0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int idx = i + j - half_k;
            if (idx >= 0 && idx < n) {
                output[i] += signal[idx] * kernel[j];
            }
        }
    }
    return output;
}

std::vector<std::vector<double>> filter_2d(const std::vector<std::vector<double>>& image, const std::vector<std::vector<double>>& kernel) {
    int rows = image.size();
    int cols = image[0].size();
    int k_rows = kernel.size();
    int k_cols = kernel[0].size();
    int half_r = k_rows / 2;
    int half_c = k_cols / 2;

    std::vector<std::vector<double>> output(rows, std::vector<double>(cols, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int ki = 0; ki < k_rows; ++ki) {
                for (int kj = 0; kj < k_cols; ++kj) {
                    int ni = i + ki - half_r;
                    int nj = j + kj - half_c;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        output[i][j] += image[ni][nj] * kernel[ki][kj];
                    }
                }
            }
        }
    }
    return output;
}
