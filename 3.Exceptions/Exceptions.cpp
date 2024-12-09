#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>
#include <string>

// Custom exception class
class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom exception occurred";
    }
};

// Demonstrates STL exception handling with out_of_range
void demonstrateSTLException() {
    try {
        std::vector<int> vec{1, 2, 3};
        std::cout << vec.at(5) << std::endl; // Throws std::out_of_range
    } catch (const std::out_of_range& e) {
        std::cout << "Caught an out_of_range error: " << e.what() << std::endl;
    }
}

// Demonstrates accessing deleted memory
void demonstrateUndefinedBehavior() {
    try {
        int* arr = new int[5];
        delete[] arr;
        std::cout << arr[10] << std::endl; // Accessing deleted memory
    } catch (const std::exception& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
}

// Demonstrates runtime error: Division by zero
void demonstrateRuntimeError() {
    try {
        int a = 10, b = 0;
        std::cout << a / b << std::endl; // Division by zero
    } catch (const std::runtime_error& e) {
        std::cout << "Caught a runtime error: " << e.what() << std::endl;
    }
}

// Demonstrates logic_error with out_of_range
void demonstrateLogicError() {
    try {
        std::string().at(1); // Accessing an empty string
    } catch (const std::logic_error& e) {
        std::cout << "Caught a logic error: " << e.what() << std::endl;
    }
}

// Demonstrates overflow and underflow
void demonstrateOverflowUnderflow() {
    try {
        int max = std::numeric_limits<int>::max();
        int result = max + 1; // Overflow
        std::cout << result << std::endl;
    } catch (const std::overflow_error& e) {
        std::cout << "Caught an overflow error: " << e.what() << std::endl;
    }

    try {
        int min = std::numeric_limits<int>::min();
        int result = min - 1; // Underflow
        std::cout << result << std::endl;
    } catch (const std::underflow_error& e) {
        std::cout << "Caught an underflow error: " << e.what() << std::endl;
    }
}

// Demonstrates exception hierarchy
void demonstrateExceptionHierarchy() {
    try {
        throw std::runtime_error("This is a runtime error");
    } catch (const std::runtime_error& e) {
        std::cout << "Caught a runtime error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught a general exception: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception" << std::endl;
    }
}

// Demonstrates throwing and catching custom exceptions
void demonstrateCustomException() {
    try {
        throw CustomException();
    } catch (const CustomException& e) {
        std::cout << "Caught a custom exception: " << e.what() << std::endl;
    }
}

// Demonstrates stack unwinding
void demonstrateStackUnwinding() {
    try {
        std::cout << "Before throwing exception" << std::endl;
        throw std::runtime_error("This is a runtime error");
        std::cout << "After throwing exception" << std::endl; // Not executed
    } catch (const std::runtime_error& e) {
        std::cout << "Caught a runtime error: " << e.what() << std::endl;
    }
}

// Demonstrates throwing and catching different types of exceptions
void demonstrateVariousThrows() {
    // Throwing a string
    try {
        throw std::string("This is a string exception");
    } catch (const std::string& e) {
        std::cout << "Caught a string exception: " << e << std::endl;
    }

    // Throwing an exception object
    try {
        throw std::runtime_error("This is a runtime error");
    } catch (const std::runtime_error& e) {
        std::cout << "Caught a runtime error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Demonstrating STL Exceptions:\n";
    demonstrateSTLException();

    std::cout << "\nDemonstrating Undefined Behavior:\n";
    demonstrateUndefinedBehavior();

    std::cout << "\nDemonstrating Runtime Errors:\n";
    demonstrateRuntimeError();

    std::cout << "\nDemonstrating Logic Errors:\n";
    demonstrateLogicError();

    std::cout << "\nDemonstrating Overflow and Underflow:\n";
    demonstrateOverflowUnderflow();

    std::cout << "\nDemonstrating Exception Hierarchy:\n";
    demonstrateExceptionHierarchy();

    std::cout << "\nDemonstrating Custom Exceptions:\n";
    demonstrateCustomException();

    std::cout << "\nDemonstrating Stack Unwinding:\n";
    demonstrateStackUnwinding();

    std::cout << "\nDemonstrating Various Throws:\n";
    demonstrateVariousThrows();

    return 0;
}
