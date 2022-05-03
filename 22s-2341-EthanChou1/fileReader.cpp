//
// Created by Ethan Chou on 1/30/2022.
//

#include "fileReader.h"
#include "tweetData.h"

/**
 * Creates a vector of tweetData which contains a word and a sentiment value
 * The words come from a tweet, which is broken up into words
 * This function also finds the sentiment associated with the tweet.
 * @param file
 * @param output
 * @param dataBase
 */
void trainingFileRead(ifstream& file, ostream& output, vector<tweetData>& dataBase) {
    DSString temp;
    bool first = true;
    char* buffer = new char[50000];
    int count = 0;
    int compare = 0;
    while(file.getline( buffer, 5000, ',' ) )
    {
        tweetData bufferData;
        int sentimentValue;
        if(first) //Ignores first line of csv file
        {
            file.getline( buffer, 5000);
            first = false;
        }
        if(count == 1) //Gets the sentiment value from the first column of csv file
        {
            sentimentValue = atoi(buffer); //using strtol doesn't work for some reason
            bufferData.setSentiment(sentimentValue);
            compare = bufferData.getSentiment();
        }
        if(count == 5) //Gets the actual tweet
        {
            file.getline( buffer, 5000);
            count = 0; //resets count so moves on to next line in csv file
            if(compare == 4)
            {
                char *token = strtok(buffer, ",.;?! ");
                // Keep printing tokens while one of the
                // delimiters present in str[].
                while (token != nullptr)
                {   //Words that don't have a particular meaning are filtered out -- should probably make this a function proof of concept first
                    if(filterChar(token) == 1)
                    {
                        break;
                    }
                    temp = token;
                    tweetData userData;
                    DSString tempTwo(temp);
                    userData.tweetWord(tempTwo);
                    userData.setSentiment(1); //positive word
                    dataBase.push_back(userData); //Adds tweetData object to vector
                    token = strtok(nullptr, ",.;?! "); //Moves on to next word
                }
            }
            else
            {
                char *token = strtok(buffer, ",.;?! ");
                while (token != nullptr)
                {
                    if(filterChar(token) == 1)
                    {
                        break;
                    }
                    tweetData userData;
                    temp = token;
                    DSString tempTwo(temp);
                    userData.setSentiment(-1); // negative word
                    userData.tweetWord(tempTwo);
                    dataBase.push_back(userData); //Adds tweetData object to vector
                    token = strtok(nullptr, ",.;?! "); //Moves on to next word
                }
            }
        }
        count++;
    }
    delete[] buffer; //Deallocates buffer
}

/**
 * Creates a vector of tweetData which contains a word and a id value
 * The words come from a tweet, which is broken up into words
 * This function will also compare the words from that tweet to the dataBase
 * created from the training set, and give it a sentiment value based off of it.
 * @param file
 * @param output
 * @param trainingDataBase
 * @param testingData
 */
void testFileRead(ifstream& file, ostream& output, vector<tweetData>& trainingDataBase, vector<tweetData>& testingData) {
    DSString temp;
    DSString tweet;
    DSString id;
    bool first = true;
    char* buffer = new char[50000];
    int count = 0;
    int sentiment = 0;
    tweetData bufferData;
    while(file.getline( buffer, 50000, ',' ) )
    {
        if(first) //Ignores first line of csv file
        {
            file.getline( buffer, 5000);
            first = false;
        }
        if(count == 1) //Gets user ID
        {
            id = buffer;
        }
        if(count == 4) //Gets actual tweet
        {
            file.getline( buffer, 5000);
            count = 0; //resets count so moves on to next line in csv file
            tweetData userData;
            userData.setID(id);
            tweet = buffer;
            userData.tweetWord(tweet);
            char *token = strtok(buffer, ",.;?! "); //Splits the tweet into a word
            while (token != nullptr) {
                if(filterChar(token) == 1)
                {
                    break;
                }
                temp = token;
                DSString tempTwo(temp);
                sentiment = wordCompare(trainingDataBase, tempTwo); //Compares the word to database
                token = strtok(nullptr, ",.;?! ");
            }
            userData.setSentiment(sentiment); //Sets the analyzed sentiment value to tweetData object
            testingData.push_back(userData); //Adds userData to vector
        }
        count++;
    }
    delete[] buffer; //Deallocates buffer
}

