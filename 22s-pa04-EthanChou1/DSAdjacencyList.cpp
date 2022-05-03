//
// Created by Ethan on 3/22/2022.
//

#include "DSAdjacencyList.h"
#include <iomanip>
#include <random>

/**
 * Reads in the requested flights, and populates it into a DSVector
 * @param input
 * @param listRequest
 */
void DSAdjacencyList::getRequestedData(ifstream &input, DSVector<Route> &listRequest) {
    char* buffer = new char[256];
    DSString temp;
    int length;
    input.getline(buffer, 256);
    length = atoi(buffer);
    numFlights = length;
    int count = 0;
    int calcCost = 0;
    int calcTime = 0;
    DSString origin;
    DSString destination;
    DSString type;
    while(!input.eof())
    {
        input.getline(buffer, 256);
        char* word = strtok(buffer, "\"");
        DSString line(word);
        readFile(origin, line, destination, type, calcTime, calcCost, count, word);
        //Creates route
        Route requested(origin, calcCost, calcTime, destination);
        //Adds route to DSVector of Routes
        listRequest.push_back(requested);
        count = 0;
        calcTime = 0;
        calcCost = 0;
    }
    //Deallocates
    delete[] buffer;
}

/**
 * Reads in each line and gets the information into
 * a route object
 * @param origin
 * @param line
 * @param destination
 * @param type
 * @param calcTime
 * @param calcCost
 * @param count
 * @param word
 */
void DSAdjacencyList::readFile(DSString& origin, DSString& line, DSString& destination, DSString& type, int& calcTime, int& calcCost, int& count, char* word) {
    while(word != nullptr)
    {
        //Gets origin
        if(line.getLength() > 0 && count == 0)
        {
            char *token = strtok(word, " ");
            origin = token;
        }
            //Gets destination
        else if(line.getLength() > 0 && count == 1)
        {
            char *token = strtok(word, " ");
            destination = token;
        }
            //Determines if it should use Cost or Time
        else if(line.getLength() > 0 && count == 2)
        {
            char *token = strtok(word, " \r\"\n"); //.txt file formatting is wierd so include /r
            type = token;
            if(type == "T")
            {
                calcTime = 1;
                calcCost = 0;
            }
            else if(type == "C")
            {
                calcTime = 0;
                calcCost = 1;
            }
        }
        count++;
        word = strtok(nullptr, "\"");
    }
}

/**
 * Reads in each line and gets the information into
 * a doubly linked list
 * @param inputData
 */
void DSAdjacencyList::getFlightData(ifstream &inputData) {
    char* buffer = new char[256];
    DSString temp;
    int length;
    inputData.getline(buffer, 256);
    length = atoi(buffer);
    int count = 0;
    double cost = 0;
    double time = 0;
    int counter = 0;
    DSString originStart;
    DSString destinationEnd;
    DSString airlineCompany;
    DSLinkedList<Airport> airport;
    while(!inputData.eof() && counter < length) {
        inputData.getline(buffer, 256);
        char* word = strtok(buffer, "\"");
        DSString start(word);
        while(word != nullptr)
        {
            //Gets origin
            if(start.getLength() > 0 && count == 0)
            {
                char *token = strtok(word, " ");
                originStart = token;
            }
            //Gets destination
            else if(start.getLength() > 0 && count == 1)
            {
                char *token = strtok(word, " ");
                destinationEnd = token;
            }
            //Gets cost
            else if(start.getLength() > 0 && count == 2)
            {
                char *token = strtok(word, " ");
                double x = ((double)rand()/RAND_MAX)*0.0009+0.0001; //Small enough number to avoid duplicate number bug and not affect outcome
                cost = atol(token);
                cost += x;
            }
            //Gets Time
            else if(start.getLength() > 0 && count == 3)
            {
                char *token = strtok(word, " ");
                double x = ((double)rand()/RAND_MAX)*0.0009+0.0001; //Small enough number to avoid duplicate number bug and not affect outcome
                time = atoi(token);
                time += x;
            }
            //Gets Airline
            else if(start.getLength() > 0 && count == 4)
            {
                char *token = strtok(word, " \r\"\n"); //.txt file formatting is wierd so include /r
                airlineCompany = token;
            }
            count++;
            word = strtok(nullptr, "\"");
        }
        count = 0;
        //Instantiates Doubly Linked List of Doubly Linked List
        inputDataToLinkedList(originStart, destinationEnd, cost, time, airlineCompany);
        inputDataToLinkedList(destinationEnd, originStart, cost, time, airlineCompany);
        counter++;
    }
    //Deallocates buffer
    delete[] buffer;
}

