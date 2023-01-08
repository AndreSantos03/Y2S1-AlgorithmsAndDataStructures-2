/**
 * @file Terminal.h
 * Funções para ler ficheiros
 */

#ifndef AEDPROJETO2_TERMINAL_H
#define AEDPROJETO2_TERMINAL_H

#include <iostream>
#include <list>
#include "Graph.h"
#include "Flight.h"
#include "FlightController.h"
#include "Airline.h"
#include "Airport.h"
#include <unordered_map>
#include "Reader.h"
#include "Algorithms.h"
#include <set>

using namespace std;

class Terminal
{
private:
    string choice;
    Algorithms algorithms;

    void getBestFlightPath(FlightController &fc);
    void getNumberOfFlights(FlightController &fc);

 public:
    Terminal(unordered_map<string, Airline> airlines,unordered_map<string, Airport> airports,Graph flights);
    void IO(FlightController &fc);
};

#endif //AEDPROJETO2_TERMINAL_H
