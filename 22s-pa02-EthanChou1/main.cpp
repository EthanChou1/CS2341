/**
 * Fall 2021 PA 02 Template Repo.
 */



/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"
#include "DSVector.h"
#include "FileRead.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        cout << "Attempting to open " << argv[1] << endl;
        cout << "Attempting to open " << argv[2] << endl;
        cout << "Attempting to open and write to " << argv[3] << endl;
        DSVector<DSString> terms;
        ifstream termsFile(argv[1]);
        ifstream testBookFile(argv[2]);
        ofstream output(argv[3]);
        FileRead driver(terms);
        driver.inputFileRead(termsFile);
        for(int i = 0; i < driver.dataStructureGet().getSize(); i++)
        {
            if(driver.isPhrase(driver.dataStructureGet().indexAt(i)))
            {
                driver.textFileReadPhrase(testBookFile, driver.dataStructureGet().indexAt(i), i);
            }
            else
            {
                driver.textFileReadWord(testBookFile, driver.dataStructureGet().indexAt(i), i);
            }
        }
        driver.outputToFile(output);
        cout << "AutoIndexer has completed!" << endl;
        output.close();
        termsFile.close();
        testBookFile.close();
    }
    return 0;
}
