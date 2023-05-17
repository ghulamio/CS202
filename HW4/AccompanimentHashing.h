#ifndef ACCOMPANIMENT_HASHING_H
#define ACCOMPANIMENT_HASHING_H

#include <iostream>

#include "Accompaniment.h"

using namespace std;

class AccompanimentHashing{
    public:
        Accompaniment* table[71];

        AccompanimentHashing();
        void addAccompaniment(Accompaniment* accompaniment);
        void removeAccompaniment(Accompaniment* accompaniment);
        Accompaniment* getAccompaniment(string name);

    private:
        int sumOfAscii(string name);
};

#endif