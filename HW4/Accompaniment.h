#ifndef ACCOMPANIMENT_H
#define ACCOMPANIMENT_H

#include <iostream>

#include "Snack.h"

using namespace std;

class Accompaniment{
    public:
        string name;
        Snack* snack1;
        Snack* snack2;

        Accompaniment(string name, Snack* snack1, Snack* snack2);
};

#endif