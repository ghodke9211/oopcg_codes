#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Create a map to store state names and their populations
    map<string, int> statePopulation;

    // Insert state names and populations into the map
    statePopulation["Maharashtra"] = 39538223;
    statePopulation["Goa"] = 29145505;
    statePopulation["Gujarat"] = 21538187;

    string state;

    // Ask the user to input a state name
    cout << "Enter the name of a state: ";
    getline(cin, state);

    // Search for the state in the map and display its population
    auto it = statePopulation.find(state);

    if (it != statePopulation.end()) {
        cout << "The population of " << state << " is " << it->second << ".\n";
    } else {
        cout << "State not found.\n";
    }

    return 0;
}
