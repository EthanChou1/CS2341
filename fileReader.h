//
// Created by Ethan Chou on 1/30/2022.
//

#ifndef PA01_SENTIMENT_FILEREADER_H
#define PA01_SENTIMENT_FILEREADER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "DSString.h"
#include "tweetData.h"
#include <algorithm>
using namespace std;

void trainingFileRead(ifstream&, ostream&, vector<tweetData>&);

int filterChar(char*);

void testFileRead(ifstream&, ostream&, vector<tweetData>&, vector<tweetData>&);

int wordCompare(const vector<tweetData>&, DSString);

void resultCompare(const vector<tweetData>&, ifstream&, ostream&);

#endif //PA01_SENTIMENT_FILEREADER_H
