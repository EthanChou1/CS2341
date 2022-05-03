//
// Created by ethan on 3/26/2022.
//

#ifndef INC_22S_FLIGHT_PLANNER_ROUTE_H
#define INC_22S_FLIGHT_PLANNER_ROUTE_H
#include "DSString.h"

class Route {
private:
    DSString start;
    DSString end;
    double cost;
    double time;
public:
    Route();
    Route(DSString origin, double cost, double time, DSString destination);
    DSString getStart();
    DSString getEnd();
    double getCost() const;
    double getTime() const;
    void setStart(DSString& origin);
    void setAirline(DSString& airline);
    void setCost(double cost);
    void setTime(double time);
//    friend bool operator!=(Airport& airportOne, Airport& airportTwo);
};

#endif //INC_22S_FLIGHT_PLANNER_ROUTE_H
