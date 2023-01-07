//
// Created by NASA on 06/01/2023.
//

/**
 * @file Airline.h
 * Funções para ler ficheiros
 */

#ifndef AEDPROJETO2_AIRLINE_H
#define AEDPROJETO2_AIRLINE_H

#include <iostream>
#include <list>

using namespace std;

class Airline{
private:
    string code, name, callSign, country;

public:
    Airline();
    Airline(string code, string name, string callSign, string country);
    string get_code() const {return code;};
    string get_name() const {return name;};
    string get_callSign() const {return callSign;};
    string get_country() const {return country;};
    bool operator<(const Airline &airline2) const;
};



#endif //AEDPROJETO2_AIRLINE_H
