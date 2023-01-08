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
 * Inicializa o FlightController, e permite obter informações sobre viajens, companhias e aeroportos
 */

void Terminal::IO() {
    cout << "-----Choose an option!-----\n" << endl;
    cout << "1: Get best flight pass." << endl;
    cout << "2: Get number of flights departing from a certain airport." << endl;
    cout << "3: Get number of airlines operating on a certain airport." << endl;
    cout << "4: Get number of how many different airports you can reach from a certain airport with a maximum number of flights." << endl;
    cout << "9: Exit." << endl;

    cin >> choice;

    if(choice == "1"){
        getBestFlightPath();
    }
    else if (choice == "2"){
        getNumberOfFlights();
    }
    else if (choice == "3"){
        getNumberOfAirlines();
    }
    else if (choice == "4"){
        getNumberOfDestinations();
    }

    else if(choice == "9"){

    }
}

/**
 * Obtêm o número máximo de voos, que um aeroporto de origem faz, caso este exista
 * @param fc  FlightController
 */

/**
 * Obtêm o número de países, para o qual um aeroporto faz viagens
 * @param fc FlightController
 */


/**
 * Obtêm o número de aeroportos, para o qual um aeroporto de origem viaja
 * @param fc FlightController
 */

void Terminal::getNumberOfDestinations(){
    string sourceCode;
    while(true){
        cout << "Enter source airport: ";
        cin >> choice;
        if (algorithms.isValidAirportCode(choice)) {
            sourceCode = choice;
            break;
        } else {
            cout << "You entered an invalid airport code!" << endl;
        }
    }
    int max;
    cout << "Enter max number of flights: ";
    cin >> choice;
    max = stoi(choice);
    set<pair<string,string>> airportsAndCities = algorithms.getDestinationFromAirports(sourceCode,max);
    for(auto s:airportsAndCities){
        cout << "You can reach the aiport " << s.first << " in city " << s.second << "." << endl;
    }
}

/**
 * Pesquisa o número de voos que estão a partir de um aeroporto de origem
 * @param fc FlightController
 */

void Terminal::getNumberOfFlights() {
    string sourceCode;
    cout << "Enter source airport: ";
    cin >> choice;
    if (algorithms.isValidAirportCode(choice)) {
        sourceCode = choice;
    } else {
        cout << "You entered an invalid airport code!" << endl;
    }
    list<pair<string, string>> flightsFromAirport = algorithms.getFlightsFromAirport(sourceCode);
    cout << endl << "This airport has " << flightsFromAirport.size() << " departing flights." << endl;

    while(true){
        cout << "Do you want a listing of said flights? : Y/N";
        cin >> choice;
        if(choice == "Y" || choice == "y"){
            for(pair<string,string> s : flightsFromAirport){
                cout << "Flight from airline " << s.first << " to the Airport " << s.second << "." << endl;
            }
            break;
        }
        else if(choice == "N" || choice == "n"){
            break;
        }
        else{
            cout << "You entered an invalid input!" << endl;
        }
    }

    IO();
}

/**
 * Retorna o número de companhias aéreas que trabalham num determinado aeroporto
 * @param fc FlightController
 */

void Terminal::getNumberOfAirlines() {
    string sourceCode;
    cout << "Enter source airport: ";
    cin >>choice;
    while(true){
        if(algorithms.isValidAirportCode(choice)){
            sourceCode=choice;
            break;
        } else {
            cout << "You entered an invalid airport code!" << endl;
        }
    }
    int sum=0;
    set<string>  air = algorithms.getAirlinesFromAirports(choice);
    cout << endl << "There are " << air.size() << " airlines operating on this airport.\n" << endl;

    while(true){
        cout << "Do you want a listing of said flights? : Y/N";
        cin >> choice;
        if(choice == "Y" || choice == "y"){
            for(string s : air){
                cout << s << endl;
            }
            break;
        }
        else if(choice == "N" || choice == "n"){
            break;
        }
        else{
            cout << "You entered an invalid input!" << endl;
        }
    }
    IO();
}

