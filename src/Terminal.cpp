//
// Created by ftmlo on 07/01/2023.
//

/**
 * @file Terminal.cpp
 * funções relacionadas com o terminal
 */

#include "Terminal.h"

/**
 * Construtor de new Terminal: Terminal object
 * @param airlines companhias aéreas
 * @param airports aeroportos
 * @param flights voos
 */

Terminal::Terminal(unordered_map<string, Airline> airlines, unordered_map<string, Airport> airports, Graph flights) {
    this->algorithms = Algorithms(airlines,airports,flights);
}

/**
 *
 */

void Terminal::IO() {
    cout << "-----Choose an option!-----\n" << endl;
    cout << "1: Get best flight pass." << endl;

    cin >> choice;

    if(choice == "1"){
        getBestFlightPath();
    }
}

/**
 * Obtêm mlehor maneira de viajar entre dois aeroportos
 */

void Terminal::getBestFlightPath() {
    while(true){
        string sourceCode;
        string targetCode;
        while(true)
        {
            cout << "Enter source airport code: ";
            cin >> choice;
            if(algorithms.isValidAirportCode(choice)){
                sourceCode = choice;
                break;
            }
            else{
                cout << "You entered an invalid airport code!" << endl;
            }
        }
        while(true)
        {
            cout << "Enter destination airport code: ";
            cin >> choice;
            if(algorithms.isValidAirportCode(choice)){
                targetCode = choice;
                break;
            }
            else{
                cout << "You entered an invalid airport code!" << endl;
            }
        }
        if(sourceCode == targetCode){
            cout << "You entered the same source and destination airports! ";
        }
        else{
            vector<string> ans = algorithms.bestPath(sourceCode,targetCode);
            cout << ans.size() << endl;
            for(string oui: ans){
                cout << oui << endl;
            }
            break;
        }
    }
    IO();
}
