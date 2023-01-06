//
// Created by NASA on 06/01/2023.
//

#ifndef AEDPROJETO2_GRAPH_H
#define AEDPROJETO2_GRAPH_H


#include <list>
#include <unordered_map>
#import <math.h>
#include <vector>
#include "Flight.h"

class Graph {
private:
    //doesn't make sense to add edges, we'll just use flights
    struct Node{
        list<Flight> adj;
        bool visited;
    };
public:
    unordered_map<string, Node> nodes;
    Graph();
    void addEdge(Airport src, Airport dest, Airline line, float weight);
    static float getDistance(float lat1, float lon1, float lat2, float lon2);
};


#endif //AEDPROJETO2_GRAPH_H
