//
// Created by NASA on 06/01/2023.
//

#ifndef AEDPROJETO2_FLIGHT_H
#define AEDPROJETO2_FLIGHT_H

#include "Airport.h"
#include "Airline.h"
#include <iostream>

using namespace std;

class Flight {
private:
    Airport source, target;
    Airline airline;
    float distance, weight;

public:
    Flight(Airport source, Airport target, Airline airline, float distance);
    Airport get_source() {return source;};
    Airport get_target() {return target;};
    Airline get_airline() {return airline;};
    float get_distance() {return distance;};
};


#endif //AEDPROJETO2_FLIGHT_H
