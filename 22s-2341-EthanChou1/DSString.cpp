//
// Created by mark on 6/2/2021.
//

#include "DSString.h"
#include <iostream>
#include <cstring>

//Creates a basic string with a null terminator
DSString::DSString() {
    length = 0;
    word = new char[length+1];
    word[length] = '\0'; //Null terminator at end
}

//Copy constructor
DSString::DSString(const char* input) {
    if(input == nullptr)
    {
        word = nullptr; //If nullptr is passed in
    }
    else
    {
        length = static_cast<int>(strlen(input));
        word = new char[length + 1];
        strcpy(word, input); //strcpy auto adds null terminator
    }
}

//Copy constructor
DSString::DSString(const DSString &newWord) {
    length = newWord.length;
    word = new char[length+1];
    for(int i = 0; i < length; i++)
    {
        word[i] = newWord.word[i];
    }
    word[length] = '\0'; //Null terminator at end
}

//Destructor
DSString::~DSString() {
    delete[] word;
}

//gets length of DSString
int DSString::getLength() {
    return static_cast<int>(strlen (this->word));
}

//Gets the word
char *DSString::c_str() {
    return word;
}

//Assigns a new word to DSString
DSString &DSString::operator=(const char *newWord) {
    if(length != static_cast<int>(strlen(newWord))) //If lengths are different, create new length
    {
        delete[] word;
        length = static_cast<int>(strlen(newWord));
        word = new char[length + 1]; //Makes sure DSString has enough room to store char
        word[length] = '\0'; //Null terminator at end
    }
    strcpy(word, newWord);
    return *this;
}

//Assigns a new word to DSString
DSString &DSString::operator=(const DSString &newWord) {
    if(length != newWord.length) //If lengths are different, create new length
    {
        delete[] word;
        length = newWord.length;
        word = new char[length + 1];
        word[length] = '\0'; //Null terminator at end
    }
    for(int i = 0; i < length; i++) //Copies over char
    {
        word[i] = newWord.word[i];
    }
    return *this;
}

//Adds a new word to DSString
DSString DSString::operator+(const DSString &newword) {
    int newLength = length + newword.length; //new length from original word and new word
    char* charTemp = new char[newLength + 1];
    charTemp[newLength] = '\0'; //Null terminator at end
    charTemp = strcpy(charTemp, word);
    for(int i = 0; i<newword.length; i++)
    {
        charTemp[i+length] = newword.word[i]; //Adds the new word to end
    }
    DSString newWord(charTemp);
    return newWord;
}

//Compares two DSString
bool DSString::operator==(const char *compareWord) {
    if(length != strlen(compareWord)) //If lengths are different, automatically false
    {
        return false;
    }
    for(int i = 0; i < length; i++)
    {
        if(this->word[i] != compareWord[i]) //Goes through each character
        {
            return false;
        }
    }
    return true;
}

//Compares two DSString
bool DSString::operator==(const DSString &compareString) {
    if(length != compareString.length) //If lengths are different, automatically false
    {
        return false;
    }
    for(int i = 0; i < length; i++)
    {
        if(this->word[i] != compareString.word[i]) //Goes through each character
        {
            return false;
        }
    }
    return true;
}

bool DSString::operator>(const DSString &compareString) {
    int num = strcmp(word, compareString.word);
    if(num > 0){
        return true;
    }
    return false;
}

bool DSString::operator>(const char *compareString) {
    int num = strcmp(word, compareString);
    if(num > 0){
        return true;
    }
    return false;
}

char &DSString::operator[](const int index) {
    if(index > length) //Makes sure it is within bounds
    {
        throw std::out_of_range("Index not available");
    }
    return word[index];
}

DSString DSString::substring(int start, int numChars) {
    if(start >= length || numChars >= length)//Makes sure it is within bounds
    {
        throw std::out_of_range("Index not available");
    }
    else
    {
        DSString tempString;
        tempString.word = new char[numChars + 1];
        tempString.length = numChars;
        strncpy(tempString.word, word + start, numChars);
        tempString.word[numChars] = '\0'; //Null terminator at end
        return tempString;
    }

}


std::ostream &operator<<(std::ostream &stream, const DSString &customWord) {
    stream << customWord.word;
    return stream;
}

