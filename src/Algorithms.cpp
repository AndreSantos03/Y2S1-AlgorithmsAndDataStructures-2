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
 * Breadth-first search para encontrar o caminho mais rápido entre dois aeroportos
 * @param a1 dados do aeroporto 1
 * @param a2 dados do aeroporto 2
 * @param allowedAirlines companhias aéreas que realizam viagens entre a1 e a2
 * @return vector<pair<string,string>>
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

/**
 * Permite obter o código do aeroporto, caso exista
 * @param city cidade do aeroporto
 * @return string
 */

string Algorithms::convertCity(string city) {
    for(auto a : airports){
        if(a.second.get_city() == city){
            return a.first;
        }
    }
    return "NONE";
}

/**
 * Obtêm o código de um aeroporto que está a menor distância do aeroporto com coordenadas lat e lon
 * @param lat latitude de um aeroporto
 * @param lon longitude de um aeroporto
 * @return string
 */

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





