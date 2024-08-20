/**
 * @author Binnur Kurt <binnur.kurt@gmail.com>
 */
#include "city.h"
#include "country.h"
#include "world-util.h"

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <numeric>

using namespace std;
using namespace world;

using MapOfContinentSize = map<string, int>;
using CountrySharedPtr = shared_ptr<country>;
using CitySharedPtr = shared_ptr<city>;
using MapOfCities = map<int, CitySharedPtr>;
using MapOfCountries = map<string, CountrySharedPtr>;
using MapOfContinentSize = map<string, int>;

MapOfCities cities;
MapOfCountries countries;

void print_continent(const string &continent) {
    cout << continent << "\t";
}

int main() {
    create_world();
    auto continentReducer = [](auto &&conts, auto &entry) {
        auto country = entry.second;
        conts.insert(country->continent);
        return conts;
    };
    auto continents = accumulate(countries.begin(), countries.end(), set<string>(), continentReducer);
    for_each(continents.begin(), continents.end(), print_continent);
    cout << endl << "done." << endl;
    return 0;
}