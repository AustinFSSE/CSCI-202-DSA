//
// Created by alm20 on 3/22/2025.
//

#include "PointingPointers.h"
#include <iostream>

using namespace std;

// Function that manipulates values by reference (through pointers)
// Parameters are pointers to integers, allowing the function to modify the original variables
static void manipulateByReference(int* pArg1, int* pArg2) {
    // Dereference pointers and increment the values they point to by 10
    *pArg1 += 10;
    *pArg2 += 10;
}

// Function that manipulates values by value (copies of the values)
// Parameters are passed by value, so the original variables are not modified
static void manipulateByValue(int pArg1, int pArg2) {
    // Increment the arguments by 10, but this does not affect the original values
    pArg1 += 10;
    pArg2 += 10;
}



int main() {

    // Declare two integer variables and initialize them
    int num1 = 5;
    int num2 = 1;

    // Declare and initialize an array of strings with two elements
    std::string arr[] = {"Austin", "NotAustin"};

    // Declare a pointer to a string (p_string)
    std::string* p_string;
    // Declare another pointer (p2_string) initialized to point to the second element of the array (arr[1])
    std::string* p2_string = &arr[1]; // Initialized to the second element

    // Initialize p_string to point to the first element of the array (arr[0])
    p_string = arr; // Same as &arr[0]

    // Print the memory address of the first element of the array (arr[0])
    cout << p_string << endl; // Prints the memory address of arr[0]

    // Dereference the pointer and print the value at that address (should print "Austin")
    cout << *p_string << endl; // Value at &arr[0] should return "Austin"

    // Demonstrate pointer arithmetic
    // (p_string + 1) moves the pointer to the next element in the array, which is "NotAustin"
    cout << *(p_string + 1) << endl; // Should return "NotAustin" because memory in an array is contiguous

    // Update p_string to point to the second element of the array (arr[1])
    p_string = &arr[1];

    // Print the value at the memory location one step before p_string (which is arr[0], should print "Austin")
    cout << *(p_string - 1) << endl; // Should return "Austin" because pointer arithmetic subtracts 1

    /* Uncommenting the line below would result in an "Index out of bounds" error:
       cout << *(p2_string + 1) << endl; // Should fail due to out-of-bounds access */

    // Call the manipulateByValue function, passing num1 and num2 by value
    manipulateByValue(num1, num2);
    // The values of num1 and num2 are not modified by manipulateByValue because they were passed by value
    cout << num1 << endl; // Prints the original value of num1 (5)
    cout << num2 << endl; // Prints the original value of num2 (1)

    // Call the manipulateByReference function, passing the addresses of num1 and num2 (by reference)
    manipulateByReference(&num1, &num2);
    // The values of num1 and num2 are modified by manipulateByReference because they were passed by reference
    cout << num1 << endl; // Prints the modified value of num1 (15)
    cout << num2 << endl; // Prints the modified value of num2 (11)

    return 0; // Return from main, indicating successful program completion
}
