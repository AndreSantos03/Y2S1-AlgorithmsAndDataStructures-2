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
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    float a = pow(sin(difLat / 2), 2) + pow(sin(difLat / 2), 2) * cos(lat1) * cos(lat2);
    float rad = 6371;
    float c = 2 * asin(sqrt(a));
    return rad * c;
}




