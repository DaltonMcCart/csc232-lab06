/**
 * CSC232 Data Structures
 * Missouri State University
 * 
 * @file   Demo.cpp
 * @author Jim Daehn
 * @brief  Entry point for hw03 target.
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stack>

int main() {
    std::cout << "Hello, demo!" << std::endl;

    std::stack<int> intStack;

    std::cout << "size of intStack: " << intStack.size() << std::endl;

    std::cout << "intStack empty? " << std::boolalpha << intStack.empty() << std::endl << std::endl;

    for (int i = 0; i < 5; ++i) {
        intStack.push(i);
    }

    std::cout << "Top of stack: " << intStack.top() << std::endl;
    std::cout << "size of intStack: " << intStack.size() << std::endl;
    std::cout << "Top of stack: " << intStack.top() << " (Notice size doesn't change with call to top())" << std::endl;
    std::cout << "size of intStack: " << intStack.size() << std::endl;
    std::cout << "intStack empty? " << std::boolalpha << intStack.empty() << std::endl << std::endl;

    std::cout << "Popping out elements...";
    while (!intStack.empty()) {
        std::cout << ' ' << intStack.top();
        intStack.pop();
    }
    std::cout << std::endl << std::endl;

    std::cout << "size of intStack: " << intStack.size() << std::endl;
    std::cout << "intStack empty? " << std::boolalpha << intStack.empty() << std::endl;


    return EXIT_SUCCESS;
}