/**
 * Retorna o caminho mais rápido entre dois aeroportos
 * @param fc FlightController
 */

void Terminal::getBestFlightPath() {
    string sourceCode;
    string targetCode;
    cout << "-----Choose an option!-----\n" << endl;

    cout << "1: Choose from airport codes." << endl;
    cout << "2: Choose from city name." << endl;
    cout << "3: Choose from latitude and longitude." << endl;
    cin >> choice;
    if(choice == "1") {
        while (true) {
            cout << "Enter source airport code: ";
            cin >> choice;
            if (algorithms.isValidAirportCode(choice)) {
                sourceCode = choice;
                break;
            } else {
                cout << "You entered an invalid airport code!" << endl;
            }
        }
        while (true) {
            cout << "Enter destination airport code: ";
            cin >> choice;
            if (algorithms.isValidAirportCode(choice)) {
                targetCode = choice;
                break;
            } else {
                cout << "You entered an invalid airport code!" << endl;
            }
        }
    }
    else if(choice == "2") {
        while (true) {
            cout << "Enter source city name: ";
            cin >> choice;
            choice = algorithms.convertCity(choice);
            if (choice != "NONE") {
                sourceCode = choice;
                break;
            } else {
                cout << "You entered an invalid city name!" << endl;
            }
        }
        while (true) {
            cout << "Enter destination city name: ";
            cin >> choice;
            choice = algorithms.convertCity(choice);
            if (choice != "NONE") {
                targetCode = choice;
                break;
            } else {
                cout << "You entered an invalid airport code!" << endl;
            }
        }
    }
    else if(choice == "3"){
        float lat;
        float lon;
        while (true) {
            cout << "Enter source latitude: ";
            cin >> choice;
            lat = stof(choice);
            if(!(lat >= -180 && lat <=180)){
                cout << "You entered an invalid latitude!" << endl;
            } else {
                break;
            }
        }
        while (true) {
            cout << "Enter source longitude: ";
            cin >> choice;
            lon = stof(choice);
            if(!(lat >= -90 && lat <=90)){
                cout << "YYou entered an invalid longitude!" << endl;
            } else {
                sourceCode = algorithms.convertCoordinates(lat,lon);
                cout << sourceCode << endl;
                break;
            }
        }
        while (true) {
            cout << "Enter destiny latitude: ";
            cin >> choice;
            lat = stof(choice);
            if(!(lat >= -180 && lat <=180)){
                cout << "You entered an invalid latitude!" << endl;
            } else {
                break;
            }
        }
        while (true) {
            cout << "Enter destiny longitude: ";
            cin >> choice;
            lon = stof(choice);
            if(!(lat >= -90 && lat <=90)){
                cout << "YYou entered an invalid longitude!" << endl;
            } else {
                targetCode = algorithms.convertCoordinates(lat,lon);
                cout << targetCode << endl;
                break;
            }
        }
    }
    cout << "-----Choose an option!-----\n" << endl;
    cout << "1: Choose specific airlines." << endl;
    cout << "2: Choose the overall best flight path." << endl;
    cin >> choice;
    list<string> allowedAirlines;
    if (choice == "1") {
        while (true) {
            cout << "Enter allowed airlines codes or enter q to process the data: ";
            cin >> choice;
            if (choice == "q") {
                break;
            } else {
                allowedAirlines.push_back(choice);
            }
        }
    }
    try{
        vector<pair<string,string>> results = algorithms.bestPath(sourceCode,targetCode,allowedAirlines);
        cout << "The fastest flight path is : \n" << endl;
        for(auto it = results.begin() + 1; it != results.end();it++){
            cout << "You take a flight to the Airport in " << algorithms.getCityFromCode(it->first) <<  " through the airline " << it->second << "." << endl;
        }
    }
    catch(...) {
        cout << "Couldn't find a path with such airline!";
    }
    IO();
}