/**
 * Reads in each line and gets the information into
 * a doubly linked list by creating Airport objects.
 * @param start
 * @param end
 * @param cost
 * @param time
 * @param airlineCompany
 */
void DSAdjacencyList::inputDataToLinkedList(const DSString& start, const DSString& end, double cost, double time, const DSString& airlineCompany) {
    int index = -1;
    for (int i = 0; i < adjList.size; i++) {
        if (adjList.get(i).get(0).getName() == start) {
            index = i;
        }
    }
    //Adds beginning node
    if (index == -1) {
        Airport orig(start);
        DSLinkedList<Airport> newList;
        newList.add(orig);
        Airport dest(end, airlineCompany, cost, time);
        newList.add(dest);
        adjList.add(newList);
    }
    else {
        //Adds ending node
        bool locationExist = false;
        for (int i = 0; i < adjList.get(index).size; i++)
        {
            if (adjList.get(index).get(i).getAirline() == airlineCompany && adjList.get(index).get(i).getName() == end
            && adjList.get(index).get(i).getCost() == cost && adjList.get(index).get(i).getTime() == time)
            {
                locationExist = true;
            }
        }
        if (!locationExist) {
            Airport dest(end, airlineCompany, cost, time);
            adjList.get(index).add(dest);
        }
    }
}

//Not going to be in main, testing AdjacencyList contents
/**
 * Outputs contents of Doubly Linked List
 */
void DSAdjacencyList::printList() {
    int count = 0;
    for(int i = 0; i < adjList.getSize(); i++)
    {
        for(int j = 0; j < adjList.get(i).getSize(); j++)
        {
            if(count == 0)
            {
                cout << adjList.get(i).get(j).getName() << "|" << adjList.get(i).get(j).getCost() << "->";
                count++;
            }
            else if( j < adjList.get(i).getSize() - 1)
            {
                cout << adjList.get(i).get(j).getName() << "|" << adjList.get(i).get(j).getCost() << "->";
            }
            else
            {
                cout << adjList.get(i).get(j).getName() << "|" << adjList.get(i).get(j).getCost();
            }
        }
        cout << endl;
        count = 0;
    }
}

/**
 * Iterative Backtracker that determines a possible route between two destinations
 * by cost
 * @param airport
 * @param end
 */
void DSAdjacencyList::calcRouteCost(const Airport& airport, const DSString& end) {
    //Iterates backward
    completeResetIterator();
    //Sources: https://www.cis.upenn.edu/~matuszek/cit594-2012/Pages/backtracking.html for non-recursive backtracking pseudocode
    // https://www.includehelp.com/algorithms/backtracking-types-and-algorithms.aspx
    //While route is not empty
    route.push(airport);
    while(!route.empty())
    {
        Airport temp = route.seeTop();
        int index;
        for (int i = 0; i < adjList.getSize(); i++)
        {
            if (adjList.get(i).get(0).getName() == temp.getName()) {
                index = i;
            }
        }
        //If there is something next
        if (adjList.get(index).hasNext())
        {
            Airport nextAirport = adjList.get(index).returnNext();
            //If stack does not already have the next Airport
            if (!route.isInStack(nextAirport))
            {
                route.push(nextAirport);
                if (route.seeTop().getName() == end)
                {
                    routeListCost.push_back(route);
                    route.pop();
                }
            }
        }
        //Go back to previous node
        else
        {
            adjList.get(index).moveIteratorToHead();
            adjList.get(index).iterateToNext();
            route.pop();
        }
    }
}

/**
 * Iterative Backtracker that determines a possible route between two destinations
 * by time
 * @param airport
 * @param end
 */
void DSAdjacencyList::calcRouteTime(const Airport& airport, const DSString& end) {
    //Iterates backward
    completeResetIterator();
    //Sources: https://www.cis.upenn.edu/~matuszek/cit594-2012/Pages/backtracking.html for non-recursive backtracking pseudocode
    // https://www.includehelp.com/algorithms/backtracking-types-and-algorithms.aspx
    //While route is not empty
    route.push(airport);
    while(!route.empty())
    {
        Airport temp = route.seeTop();
        int index;
        for (int i = 0; i < adjList.getSize(); i++)
        {
            if (adjList.get(i).get(0).getName() == temp.getName()) {
                index = i;
            }
        }
        //If there is something next
        if (adjList.get(index).hasNext())
        {
            Airport nextAirport = adjList.get(index).returnNext();
            //If stack does not already have the next Airport
            if (!route.isInStack(nextAirport))
            {
                route.push(nextAirport);
                //If top of stack is the destination
                if (route.seeTop().getName() == end)
                {
                    routeListTime.push_back(route);

                    route.pop();
                }
            }
        }
            //Go back to previous node
        else
        {
            adjList.get(index).moveIteratorToHead();
            adjList.get(index).iterateToNext();
            route.pop();
        }
    }
}

