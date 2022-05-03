#include <iostream>
#include <chrono>
#include "ArrayClass.h"
#include "include/sorting_library.h"
using namespace std;

int main() {

    //make some data to sort
    //Can't delete for something otherwise code won't work
    const int DATA_SIZE = 100000; //tested with 0, 20000, 40000, 60000, 80000, and 100000
    int data[DATA_SIZE];
    for (int i = DATA_SIZE - 1; i >= 0; i--)
        data[i] = i;

    //Replace mystery01 with any number from 1-5 ex: mystery02
    ArrayClass array(DATA_SIZE);
    cout << "Ordered Array" << endl;
    //Array already in order
    array.ArrayInOrderSort();

    cout << fixed << showpoint;
    cout.precision(9);
    print_version_number();

    chrono::time_point<chrono::high_resolution_clock> start, end;

    start = chrono::high_resolution_clock::now();
    mystery03(array.returnArray(), array.getSize());
    end = chrono::high_resolution_clock::now();

    chrono::duration<double> time_in_seconds = end - start;
    cout << fixed << "Duration: " << time_in_seconds.count() << endl;

    cout << "Backwards Array" << endl;
    //Array in backwards order
    array.ArrayBackwardsSort();

    cout << fixed << showpoint;
    cout.precision(9);
    print_version_number();

    start = chrono::high_resolution_clock::now();
    mystery03(array.returnArray(), array.getSize());
    end = chrono::high_resolution_clock::now();

    time_in_seconds = end - start;
    cout << fixed << "Duration: " << time_in_seconds.count() << endl;

    cout << "Random Array" << endl;
    array.ArrayRandomSort();

    cout << fixed << showpoint;
    cout.precision(9);
    print_version_number();

    start = chrono::high_resolution_clock::now();
    mystery03(array.returnArray(), array.getSize());
    end = chrono::high_resolution_clock::now();

    time_in_seconds = end - start;
    cout << fixed << "Duration: " << time_in_seconds.count() << endl;
    return 0;
}
