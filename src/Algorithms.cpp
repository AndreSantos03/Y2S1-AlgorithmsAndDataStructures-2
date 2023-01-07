//
// Created by NASA on 07/01/2023.
//

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

vector<string> Algorithms::bestPath(string a1, string a2){
    unordered_map<string, pair<int, vector<string>>> nodesPath;
    nodesPath[a1] = {0, {}};
    queue<string> q;
    q.push(a1);

    for (auto &[key, value] : nodes) {
        value.visited = false;
    }

    nodes[a1].visited = true;

    while(!q.empty()){
        for(auto e:nodes[q.front()].adj){
            string eCode = e.get_target().get_code();
            if(nodesPath[q.front()].first + e.get_distance() < nodesPath[eCode].first ){
                nodes[eCode].visited = true;
                q.push(eCode);

                nodesPath[eCode] = {nodesPath[q.front()].first + e.get_distance(), nodesPath[q.front()].second};
                nodesPath[eCode].second.push_back(e.get_target().get_code());
            }
        }
        q.pop();
    }
    return nodesPath[a2].second;
}




