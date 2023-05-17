#include "SnackHashing.h"

SnackHashing::SnackHashing(){
    for (int i = 0; i < 11; i++){
        table[i] = NULL;
    }
}

void SnackHashing::addSnack(Snack* snack){
    int hash = (sumOfAscii(snack->name) % 11);
    table[hash] = snack;
}

Snack* SnackHashing::getSnack(string name){
    int hash = (sumOfAscii(name) % 11);
    return table[hash];
}

int SnackHashing::sumOfAscii(string name){
    int sum = 0;
    for (char c: name){
        sum += (int) c;
    }
    return sum;
}