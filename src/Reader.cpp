//
// Created by NASA on 06/01/2023.
//

#include "Reader.h"

unordered_map<string, Airline> Reader::readAirlines(){
    unordered_map<string, Airline> retHash;
    ifstream f;
    f.open("../data/airlines.csv");
    string buf;
    getline(f,buf,'\n');
    while(getline(f,buf,'\n')){
        stringstream line(buf);
        string code, name, callSign, country;
        getline(line, code, ',');
        getline(line, name, ',');
        getline(line, callSign, ',');
        getline(line, country, '\n');
        retHash[code] = Airline(code, name, callSign, country);
    }
    f.close();
    return retHash;
}

unordered_map<string, Airport> Reader::readAirports() {
    unordered_map<string, Airport> retHash;
    ifstream f;
    f.open("../data/airports.csv");
    string buf;
    getline(f,buf,'\n');
    while(getline(f,buf,'\n')){
        stringstream line(buf);
        string code, name, city, country, sLat, sLon;
        float latitude, longitude;
        getline(line, code, ',');
        getline(line, name, ',');
        getline(line, city, ',');
        getline(line, country, ',');
        getline(line, sLat, ',');
        getline(line, sLon, '\n');
        retHash[code] = Airport(code, name, city, country, stof(sLat), stof(sLon));
    }
    f.close();
    return retHash;
}

Graph Reader::readFlights(unordered_map<string, Airline> airlines, unordered_map<string, Airport> airports) {
    Graph retGraph;
    ifstream f;
    f.open("../data/flights.csv");
    string buf;
    getline(f,buf,'\n');
    while(getline(f,buf,'\n')){
        stringstream line(buf);
        string source, target, airline;
        getline(line, source, ',');
        getline(line, target, ',');
        getline(line, airline, ',');
        Airport a1 = airports[source];
        Airport a2 = airports[target];
        retGraph.addEdge(a1,a2,airlines[airline], Graph::getDistance(a1.get_latitude(), a1.get_longitude(), a2.get_latitude(), a2.get_longitude()));
    }
    f.close();
    return retGraph;
}
