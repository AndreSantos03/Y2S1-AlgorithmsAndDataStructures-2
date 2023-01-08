#include <iostream>
#include "FlightController.h"
#include "Terminal.h"
#include "Algorithms.h"

using namespace std;

/**
 * Inicializa o flightController e o Terminal
 * @return int
 */

int main() {
    FlightController fc;
    fc.initialize();

    Terminal terminal(fc.get_airlines(),fc.get_airports(),fc.get_flights());

    while(true){
        terminal.IO(fc);
    }
}

