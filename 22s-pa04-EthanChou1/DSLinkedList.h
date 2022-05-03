//
// Created by ethan on 3/22/2022.
//
#ifndef INC_2341_PA04TEMPLATE_DSLINKEDLIST_H
#define INC_2341_PA04TEMPLATE_DSLINKEDLIST_H

#include <iostream>
#include <fstream>
#include "Airport.h"
using namespace std;
template<typename T>
class Node {
public:
    T dataType;
    Node<T> *nextNode;
    Node<T> *previousNode;
    //Default constructor
    Node(){
        nextNode = nullptr;
        previousNode = nullptr;
    }

    Node(const T& dataType){
        this->dataType = dataType;
        nextNode = nullptr;
        previousNode = nullptr;
    }

    Node(const Node<T>& node)
    {
        nextNode = nullptr;
        previousNode = nullptr;
        this->dataType = node.dataType;
    }

    //Overloaded stream operator
    friend ostream& operator<<(ostream& output, const Node<T> &node)
    {
        output << node.dataType;
        return output;
    }
};

template<typename T> class DSLinkedList{
public:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *iterator;
    int size;

    DSLinkedList();
    DSLinkedList(const T& nodeConstruct);
    DSLinkedList(const DSLinkedList<T> &list);
    ~DSLinkedList();
    void add(const T& newNode);
    void addToHead(const T& newNode);
    void moveIteratorToHead();
    int getSize();
    bool contains(const T& dataType);
    bool hasNext();
    void remove(int index);
    T removeBack();
    T& get(int);
    void iterateToNext();
    void clearAll();
    T returnNext();

    DSLinkedList<T>& operator=(const DSLinkedList<T>&);


};

//Constructors
template<typename T>
DSLinkedList<T>::DSLinkedList() {
    head = nullptr;
    tail = nullptr;
    iterator = nullptr;
    size = 0;
}

template<typename T>
DSLinkedList<T>::DSLinkedList(const T &nodeConstruct) {
    auto *node = new Node<T>(nodeConstruct);
    head = tail = iterator = node;
    size = 1;
}

template<typename T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList<T> &list) {
    if(list.size == 0)
    {
        head = tail = iterator = nullptr;
        size = 0;
    }
    else
    {
        add(list.head->dataType);
        if(list.size == 1)
        {
            tail = head;
        }
        else{
            Node<T> *currentNode = list.head->nextNode;
            while( currentNode != nullptr)
            {
                add(currentNode->dataType);
                tail = currentNode;
                currentNode = currentNode->nextNode;
            }
        }
        size = list.size;
    }

}

//Adds node to link list
template<typename T>
void DSLinkedList<T>::add(const T &newNode) {
    Node<T> *node = new Node<T>(newNode);
    if(size == 0)
    {
        head = tail = iterator = node;
    }
    else
    {
        Node<T> *currentNode = head;
        while(currentNode->nextNode != nullptr)
        {
            currentNode = currentNode->nextNode;
        }

        currentNode->nextNode = node;
        node->previousNode = currentNode;
        tail = node;
    }
    size++;
}

//Adds to front of link list
template<typename T>
void DSLinkedList<T>::addToHead(const T &newNode) {
    Node<T> *node = new Node<T>(newNode);
    if(size == 0)
    {
        head = tail = iterator = nullptr;
    }
    else
    {
        head->previousNode = node;
        node->nextNode = head;
        head = node;
    }
    size++;
}

//Destructor
template<typename T>
DSLinkedList<T>::~DSLinkedList() {
    clearAll();
}

//Gets link list size
template<typename T>
int DSLinkedList<T>::getSize() {
    return size;
}

//Removes from index of link list
template<typename T>
void DSLinkedList<T>::remove(int index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index is out of bounds");
    }
    if(size == 0) {
        return;
    }
    if (size == 1) {
        tail = nullptr;
        iterator = nullptr;
        delete head;
        head = nullptr;
        size = 0;
    }
    else if (index == 0) {
        Node<T>* temp = head;
        head = temp->nextNode;
        delete temp;
        head->previousNode = nullptr;
        size--;
    }
    else if (index == size-1) {
        Node<T>* temp = tail;
        tail = temp->previousNode;
        delete temp;
        tail->nextNode = nullptr;
        size--;
    }
    else {
        Node<T>* currentNode = head;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->nextNode;
        }
        currentNode->nextNode->previousNode = currentNode->previousNode;
        currentNode->previousNode->nextNode = currentNode->nextNode;
        delete currentNode;
        size--;
    }
}

//Operator = assignment overload
template<typename T>
DSLinkedList<T> &DSLinkedList<T>::operator=(const DSLinkedList<T> &newList) {
    clearAll();
    if(newList.size == 0)
    {
        head = tail = iterator = nullptr;
        size = 0;
    }
    else
    {
        add(newList.head->dataType);
        if(newList.size == 1)
        {
            tail = head;
        }
        else
        {
            Node<T> *currentNode = newList.head->nextNode;
            while(currentNode != nullptr)
            {
                add(currentNode->dataType);
                tail = currentNode;
                currentNode = currentNode->nextNode;
            }
        }
        size = newList.size;
    }
    return *this;
}

//Check if link list contains datatype
template<typename T>
bool DSLinkedList<T>::contains(const T& data) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->dataType == data) {
            return true;
        }
        current = current->nextNode;
    }
    return false;
}

//Deletes link list contents
template<typename T>
void DSLinkedList<T>::clearAll() {
    if (size != 0) {
        if (size == 1) {
            tail = nullptr;
            iterator = nullptr;
            delete head;
        }
        else {
            tail = nullptr;
            iterator = nullptr;
            while (head != nullptr) {
                Node<T>* currentNode = head;
                head = head->nextNode;
                delete currentNode;
            }
        }
        size = 0;
    }
}

//Removes end of Link list
template<typename T>
T DSLinkedList<T>::removeBack() {
    if(size == 0)
    {
        throw std::out_of_range("Linked List is empty");
    }
    if (size != 0) {
        if (size == 1) {
            T element = tail->dataType;
            tail = nullptr;
            iterator = nullptr;
            delete head;
            size = 0;
            return element;
        }
        else {
            T element = tail->dataType;
            remove(size-1);
            return element;
        }
    }
}

//Gets data from index of link list
template<typename T>
T &DSLinkedList<T>::get(int index) {
    if(index >= size || index < 0)
    {
        throw std::out_of_range("Index is out of bounds");
    }
    Node<T> *currentNode = head;
    for(int i = 0; i < index; i++)
    {
        currentNode = currentNode->nextNode;
    }
    return currentNode->dataType;
}

//Iterates to next node
template<typename T>
void DSLinkedList<T>::iterateToNext() {
        iterator = head->nextNode;
}

//Returns next node
template<typename T>
T DSLinkedList<T>::returnNext() {
    T item = iterator->dataType;
    iterator = iterator->nextNode;
    return item;
}

//Moves iterator to front
template<typename T>
void DSLinkedList<T>::moveIteratorToHead() {
    iterator = head;
}

//Checks if link list has next node
template<typename T>
bool DSLinkedList<T>::hasNext() {
    if (iterator == nullptr) {
        return false;
    }
    return true;
}

#endif //INC_2341_PA04TEMPLATE_DSLINKEDLIST_H
