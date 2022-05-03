/**
 * Fall 2021 PA 04 - Flight Planner Template Repo.
 * Based on PA 02 Template repo
 */

#include <iostream>
#include <fstream>

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"
#include "DSLinkedList.h"
#include "DSAdjacencyList.h"
int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        std::cout << "Attempting to open " << argv[1] << std::endl;
        std::cout << "Attempting to open " << argv[2] << std::endl;
        ifstream flightData(argv[1]);
        ifstream requestedFlight(argv[2]);
        ofstream output(argv[3]);
        DSLinkedList<DSLinkedList<Airport>*> cities;
        DSStack<DSLinkedList<Airport>> stack;
        DSVector<Route> list;
        DSAdjacencyList flightPlanner;
        flightPlanner.getFlightData(flightData);
        flightPlanner.getRequestedData(requestedFlight, list);
        flightPlanner.outputToFile(list, output);
        flightData.close();
        requestedFlight.close();
        output.close();
    }


    return 0;
}