/**
 * @file Reader.h
 * Funções para ler ficheiros
 */

#ifndef AEDPROJETO2_READER_H
#define AEDPROJETO2_READER_H

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
#include "Graph.h"



using namespace std;

class Reader {
public:
    static unordered_map<string, Airline> readAirlines();
    static unordered_map<string, Airport> readAirports();
    static Graph readFlights(unordered_map<string,Airline> airlines, unordered_map<string, Airport> airports);
};


#endif //AEDPROJETO2_READER_H
