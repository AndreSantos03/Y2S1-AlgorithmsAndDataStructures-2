//
// Created by NASA on 06/01/2023.
//

#include "Airport.h"


Airport::Airport() {}

Airport::Airport(string code,string name,string city,string country,float latitude, float longitude){
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

bool Airport::operator<(const Airport &airport2) const{
    return this->code < airport2.get_code();
}
