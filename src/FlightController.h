/**
 * @file FlightController.h
 * Funções para ler ficheiros
 */

#ifndef AEDPROJETO2_FLIGHTCONTROLLER_H
#define AEDPROJETO2_FLIGHTCONTROLLER_H

#include <iostream>
#include <list>
#include "Graph.h"
#include "Flight.h"
#include "Airline.h"
#include "Airport.h"
#include <unordered_map>
#include "Reader.h"

using namespace std;

class FlightController {
private:
    unordered_map<string, Airline> airlines;
    unordered_map<string, Airport> airports;
    Graph flights;
public:
    FlightController();

    Graph get_flights(){return flights;}
    unordered_map<string, Airline> get_airlines() {return airlines;};
    unordered_map<string, Airport> get_airports() {return airports;};
};


#endif //AEDPROJETO2_FLIGHTCONTROLLER_H
