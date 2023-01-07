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
#include <limits>

class Algorithms {
private:
    unordered_map<string, Airline> airlines;
    unordered_map<string, Airport> airports;
    Graph flights;
    unordered_map<string, Graph::Node> nodes;

public:
    Algorithms();
    Algorithms(unordered_map<string, Airline> airlines,unordered_map<string, Airport> airports,Graph flights);
    bool isValidAirportCode(string code);
    vector<pair<string,string>> bestPath(string a1, string a2);
    string convertCity(string city);
    string convertCoordinates(float lat, float lon);
    string getCityFromCode(string code){return airports[code].get_city();};
};


#endif //AEDPROJETO2_ALGORITHMS_H
