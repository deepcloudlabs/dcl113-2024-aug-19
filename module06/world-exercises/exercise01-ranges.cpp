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
#include <ranges>

using namespace std;
using namespace world;

map<int, shared_ptr<city>> cities;
map<string, shared_ptr<country>> countries;

void print_continent(const string &continent) {
    cout << continent << "\t";
}

int main(int argc, char *argv[]) {
    create_world();
    auto continents = ranges::to<set>(countries | views::values | views::transform([](auto p){return p->continent;}));
    ranges::for_each(continents,[](auto& cont){cout << cont << endl;});
    return 0;
}