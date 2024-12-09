#include <iostream>
#include <ctime>
#include <complex>
#include <vector>
#include <random>
#include <regex>
#include <cmath>

int main() {
    // Date and Time
    std::time_t now = std::time(nullptr);
    std::cout << "Current time: " << std::ctime(&now);

    // Complex numbers
    std::complex<double> complex1(1.0, 2.0);
    std::complex<double> complex2(3.0, 4.0);
    std::complex<double> complexSum = complex1 + complex2;
    std::cout << "Sum of complex numbers: " << complexSum << std::endl;

    // Matrix math (using a simple 2x2 matrix example)
    std::vector<std::vector<int>> matrix1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> matrix2 = {{5, 6}, {7, 8}};
    std::vector<std::vector<int>> matrixSum(2, std::vector<int>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    std::cout << "Sum of matrices: " << std::endl;
    for (const auto& row : matrixSum) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    std::cout << "Random number: " << dis(gen) << std::endl;

    // Regular expressions
    std::string text = "The quick brown fox jumps over the lazy dog.";
    std::regex word_regex("(\\b\\w+\\b)");
    auto words_begin = std::sregex_iterator(text.begin(), text.end(), word_regex);
    auto words_end = std::sregex_iterator();
    std::cout << "Words in the text: ";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::cout << (*i).str() << " ";
    }
    std::cout << std::endl;

    // cmath
    double number = 9.0;
    std::cout << "Square root of " << number << " is " << std::sqrt(number) << std::endl;

    return 0;
}