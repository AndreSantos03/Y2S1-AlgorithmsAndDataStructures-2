/**
 * @file Algorithms.cpp
 * Funções para
 */

#include "Algorithms.h"

/**
 * @brief
 * Construtor default da class Algorithms
 */

Algorithms::Algorithms() {}

/**
 * Construtor de new Algorithms: Algorithms object
 * @param airlines companhias aéreas
 * @param airports aeroportos
 * @param flights voos
 */

Algorithms::Algorithms(unordered_map<string, Airline> airlines, unordered_map<string, Airport> airports, Graph flights) {
    this->airlines = airlines;
    this->airports = airports;
    this->flights = flights;
    nodes = flights.nodes;
}

/**
 * Verifica se o código do aeroporto existe
 * @param code código do aeroporto
 * @return true se o código do aeroporto existir
 * @return false caso contrário
 */

bool Algorithms::isValidAirportCode(string code) {
    return (airports.find(code) != airports.end());
}

/**
 *
 * @param a1
 * @param a2
 * @return vector<string>
 */

//BFS Implementation with distance
vector<pair<string,string>> Algorithms::bestPath(string a1, string a2, list<string> allowedAirlines) {
    bool restricted = true;
    if(allowedAirlines.empty()){
        restricted = false;
    }
    unordered_map<string, pair<int, vector<pair<string,string>>>> nodesPath;
    nodesPath[a1] = {0, {{a1,""}}};//string is irrelevant

    for (auto &n : nodes) {
        n.second.visited = false;
    }
    queue<string> q;
    q.push(a1);
    nodes[a1].visited = true;

    while(!q.empty()){
        for(auto e:nodes[q.front()].adj){
            string eCode = e.get_target().get_code();
            if( nodesPath[q.front()].first + 1 < nodesPath[eCode].first || !nodes[eCode].visited ){
                if(!restricted || find(allowedAirlines.begin(),allowedAirlines.end(),e.get_airline().get_code()) != allowedAirlines.end()){
                    nodesPath[eCode] = {nodesPath[q.front()].first + 1, nodesPath[q.front()].second};
                    nodesPath[eCode].second.push_back({eCode,e.get_airline().get_callSign()});
                    q.push(eCode);
                    nodes[eCode].visited = true;
                }
            }
        }
        q.pop();
    }

    string fastest = nodesPath[a2].second.back().first;
    for (auto &[key, value] : airports)
    {
        if (value.get_city() == a2 && (fastest == "" || nodesPath[value.get_code()] < nodesPath[fastest]))
        {
            fastest = value.get_code();
        }
    }

    return nodesPath[fastest].second;
}

string Algorithms::convertCity(string city) {
    for(auto a : airports){
        if(a.second.get_city() == city){
            return a.first;
        }
    }
    return "NONE";
}

string Algorithms::convertCoordinates(float lat, float lon) {
    float minDistance = std::numeric_limits<float>::max();
    string code;
    for(auto a : airports){
        float distance = Graph::getDistance(a.second.get_latitude(),a.second.get_longitude(),lat,lon);
        if(distance < minDistance){
            minDistance = distance;
            code = a.first;
        }
    }
    return code;
}





