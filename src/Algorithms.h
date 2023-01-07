/**
 * @file Algorithms.h
 * Funções para ler ficheiros
 */

#ifndef AEDPROJETO2_ALGORITHMS_H
#define AEDPROJETO2_ALGORITHMS_H


#include "Graph.h"
#include <limits>
#include <algorithm>

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
    vector<pair<string,string>> bestPath(string a1, string a2, list<string> allowedAirlines);
    string convertCity(string city);
    string convertCoordinates(float lat, float lon);
    string getCityFromCode(string code){return airports[code].get_city();};
};


#endif //AEDPROJETO2_ALGORITHMS_H
