//
// Created by ethan on 3/8/2022.
//

#include "ArrayClass.h"
#include <random>
using namespace std;
ArrayClass::ArrayClass() {
    array[size];
}

ArrayClass::ArrayClass(int size) {
    this->size = size;
    array[size];
}

int ArrayClass::getSize() {
    return size;
}

void ArrayClass::ArrayInOrderSort() {
    for (int i = 0; i <= size - 1; i++){
        array[i] = i;
    }
}

void ArrayClass::ArrayRandomSort() {
    int x = 0;
    for (int i = 0; i <= size - 1; i++) {
        array[i] = randNum(x);
    }
}

void ArrayClass::ArrayBackwardsSort() {
    for (int i = size - 1; i >= 0; i--){
        array[i] = i;
    }
}

/**
 * Creates a random number
 * and returns it
 * through pass by reference
 * @param x
 */
int ArrayClass::randNum(int& x) {
    random_device rdX;
    default_random_engine generatorX(rdX());
    uniform_int_distribution<int> distributionX(0,1000);
    x = distributionX(generatorX);
    return x;
}

int *ArrayClass::returnArray() {
    return array;
}
