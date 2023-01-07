#include <iostream>
#include "FlightController.h"
#include "Terminal.h"

using namespace std;

int main() {
    FlightController flightController;
    FlightController();

    Terminal::info(flightController);

    return 0;
}
