//
// Created by alm20 on 3/22/2025.
//

#include "romanType.h"

#include <iostream>
#include <string>


int main() {

    romanType r;
    int choice = 0;
    std::string r_numerals;
    int numbers;
    while (true) {
        std::cout << "\nWelcome to my program!" << std::endl;
        std::cout << "You have 2 choices\n 1. enter a set of Roman Numerals\n 2. Enter a whole number" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a set of roman numerals: ";
            std::cin >> r_numerals;
            std::cout << std::fixed << std::setprecision(2) << r_numerals << " converts to -> " << r.conversionToNumericalValue(r_numerals) << std::endl;
            break;
            case 2:
                std::cout << "Enter a whole number: ";
                std::cin >> numbers;
                return r.conversionFromRomanToNumericalValue(numbers);
            default: return 1;
        }
    }
}
