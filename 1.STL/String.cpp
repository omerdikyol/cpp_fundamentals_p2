#include <iostream>
#include <string>

int main() {
    // Creating strings
    std::string str1 = "Hello";
    std::string str2 = "World";
    std::string str3 = str1 + " " + str2; // Concatenation

    // Output the strings
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    // String length
    std::cout << "Length of str3: " << str3.length() << std::endl;

    // Accessing characters
    std::cout << "First character of str3: " << str3[0] << std::endl;

    // Substring
    std::string subStr = str3.substr(6, 5); // "World"
    std::cout << "Substring of str3: " << subStr << std::endl;

    // Find
    size_t pos = str3.find("World");
    if (pos != std::string::npos) {
        std::cout << "'World' found at position: " << pos << std::endl;
    } else {
        std::cout << "'World' not found" << std::endl;
    }

    // Replace
    str3.replace(6, 5, "C++");
    std::cout << "After replace: " << str3 << std::endl;

    // Erase
    str3.erase(5, 3); // Remove " C+"
    std::cout << "After erase: " << str3 << std::endl;

    // Insert
    str3.insert(5, " Beautiful");
    std::cout << "After insert: " << str3 << std::endl;

    return 0;
}