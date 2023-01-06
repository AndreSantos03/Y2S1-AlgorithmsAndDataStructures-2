//
// Created by NASA on 06/01/2023.
//

#include "Flight.h"

Flight::Flight(Airport source, Airport target, Airline airline, float distance){
    this->source = source;
    this->target = target;
    this->airline = airline;
    this->distance = distance;
}