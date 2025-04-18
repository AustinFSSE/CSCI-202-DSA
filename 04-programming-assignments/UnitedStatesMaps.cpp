//
// Created by Austin Martin on 4/13/25.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

// Function to load states from the file into the map
map<string, string> loadStates(const string& filename) {
    ifstream unitedStates(filename);  // Open the file
    map<string, string> states;  // Map to store abbreviations as keys and full names as values
    string line;

    // Read the file line by line
    while (getline(unitedStates, line)) {
        stringstream ss(line);  // Use stringstream to split the line
        string abbreviation, name;

        // Split each line by a comma into abbreviation and name
        if (getline(ss, abbreviation, ',') && getline(ss, name)) {
            states[abbreviation] = name;  // Insert into map
        }
    }

    return states;  // Return the populated map
}

// Function to find the full state name from an abbreviation
string getStateName(const map<string, string>& states, const string& abbreviation) {
    const auto it = states.find(abbreviation);  // Look for the abbreviation in the map
    return it != states.end() ? it->second : "";  // If found, return the state name; otherwise, return an empty string
}

// Function to find the abbreviation from a full state name
string getStateAbbreviation(const map<string, string>& states, const string& name) {
    // Iterate over the map to find the state name
    for (const auto& pair : states) {
        if (pair.second == name) {  // If the state name matches
            return pair.first;  // Return the abbreviation
        }
    }
    return "";  // If not found, return an empty string
}

// Function to prompt and handle user input
void processUserQuery(const map<string, string>& states) {
    string input;
    cout << "Welcome to United States!" << endl;
    cout << "Please enter a state name or state abbreviation!" << endl;
    cin >> input;  // Get user input

    if (input.length() <= 3) {  // If the input is likely an abbreviation
        string stateName = getStateName(states, input);  // Get the full state name
        if (!stateName.empty()) {
            cout << stateName << endl;  // Output the full name
        } else {
            cout << "That is not a state abbreviation!" << endl;  // Invalid abbreviation
        }
    } else {  // If the input is likely a full state name
        string abbreviation = getStateAbbreviation(states, input);  // Get the abbreviation
        if (!abbreviation.empty()) {
            cout << abbreviation << endl;  // Output the abbreviation
        } else {
            cout << "That is not a state!" << endl;  // Invalid state name
        }
    }
}

int main() {
    const string filename = "States.txt";  // File containing state information
    map<string, string> states = loadStates(filename);  // Load the states into the map
    processUserQuery(states);  // Handle user input
    return 0;  // Program ends
}
