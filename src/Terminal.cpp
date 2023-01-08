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

void Terminal::IO(FlightController &fc) {
    cout << "-----Choose an option!-----\n" << endl;
    cout << "1: Get best flight pass." << endl;
    cout << "2: Get number of flights departing from a certain airport." << endl;
    cout << "3: Get number of airlines operating on a certain airport." << endl;
    cout << "4: Get number of possible destinations departing from a certain airport." << endl;
    cout << "5: Get number of different countries you can fly to from a certain airport." << endl;
    cout << "6: Get number of how many different countries you can reach from a certain airport with a maximum number of flights." << endl;
    cout << "9: Exit." << endl;

    cin >> choice;

    if(choice == "1"){
        getBestFlightPath(fc);
    }
    else if (choice == "2"){
        getNumberOfFlights(fc);
    }
    else if (choice == "3"){
        getNumberOfAirlines(fc);
    }
    else if (choice == "4"){
        getNumberOfDestinations(fc);
    }
    else if (choice == "5"){
        getNumberOfCountries(fc);
    }
    else if (choice == "6"){
        getNumberOfCountriesWithinX(fc);
    }
    else if(choice == "9"){

    }
}

void Terminal::getNumberOfCountriesWithinX(FlightController &fc) {
    string sourceCode;
    cout << "Enter source airport: ";
    cin >> choice;
    if (algorithms.isValidAirportCode(choice)) {
        sourceCode = choice;
    } else {
        cout << "You entered an invalid airport code!" << endl;
    }
    cout << "\n Enter maximum number of flights: " << endl;
    int max = 0;
    cin >> max;
    if(max>0){
        cout << endl << "There are " << fc.get_flights().BFL(choice, max+1).size() << " airports reachable within " << max << " flights from this airport." << endl;
    }
}

void Terminal::getNumberOfCountries(FlightController &fc) {
    string sourceCode;
    cout << "Enter source airport: ";
    cin >> choice;
    if (algorithms.isValidAirportCode(choice)) {
        sourceCode = choice;
    } else {
        cout << "You entered an invalid airport code!" << endl;
    }
    int sum=0;
    set<string> diff_airports;
    list<Flight> flights = fc.get_flights().nodes[choice].adj;
    for(Flight a : flights){
        diff_airports.insert(a.get_target().get_country());
    }
    cout << endl << "There are " << diff_airports.size() << " reachable from this airport.\n" <<endl;
}

void Terminal::getNumberOfDestinations(FlightController &fc){
    string sourceCode;
    cout << "Enter source airport: ";
    cin >> choice;
    if (algorithms.isValidAirportCode(choice)) {
        sourceCode = choice;
    } else {
        cout << "You entered an invalid airport code!" << endl;
    }
    int sum=0;
    set<string> diff_airports;
    list<Flight> flights = fc.get_flights().nodes[choice].adj;
    for (Flight a : flights){
        diff_airports.insert(a.get_target().get_code());
    }
    cout << endl << "There are " << diff_airports.size() << " airports reachable from this airport.\n" << endl;
}

void Terminal::getNumberOfFlights(FlightController &fc) {
    string sourceCode;
    cout << "Enter source airport: ";
    cin >> choice;
    if (algorithms.isValidAirportCode(choice)) {
        sourceCode = choice;
    } else {
        cout << "You entered an invalid airport code!" << endl;
    }
    int sum = fc.get_flights().nodes[choice].adj.size();
    cout << endl << "This airport has " << sum << " departing flights.\n" << endl;
}
void Terminal::getNumberOfAirlines(FlightController &fc) {
    string sourceCode;
    cout << "Enter source airport: ";
    cin >>choice;
    if(algorithms.isValidAirportCode(choice)){
        sourceCode=choice;
    } else {
        cout << "You entered an invalid airport code!" << endl;
    }
    int sum=0;
    set<string> diff_airlines;
    list<Flight> flights = fc.get_flights().nodes[choice].adj;
    for(Flight a : flights){
        diff_airlines.insert(a.get_airline().get_code());
    }
    cout << endl << "There are " << diff_airlines.size() << " airlines operating on this airport.\n" << endl;
}

/**
 * Obtém a melhor maneira de viajar entre dois aeroportos
 */

void Terminal::getBestFlightPath(FlightController &fc) {
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
    IO(fc);
}
