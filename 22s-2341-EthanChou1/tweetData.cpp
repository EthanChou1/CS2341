//
// Created by Ethan Chou on 1/24/2022.
//

#include "tweetData.h"
#include "DSString.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * Destructor
 */
tweetData::~tweetData() {
    delete tweet;
}

/**
 * Base Constructor
 */
tweetData::tweetData() {
    tweet = nullptr;
    sentiment = 0;
}

/**
 * Overloaded Constructor
 * @param word
 */
tweetData::tweetData(const DSString& word) {
    this->word = word;
}

/**
 * Sets the sentiment value
 * @param sent
 */
void tweetData::setSentiment(int sent) {
    this->sentiment = sent;
}

/**
 * Returns the sentiment value
 */
int tweetData::getSentiment() const {
    return sentiment;
}

/**
 * Sets the word
 * @param word
 */
void tweetData::tweetWord(const DSString& word) {
    this->word = word;
}

/**
* Returns the word
*/
DSString tweetData::returnWord() {
    return word;
}

/**
* Sets ID
*/
void tweetData::setID(const DSString& id) {
    this->id = id;
}

/**
* Returns ID
 * @returns id
*/
DSString tweetData::getID() const {
    return id;
}
