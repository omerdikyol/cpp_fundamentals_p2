#include <iostream>
#include <vector>
#include <algorithm>

// Function to print a vector
void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example vector
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};

    // Print the vector elements
    std::cout << "Vector elements: ";
    printVector(vec);

    // Using for_each to increment each element by 1 using a lambda function
    std::for_each(vec.begin(), vec.end(), [](int &n){ n++; });
    std::cout << "Vector after for_each increment: ";
    printVector(vec);

    // Using find_if to find the first element greater than 5 using a lambda function
    auto it = std::find_if(vec.begin(), vec.end(), [](int n){ return n > 5; });
    if (it != vec.end()) {
        std::cout << "First element greater than 5 is: " << *it << std::endl;
    } else {
        std::cout << "No element greater than 5 found." << std::endl;
    }

    // Sorting the vector
    std::sort(vec.begin(), vec.end());
    std::cout << "Sorted vector: ";
    printVector(vec);

    // Sorting the vector in descending order
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "Sorted vector in descending order: ";
    printVector(vec);

    // Searching for an element in the vector
    int target = 5;
    bool found = std::binary_search(vec.begin(), vec.end(), target);
    if (found) {
        std::cout << "Element " << target << " found in the vector." << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the vector." << std::endl;
    }

    return 0;
}