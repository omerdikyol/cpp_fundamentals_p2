#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 1. Basic Lambda
    auto greet = []() {
        std::cout << "Hello, Lambda!" << std::endl;
    };
    greet(); // Outputs: Hello, Lambda!

    // 2. Lambda with Parameters
    auto add = [](int a, int b) {
        return a + b;
    };
    std::cout << "Sum: " << add(5, 10) << std::endl; // Outputs: Sum: 15

    // 3. Lambda with Capture by Value
    int x = 10, y = 20;
    auto sum = [x, y]() {
        return x + y;
    };
    std::cout << "Sum of captured variables (by value): " << sum() << std::endl; // Outputs: 30
    std::cout << "Original x value: " << x << std::endl; // Outputs: 10

    // 4. Lambda with Capture by Reference
    int total = 0;
    auto addToTotal = [&total](int n) {
        total += n;
    };
    addToTotal(5);
    addToTotal(15);
    std::cout << "Total (captured by reference): " << total << std::endl; // Outputs: 20

    // 5. Mixed Capture
    x = 10;
    int z = 5;
    auto mixedCapture = [x, &z]() {
        return x + (++z);
    };
    std::cout << "Mixed capture result: " << mixedCapture() << std::endl; // Outputs: 16
    std::cout << "Value of z after lambda: " << z << std::endl; // Outputs: 6

    // 6. Using Lambdas with STL Algorithms
    std::vector<int> nums = {4, 2, 5, 3, 1};

    // Sort in descending order
    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
    std::cout << "Sorted vector (descending): ";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    // Multiply each element by 2 using for_each
    std::for_each(nums.begin(), nums.end(), [](int& n) {
        n *= 2;
    });
    std::cout << "Vector after multiplying elements by 2: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    // 7. Generic Lambda (C++14)
    auto print = [](auto value) {
        std::cout << "Lambda Says: " << value << std::endl;
    };
    print(42);    // Outputs: 42
    print("Generic Lambda");  // Outputs: Generic Lambda

    // 8. Recursive Lambda (C++17)
    auto factorial = [](auto self, int n) -> int {
        return (n <= 1) ? 1 : n * self(self, n - 1);
    };
    std::cout << "Factorial of 5: " << factorial(factorial, 5) << std::endl; // Outputs: 120

    return 0;
}
