#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <set>

// A simple class representing a person
class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Getters and setters
    std::string getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    // Overloaded comparison operators for sorting
    bool operator<(const Person& other) const {
        return age < other.age;
    }

private:
    std::string name;
    int age;
};

int vectorExamples() {
    // Vector: A dynamic array that can grow and shrink in size
    // #include <vector>

    // Create a vector of integers
    std::vector<int> numbers;

    // Add some elements to the vector
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);

    // Access and modify elements
    numbers[0] = 10;
    numbers[1] = 20;

    // Iterate using iterators
    std::cout << "Vector elements using iterators: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) { // auto is a placeholder for the type of the iterator
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Iterate using reverse iterators
    std::cout << "Vector elements in reverse: ";
    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) { // auto does not mean that the type is unknown, it means that the type is deduced from the initializer
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Create a vector of Person objects
    std::vector<Person> people;

    // Add some Person objects to the vector
    people.push_back(Person("Alice", 30));
    people.push_back(Person("Bob", 25));
    people.push_back(Person("Charlie", 35));
    
    Person jane = Person("Jane", 22);
    people.push_back(jane);

    // Remove the last element
    people.pop_back();

    // Insert an element at a specific position
    people.insert(people.begin() + 1, Person("Dave", 28));

    // Erase an element at a specific position
    people.erase(people.begin() + 2);

    // Use the emplace_back method to construct elements in place
    people.emplace_back("Eve", 40);

    // Display the elements of the vector
    std::cout << "People vector elements: ";
    for (const Person& person : people) {
        std::cout << person.getName() << " (" << person.getAge() << ") ";
    }
    std::cout << std::endl;

    // Check if the vector is empty
    if (people.empty()) {
        std::cout << "The people vector is empty." << std::endl;
    } else {
        std::cout << "The people vector is not empty." << std::endl;
    }

    // Get the size of the vector
    std::cout << "The size of the people vector is: " << people.size() << std::endl;

    // Reserve space for elements
    people.reserve(10);
    std::cout << "The capacity of the people vector after reserving space is: " << people.capacity() << std::endl;

    // Shrink the capacity to fit the size
    people.shrink_to_fit();
    std::cout << "The capacity of the people vector after shrinking to fit is: " << people.capacity() << std::endl;

    // Accessing elements using at() method
    try {
        std::cout << "First person: " << people.at(0).getName() << " (" << people.at(0).getAge() << ")" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;
    }

    // Using front() and back() methods
    if (!people.empty()) {
        std::cout << "First person using front(): " << people.front().getName() << " (" << people.front().getAge() << ")" << std::endl;
        std::cout << "Last person using back(): " << people.back().getName() << " (" << people.back().getAge() << ")" << std::endl;
    }

    // Using data() method to get a pointer to the underlying array
    Person* data = people.data();
    if (data != nullptr) {
        std::cout << "First person using data(): " << data->getName() << " (" << data->getAge() << ")" << std::endl;
    }

    // Using the swap() method to swap contents of two vectors
    std::vector<Person> otherPeople;
    otherPeople.push_back(Person("Frank", 50));
    otherPeople.push_back(Person("Grace", 45));

    std::cout << "Before swap:" << std::endl;
    std::cout << "People vector size: " << people.size() << std::endl;
    std::cout << "OtherPeople vector size: " << otherPeople.size() << std::endl;

    people.swap(otherPeople);

    std::cout << "After swap:" << std::endl;
    std::cout << "People vector size: " << people.size() << std::endl;
    std::cout << "OtherPeople vector size: " << otherPeople.size() << std::endl;

    // Using the assign() method to assign new contents to the vector
    people.assign(3, Person("Hank", 60));
    std::cout << "People vector after assign: ";
    for (const Person& person : people) {
        std::cout << person.getName() << " (" << person.getAge() << ") ";
    }
    std::cout << std::endl;
    
    // Clear all elements from the vector
    people.clear();

    return 0;
};

