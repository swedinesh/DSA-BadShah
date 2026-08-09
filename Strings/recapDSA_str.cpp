#include <iostream>
#include <string>

int main() {
    std::string text = "Hello World";

    // 1. Length
    std::cout << "Length: " << text.length() << std::endl; // Output: 11

    // 2. Access
    std::cout << "First char: " << text.at(0) << std::endl; // Output: H

    // 3. Search
    size_t found = text.find("World");
    if (found != std::string::npos) {
        std::cout << "Found at index: " << found << std::endl; // Output: 6
    }

    // 4. Modify
    text.append("!");          // "Hello World!"
    text.erase(0, 6);          // "World!" (removes "Hello ")
    text.insert(0, "Hi ");     // "Hi World!"
    
    std::cout << "Final string: " << text << std::endl; // Output: Hi World!

    return 0;
}