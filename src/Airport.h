/**
 * @file Airport.h
 * Funções para ler ficheiros
 */

#ifndef AEDPROJETO2_AIRPORT_H
#define AEDPROJETO2_AIRPORT_H

#include <iostream>
#include <list>

using namespace std;

class Airport {
private:
    string code, name, city, country;
    float latitude, longitude;
public:
    Airport();
    Airport(string code,string name,string city,string country,float latitude, float longitude);
    string get_code() const {return code;};
    string get_name() const {return name;};
    string get_city() const {return city;};
    string get_country() const {return country;};
    float get_latitude() const {return latitude;};
    float get_longitude() const {return longitude;};
    bool operator<(const Airport &airport2) const;
};


#endif //AEDPROJETO2_AIRPORT_H