int mapExamples() {
    // Map: An associative container that stores key-value pairs
    // #include <map>

    // Create a map of string to int
    std::map<std::string, int> ageMap;

    // Add some elements to the map
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;

    // Display the elements of the map
    std::cout << "Map elements: ";
    for (const auto& pair : ageMap) {
        std::cout << pair.first << " (" << pair.second << ") ";
    }
    std::cout << std::endl;

    // Iterate using iterators
    std::cout << "Map elements using iterators: ";
    for (auto it = ageMap.begin(); it != ageMap.end(); ++it) {
        std::cout << it->first << " (" << it->second << ") ";
    }

    // Access and modify elements
    ageMap["Alice"] = 31;
    ageMap["Bob"] = 26;

    // Check if a key exists
    if (ageMap.find("Charlie") != ageMap.end()) {
        std::cout << "Charlie is in the map." << std::endl;
    } else {
        std::cout << "Charlie is not in the map." << std::endl;
    }

    auto found = ageMap.find("Charlie");
    if (found != ageMap.end()) {
        std::cout << "Charlie's age is: " << found->second << std::endl;
    }

    // Remove an element by key
    ageMap.erase("Charlie");

    // Insert an element
    ageMap.insert(std::make_pair("Dave", 28));

    // Use the emplace method to construct elements in place
    ageMap.emplace("Eve", 40);

    // Check if the map is empty
    if (ageMap.empty()) {
        std::cout << "The ageMap is empty." << std::endl;
    } else {
        std::cout << "The ageMap is not empty." << std::endl;
    }

    // Get the size of the map
    std::cout << "The size of the ageMap is: " << ageMap.size() << std::endl;

    // Clear all elements from the map
    ageMap.clear();

    return 0;
};

