//
// Created by NASA on 07/01/2023.
//

#ifndef AEDPROJETO2_ALGORITHMS_H
#define AEDPROJETO2_ALGORITHMS_H


#include "Graph.h"

class Algorithms {
private:
    unordered_map<string, Airline> airlines;
    unordered_map<string, Airport> airports;
    Graph flights;
public:
    Algorithms();
    Algorithms(unordered_map<string, Airline> airlines,unordered_map<string, Airport> airports,Graph flights);
    bool isValidAirportCode(string code);
};


#endif //AEDPROJETO2_ALGORITHMS_H
