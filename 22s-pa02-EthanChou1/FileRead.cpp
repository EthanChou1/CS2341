//
// Created by Ethan Chou on 2/15/2022.
//

#include "FileRead.h"

//Constructor
FileRead::FileRead(const DSVector<DSString>& temp) {
    dataStructure = temp;
}

//Returns a DSVector of DSStrings
DSVector<DSString> FileRead::dataStructureGet() {
    return dataStructure;
}

/**
 * Reads in the terms.txt file and gets a DSVector of DSStrings
 * @param file
 */
void FileRead::inputFileRead(ifstream& file) {
    DSString temp;
    char* buffer = new char[100];
    while(file.getline( buffer, 100) ) {
        temp = buffer;
        temp.toLowerCase(); //Converts to lower case
        dataStructure.push_back(temp);
        int count = 0;
        for(int i = 0 ; i < dataStructure.getSize(); i++) //Removes duplicates
        {
            if(dataStructure.indexAt(i) == temp)
            {
                count++;
                if(count > 1)
                {
                    dataStructure.removeLast();
                    count = 0;
                }
            }
        }
    }
    dataStructure.sortVector(); //Sorts in alphabetical order
    delete[] buffer; //Deallocates
}

/**
 * Reads in test_book.txt, if term is a single word, uses this function
 * It goes through each word in test_book.txt and compares.
 * If true, adds page number to Term through concatenation
 * @param file
 * @param term
 * @param vectorIndex
 */
void FileRead::textFileReadWord(ifstream& file, DSString& term, int vectorIndex) {
    char* buffer = new char[256];
    file.clear();
    file.seekg(0, ios::beg);
    DSString pageNum;
    DSVector<DSString> pageNums;
    int count;
    while(!file.eof())
    {
        file.getline(buffer, 256);
        int index = 0;
        while(buffer[index] != '\0')
        {
            buffer[index] = tolower(buffer[index]); //Makes the line lowercase
            index++;
        }
        char* word = strtok(buffer, "\""); //Gets line into individual words
        DSString linePhrase(word);
        while(word!= nullptr)
        {
            if(linePhrase.getLength() > 0)
            {
                if(word[0] == '<' && word[strlen(word)-1] == '>') //If word is a page number, retrieves the page number
                {
                    char *token = strtok(word, "<>");
                    pageNum = token;
                }
                else
                {
                    char *token = strtok(word, " .,:;?![]()\"");
                    if(token != nullptr && strcmp(token, term.c_str()) == 0) //Compares word to term
                    {
                        count = 0;
                        pageNums.push_back(pageNum); //Adds page number to DSVector of int
                        for(int i = 0 ; i < pageNums.getSize(); i++)
                        {
                            if(pageNum == pageNums.indexAt(i))
                            {
                                count++;
                                if(count > 1) //Removes identical page numbers
                                {
                                    pageNums.removeLast();
                                    count = 0;
                                }
                            }
                        }
                    }
                }

            }
            word = strtok(nullptr, "\"");
        }
    }
    pageNums.sortVectorDSStringInt();
    delete[] buffer; //Deallocates
    term = term + ": "; //Adds page numbers to term ex: word: 1, 3, 6
    for(int i = 0; i < pageNums.getSize(); i++)
    {
        if(i < pageNums.getSize() - 1)
        {
            term = term + pageNums.indexAt(i);
            term = term + ", ";
        }
        else if(i < pageNums.getSize())
        {
            term = term + pageNums.indexAt(i);
        }
    }
    dataStructure.indexAt(vectorIndex) = term; //Reassigns term to term in dataStructure
}

/**
 * Reads in test_book.txt, if term is a phrase, uses this function
 * It goes through each word in test_book.txt and compares.
 * If true, adds page number to Term through concatenation
 * @param file
 * @param term
 * @param vectorIndex
 */
