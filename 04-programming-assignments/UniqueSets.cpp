//
// Created by Austin Martin on 4/12/25.
//
#include <iostream>
#include <fstream>
#include <set>
#include <regex>

using namespace std;

int main() {

    set<string> sets;
    regex word_pattern("[a-zA-z]+");

    string text = "Humpty Dumpty sat on a wall,\n"
                  "Humpty Dumpty had a great fall All the king’s horses\n"
                  "and all the king’s men\n"
                  "Could not put Humpty together again.\n";
    ofstream File("Song.txt");

    File << text;

    File.close();

    ifstream reader("Song.txt");
    string line;
    while (getline(reader, line)) {
        sregex_iterator words_begin(line.begin(), line.end(), word_pattern);
        sregex_iterator words_end;

        for (sregex_iterator i = words_begin; i != words_end; ++i) {
            string word = i->str();
            sets.insert(word);
        }

    }

    for (const auto& word : sets) {
        cout << word << endl;
    }
    return 0;
}