#ifndef SNACK_H
#define SNACK_H

#include <iostream>
#include <string>

#include "linked_list.h"
#include "linked_list.cpp"

using namespace std;

class Snack{
    public:
        string name;
        linked_list<Snack*> accompaniments;

        Snack(string name);
        void addAccompaniment(Snack* snack);
        void removeAccompaniment(Snack* snack);
        bool canBeAccompanimentWith(Snack* snack);
};

#endif