void FileRead::textFileReadPhrase(ifstream& file, DSString& term, int vectorIndex) {
    char* buffer = new char[256];
    file.clear();
    file.seekg(0, ios::beg);
    DSString pageNum;
    DSVector<DSString> pageNums;
    DSVector<DSString> wordPhrase;
    DSString tempPhrase = term;
    int counter = 0;
    char* phraseBuffer = strtok(tempPhrase.c_str(), " .,:;[]()?!\"");
    while(phraseBuffer != nullptr) //Breaks up the phrase into individual words and stores in DSVector of DSString
    {
        DSString temp(phraseBuffer);
        wordPhrase.push_back(temp);
        phraseBuffer = strtok(nullptr, " .,:;[]()?!\"");
    }
    while(!file.eof())
    {
        file.getline(buffer, 256);
        int index = 0;
        while(buffer[index] != '\0')
        {
            buffer[index] = tolower(buffer[index]); //Makes the line lowercase
            index++;
        }
        char* word = strtok(buffer, "\"");
        DSString linePhrase(word);
        while(word!= nullptr)
        {
            if(linePhrase.getLength() > 0)
            {
                if(word[0] == '<' && word[strlen(word)-1] == '>')
                {
                    char* token = strtok(word, "<>"); //Gets page number
                    pageNum = token;
                }
                else if(word[0] != '<' && word[strlen(word)-1] != '>') {
                    char *token = strtok(word, " .,:;[]()?!\""); //Gets word from line
                    if (token != nullptr && counter < wordPhrase.getSize() &&
                        strcmp(token, wordPhrase.indexAt(counter).c_str()) == 0) //Compares word to first item in Vector
                    {
                        if (counter < wordPhrase.getSize()) //Goes on to next term
                        {
                            counter++;
                        }
                    }
                    else //Resets counter
                    {
                        counter = 0;
                    }
                    if(counter == wordPhrase.getSize()){
                        int count = 0;
                        pageNums.push_back(pageNum); //Adds page number to DSVector of int
                        for(int i = 0 ; i < pageNums.getSize(); i++){
                            if(pageNum == pageNums.indexAt(i)){
                                count++;
                                if(count > 1) //Removes identical page numbers
                                {
                                    pageNums.removeLast();
                                    count = 0;
                                }
                            }
                        }
                    }
                }
            }
            word = strtok(nullptr, "\"");
        }
    }
    pageNums.sortVectorDSStringInt();
    delete[] buffer; //Deallocates
    term = term + ": "; //Adds page numbers to term ex: word: 1, 3, 6
    for(int i = 0; i < pageNums.getSize(); i++)
    {
        if (i < pageNums.getSize() - 1) {
            term = term + pageNums.indexAt(i);
            term = term + ", ";
        } else if (i < pageNums.getSize()) {
            term = term + pageNums.indexAt(i);
        }
    }
    dataStructure.indexAt(vectorIndex) = term; //Reassigns term to term in dataStructure
}

/**
 * Sees if dsString is a single word or phrase, determines which
 * Searching function to use.
 * @param dsString
 */
bool FileRead::isPhrase(DSString& dsString) {
    for(int i = 0; i < dsString.getLength(); i++)
    {
        if(dsString[i] == ' '|| dsString[i] == '.' || dsString[i] == '?' || dsString[i] == '!') //If term has a space or period in it means it is a phrase
        {
            return true;
        }
    }
    return false;
}

/**
 * Formats the data and outputs to output.txt
 * The first line will contain 65 characters,
 * and subsequent lines will contain 70 characters
 * @param output
 */
void FileRead::outputToFile(ofstream& output) {
    char buffer;
    char upperIndex;
    int count = 0;
    buffer = dataStructure.indexAt(0).c_str()[0];
    for(int i = 0; i < dataStructure.getSize(); i++)
    {
        DSString check = dataStructure.indexAt(i).c_str();
        if(check[check.getLength() - 1] == ' ') //If there are no numbers at the end, skip to next
        {
            i++;
        }
        upperIndex = toupper(buffer);
        if(count == 0)
        {
            output << "[" << upperIndex << "]" << endl; //Prints out first letter of index upper case
            for(int j = 0; j < dataStructure.getSize(); j++)
            {
                if(buffer == dataStructure.indexAt(j).c_str()[0]) {
                    if(dataStructure.indexAt(j).getLength() < 70) //If original string is less than 70 characters
                    {
                        output << dataStructure.indexAt(j) << endl;
                    }
                    else if(dataStructure.indexAt(j).getLength() > 70)
                    {
                        //Gets number of times the original string needs to be moved to a new line
                        int divCount = dataStructure.indexAt(j).getLength() / 65; //65 because need to account for index lines
                        int lastIndex = 0;
                        output << dataStructure.indexAt(j).substring(0, 61) << endl; //First line
                        for(int k = 1; k < divCount; k++) //Subsequent lines
                        {
                            //Creates a substring from original string with starting index of multiple of 65, and length of 64 due to 4 spaces of indexing
                            lastIndex = (65*k)+61;
                            output << "    " << dataStructure.indexAt(j).substring(65*k - 4, (65*k)+61) << endl;
                        }
                        //Prevents the function from outputting duplicates
                        if( divCount == 1)
                        {
                            lastIndex = 61;
                            output << "    " << dataStructure.indexAt(j).substring(lastIndex, dataStructure.indexAt(j).getLength()) << endl;
                        }
                        else
                        {
                            //Final line
                            output << "    " << dataStructure.indexAt(j).substring(lastIndex, dataStructure.indexAt(j).getLength()) << endl;
                        }
                    }
                }
            }
            count++;
        }
        else if(buffer != dataStructure.indexAt(i).c_str()[0]) //If first letter of new word is different
        {
            buffer = dataStructure.indexAt(i).c_str()[0]; //Reassigns new letter
            count = 0;
            i--;
        }
    }
}