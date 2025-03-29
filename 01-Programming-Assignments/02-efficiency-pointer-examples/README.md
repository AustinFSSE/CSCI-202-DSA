# PointingPointers Project

## Overview
The **PointingPointers** project demonstrates the use of pointers, pointer arithmetic, and passing variables by reference and value in C++. This project explores how pointers interact with arrays, function arguments, and memory addresses.

## Features
- Manipulating variables by **reference** using pointers
- Manipulating variables by **value**
- Demonstrating **pointer arithmetic** with arrays
- Displaying memory addresses and values pointed to by pointers

## Files
### `PointingPointers.h`
Contains the **PointingPointers** class that defines:
- `void manipulateByReference(int* pArg1, int* pArg2)`: Modifies the values of integer variables by reference.
- `void manipulateByValue(int pArg1, int pArg2)`: Modifies integer values by value (without affecting original values).
- A note about **referential argument passing** as an alternative to pointer-based reference passing.

### `PointingPointers.cpp`
- Implements the **manipulation functions**.
- Demonstrates pointer initialization, pointer arithmetic, and accessing memory addresses.
- Uses an array of strings to show how pointer arithmetic can navigate elements in an array.
- Prints memory addresses and values stored at those locations.

## Usage
1. **Compile and Run** the program using a C++ compiler:
   ```sh
   g++ PointingPointers.cpp -o PointingPointers
   ./PointingPointers
   ```
2. The program will output:
    - The memory address of the first array element
    - The value of the first element accessed via a pointer
    - The second element using pointer arithmetic
    - Backtracking to the first element using pointer arithmetic

## Example Output
```
0x7ffeefbff5a0
Austin
NotAustin
Austin
```

## Key Learnings
- Pointers store memory addresses and allow direct manipulation of memory.
- Pointer arithmetic enables navigation through an array.
- Passing by **reference** modifies the original values, while passing by **value** does not.
- Overloading functions with references cannot be done exactly as with pointers.

## Future Enhancements
- Expand pointer manipulation functions.
- Add examples with dynamic memory allocation.
- Implement safer pointer operations using `std::unique_ptr` or `std::shared_ptr`.

---
**Author:** alm20  
**Created on:** 3/22/2025

