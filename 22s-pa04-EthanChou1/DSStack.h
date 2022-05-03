//
// Created by ethan on 3/22/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_DSSTACK_H
#define INC_22S_FLIGHT_PLANNER_DSSTACK_H
#include "DSLinkedList.h"
#include "DSString.h"
template<class T>
class DSStack{
private:
    DSLinkedList<T> data;
public:

    bool empty();
    void push(const T&);
    T pop();
    T seeTop();
    T& getAtIndex(int);
    bool isInStack(T&);
    int getSize();

};

//Checks if stack is empty
template<class T>
bool DSStack<T>::empty() {
    if(data.getSize() != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Pushes to stack
template<class T>
void DSStack<T>::push(const T& data) {
    this->data.add(data);
}

//removes top from stack
template<class T>
T DSStack<T>::pop() {
    if(empty())
    {
        throw std::logic_error("Stack is empty");
    }
    return data.removeBack();
}

//Sees top but does not remove
template<class T>
T DSStack<T>::seeTop() {
    if(empty())
    {
        throw std::logic_error("Stack is empty");
    }
    return data.get(data.getSize() - 1);
}

//Gets at index from stack
template<class T>
T& DSStack<T>::getAtIndex(const int index) {
    return data.get(index);
}

//Checks if datatype is in stack
template<class T>
bool DSStack<T>::isInStack(T& dataType) {
    return data.contains(dataType);
}

//Gets size of stack
template<class T>
int DSStack<T>::getSize() {
    return data.getSize();
}


#endif //INC_22S_FLIGHT_PLANNER_DSSTACK_H
