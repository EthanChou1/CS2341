//
// Created by Ethan Chou on 1/24/2022.
//

#ifndef PA01_SENTIMENT_TWEETDATA_H
#define PA01_SENTIMENT_TWEETDATA_H

#include <iostream>
#include <vector>
#include "DSString.h"
using namespace std;
class tweetData {

public:
    ~tweetData();
    tweetData();
    tweetData(const DSString&);
    void setSentiment(int sentiment);
    int getSentiment() const;
    void setID(const DSString&);
    DSString getID() const;
    void tweetWord(const DSString&);
    DSString returnWord();



private:
    int sentiment;
    DSString id;
    DSString* tweet;
    DSString word;
    vector<DSString> words;
};


#endif //PA01_SENTIMENT_TWEETDATA_H
