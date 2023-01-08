/**
 * @file FlightController.cpp
 * Funções para ler informações em ficheiros, em relação aos voos
 */

#include "FlightController.h"

/**
 * Lê as companhias aéreas, aeroportos e voos, a partir de ficheiros
 */

void FlightController::initialize() {
    airlines = Reader::readAirlines();
    airports = Reader::readAirports();
    flights = Reader::readFlights(airlines,airports);
}
