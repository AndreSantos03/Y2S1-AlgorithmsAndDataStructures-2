/**
 * @file Flight.cpp
 * Funções para obter informações sobre os voos
 */

#include "Flight.h"

/**
 * @brief
 * Construtor de new Flight: Flight object
 *
 * @param source aeroporto de origem
 * @param target aeroporto de destino
 * @param airline companhia aérea
 * @param weight peso do avião
 */

Flight::Flight(Airport source, Airport target, Airline airline, float weight){
    this->source = source;
    this->target = target;
    this->airline = airline;
    this->distance = distance;
}