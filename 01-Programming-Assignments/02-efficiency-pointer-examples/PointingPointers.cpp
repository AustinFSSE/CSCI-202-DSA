//
// Created by alm20 on 3/22/2025.
//

#include "PointingPointers.h"

#include <iostream>

using namespace std;

int main() {
    PointingPointers pp;

    int nValue1 = 1;
    int nValue2 = 2;
    cout << "nValue1 = " << nValue1 << endl;
    cout << "nValue2 = " << nValue2 << endl;
    pp.manipulateByValue(nValue1, nValue2); // values don't change because values were passed and not their memory addresses
    cout << "nValue1 = " << nValue1 << endl;
    cout << "nValue2 = " << nValue2 << endl;
    pp.manipulateByReference(&nValue1, &nValue2); // values change because new values were saved at nValue1's & nValue2's internal memory address
    cout << "nValue1 = " << nValue1 << endl;
    cout << "nValue2 = " << nValue2 << endl;

    return 0;
}