/**
 * Outputs the information according to either cost or time
 * @param listRequest
 * @param output
 */
void DSAdjacencyList::outputToFile(DSVector<Route> listRequest, ostream& output) {
    for(int i = 0; i < listRequest.getSize(); i++)
    {
        bool useCost = false;
        bool useTime = false;
        //Outputs header and uses cost or time depending on boolean
        output << "Flight " << i + 1 << ": " << listRequest.indexAt(i).getStart() << ", " << listRequest.indexAt(i).getEnd() << " (";
        if (listRequest.indexAt(i).getCost() == 1) {
            output << "Cost)" << endl;
            useCost = true;
            useTime = false;
        }
        else if (listRequest.indexAt(i).getTime() == 1) {
            output << "Time)" << endl;
            useTime = true;
            useCost = false;
        }
        bool startExists = false;
        bool endExists = false;
        //Determines if both starting and ending locations exist
        for (int k = 0; k < adjList.getSize(); k++) {
            for (int j = 0; j < adjList.get(k).getSize(); j++) {
                if (adjList.get(k).get(0).getName() == listRequest.indexAt(i).getStart()) {
                    startExists = true;
                }
                if (adjList.get(k).get(0).getName() == listRequest.indexAt(i).getEnd()) {
                    endExists = true;
                }
            }
        }
        if (!startExists || !endExists) //Both do not exist
        {
            output << "\t One or both of the Airports do not exist." << endl;
        }
        else
        {
            if (!(listRequest.indexAt(i).getStart() == listRequest.indexAt(i).getEnd()))
            {
                int index;
                for (int m = 0; m < adjList.getSize(); m++) {
                    if (adjList.get(m).get(0).getName() == listRequest.indexAt(i).getStart())
                    {
                        index = m;
                    }
                }
                if(useCost)
                {
                    //Populates DSStack with only flights that are by cost
                    calcRouteCost(adjList.get(index).get(0), listRequest.indexAt(i).getEnd());
                }
                else if(useTime)
                {
                    //Populates DSStack with only flights that are by time
                    calcRouteTime(adjList.get(index).get(0), listRequest.indexAt(i).getEnd());
                }
                useCostOrTime(useCost, useTime, output); //Outputs info according to cost or time.
            }
            else { //No paths
                output << "\t No paths for same-city flights can be found." << endl;
            }
        }
    }

}

/**
 * Gets the top three flights by cost
 * @param output
 */
void DSAdjacencyList::getCost(ostream& output) {
    int count = 0;
    double cost = 0;
    for(int i = 0; i < 3; i++)
    {
        if(i > routeListCost.getSize() - 1)
        {
            break;
        }
        count++;
        int index = 0;
        double lowest = 9999; //Temp value
        for(int j = 0; j < routeListCost.getSize(); j++)
        {
            double currentCost = 0;
            for(int k = 0; k < routeListCost.indexAt(j).getSize(); k++)
            {
                //Adds up cost from all flights
                currentCost = currentCost + routeListCost.indexAt(j).getAtIndex(k).getCost();
            }
            if(currentCost < lowest && currentCost > cost)
            {
                lowest = currentCost; //Gets current lowest cost
                index = j;
            }
        }
        cost = lowest;
        double totalCost = cost; //Assigns the lowest cost
        double totalTime = 0; //total time
        output << "\t Itinerary " << count << ": " << endl;
        DSString tempAirline;
        DSString temp;
        for(int l = 0; l < routeListCost.indexAt(index).getSize(); l++)
        {
            if(l == 0)
            {
                output << "\t\t" << routeListCost.indexAt(index).getAtIndex(l).getName() << "->";
            }
            else if(l == routeListCost.indexAt(index).getSize() - 1)
            {
                tempAirline = routeListCost.indexAt(index).getAtIndex(l).getAirline();
                output  << routeListCost.indexAt(index).getAtIndex(l).getName() << " (" << tempAirline << ")" << endl;
            }
            else
            {
                tempAirline = routeListCost.indexAt(index).getAtIndex(l).getAirline();
                output  << routeListCost.indexAt(index).getAtIndex(l).getName() << " (" << tempAirline << ")\n\t\t";
                output  << routeListCost.indexAt(index).getAtIndex(l).getName() << "->";
            }
            totalTime += routeListCost.indexAt(index).getAtIndex(l).getTime(); //Adds up total time
        }
        //Adds extra cost and time based on layovers
        //Adds 23 to cost based on number of layovers
        //Adds 43 to time based on number of layovers
        int extraCostTime = routeListCost.indexAt(index).getSize();
        if(extraCostTime >= 3)
        {
            totalTime += (routeListCost.indexAt(index).getSize() - 2) * 43;
            totalCost += (routeListCost.indexAt(index).getSize() - 2) * 23;
        }
        //Adds extra time based on airline changes
        //Adds 27 to time for each airline change
        for(int m = 1; m < routeListCost.indexAt(index).getSize() - 1; m++)
        {
            DSString one = routeListCost.indexAt(index).getAtIndex(m).getAirline();
            DSString two = routeListCost.indexAt(index).getAtIndex(m + 1).getAirline();
            if(one != two)
            {
                totalTime += 27;
            }
        }
        output << "\t\tTotals for Itinerary " << count << ": Time: "  << fixed << setprecision(0) << totalTime
        << " Cost: " << fixed << setprecision(2) << totalCost  << endl;
    }
    //Moves on to next requested
    while (!routeListCost.isEmpty()) {
        routeListCost.removeLast();
    }
}

