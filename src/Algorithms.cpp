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


//BFS Implementation with distance
vector<pair<string,string>> Algorithms::bestPath(string a1, string a2){
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
            if( nodesPath[q.front()].first + 1 < nodesPath[eCode].first || !nodes[eCode].visited){
                nodesPath[eCode] = {nodesPath[q.front()].first + 1, nodesPath[q.front()].second};
                nodesPath[eCode].second.push_back({eCode,e.get_airline().get_callSign()});
                nodes[eCode].visited = true;
                q.push(eCode);
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





