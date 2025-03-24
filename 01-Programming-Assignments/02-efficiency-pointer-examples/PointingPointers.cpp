//
// Created by alm20 on 3/22/2025.
//

#include "PointingPointers.h"

#include <iostream>

using namespace std;

void manipulateByReference(int* pArg1, int* pArg2) {

    *pArg1 += 10;
    *pArg2 += 10;
}
void manipulateByValue(int pArg1, int pArg2) {

    pArg1 += 10;
    pArg2 += 10;
}

int main() {
    std::string arr[] = {"Austin", "NotAustin"};

    // Declare pointer
    std::string* p_string;
    std::string* p2_string = &arr[1]; // Initialized to the second element

    // Initialize pointer to an array value
    p_string = arr; // same as &arr[0]
    cout << p_string << endl; // memory address
    cout << *p_string << endl; // value @ &arr[0] should return "Austin"

    // display pointer arithmetic
    cout << *(p_string + 1) << endl; // should return "NotAustin" since memory in an array is contiguous
    p_string = &arr[1];
    cout << *(p_string - 1) << endl; // should return "Austin"

    /*cout << *(p2_string + 1) << endl; // should fail Index out of bounds*/

    return 0;
}
