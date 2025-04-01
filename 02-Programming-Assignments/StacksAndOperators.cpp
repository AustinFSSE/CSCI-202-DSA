//
// Created by Austin Martin on 3/31/25.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Class to handle the conversion of infix expressions to postfix expressions
class InfixToPostfix {

private:
    // Private member variables to store infix and postfix expressions
    string infix;
    string postfix;

    // Function to determine the precedence of an operator
    int operatorPrecedence(char op) {
        // + and - have precedence 1
        if (op == '+' || op == '-')
            return 1;
        // * and / have precedence 2
        if (op == '*' || op == '/')
            return 2;
        // Return 0 if the character is not an operator
        return 0;
    }

    // Function to check if a character is a valid operator
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    // Function to check if the character is an uppercase letter (A-Z)
    bool letterChecker(char c) {
        // Uses ASCII values to check if c is between 'A' and 'Z'
        return (static_cast<int>(c) >= 65 && static_cast<int>(c) <= 90);
    }

public:
    // Default constructor
    InfixToPostfix() {}

    // Sets the infix expression from user input
    void getInfix(string& expr) {
        infix = expr;
    }

    // Displays the infix expression
    void showInfix() {
        cout << "Infix Expression: " << infix << endl;
        infix.clear(); // Clear infix after displaying
    }

    // Displays the postfix expression
    void showPostfix() {
        cout << "Postfix Expression: " << postfix << endl;
        postfix.clear(); // Clear postfix after displaying
    }

    // Method to convert the infix expression to postfix using a stack
    void convertToPostfix() {
        stack<char> s;

        // Iterate through each character in the infix expression
        for (char c : infix) {
            // If the character is an uppercase letter (operand), add it to postfix
            if (letterChecker(c)) {
                postfix += c;
            }
            // If the character is an opening parenthesis, push it onto the stack
            else if (c == '(') {
                s.push(c);
            }
            // If the character is a closing parenthesis, pop and add all operators until '(' is found
            else if (c == ')') {
                while (s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                s.pop(); // Remove the opening parenthesis '(' from the stack
            }
            // If the character is an operator
            else if (isOperator(c)) {
                // While the stack is not empty and the operator on top of the stack has greater or equal precedence
                while (!s.empty() && operatorPrecedence(s.top()) >= operatorPrecedence(c)) {
                    postfix += s.top(); // Add the operator to postfix
                    s.pop(); // Remove the operator from the stack
                }
                s.push(c); // Push the current operator onto the stack
            }
        }

        // Pop and append any remaining operators in the stack to postfix
        while (!s.empty()) {
            postfix += s.top();
            s.pop();
        }
    }
};

int main() {
    InfixToPostfix converter;

    // Array of test infix expressions
    string expressions[] = {
        "A+B-C",
        "(A+B)*C",
        "(A+B)*(C-D)",
        "A+((B+C)*(E-F)-G)/(H-I)",
        "A+B*(C+D)-E/F*G+H"
    };

    // Loop through each expression, convert, and display the result
    for (string& expr : expressions) {
        converter.getInfix(expr);   // Set the infix expression
        converter.convertToPostfix(); // Convert to postfix
        converter.showInfix();      // Display infix
        converter.showPostfix();    // Display postfix
        cout << endl;
    }

    return 0;
}
