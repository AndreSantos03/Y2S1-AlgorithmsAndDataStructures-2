//
// Created by NASA on 07/01/2023.
//

#include "Algorithms.h"

Algorithms::Algorithms() {}

Algorithms::Algorithms(unordered_map<string, Airline> airlines, unordered_map<string, Airport> airports, Graph flights) {
    this->airlines = airlines;
    this->airports = airports;
    this->flights = flights;
    nodes = flights.nodes;
}

bool Algorithms::isValidAirportCode(string code) {
    return (airports.find(code) != airports.end());
}


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




