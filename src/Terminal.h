//
// Created by ftmlo on 07/01/2023.
//

#ifndef AEDPROJETO2_TERMINAL_H
#define AEDPROJETO2_TERMINAL_H

#include <iostream>
#include <list>
#include "Graph.h"
#include "Flight.h"
#include "FlightController.h"
#include "Airline.h"
#include "Airport.h"
#include <unordered_map>
#include "Reader.h"
#include <set>

using namespace std;

class Terminal
{
 private:
    static void info_1(FlightController &fm);
    static void info_2(FlightController &fm);
    static void info_3(FlightController &fm);
    static void info_4(FlightController &fm);
    static void info_5(FlightController &fm);


 public:
    static void info(FlightController &fm);
};

#endif //AEDPROJETO2_TERMINAL_H
