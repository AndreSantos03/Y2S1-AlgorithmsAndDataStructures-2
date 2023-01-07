#include <iostream>
#include "FlightController.h"
#include "Terminal.h"
#include "Algorithms.h"

using namespace std;

int main() {
    FlightController flightController = FlightController();

    Terminal terminal(flightController.get_airlines(),flightController.get_airports(),flightController.get_flights());

    while(true){
        terminal.IO();
    }

    return 0;
}
