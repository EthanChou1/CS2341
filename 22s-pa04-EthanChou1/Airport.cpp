//
// Created by Ethan on 3/22/2022.
//

#include "Airport.h"
using namespace std;
Airport::Airport() {
    cost = 0;
    time = 0;
    airportName = "";
    airlineCompany = "";
}

DSString Airport::getName() {
    return airportName;
}

DSString Airport::getAirline() {
    return airlineCompany;
}

double Airport::getCost()  {
    return cost;
}

double Airport::getTime()  {
    return time;
}

void Airport::setStart(DSString &origin) {
    airportName = origin;
}

void Airport::setCost(double cost) {
    this->cost = cost;
}

void Airport::setTime(double time) {
    this->time = time;
}


void Airport::setAirline(DSString& airline) {
    airlineCompany = airline;
}

Airport::Airport(DSString destination, DSString company, double cost, double time) {
    airportName = destination;
    airlineCompany = company;
    this->cost = cost;
    this->time = time;
}

Airport::Airport(DSString start) {
    airportName = start;
    cost = 0;
    time = 0;
}


bool Airport::operator==(Airport airportOne) {
    if(airportOne.airportName == airportName)
    {
        return true;
    }
    else
    {
        return false;
    }
}