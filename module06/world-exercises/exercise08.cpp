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
#include <ranges>
#include <parallel/numeric>
#include <functional>

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

auto
in_continent(shared_ptr<country> &ulke, const string &continent) {
    return ulke->continent == continent;
}

auto
string_length_shorter(const string &s, int length_limit) {
    return s.size() <= length_limit;
}

auto
to_country_name(shared_ptr<country> &ulke) {
    return ulke->name;
}

int main() {
    create_world();
    auto is_asian = bind(in_continent, placeholders::_1, "Asia");
    auto length_shorter_than4 = bind(string_length_shorter, placeholders::_1, 4);
    // "Asia" kıtasındaki 4 ya da daha az karakterden oluşan ülke isimleri
    for (auto country_name:
            ranges::views::values(countries)
            | ranges::views::filter(is_asian)
            | ranges::views::transform(to_country_name)
            | ranges::views::filter(length_shorter_than4)
            ) {
        cout << country_name << endl;
    }
    auto to_country = [](pair<const string, shared_ptr<country>> &entry) {
        return entry.second;
    };
    vector<shared_ptr<country>> v_countries;
    // ranges::views::values(countries)
    transform(countries.begin(), countries.end(), back_inserter(v_countries), to_country);

    // ranges::views::filter(is_asian)
    vector<shared_ptr<country>> asian_countries;
    copy_if(v_countries.begin(), v_countries.end(), back_inserter(asian_countries), is_asian);

    // ranges::views::transform(to_country_name)
    vector<string> asian_countries_names;
    transform(asian_countries.begin(), asian_countries.end(), back_inserter(asian_countries_names), to_country_name);

    // ranges::views::filter(length_shorter_than4)
    vector<string> asian_countries_names_shorter_than4;
    copy_if(asian_countries_names.begin(), asian_countries_names.end(),
            back_inserter(asian_countries_names_shorter_than4), length_shorter_than4);

    // for (auto country_name :
    for_each(asian_countries_names_shorter_than4.begin(), asian_countries_names_shorter_than4.end(),
             [](auto s) { cout << s << endl; });
    return 0;
}