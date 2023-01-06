//
// Created by NASA on 06/01/2023.
//

#ifndef AEDPROJETO2_READER_H
#define AEDPROJETO2_READER_H

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "Airline.h"
#include "Airport.h"
#include "Graph.h"



using namespace std;

class Reader {
public:
    static unordered_map<string, Airline> readAirlines();
    static unordered_map<string, Airport> readAirports();
    static Graph readFlights(unordered_map<string,Airline> airlines, unordered_map<string, Airport> airports);
};


#endif //AEDPROJETO2_READER_H
