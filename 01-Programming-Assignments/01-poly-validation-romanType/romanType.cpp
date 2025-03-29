
    //
    // Created by alm20 on 3/22/2025.
    //


    #include "romanType.h"   // Include the header file for the romanType class definition
    #include <iostream>       // For input/output operations
    #include <string>         // For string manipulation


    int main() {
    // Declare an instance of the romanType class
    romanType r;
    int choice = 0;            // Variable to hold user's choice for input type
    std::string r_numerals;    // String to hold the Roman numerals entered by user
    int numbers;               // Integer to hold the whole number entered by the user

    while (true) {
        // Display a welcome message and present the options to the user
        std::cout << "\nWelcome to my program!" << std::endl;
        std::cout << "You have 2 choices\n 1. enter a set of Roman Numerals\n 2. Enter a whole number" << std::endl;
        std::cin >> choice; // Read the user's choice

        // Process based on the user's choice
        switch (choice) {
            case 1:
                std::cout << "Enter a set of roman numerals: ";  // Prompt for Roman numerals
            std::cin >> r_numerals;  // Read the Roman numeral input
            std::cout << std::fixed << std::setprecision(2) << r_numerals << " converts to -> ";
            return r.conversionToNumericalValue(r_numerals);  // Convert Roman numerals to a numerical value and return it

            case 2:
                std::cout << "Enter a whole number: ";  // Prompt for a whole number
            std::cin >> numbers;  // Read the whole number input
            std::cout << numbers << " converts to -> ";
            return r.conversionFromRomanToNumericalValue(numbers);  // Convert whole number to Roman numerals and return it

            default:
                return 1;  // Exit the program if the user enters an invalid choice
        }
    }
}
