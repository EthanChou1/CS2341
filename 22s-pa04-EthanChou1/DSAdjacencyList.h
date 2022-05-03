//
// Created by ethan on 3/22/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_DSADJACENCYLIST_H
#define INC_22S_FLIGHT_PLANNER_DSADJACENCYLIST_H
#include "DSStack.h"
#include "DSVector.h"
#include "Airport.h"
#include "Route.h"
using namespace std;

class DSAdjacencyList {
private:
    DSLinkedList<DSLinkedList<Airport>> adjList;
    DSVector<DSStack<Airport>> routeListCost;
    DSVector<DSStack<Airport>> routeListTime;
    DSStack<Airport> route;
    int numFlights;
public:
    void getRequestedData(ifstream &input, DSVector<Route> &listRequest);
    static void readFile(DSString&, DSString&, DSString&, DSString&, int&, int&, int&, char*);
    void getFlightData(ifstream &inputData);
    void inputDataToLinkedList(const DSString& start, const DSString& end, double cost, double time,const DSString& airline);
    void printList();
    void calcRouteCost(const Airport&, const DSString&);
    void calcRouteTime(const Airport&, const DSString&);
    void getCost(ostream& output);
    void getTime(ostream& output);
    void useCostOrTime(bool, bool, ostream& output);
    void outputToFile( DSVector<Route>, ostream& output);
    void completeResetIterator();
};
#endif //INC_22S_FLIGHT_PLANNER_DSADJACENCYLIST_H
