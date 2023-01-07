/**
 * @file Airline.cpp
 * funções para obter informações sobre as companhias aéreas
 */

#include "Airline.h"

/**
 * @brief
 * Construtor default da class Airline
 */

Airline::Airline(){};

/**
 * @brief
 * Construtor de new Airline: Airline object
 *
 * @param code código da companhia aérea
 * @param name nome da companhia
 * @param callSign indicativo da companhia
 * @param country país de origem da companhia
 */

Airline::Airline(string code, string name, string callSign, string country){
    this->code = code;
    this->name = name;
    this->callSign = callSign;
    this->country = country;
}

/**
 * @brief
 * Override do operator< para poder comparar os códigos de duas companhias
 * @return true se o código doa companhia aérea 1 for menor do que o da companhia 2
 * @return false caso contrário
 */

bool Airline::operator<(const Airline &airline2) const
{
    return this->code < airline2.get_code();
}
