//
// Created by Ethan Chou on 2/14/2022.
//

#ifndef INC_21F_PA02_DSVECTOR_H
#define INC_21F_PA02_DSVECTOR_H
#include <iostream>
using namespace std;
template<class T>
class DSVector
{
private:
    T* data;
    int size; //number of Elements
    int capacity; //Maximum capacity in data
    int iteratorCount; //Iterator counter


public:
    //Constructors
    DSVector();
    ~DSVector();
    DSVector(int initSize);
    DSVector(const DSVector& copyDSVector);

    //Functions
    void resize();
    int getSize();
    int getCapacity();
    void removeIndex(int index);
    T& indexAt(int index);
    void push_back(const T&);
    void removeLast();
    void sortVector();
    void sortVectorDSStringInt();
    T& iteratorVector();
    void resetIterator();
    int getIterator();
    bool isEmpty();

    //Overloaded operators
    DSVector& operator=(const DSVector& arg);
    DSVector& operator[](int arg);


};

//Default constructor
template<class T>
DSVector<T>::DSVector()
{
    size = 0;
    capacity = 10; //Initial value of 10 according to assignment
    data = new T[capacity];
    iteratorCount = 0;
}

//Destructor
template<class T>
DSVector<T>::~DSVector() {
    delete[] data;
}

//Full constructor
template<class T>
DSVector<T>::DSVector(int initSize) {
    size = 0;
    capacity = initSize;
    data = new T[capacity];
    iteratorCount = 0;
}

//Copy Constructor
template<class T>
DSVector<T>::DSVector(const DSVector& copyDSVector) {
    size = copyDSVector.size;
    capacity = copyDSVector.capacity;
    data = new T[capacity];
    iteratorCount = copyDSVector.iteratorCount;
    for( int i = 0; i < capacity; i++)
    {
        data[i] = copyDSVector.data[i];
    }
}

//Resizes the capacity of the vector by doubling it
template<class T>
void DSVector<T>::resize() {
    T* temp = new T[capacity * 2];
    for( int i = 0; i < capacity; i++)
    {
        temp[i] = data[i];
    }
    delete[] data; //Deallocates
    data = temp;
    capacity *= 2;
}

//Gets size
template<class T>
int DSVector<T>::getSize() {
    return size;
}

//Gets capacity
template<class T>
int DSVector<T>::getCapacity() {
    return capacity;
}

//Adds to end of vector
template<class T>
void DSVector<T>::push_back(const T& value) {
    if(size == capacity)
    {
        resize();
    }
    data[size] = value;
    size++;
}

//Assignment operator
template<class T>
DSVector<T>& DSVector<T>::operator=(const DSVector& arg) {
    if(&arg != this)
    {
        delete[] data;
    }
    size = arg.size;
    capacity = arg.capacity;
    data = new T[capacity];
    for(int i = 0; i < size; i++)
    {
        data[i] = arg.data[i];
    }
    return *this;
}

//[] Operator
template<class T>
DSVector<T> &DSVector<T>::operator[](int arg) {
    if(arg > size) //Makes sure it is within bounds
    {
        throw std::out_of_range("Index not available");
    }
    return data[arg];
}

//Removes last element
template<class T>
void DSVector<T>::removeLast() {
    if(size > 0)
    {
        size--;
    }
    else
    {
        throw std::out_of_range("Index not available");
    }
}

//Removes from certain index
template<class T>
void DSVector<T>::removeIndex(int index) {
    if(index < 0)
    {
        throw std::out_of_range("Index not available");
    }
    for(int i = index; i < size - 1; i++)
    {
        data[i] = data[i+1];
    }
}

//Gets specific index
template<class T>
T& DSVector<T>::indexAt(int index) {
    if(index > size) //Makes sure it is within bounds
    {
        throw std::out_of_range("Index not available");
    }
    return data[index];
}

//Sorts in according to alphabet
template<class T>
void DSVector<T>::sortVector() {
    int first;
    int second;
    bool swap = false;
    T one;
    T two;
    for(first = 0; first < size - 1; first++)
    {
        for(second = 0; second < size - first - 1; second++)
        {
            //Swap indexes if true
            if(data[second] > data[second+1])
            {
                one = data[second];
                two = data[second+1];
                data[second] = two;
                data[second + 1] = one;
                swap = true;
            }
        }
        if(!swap)
        {
            break;
        }
    }
}

//Sorts if Vector contains DSString of a number
template<class T>
void DSVector<T>::sortVectorDSStringInt() {
    int first;
    int second;
    bool swap = false;
    T one;
    T two;
    int temp;
    int temp2;
    for(first = 0; first < size - 1; first++)
    {
        for(second = 0; second < size - first - 1; second++)
        {
            temp = atoi(data[second].c_str()); //Converts DSString to int
            temp2 = atoi(data[second + 1].c_str());
            if(temp > temp2) //Standard int comparison
            {
                one = data[second];
                two = data[second+1];
                data[second] = two;
                data[second + 1] = one;
                swap = true;
            }
        }
        if(!swap)
        {
            break;
        }
    }
}

//Iterator
template<class T>
T& DSVector<T>::iteratorVector() {
    int temp = iteratorCount;
    iteratorCount++;
    if(iteratorCount > size)
    {
        throw std::out_of_range("Index not available, please reset Iterator");
    }
    else
    {
        return data[temp];
    }
}

//Resets Iterator
template<class T>
void DSVector<T>::resetIterator() {
    iteratorCount = 0;
}

//Get iterator count
template<class T>
int DSVector<T>::getIterator() {
    return iteratorCount;
}

template<class T>
bool DSVector<T>::isEmpty() {
    if (size == 0) {
        return true;
    }
    return false;
}


#endif //INC_21F_PA02_DSVECTOR_H
