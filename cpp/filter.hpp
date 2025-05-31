#pragma once
#include <vector>

std::vector<double> filter_1d(const std::vector<double>& signal, const std::vector<double>& kernel);
std::vector<std::vector<double>> filter_2d(const std::vector<std::vector<double>>& image, const std::vector<std::vector<double>>& kernel);