/**
 * Gets the top three flights by time
 * @param output
 */
void DSAdjacencyList::getTime(ostream& output) {
    int count = 0;
    double time = 0;
    for(int i = 0; i < 3; i++)
    {
        if(i > routeListTime.getSize() - 1)
        {
            break;
        }
        count++;
        int index = 0;
        double lowest = 9999; //temporary value
        for(int j = 0; j < routeListTime.getSize(); j++)
        {
            double currentTime = 0;
            for(int k = 0; k < routeListTime.indexAt(j).getSize(); k++)
            {
                //Adds up the time from all flights
                currentTime = currentTime + routeListTime.indexAt(j).getAtIndex(k).getTime();
            }
            if(currentTime < lowest && currentTime > time)
            {
                lowest = currentTime; //Gets current lowest time
                index = j;
            }
        }
        time = lowest;
        double totalCost = 0;
        double totalTime = time; //Gets the lowest time
        DSString tempAirline;
        DSString temp;
        output << "\t Itinerary " << count << ": " << endl;
        for(int l = 0; l < routeListTime.indexAt(index).getSize(); l++)
        {
            if(l == 0)
            {
                output << "\t\t" << routeListTime.indexAt(index).getAtIndex(l).getName() << "->";
            }
            else if(l == routeListTime.indexAt(index).getSize() - 1)
            {
                tempAirline = routeListTime.indexAt(index).getAtIndex(l).getAirline();
                output  << routeListTime.indexAt(index).getAtIndex(l).getName() << " (" << tempAirline << ")" << endl;
            }
            else
            {
                tempAirline = routeListTime.indexAt(index).getAtIndex(l).getAirline();
                output  << routeListTime.indexAt(index).getAtIndex(l).getName() << " (" << tempAirline << ")\n\t\t";
                output  << routeListTime.indexAt(index).getAtIndex(l).getName() << "->";
            }
            totalCost +=  routeListTime.indexAt(index).getAtIndex(l).getCost(); //Adds up total cost
        }
        //Adds extra cost and time based on layovers
        //Adds 23 to cost based on number of layovers
        //Adds 43 to time based on number of layovers
        int extraCostTime = routeListTime.indexAt(index).getSize();
        if(extraCostTime >= 3)
        {
            totalTime += (routeListTime.indexAt(index).getSize() - 2) * 43;
            totalCost += (routeListTime.indexAt(index).getSize() - 2) * 23;
        }
        //Adds extra time based on airline changes
        //Adds 27 to time for each airline change
        for(int m = 1; m < routeListTime.indexAt(index).getSize() - 1; m++)
        {
            DSString one = routeListTime.indexAt(index).getAtIndex(m).getAirline();
            DSString two = routeListTime.indexAt(index).getAtIndex(m + 1).getAirline();
            if(one != two)
            {
                totalTime += 27;
            }
        }
        output << "\t\tTotals for Itinerary " << count << ": Time: " << fixed << setprecision(0) << totalTime
               << " Cost: " << fixed << setprecision(2) << totalCost << endl;
    }
    //Moves on to next requested
    while (!routeListTime.isEmpty()) {
        routeListTime.removeLast();
    }
}

/**
 * Resets the iterator for the DSLinkedList class
 */
void DSAdjacencyList::completeResetIterator() {
    //resets iterator to very beginning
    for (int i = 0; i < adjList.getSize(); i++) {
        adjList.get(i).iterateToNext();
    }
}

/**
 * Determines whether to use cost or time sorting method
 * @param cost
 * @param time
 * @param output
 */
void DSAdjacencyList::useCostOrTime(bool cost, bool time, ostream& output) {
    if(cost)
    {
        //Use cost output
        getCost(output);
    }
    if(time)
    {
        //use time output
        getTime(output);
    }
}