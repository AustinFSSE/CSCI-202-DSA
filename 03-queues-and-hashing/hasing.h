//
// Created by Austin Martin on 4/7/25.
//

#pragma once

// A simple hash table class using linear probing for collision resolution
class hashing {
public:
    // Searches for a key in the hash table and prints whether it exists
    void search(int key) const;

    // Checks if a specific key exists in the table (helper function)
    bool isItemEqual(int key);

    // Retrieves a key from the table if it exists
    int retrieve(int key) const;

    // Removes a key from the table
    void remove(int key);

    // Prints the entire hash table with indices and values
    void print() const;

    // Inserts a key into the hash table using linear probing
    void insert(int key);

    // Constructor initializes the table
    hashing();

private:
    const int size = 5;         // Fixed size of the hash table
    int table[5]{};             // Array representing the hash table; default-initialized to 0
    bool avoidance[5]{};        // Boolean array to track occupied slots; false = empty

    // Hash function: returns an index based on the key
    int hash(int key) const {
        return key % size;      // Simple modulo-based hash
    }

    // Checks whether a key exists in the hash table using linear probing
    bool isItemEqual(int key) const {
        int index = hash(key);          // Compute initial hash index
        int firstIndex = index;         // Save original index to detect a full loop

        // Loop while the slot has been used (could contain a valid or deleted item)
        while (avoidance[index]) {
            if (table[index] == key) {  // Found the key
                return true;
            }
            index = (index + 1) % size; // Move to next slot (with wrap-around)
            if (index == firstIndex) break; // Avoid infinite loop
        }
        return false; // Key not found
    }
};
