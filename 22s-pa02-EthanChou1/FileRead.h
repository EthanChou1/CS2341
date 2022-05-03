//
// Created by Ethan Chou on 2/15/2022.
//

#ifndef INC_21F_PA02_FILEREAD_H
#define INC_21F_PA02_FILEREAD_H
#include <fstream>
#include <iostream>
#include "DSVector.h"
#include "DSString.h"
using namespace std;
class FileRead
{
public:

    void inputFileRead(ifstream&);
    void textFileReadWord(ifstream&, DSString&, int);
    void textFileReadPhrase(ifstream&, DSString&, int);
    bool isPhrase(DSString&);
    void outputToFile(ofstream&);
    FileRead() = default;
    explicit FileRead(const DSVector<DSString>&);
    ~FileRead() = default;
    DSVector<DSString> dataStructureGet();

private:

    DSVector<DSString> dataStructure;
};


#endif //INC_21F_PA02_FILEREAD_H
