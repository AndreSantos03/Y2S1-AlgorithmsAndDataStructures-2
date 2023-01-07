//
// Created by NASA on 07/01/2023.
//

#include "Algorithms.h"

Algorithms::Algorithms() {}

Algorithms::Algorithms(unordered_map<string, Airline> airlines, unordered_map<string, Airport> airports, Graph flights) {
    this->airlines = airlines;
    this->airports = airports;
    this->flights = flights;
}

bool Algorithms::isValidAirportCode(string code) {
    return (airports.find(code) != airports.end());
}



