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

int main() {
    create_world();

    // Find the richest country in each continent
    auto compareByGnp = [](auto &left, auto &right) {
        return left->gnp < right->gnp;
    };
    auto continentRichestCountryReducer = [&compareByGnp](auto &&continentCountries, /* reduce type */ auto &entry) {
        auto ctry = entry.second;
        auto continent = ctry->continent;
        auto continentRichestCountry = continentCountries.find(continent);
        if (continentRichestCountry == continentCountries.end())
            continentCountries[continent] = ctry;
        else {
            auto richestCountry = continentRichestCountry->second;
            if (compareByGnp(richestCountry, ctry))
                continentCountries[continent] = ctry;
        }
        return continentCountries;
    };
    auto continentCountries = std::accumulate(
            countries.begin(),
            countries.end(),
            std::map<std::string, shared_ptr<country>>(), // reduce type
            continentRichestCountryReducer
    );
    auto print_continent_richest_country = [](const auto &pair) {
        std::cout << pair.first << ": " << pair.second->name << "\n";
    };

    std::for_each(continentCountries.cbegin(), continentCountries.cend(), print_continent_richest_country);

    return 0;
}