/**
 * @file FlightController.cpp
 * Funções para ler informações em ficheiros, em relação aos voos
 */

#include "FlightController.h"

/**
 * @brief
 * Construtor default da class FlightController
 */

FlightController::FlightController() {
    airlines = Reader::readAirlines();
    airports = Reader::readAirports();
    flights = Reader::readFlights(airlines,airports);
}