int listExamples() {
    // List: A doubly linked list that allows fast insertion and deletion of elements
    // #include <list>

    // Faster insertion and deletion compared to vectors
    // Slower random access compared to vectors

    // Create a list of integers
    std::list<int> numberList;

    // Add some elements to the list
    numberList.push_back(1);
    numberList.push_back(2);
    numberList.push_back(3);
    numberList.push_back(4);
    numberList.push_back(5);

    // Display the elements of the list
    std::cout << "List elements: ";
    for (int number : numberList) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Access and modify elements
    auto it = numberList.begin();
    std::advance(it, 1); // Move iterator to the second element
    *it = 20;

    // Iterate using iterators
    std::cout << "List elements using iterators: ";
    for (auto it = numberList.begin(); it != numberList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Iterate using reverse iterators
    std::cout << "List elements in reverse: ";
    for (auto rit = numberList.rbegin(); rit != numberList.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Create a list of Person objects
    std::list<Person> personList;

    // Add some Person objects to the list
    personList.push_back(Person("Alice", 30));
    personList.push_back(Person("Bob", 25));
    personList.push_back(Person("Charlie", 35));

    // Display the elements of the list
    std::cout << "Person list elements: ";
    for (const Person& person : personList) {
        std::cout << person.getName() << " (" << person.getAge() << ") ";
    }
    std::cout << std::endl;

    // Remove the last element
    personList.pop_back();

    // Insert an element at a specific position
    auto personIt = personList.begin();
    std::advance(personIt, 1);
    personList.insert(personIt, Person("Dave", 28));

    // Erase an element at a specific position
    personIt = personList.begin();
    std::advance(personIt, 1);
    personList.erase(personIt);

    // Use the emplace_back method to construct elements in place
    personList.emplace_back("Eve", 40);

    // Check if the list is empty
    if (personList.empty()) {
        std::cout << "The person list is empty." << std::endl;
    } else {
        std::cout << "The person list is not empty." << std::endl;
    }

    // Get the size of the list
    std::cout << "The size of the person list is: " << personList.size() << std::endl;

    // Clear all elements from the list
    personList.clear();
    
    return 0;
};

int queueExamples() {
    // Queue: A FIFO (First-In-First-Out) data structure
    // #include <queue>

    // Create a queue of integers
    std::queue<int> numberQueue;

    // Add some elements to the queue
    numberQueue.push(1);
    numberQueue.push(2);
    numberQueue.push(3);
    numberQueue.push(4);
    numberQueue.push(5);

    // Display the elements of the queue
    std::cout << "Queue elements: ";
    while (!numberQueue.empty()) {
        std::cout << numberQueue.front() << " ";
        numberQueue.pop();
    }
    std::cout << std::endl;

    // Create a queue of Person objects
    std::queue<Person> personQueue;

    // Add some Person objects to the queue
    personQueue.push(Person("Alice", 30));
    personQueue.push(Person("Bob", 25));
    personQueue.push(Person("Charlie", 35));

    // Display the elements of the queue
    std::cout << "Person queue elements: ";
    while (!personQueue.empty()) {
        const Person& person = personQueue.front();
        std::cout << person.getName() << " (" << person.getAge() << ") ";
        personQueue.pop();
    }
    std::cout << std::endl;

    return 0;
};

int setExamples() {
    // Set: An associative container that contains a sorted set of unique objects
    // #include <set>

    // Create a set of integers
    std::set<int> numberSet;

    // Add some elements to the set
    numberSet.insert(1);
    numberSet.insert(2);
    numberSet.insert(4);
    numberSet.insert(5);
    numberSet.insert(3);

    // Display the elements of the set
    std::cout << "Set elements: ";
    for (int number : numberSet) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Access and modify elements
    numberSet.erase(3); // Remove element with value 3

    // Iterate using iterators
    std::cout << "Set elements using iterators: ";
    for (auto it = numberSet.begin(); it != numberSet.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Check if an element exists
    if (numberSet.find(2) != numberSet.end()) {
        std::cout << "Element 2 is in the set." << std::endl;
    } else {
        std::cout << "Element 2 is not in the set." << std::endl;
    }

    // Create a set of Person objects
    std::set<Person> personSet;

    // Add some Person objects to the set
    personSet.insert(Person("Alice", 30));
    personSet.insert(Person("Bob", 25));
    personSet.insert(Person("Charlie", 35));

    // Display the elements of the set
    std::cout << "Person set elements: ";
    for (const Person& person : personSet) {
        std::cout << person.getName() << " (" << person.getAge() << ") ";
    }
    std::cout << std::endl;

    // Remove an element
    personSet.erase(Person("Alice", 30));

    // Check if the set is empty
    if (personSet.empty()) {
        std::cout << "The person set is empty." << std::endl;
    } else {
        std::cout << "The person set is not empty." << std::endl;
    }

    // Get the size of the set
    std::cout << "The size of the person set is: " << personSet.size() << std::endl;

    // Clear all elements from the set
    personSet.clear();

    return 0;
};

int multimapExamples() {
    // Multimap: An associative container that contains a sorted set of key-value pairs, where multiple elements can have the same key
    // #include <map>

    // Create a multimap of string to int
    std::multimap<std::string, int> ageMultimap;

    // Add some elements to the multimap
    ageMultimap.insert(std::make_pair("Alice", 30));
    ageMultimap.insert(std::make_pair("Bob", 25));
    ageMultimap.insert(std::make_pair("Charlie", 35));
    ageMultimap.insert(std::make_pair("Alice", 32)); // Alice appears twice

    // Display the elements of the multimap
    std::cout << "Multimap elements: ";
    for (const auto& pair : ageMultimap) {
        std::cout << pair.first << " (" << pair.second << ") ";
    }
    std::cout << std::endl;

    // Iterate using iterators
    std::cout << "Multimap elements using iterators: ";
    for (auto it = ageMultimap.begin(); it != ageMultimap.end(); ++it) {
        std::cout << it->first << " (" << it->second << ") ";
    }
    std::cout << std::endl;

    // Access and modify elements
    auto range = ageMultimap.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == 30) {
            it->second = 31; // Modify the value
        }
    }

    // Display the elements of the multimap after modification
    std::cout << "Multimap elements after modification: ";
    for (const auto& pair : ageMultimap) {
        std::cout << pair.first << " (" << pair.second << ") ";
    }
    std::cout << std::endl;

    // Check if a key exists
    if (ageMultimap.find("Charlie") != ageMultimap.end()) {
        std::cout << "Charlie is in the multimap." << std::endl;
    } else {
        std::cout << "Charlie is not in the multimap." << std::endl;
    }

    // Remove an element by key
    ageMultimap.erase("Charlie");

    // Insert an element
    ageMultimap.insert(std::make_pair("Dave", 28));

    // Use the emplace method to construct elements in place
    ageMultimap.emplace("Eve", 40);

    // Check if the multimap is empty
    if (ageMultimap.empty()) {
        std::cout << "The ageMultimap is empty." << std::endl;
    } else {
        std::cout << "The ageMultimap is not empty." << std::endl;
    }

    // Get the size of the multimap
    std::cout << "The size of the ageMultimap is: " << ageMultimap.size() << std::endl;

    // Clear all elements from the multimap
    ageMultimap.clear();

    return 0;
};

int main() {
    std::cout << "\nVector Examples:\n" << std::endl;
    vectorExamples();
    std::cout << "----------------------------------------\nMap Examples:\n" << std::endl;
    mapExamples();
    std::cout << "----------------------------------------\nList Examples:\n" << std::endl;
    listExamples();
    std::cout << "----------------------------------------\nQueue Examples:\n" << std::endl;
    queueExamples();
    std::cout << "----------------------------------------\nSet Examples:\n" << std::endl;
    setExamples();
    std::cout << "----------------------------------------\nMultimap Examples:\n" << std::endl;
    multimapExamples();
    
    return 0;
}
