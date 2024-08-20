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

int main(){
    create_world();
    auto compareByGnpAsc = [](auto &firstEntry,auto &secondEntry){
        return firstEntry.second->gnp < secondEntry.second->gnp;
    };
    // reduce
    auto richest_country_entry =
    max_element(countries.begin(),countries.end(),compareByGnpAsc);
    cout << richest_country_entry->second->name << ", "
         << richest_country_entry->second->gnp
         << endl;
    auto poor_country_entry =
            min_element(countries.begin(),countries.end(),compareByGnpAsc);
    cout << poor_country_entry->second->name << ", "
         << poor_country_entry->second->gnp
         << endl;
    return 0;
}