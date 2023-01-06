//
// Created by NASA on 06/01/2023.
//

#include "Airline.h"

Airline::Airline(){};

Airline::Airline(string code, string name, string callSign, string country){
    this->code = code;
    this->name = name;
    this->callSign = callSign;
    this->country = country;
}

bool Airline::operator<(const Airline &airline2) const
{
    return this->code < airline2.get_code();
}
