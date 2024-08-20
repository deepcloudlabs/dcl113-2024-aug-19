/**
 * @author Binnur Kurt <binnur.kurt@gmail.com>
 */
#include "city.h"
#include "world-util.h"

#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
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
    auto country_shared_ptrs =
            countries | views::values | views::filter([](const CountrySharedPtr ctry) { return ctry->gnp > 0; });
    auto richest_country = ranges::max(country_shared_ptrs, ranges::less{},&country::gnp);
    auto poorest_country = ranges::min(country_shared_ptrs,ranges::less{},&country::gnp);

    cout << richest_country->name << ", "
         << richest_country->gnp
         << endl;
    cout << poorest_country->name << ", "
         << poorest_country->gnp
         << endl;
    return 0;
}