#include "city.h"
#include "country.h"
#include "world-util.h"

#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <ranges>

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

int main() {
    create_world();
    MapOfContinentSize mapOfContinentSize = ranges::fold_left(countries | views::values, MapOfContinentSize{},
                                                              [](MapOfContinentSize group,
                                                                 const CountrySharedPtr &countrySharedPtr) {
                                                                  group[countrySharedPtr->continent]++;
                                                                  return group;
                                                              });
    for (const auto &[continent, continentCountrySize]: mapOfContinentSize) {
        cout << continent << ": " << continentCountrySize << endl;
    }
    return 0;
}