//
// Created by NASA on 06/01/2023.
//

/**
 * @file Airport.cpp
 * Funções para obter informações sobre os aeroportos
 */

#include "Airport.h"


/**
 * @brief
 * Construtor default da class Airport
 */

Airport::Airport() {}

/**
 * @brief
 * Construtor de new Airport: Airport object
 *
 * @param code código do aeroporto
 * @param name nome do aeroporto
 * @param city cidade do aeroporto
 * @param country país do aeroporto
 * @param latitude latitude do aeroporto
 * @param longitude longitude do aeroporto
 */


Airport::Airport(string code,string name,string city,string country,float latitude, float longitude){
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

/**
 * @brief
 * Override do operator< para poder comparar os códigos de dois aeroportos
 * @return true se o código do aeroporto 1 for menor do que o do aeroporto 2
 * @return false caso contrário
 */

bool Airport::operator<(const Airport &airport2) const{
    return this->code < airport2.get_code();
}
