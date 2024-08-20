/**
 * @author Binnur Kurt <binnur.kurt@gmail.com>
 */
#include "city.h"
#include "country.h"
#include "world-util.h"

#include <map>
#include <iostream>
#include <string>
#include <memory>
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

void print_continent_country_counts(const pair<string, int> &entry) {
    cout << entry.first << ": " << entry.second << endl;
}

int main() {
    create_world();
    auto groupingByContinentCounter = [](auto &&groupByCounting, auto &entry) {
        ++groupByCounting[entry.second->continent];
        return groupByCounting;
    };
    // reduce
    map<string, int> numOfCountriesByContinent = accumulate(countries.begin(), countries.end(), map<string, int>(),
                                                            groupingByContinentCounter);
    for_each(numOfCountriesByContinent.begin(), numOfCountriesByContinent.end(), print_continent_country_counts);
    return 0;
}