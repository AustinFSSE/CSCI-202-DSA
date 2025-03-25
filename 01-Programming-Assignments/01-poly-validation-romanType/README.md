# Roman Numeral Converter

## Overview
This project implements a Roman numeral converter in C++. The program allows users to:
1. Convert Roman numerals to their numerical values.
2. Convert numerical values to Roman numerals.

The main functionality is implemented in the `romanType` class, which handles conversions between Roman numerals and integers using an enumeration-based approach.

## Features
- **Bidirectional conversion**: Supports both Roman numeral to integer conversion and vice versa.
- **Enum-based representation**: Uses an `enum` to define Roman numeral values for efficient mapping.
- **Tokenization**: Breaks down input numerals into meaningful components for processing.
- **Interactive CLI**: Provides a simple menu-based console interface for user input.

## Files
- `main.cpp`: Contains the main function and user interaction logic.
- `romanType.h`: Declares the `romanType` class and its methods.
- `romanType.cpp`: Implements the conversion logic and helper functions.

## Usage
### Compilation
Use a C++ compiler like g++:
```sh
 g++ -o romanConverter main.cpp romanType.cpp
```

### Running the Program
```sh
./romanConverter
```

### Program Flow
1. The user is prompted to select a conversion type:
    - Enter a set of Roman numerals.
    - Enter a whole number.
2. The program converts the input and displays the result.

### Example Inputs & Outputs
#### Roman to Integer
```
Enter a set of Roman numerals: MCMXCIV
MCMXCIV converts to -> 1994
```
#### Integer to Roman
```
Enter a whole number: 2025
2025 converts to -> MMXXV
```

## Class `romanType`
### Methods
- `double conversionToNumericalValue(const std::string &numerals)`: Converts a Roman numeral string to its integer value.
- `int conversionFromRomanToNumericalValue(int number)`: Converts an integer to its Roman numeral representation.
- `std::vector<RomanNumerals> tokenize(const std::string &numerals)`: Breaks down a Roman numeral string into its components.
- `std::vector<RomanNumerals> tokenize(int number)`: Converts an integer into a sequence of Roman numeral tokens.
- `static void printEnumKeys(RomanNumerals r)`: Prints the Roman numeral associated with an enum value.

### Enum `RomanNumerals`
Defines the numerical values of Roman numeral symbols:
```cpp
enum RomanNumerals {
    M = 1000, CM = 900, D = 500, CD = 400,
    C = 100, XC = 90, L = 50, XL = 40,
    X = 10, IX = 9, V = 5, IV = 4, I = 1
};
```

## Notes
- Input Roman numerals should be valid (e.g., "IIII" is not a correct notation).
- The program uses `std::vector` for tokenization and stores values as enums for efficiency.
- `std::setprecision(2)` ensures floating-point outputs are formatted correctly.

## Future Improvements
- Improve error handling for invalid Roman numerals.
- Optimize conversion functions for better performance.
- Expand support for larger numbers.

## License
This project is open-source and can be used freely.

