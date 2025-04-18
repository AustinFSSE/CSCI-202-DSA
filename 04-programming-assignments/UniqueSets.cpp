//
// Created by Austin Martin on 4/12/25.
//
#include <iostream>
#include <fstream>
#include <set>
#include <regex>
#include <string>


using namespace std;

int main() {
    // Create a set to hold unique words (automatically sorted)
    set<string> sets;

    // Regex pattern to match words (case-insensitive, alphabetic only)
    regex word_pattern("[a-zA-Z]+");

    // Multi-line string to write to the file
    string text = "Humpty Dumpty sat on a wall,\n"
                  "Humpty Dumpty had a great fall All the king’s horses\n"
                  "and all the king’s men\n"
                  "Could not put Humpty together again.\n";

    // Create and write text to a file named "Song.txt"
    ofstream File("Song.txt");
    File << text;
    File.close(); // Close the file after writing

    // Open the file for reading
    ifstream reader("Song.txt");
    string line;

    // Read each line from the file
    while (getline(reader, line)) {
        // Use regex to find all words in the line
        sregex_iterator words_begin(line.begin(), line.end(), word_pattern);
        sregex_iterator words_end;

        // Iterate through all regex matches and insert into set
        for (sregex_iterator i = words_begin; i != words_end; ++i) {
            string word = i->str(); // Extract the matched word
            sets.insert(word);      // Automatically avoids duplicates
        }
    }

    // Print all unique words in alphabetical order
    for (const auto& word : sets) {
        cout << word << endl;
    }

    return 0;
}
