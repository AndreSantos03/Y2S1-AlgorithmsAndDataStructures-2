/**
 * @file Graph.cpp
 * Funções para obter informações, envolvendo grafos
 */

#include "Graph.h"

/**
 * @brief
 * Construtor default da class Graph
 */

Graph::Graph(){}

/**
 * @brief
 * Adiciona um vértice novo, que corresponde a um voo, ao grafo do aeroporto de origem
 *
 * @param source aeroporto de origem
 * @param target aeroporto de destino
 * @param airline companhia aérea
 * @param distance distância entre os aeroportos
 */

void Graph::addEdge(Airport source, Airport target, Airline airline,float distance)
{
    nodes[source.get_code()].adj.push_back(Flight(source, target, airline,distance));
}

/**
 * @brief
 * Obtêm a distância entre dois aeroportos, a partir da sua longitude e latitude
 * @param lat1 latitude do aeroporto 1
 * @param lon1 longitude do aeroporto 1
 * @param lat2 latitude do aeroporto 2
 * @param lon2 longitude do aeroporto 2
 * @return float
 */

float Graph::getDistance(float lat1, float lon1, float lat2, float lon2) {
    float difLat = (lat2 - lat1) * M_PI / 180.0;
    float difLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    // apply formula
    float a = pow(sin(difLat / 2), 2) + pow(sin(difLon / 2), 2) * cos(lat1) * cos(lat2);
    float rad = 6371;
    float c = 2 * asin(sqrt(a));
    return rad * c;
}

/**
 * Executa uma breadth-first search
 * @param s
 * @param f
 * @param airports aeroportos
 * @return vector<string>
 */

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

/**
 *
 * @param c
 * @param d
 * @return set<string>
 */

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