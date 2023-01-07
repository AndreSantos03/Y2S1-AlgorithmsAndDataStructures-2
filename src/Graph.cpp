//
// Created by NASA on 06/01/2023.
//

#include "Graph.h"

Graph::Graph(){}

void Graph::addEdge(Airport source, Airport target, Airline airline,float distance)
{
    nodes[source.get_code()].adj.push_back(Flight(source, target, airline,distance));
}


float Graph::getDistance(float lat1, float lon1, float lat2, float lon2) {
    float difLat = (lat2 - lat1) * M_PI / 180.0;
    float difLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    // apply formula
    float a = pow(sin(difLat / 2), 2) + pow(sin(difLon1 / 2), 2) * cos(lat1) * cos(lat2);
    float rad = 6371;
    float c = 2 * asin(sqrt(a));
    return rad * c;
}

vector<string> Graph::BFS(std::string s, std::string f, unordered_map<std::string, Airport> airports) {
    unordered_map<string, pair<int, vector<string>>> ans;
    ans[s] = {0, {}};

    for(auto &[key, value] : nodes) value.visited = false;

    queue<string> q;
    q.push(s);
    nodes[s].visited = true;

    if (s == f){
        return {};
    }
    while (!q.empty()){
        for(auto e: nodes[q.front()].adj){
            string w = e.get_target().get_code();
            if (!nodes[w].visited || ans[q.front()].first + e.get_distance() < ans[w].first){
                ans[w] = {ans[q.front()].first + e.get_distance(), ans[q.front()].second};
                ans[w].second.push_back(e.get_target().get_code());
                q.push(w);
                nodes[w].visited = true;
            }
        }
        q.pop();
    }
    return ans[f].second;
}

set<string> Graph::BFL(std::string c, int d) {
    unordered_map<string, bool> visited;
    set<string> airports_visited;
    set<string> airports_visiting;
    set<string> temp;

    visited[c] = true;

    for (int i = 0; i<d ; i++){
        for (string c : airports_visiting){
            for (auto e:nodes[c].adj) {
                if(!visited[e.get_target().get_code()]){
                    temp.insert(e.get_target().get_code());
                    visited[e.get_target().get_code()] = true;
                }
            }
            airports_visited.insert(c);
        }
        for(string c : temp){
            airports_visiting.insert(c);
        }
    }
    return airports_visited;
}