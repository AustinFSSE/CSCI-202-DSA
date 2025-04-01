//
// Created by Austin Martin on 3/31/25.
//

#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

// Binary class to handle binary input and conversion
class Binary {

private:
    // Private member variable to store the binary number as a string
    string number;

public:

    // Method to prompt the user for a binary number
    string promptUser() {
        cout << "Enter a number in binary format. ex: 1's or 0's  " << endl;
        cin >> number;  // Read user input
        return number;  // Return the entered binary number
    }

    // Static method to tokenize the binary number into a stack of characters
    static stack<char> tokenize(const string& number) {
        stack<char> tokens;
        // Iterate through the binary string from right to left
        // This preserves the correct order when pushed onto the stack
        for (int i = number.length() - 1; i >= 0; i--) {
            tokens.push(number[i]);  // Push each binary digit onto the stack
        }
        return tokens;  // Return the stack containing the binary digits
    }

    // Recursive function to convert a binary stack to its decimal equivalent
    int convertBinary(stack<char> tokens) {
        // Base case: if the stack is empty, return 0
        if (tokens.empty()) {
            return 0;
        }

        // Extract the top binary digit from the stack
        char digit = tokens.top();
        tokens.pop();  // Remove the processed digit from the stack

        // Convert the binary digit to an integer and multiply by the corresponding power of 2
        int result = (digit - '0') * pow(2, tokens.size());

        // Recursively process the remaining stack and add the current result
        return result + convertBinary(tokens);
    }
};

int main() {
    Binary binary;

    // Prompt the user for input and tokenize the binary number
    const stack<char> initStack = Binary::tokenize(binary.promptUser());

    // Convert the binary stack to decimal and print the result
    cout << binary.convertBinary(initStack);

    return 0;
}
