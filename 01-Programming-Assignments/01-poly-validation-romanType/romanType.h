//
// Created by alm20 on 3/22/2025.
//

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

// Define the romanType class that handles conversion between Roman numerals and numerical values
class romanType {
public:

    // Define an enum for Roman numerals, mapping each symbol to its corresponding value
    enum RomanNumerals {
        M = 1000,
        D = 500,
        C = 100,
        L = 50,
        X = 10,
        V = 5,
        I = 1,
        IV = 4,
        IX = 9,
        XL = 40,
        XC = 90,
        CD = 400,
        CM = 900
    };

    // This function prints the Roman numeral corresponding to an enum value
    void printEnumKeys(RomanNumerals r) {
        switch (r) {
            case M: std::cout << "M"; break;
            case D: std::cout << "D"; break;
            case C: std::cout << "C"; break;
            case L: std::cout << "L"; break;
            case X: std::cout << "X"; break;
            case V: std::cout << "V"; break;
            case I: std::cout << "I"; break;
            case IV: std::cout << "IV"; break;
            case IX: std::cout << "IX"; break;
            case XL: std::cout << "XL"; break;
            case XC: std::cout << "XC"; break;
            case CD: std::cout << "CD"; break;
            case CM: std::cout << "CM"; break;
        }
    }

    // This function converts a string of Roman numerals into its numerical value
    int conversionToNumericalValue(const std::string &numerals) {
        // Tokenize the Roman numeral string into individual RomanNumerals
        std::vector<RomanNumerals> romans = tokenize(numerals);
        // Sum the values of each Roman numeral in the vector
        for (auto& c : romans) {
            total += c;
        }
        // Output the total value, formatted to 2 decimal places
        std::cout << std::fixed << std::setprecision(2) <<  total;
        return total;
    }

    // This function handles converting a whole number into Roman numerals (though not implemented fully)
    int conversionFromRomanToNumericalValue(int numbers) {
        // Call the tokenize function, though it only prints Roman numerals and doesn't complete the conversion
        tokenize(numbers);
        return 1;
    }

private:

    std::string roman_numerals; // Variable to store the Roman numerals (currently unused)
    int number = 0; // Variable to store the number (currently unused)
    int total = 0; // Variable to accumulate the total numerical value of Roman numerals

    // Helper function to convert a two-character Roman numeral string to the corresponding enum value
    RomanNumerals charToEnum(const std::string &numerals) {
        const char first_numeral = numerals[0];
        const char second_numeral = numerals[1];

        if (first_numeral == 'I' && second_numeral == 'V') return IV;
        if (first_numeral == 'I' && second_numeral == 'X') return IX;
        if (first_numeral == 'X' && second_numeral == 'L') return XL;
        if (first_numeral == 'X' && second_numeral == 'C') return XC;
        if (first_numeral == 'C' && second_numeral == 'D') return CD;
        if (first_numeral == 'C' && second_numeral == 'M') return CM;
        return I; // Return 'I' if no match is found
    }

    // Overloaded helper function to convert a single character Roman numeral to the corresponding enum value
    RomanNumerals charToEnum(char c) {
        switch (c) {
            case 'M': return M;
            case 'D': return D;
            case 'C': return C;
            case 'L': return L;
            case 'X': return X;
            case 'V': return V;
            case 'I': return I;
            default: return M; // Default case if an invalid character is encountered
        }
    }

    // This function tokenizes a string of Roman numerals into individual RomanNumerals (enums)
    std::vector<RomanNumerals> tokenize(const std::string &numerals) {
        int k = 0;
        std::vector<RomanNumerals> romans;

        // Loop through the input string, converting characters to corresponding Roman numerals
        for (int i = 0; k < numerals.size(); i++) {
            const int first = charToEnum(numerals[k]); // Convert current character to Roman numeral enum
            const int second = charToEnum(numerals[k + 1]); // Convert next character if available

            // If the first numeral has a smaller value than the second, combine them as a valid Roman numeral
            if (first < second) {
                std::string two_letters = std::string(1, numerals[k]) + numerals[k + 1];
                romans.push_back(charToEnum(two_letters)); // Push combined numeral
                k += 2; // Skip the next character as it's already processed
            } else {
                romans.push_back(charToEnum(numerals[k])); // Process single character Roman numeral
                k++; // Move to the next character
            }
        }
        return romans;
    }

    // This function tokenizes a numerical value into a vector of Roman numerals
    std::vector<RomanNumerals> tokenize(int number) {
        std::vector<RomanNumerals> tokens;
        bool flag = true;

        // Convert the integer to a vector of Roman numerals by subtracting corresponding values
        while (flag) {
            if (number >= 1000) {
                number -= 1000;
                tokens.push_back(M);
            } else if (number >= 900) {
                number -= 900;
                tokens.push_back(CM);
            } else if (number >= 500) {
                number -= 500;
                tokens.push_back(D);
            } else if (number >= 400) {
                number -= 400;
                tokens.push_back(CD);
            } else if (number >= 100) {
                number -= 100;
                tokens.push_back(C);
            } else if (number >= 90) {
                number -= 90;
                tokens.push_back(XC);
            } else if (number >= 50) {
                number -= 50;
                tokens.push_back(L);
            } else if (number >= 40) {
                number -= 40;
                tokens.push_back(XL);
            } else if (number >= 10) {
                number -= 10;
                tokens.push_back(X);
            } else if (number == 9) {
                number -= 9;
                tokens.push_back(IX);
            } else if (number >= 5) {
                number -= 5;
                tokens.push_back(V);
            } else if (number == 4) {
                number -= 4;
                tokens.push_back(IV);
            } else if (number >= 1) {
                number -= 1;
                tokens.push_back(I);
            } else {
                flag = false; // Exit the loop when the number is reduced to 0
            }
        }

        // Print the Roman numerals (for demonstration or debugging purposes)
        for (auto t : tokens) {
            printEnumKeys(t);
        }

        return tokens; // Return the vector of Roman numerals
    }
};
