#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct EvenNumber { // predicate
    bool operator()(const int &number) {
        return number % 2 == 0;
    }
};

template<char delimeter_char, char end_of_line_char>
struct PrintNumber {
    void operator()(const int &number) {
        cout << number << delimeter_char << end_of_line_char;
    }
};

template<int pow>
struct Power {
    int operator()(const int &number) {
        auto result = 1;
        for (auto i = 0; i < pow; ++i) {
            result *= number;
        }
        return result;
    }
};

struct Topla {
    int operator()(int birikec, const int &number) {
        return birikec + number;
    }
};

int main() {
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // numbers -> filter if even -> map to cubed -> reduce to their sum
    // filter even number
    vector<int> even_numbers{};
    copy_if(numbers.begin(), numbers.end(), back_inserter(even_numbers), EvenNumber{});
    for_each(even_numbers.begin(), even_numbers.end(), PrintNumber<':', ' '>{});

    // map to their cubes
    vector<int> cubed_numbers{};
    transform(even_numbers.begin(), even_numbers.end(), back_inserter(cubed_numbers), Power<3>{});
    cout << endl;
    for_each(cubed_numbers.begin(), cubed_numbers.end(), PrintNumber<':', ' '>{});

    auto sum = accumulate(cubed_numbers.begin(), cubed_numbers.end(), int{}, Topla{});
    cout << "\nsum is " << sum << endl;
    return 0;
}