//
// Created by Austin Martin on 4/7/25.
//

#include <iostream>
#include <ostream>
#include "hasing.h"

// Constructor: Initializes the hash table and avoidance flags
hashing::hashing() {
    for (int i = 0; i < size; i++) {
        table[i] = 0;           // Default value at each slot
        avoidance[i] = false;   // Marks this slot as unoccupied
    }
}


void hashing::insert(int key) {
    int index = hash(key);     // Compute the initial index using the hash function
    int firstIndex = index;    // Keep track to detect wraparound

    // Linear probing: find the next available slot
    while (avoidance[index]) {
        index = (index + 1) % size;  // Wrap around
        if (index == firstIndex) {
            // All slots visited — table is full
            std::cout << key << " is already in hashing" << std::endl;
            return;
        }
    }

    // Insert the key and mark slot as used
    table[index] = key;
    avoidance[index] = true;
}


void hashing::search(const int key) const {
    int index = hash(key);
    int firstIndex = index;

    // Probes the table for the key using avoidance flags
    while (avoidance[index]) {
        if (isItemEqual(key)) {  // This logic is flawed — `isItemEqual` doesn't check current index
            std::cout << key << " is in hashing" << std::endl;
            return;
        }
        index = (index + 1) % size;
        if (index == firstIndex) {
            break;  // Full loop completed
        }
    }
    std::cout << key << " is not in hashing" << std::endl;
}


void hashing::print() const {
    for (int i = 0; i < size; i++) {
        if (avoidance[i]) {
            std::cout << i << " --> " << table[i] << std::endl;
        } else {
            std::cout << i << " --> empty" << std::endl;
        }
    }
}

int hashing::retrieve(const int key) const {

    int index = hash(key);
    const int firstIndex = index;
    while (avoidance[index]) {
        if (table[index] == key) {
            std::cout << key << " is in hashing" << std::endl;
            return table[index];
        }
        index = (index + 1) % size;
        if (index == firstIndex) {
            break;
        }
    }
    std::cout << key << " is not in hashing" << std::endl;
    return 0;
}

void hashing::remove(const int key) {
    for (int i = 0; i < size - 1; i++) {
        if (table[i] == key) {
            std::cout << key << " is removed " << std::endl;
            avoidance[i] = false;
            table[i] = 0;
        }
    }
}




int main() {
    auto h_table = hashing(); // Create an instance of the hash table

    h_table.insert(10);
    h_table.insert(20);
    h_table.insert(30);
    h_table.print();  // Print current state of hash table

    std::cout << std::endl;

    h_table.search(20);  // Should find it
    h_table.remove(20);  // Attempt to remove it
    h_table.search(20);  // Should NOT find it (but due to bug, may still find it)
    h_table.print();     // Print current state

    std::cout << std::endl;

    h_table.insert(40);
    h_table.insert(50);

    int retrieval = h_table.retrieve(40);  // Get value at key
    std::cout << retrieval << std::endl;

    h_table.search(22);  // Should not be in the table
    h_table.search(10);  // Should be found

    return 0;
}

