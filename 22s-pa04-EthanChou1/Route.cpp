//
// Created by ethan on 3/26/2022.
//

#include "Route.h"
Route::Route() {
    cost = 0;
    time = 0;
    start = "";
    end = "";
}

DSString Route::getStart() {
    return start;
}

DSString Route::getEnd() {
    return end;
}

double Route::getCost() const {
    return cost;
}

double Route::getTime() const {
    return time;
}

void Route::setStart(DSString &origin) {
    start = origin;
}

void Route::setCost(double cost) {
    this->cost = cost;
}

void Route::setTime(double time) {
    this->time = time;
}


void Route::setAirline(DSString& destination) {
    end = destination;
}

Route::Route(DSString origin, double cost, double time, DSString destination) {
    this->cost = cost;
    this->time = time;
    start = origin;
    end = destination;
}
