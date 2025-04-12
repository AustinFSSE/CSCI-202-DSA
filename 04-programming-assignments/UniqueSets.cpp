//
// Created by Austin Martin on 4/12/25.
//
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>

using namespace std;

int main() {

    set<string> sets;

    string text = "Humpty Dumpty sat on a wall,\n"
                  "Humpty Dumpty had a great fall All the king’s horses\n"
                  "and all the king’s men\n"
                  "Couldn’t put Humpty together again.\n";
    ofstream File("Song.txt");

    File << text;

    File.close();

    ifstream reader("Song.txt");
    string line;
    while (getline(reader, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            sets.insert(word);
        }

    }

    for (const auto& word : sets) {
        cout << word << endl;
    }
    return 0;
}