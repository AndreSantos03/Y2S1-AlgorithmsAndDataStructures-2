//
// Created by NASA on 07/01/2023.
//

/**
 * @file Algorithms.h
 * Funções para ler ficheiros
 */

#ifndef AEDPROJETO2_ALGORITHMS_H
#define AEDPROJETO2_ALGORITHMS_H


#include "Graph.h"


class Algorithms {
private:
    unordered_map<string, Airline> airlines;
    unordered_map<string, Airport> airports;
    Graph flights;
    unordered_map<string, Graph::Node> nodes;

    void dfsDistance(string count);
public:
    Algorithms();
    Algorithms(unordered_map<string, Airline> airlines,unordered_map<string, Airport> airports,Graph flights);
    bool isValidAirportCode(string code);
    vector<string> bestPath(string a1, string a2);
};


#endif //AEDPROJETO2_ALGORITHMS_H
