//
// Created by ethan on 3/8/2022.
//

#ifndef PA03_TEMPLATE_ARRAYCLASS_H
#define PA03_TEMPLATE_ARRAYCLASS_H


class ArrayClass {
public:
    ArrayClass();
    ArrayClass(int);
    void ArrayInOrderSort();
    void ArrayRandomSort();
    void ArrayBackwardsSort();
    int randNum(int&);
    int getSize();
    int* returnArray();
private:
    int size = 0;
    int array[0];
};


#endif //PA03_TEMPLATE_ARRAYCLASS_H
