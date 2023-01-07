//
// Created by ftmlo on 07/01/2023.
//

#include "Terminal.h"

void Terminal::info(FlightController &fm) {
    cout << "\n"
            "1 - How many different Airports can you go to from a specific one?\n"
            "2 - How many different Countries can you visit from a specific Airport?\n"
            "3 - How many different places can you visit from a specific Airport in a specific number of flights max?\n"
            "4 - How many flights start from a specific Airport?\n"
            "5 - How many Airlines operate on a specific Airport" << endl;

    int option=0;
    cin >> option;

    switch (option) {
        case 1:
            info_1(fm);
            break;
        case 2:
            info_2(fm);
            break;
        case 3:
            info_3(fm);
            break;
        case 4:
            info_4(fm);
            break;
        case 5:
            info_5(fm);
            break;
        default:
            cout << "\n Choose a number between 1 and 5\n" << endl;
            return;
    }
}

void Terminal::info_1(FlightController &fm) {
    cout << "\n Which Airport?\n" << endl;
    string option = "";
    cin >> option;
    int sum = 0;
    set<string> diff_airports;
    list<Flight> flights = fm.get_flights().nodes[option].adj;
    for (Flight p : flights){
        diff_airports.insert(p.get_target().get_code());
    }
    cout << endl << "You can travel to " << diff_airports.size() << " different Airports from this Airport\n" << endl;
}

void Terminal::info_2(FlightController &fm) {
    cout << "\n Which Airport?\n" << endl;
    string option = "";
    cin >> option;
    int sum = 0;
    set<string> diff_airports;
    list<Flight> flights = fm.get_flights().nodes[option].adj;
    for (Flight p : flights){
        diff_airports.insert(p.get_target().get_country());
    }
    cout << endl << "You can travel to " << diff_airports.size() << " different Countries from this Airport\n" << endl;
}

void Terminal::info_3(FlightController &fm) {
    cout << "\n Which Airport?\n" << endl;
    string option = "";
    cin >> option;
    cout << "\nMax Flights?\n";
    int max = 0;
    cin >> max;
    if (max > 0){
        cout << endl << "You can travel to " << fm.get_flights().BFL(option, max+1).size() << " different Airports within " << max << " flights from this Airport\n" <<endl;
    }
}

void Terminal::info_4(FlightController &fm) {
    cout << "\n Which Airport?\n" << endl;
    string option = "";
    cin >> option;
    int sum = fm.get_flights().nodes[option].adj.size();
    cout << endl << sum << " flights start on this Airport\n" << endl;
}

void Terminal::info_5(FlightController &fm) {
    cout << "\n Which Airport?\n" << endl;
    string option = "";
    cin >> option;
    int sum = 0;
    set<string> diff_airlines;
    list<Flight> flights = fm.get_flights().nodes[option].adj;
    for (Flight p : flights){
        diff_airlines.insert(p.get_airline().get_code());
    }
    cout << endl << diff_airlines.size() << " Airlines operate on this Airport\n" << endl;
}
