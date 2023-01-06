//
// Created by NASA on 06/01/2023.
//

#include "FlightController.h"

FlightController::FlightController() {
    airlines = Reader::readAirlines();
    airports = Reader::readAirports();
    flights = Reader::readFlights(airlines,airports);
}
