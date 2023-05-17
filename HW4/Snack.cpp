#include "Snack.h"

Snack::Snack(string name){
    this->name = name;
}

void Snack::addAccompaniment(Snack* snack){
    for (int i = 0; i < this->accompaniments.size; i++){
        if (accompaniments[i] == snack){
            return;
        }
    }
    accompaniments.push_front(snack);
}

void Snack::removeAccompaniment(Snack* snack){
    for (int i = 0; i < this->accompaniments.size; i++){
        if (accompaniments[i] == snack){
            accompaniments.remove(snack);
            return;
        }
    }
}

bool Snack::canBeAccompanimentWith(Snack* snack){
    return accompaniments.contains(snack);
}