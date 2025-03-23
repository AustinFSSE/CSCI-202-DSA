//
// Created by alm20 on 3/22/2025.
//

#pragma once

using namespace std;

class PointingPointers {

public:
    void manipulateByReference(int* pArg1, int* pArg2) {

        *pArg1 += 10;
        *pArg2 += 10;
    }
    void manipulateByValue(int pArg1, int pArg2) {

        pArg1 += 10;
        pArg2 += 10;
    }
    /*
     * void manipulatedByReference(int& pArg1, int& pArg2) <-- this is called Referential argument passing
     * and referential argument passing is the exact same as passing by reference. C++ does all the pointer business
     * behind the curtains. However, you cannot overload this method the same way you can when using the pointer way.
     * the ampersand sign is not attached to the type 'int&'.
     * this just lets C++ know to handle pointers in the background.
     */
};


