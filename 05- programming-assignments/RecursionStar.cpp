//
// Created by Austin Martin on 4/18/25.
//

#include <iostream>
#include <string>
using namespace std;

int displayStars(int numberOfLines, int numberOfStars, bool flag) {
    if (numberOfLines == 0) {return 0;}
    if (flag) {
        if (numberOfStars == 0) {
            displayStars(numberOfLines + 1, numberOfStars, false);
        } else {
            cout << string(numberOfStars, '*');
            cout << endl;
            displayStars(numberOfLines - 1, numberOfStars - 1, true);
        }

    } else {
        cout << string(numberOfStars, '*');
        cout << endl;
        displayStars(numberOfLines - 1, numberOfStars + 1, false);
    }
    return 0;
}
bool entryValidator(int number) {
    return number % 2 == 0;
}
int main() {

    string numberOfLines;
    do {
        cout << "Enter number of line or enter \'Quit': ";
        cin >> numberOfLines;
        if (numberOfLines == "quit") {
            return 0;
        }
        if (stoi(numberOfLines) % 2 != 0) {
            cout << "You must enter a number divisible by 2!" << endl;
        }
    } while (!entryValidator(stoi(numberOfLines)));
    int number = stoi(numberOfLines);
    int numberOfStars = number / 2;

    // cout << string(5, '*') << endl; // prints *****
    displayStars(number, numberOfStars, true);
    return 0;
}