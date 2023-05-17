#ifndef SNACK_HASHING_H
#define SNACK_HASHING_H

#include <iostream>

#include "Snack.h"

using namespace std;

class SnackHashing{
    public:
        Snack* table[11];

        SnackHashing();
        void addSnack(Snack* snack);
        Snack* getSnack(string name);

    private:
        int sumOfAscii(string name);
};

#endif