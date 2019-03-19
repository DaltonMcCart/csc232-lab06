/**
 * CSC232 Data Structures
 * Missouri State University
 * 
 * @file    Main.cpp
 * @authors Jim Daehn <jdaehn@missouristate.edu>
 *          Dalton McCart <mccart42@live.missouristate.edu>
 * @brief   Entry point for hw03 target.
 */

#include <cstdlib>
#include <iostream>
#include <stack>
#include <iomanip>

//Function Prototypes
std::string reverseString (const std::string& original);
bool isBalanced (const std::string& expression);

//Main
int main() {
    std::string course{"CSC232 - Data Structures"};
    std::cout << "The original string: " <<  course << std::endl;
    std::cout << "The reversed string: " << reverseString(course) << std::endl;

    std::string braces{"{abc{de}{fg}hij}kl"};
    std::cout << "The input expression: " << braces << std::endl;
    std::cout << "Are the braces balanced? " << std::boolalpha << isBalanced(braces) << std::endl;

    return EXIT_SUCCESS;
}

//Function Definitions
//reverseString function
std::string reverseString (const std::string& original){
    std::stack<char> stringStack;
    std::string reversedString;

    for (unsigned int i = 0; i < original.length(); i++) {
        stringStack.push(original.at(i));
    }

    while (!stringStack.empty()) {
        reversedString.push_back (stringStack.top());
        stringStack.pop();
    }

    return reversedString;
}

//isBalanced function
bool isBalanced (const std::string& expression){
    std::stack <char> openBraces;
    std::stack <char> closedBraces;
    for (auto i : expression) {
        if (i == '{'){
            openBraces.push('{');
        }

        if (i == '}'){
            if (!openBraces.empty()){
                openBraces.pop ();
            }
            else {
                return false;
            }
        }
    }

    return openBraces.empty();
}