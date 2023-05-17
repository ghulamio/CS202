#include "AccompanimentHashing.h"

AccompanimentHashing::AccompanimentHashing(){
    for (int i = 0; i < 71; i++){
        table[i] = NULL;
    }
}

void AccompanimentHashing::addAccompaniment(Accompaniment* accompaniment){
    int hash = (sumOfAscii(accompaniment->name) % 71);
    table[hash] = accompaniment;
}

void AccompanimentHashing::removeAccompaniment(Accompaniment* accompaniment){
    int hash = (sumOfAscii(accompaniment->name) % 71);
    table[hash] = NULL;
}

Accompaniment* AccompanimentHashing::getAccompaniment(string name){
    int hash = (sumOfAscii(name) % 71);
    return table[hash];
}

int AccompanimentHashing::sumOfAscii(string name){
    int sum = 0;
    for (char c: name){
        sum += (int) c;
    }
    return sum;
}