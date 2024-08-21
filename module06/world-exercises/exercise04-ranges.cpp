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
#include <ranges>

using namespace std;
using namespace world;

using MapOfContinentRichestCountry = map<string, shared_ptr<country>>;
using CountrySharedPtr = shared_ptr<country>;
using CitySharedPtr = shared_ptr<city>;
using MapOfCities = map<int, CitySharedPtr>;
using MapOfCountries = map<string, CountrySharedPtr>;

MapOfCities cities;
MapOfCountries countries;

int main() {
    create_world();

    // Find the richest country in each continent
    MapOfContinentRichestCountry mapOfContinentRichestCountry = ranges::fold_left(countries | views::values,
                                                                                  MapOfContinentRichestCountry{},
                                                                                  [](MapOfContinentRichestCountry group,
                                                                                     const CountrySharedPtr &countrySharedPtr) {
                                                                                      auto found = group.find(
                                                                                              countrySharedPtr->continent);
                                                                                      if (found == group.end()) {
                                                                                          group[countrySharedPtr->continent] = countrySharedPtr;
                                                                                      } else if (found->second->gnp <
                                                                                                 countrySharedPtr->gnp) {
                                                                                          group[countrySharedPtr->continent] = countrySharedPtr;
                                                                                      }
                                                                                      return group;
                                                                                  });
    for (const auto &[continent, richestCountry]: mapOfContinentRichestCountry) {
        cout << continent << ": " << *richestCountry << endl;
    }
    return 0;
}