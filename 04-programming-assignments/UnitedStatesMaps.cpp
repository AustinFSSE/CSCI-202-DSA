//
// Created by Austin Martin on 4/13/25.
//


#include <fstream>
#include <iostream>

#include <map>
#include <sstream>

using namespace std;


int main() {

    ifstream unitedStates("States.txt");
    string line;
    map<string,string> states;
    vector<string> state;
    while (getline(unitedStates, line)) {
        stringstream ss(line);
        string word;
        while (getline(ss, word, ',')) {
            state.push_back(word);
        }
        // cout << state[0] << endl;
        states.insert(make_pair(state[0], state[1]));
        state.erase(state.begin(), state.end());

    }
    // for (const auto& word : states) {
    //     cout << word.first << " " << word.second << endl;
    // }
    string input;
    cout << "Welcome to United States!" << endl;
    cout << "Please enter a state name or state abbreviation!" << endl;
    cin >> input;


    if (input.length() <= 3) {
        for (const auto& word : states) {
            if (input == word.first) {
                cout << word.second << endl;
                return 0;
            }
        }
        cout << "That is not a state abbreviation!" << endl;
        return 0;
    }
    for (const auto& word : states) {

        if (tolower(input.data()) == tolower(word.second.data())) {
            cout << word.first << endl;
            return 0;
        }
    }
    cout << "That is not a state!" << endl;
    return 0;
}
