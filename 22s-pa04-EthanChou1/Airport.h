//
// Created by Ethan on 3/22/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_AIRPORT_H
#define INC_22S_FLIGHT_PLANNER_AIRPORT_H
#include "DSString.h"

class Airport {
private:
    DSString airportName;
    DSString airlineCompany;
    double cost;
    double time;
public:
    Airport();
    Airport(DSString destination, DSString airline, double cost, double time);
    explicit Airport(DSString start);
    DSString getName();
    DSString getAirline();
    double getCost();
    double getTime();
    void setStart(DSString& origin);
    void setAirline(DSString& airline);
    void setCost(double cost);
    void setTime(double time);
    bool operator==(Airport airportOne);
//    friend bool operator!=(Airport& airportOne, Airport& airportTwo);
};


#endif //INC_22S_FLIGHT_PLANNER_AIRPORT_H