/**
 * Compares a DSString word to the created database, and calculates the sentiment
 * @param trainingData
 * @param wordTweet
 * @return sentiment
 */
int wordCompare(const vector<tweetData>& trainingData, DSString wordTweet) {
    int sentiment = 0;
    tweetData temp;
    for(auto & i : trainingData) //Goes through created database
    {
        temp = i;
        if(wordTweet == temp.returnWord())
        {
            sentiment = temp.getSentiment() + sentiment; //Adds total sentiment
        }
        else
        {
            continue;
        }
    }
    if(sentiment > 0) //If positive
    {
        sentiment = 4;
        return sentiment;
    }
    else if(sentiment < 0) //If negative
    {
        sentiment = 0;
        return sentiment;
    }
    return sentiment;
}

/**
 * Goes through and filters the database for commonly used words,
 * such as pronouns, or words that don't mean anything like
 * "the", "that", conjunctions.
 * @param token
 * @return int
 */
int filterChar(char *token) {
    if(strcmp(token, "Or") == 0 ||strcmp(token, "yet") == 0 ||
       strcmp(token, "nor") == 0 ||strcmp(token, "Not") == 0 ||
       strcmp(token, "not") == 0 ||strcmp(token, "No") == 0 ||
       strcmp(token, "Yes") == 0 ||strcmp(token, "yes") == 0 ||
       strcmp(token, "just") == 0 ||strcmp(token, "Just") == 0 ||
       strcmp(token, "Haha") == 0 ||strcmp(token, "haha") == 0 ||
       strcmp(token, "Have") == 0 ||strcmp(token, "hey") == 0 ||
       strcmp(token, "Hey") == 0 ||strcmp(token, "going") == 0 ||
       strcmp(token, "lol") == 0 ||strcmp(token, "LOL") == 0 ||
       strcmp(token, "Oh") == 0 ||strcmp(token, "oh") == 0 ||
       strcmp(token, "But") == 0 ||strcmp(token, "no") == 0 ||
       strcmp(token, "but") == 0 ||strcmp(token, "IM") == 0 ||
       strcmp(token, "can't") == 0 ||strcmp(token, "Can't") == 0 ||
       strcmp(token, "cant") == 0 ||strcmp(token, "Cant") == 0 ||
       strcmp(token, "can") == 0 ||strcmp(token, "Can") == 0 ||
       strcmp(token, "as") == 0 ||strcmp(token, "That") == 0 ||
       strcmp(token, "\"") == 0 ||strcmp(token, "our") == 0 ||
       strcmp(token, "those") == 0 ||strcmp(token, "!") == 0 ||
       strcmp(token, "?") == 0 ||strcmp(token, "-") == 0 ||
       strcmp(token, "mine") == 0 ||strcmp(token, "Mine") == 0 ||
       strcmp(token, "You're") == 0 ||strcmp(token, "you're") == 0 ||
       strcmp(token, "i'll") == 0 ||strcmp(token, "I'll") == 0 ||
       strcmp(token, "on") == 0 ||strcmp(token, "it's") == 0 ||
       strcmp(token, "of") == 0 ||strcmp(token, "like") == 0 ||
       strcmp(token, "with") == 0 ||strcmp(token, "In") == 0 ||
       strcmp(token, "This") == 0 ||strcmp(token, "this") == 0 ||
       strcmp(token, "that") == 0 ||strcmp(token, "Im") == 0 ||
       strcmp(token, "for") == 0 ||strcmp(token, "How") == 0 ||
       strcmp(token, "how") == 0 ||strcmp(token, "\n") == 0 ||
       strcmp(token, "U") == 0 ||strcmp(token, "or") == 0 ||
       strcmp(token, "K") == 0 ||strcmp(token, "It") == 0 ||
       strcmp(token, "r") == 0 ||strcmp(token, "we") == 0 ||
       strcmp(token, "im") == 0 ||strcmp(token, "Its") == 0 ||
       strcmp(token, "The") == 0 ||strcmp(token, "from") == 0 ||
       strcmp(token, "If") == 0 ||strcmp(token, "if") == 0 ||
       strcmp(token, "by") == 0 ||strcmp(token, "in") == 0 ||
       strcmp(token, "i'm") == 0 ||strcmp(token, "Ur") == 0 ||
       strcmp(token, "Their") == 0 || strcmp(token, "It's") == 0 ||
       strcmp(token, "Our") == 0 || strcmp(token, "My") == 0 ||
       strcmp(token, "She") == 0 || strcmp(token, "He") == 0 ||
       strcmp(token, "Your") == 0 ||strcmp(token, "You") == 0 ||
       strcmp(token, "I've") == 0 ||strcmp(token, "have") == 0 ||
       strcmp(token, "has") == 0 || strcmp(token, "I'm") == 0 ||
       strcmp(token, "ur") == 0 ||strcmp(token, "u") == 0 ||
       strcmp(token, "the") == 0 ||strcmp(token, "too") == 0 ||
       strcmp(token, "its") == 0 ||strcmp(token, "\0") == 0 ||
       strcmp(token, "do") == 0 ||strcmp(token, "to") == 0 ||
       strcmp(token, "and") == 0 ||strcmp(token, "I") == 0 ||
       strcmp(token, "so") == 0 ||strcmp(token, "at") == 0 ||
       strcmp(token, "a") == 0 || strcmp(token, " ") == 0 ||
       strcmp(token, "i") == 0 || strcmp(token, "you")== 0 ||
       strcmp(token, "is")== 0 || strcmp(token, "it") == 0 ||
       strcmp(token, "was") == 0|| strcmp(token, "your")== 0 ||
       strcmp(token, "am")== 0 || strcmp(token, "are")== 0 ||
       strcmp(token, "he")== 0 || strcmp(token, "she")== 0 ||
       strcmp(token, "his")== 0 || strcmp(token, "hers") == 0||
       strcmp(token, "they") == 0|| strcmp(token, "them")== 0 ||
       strcmp(token, "him") == 0|| strcmp(token, "be") == 0 ||
       strcmp(token, "me") == 0 || strcmp(token, "my") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Compares the testing result to the actual results
 * Outputs a file with the ID's of the user the analyzer got
 * incorrect, and calculates the accuracy of the program
 * @param result
 * @param file
 * @param output
 */
void resultCompare(const vector<tweetData>& result, ifstream& file, ostream& output) {
    DSString temp;
    DSString tweet;
    int sentiment;
    bool first = true;
    char* buffer = new char[50000];
    double count = 0;
    double accuracy;
    int vectorIndex = 0;
    tweetData tweetInfo;
    tweetData bufferData;
    vector<tweetData> incorrectTweets;
    while(file.getline( buffer, 50000, ',' ) )
    {
        tweetInfo = result.at(vectorIndex); //Reads through the testing database and gets the sentiment value
        if(first)
        {
            file.getline( buffer, 5000);
            first = false;
        }
        sentiment = atoi(buffer); //Using strtol doesn't work for some reason
        int tweetSentiment = tweetInfo.getSentiment();
        if(sentiment != tweetSentiment) //Compares sentiment value
        {
            incorrectTweets.push_back(tweetInfo); //Stores into a vector for later output to output file
        }
        else
        {
            count++;
        }
        file.getline( buffer, 5000);
        vectorIndex++;
    }
    accuracy = count / 10000;
    output << accuracy << endl; //Prints accuracy at top of output file
    for(auto & incorrectTweet : incorrectTweets) //Prints IDs that were wrong
    {
        tweetInfo = incorrectTweet;
        output << tweetInfo.getID() << endl;
    }
    delete[] buffer; //Deallocates buffer
}

