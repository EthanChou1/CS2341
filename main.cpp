//Created by Ethan Chou on January 30th 2022
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <vector>
#include "fileReader.h"
#include "tweetData.h"
using namespace std;

int main(int argc, char** argv) {
        vector<tweetData> trainingDataBase;
        vector<tweetData> testDataBase;
        vector<tweetData> result;
        if(argc == 1)
        {
            Catch::Session().run();
        }
        ifstream file;
        file.open(argv[1]);

        ifstream fileTwo;
        fileTwo.open(argv[2]);

        ifstream fileThree;
        fileThree.open(argv[3]);

        ofstream outputFile;
        outputFile.open(argv[4]);


        trainingFileRead(file, outputFile, trainingDataBase);
        testFileRead(fileTwo, outputFile, trainingDataBase, testDataBase);
        resultCompare(testDataBase, fileThree, outputFile);

        file.close();
        fileTwo.close();
        fileThree.close();
        outputFile.close();
        cout << "Sentiment Analysis is complete!" << endl;
    return 0;
}
