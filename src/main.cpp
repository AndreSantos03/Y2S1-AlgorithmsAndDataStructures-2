#include <iostream>
#include "FlightController.h"
#include "Terminal.h"
#include "Algorithms.h"

/**
 * @file main.cpp
 * Inicializa todas as classes, da end do input e do output e processa os pedidos de informação de aeroportos, voos e companhias aéreas
 */

using namespace std;

/**
 * Inicializa todas as classes
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

