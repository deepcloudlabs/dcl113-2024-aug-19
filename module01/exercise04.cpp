#include <iostream>
#include <vector>
#include <parallel/numeric> // since c++17
#include <string>
#include <execution>
#include <fstream>

using namespace std;

//region global data
vector<string> files{
        string("c:\\tmp\\dictionary-eng.txt"),
        string("c:\\tmp\\dictionary-tur.txt"),
        string("c:\\tmp\\cluster-info.txt"),
        string("c:\\tmp\\algotrading-market-apis.txt"),
        string("c:\\tmp\\war-and-peace.txt")
};
inline
auto is_new_line(char c){
    return c == '\n';
}

auto
open_file(const string& file_name){
    return ifstream{file_name};
}

auto&
read_one_char(ifstream& input_file,char &c){
    return input_file.get(c);
}

auto map_file_to_line_counts(const string &file_name) {
    ifstream input_file = open_file(file_name);
    auto line_count = 0;
    char c;
    // external loop -> implements an algorithm
    while (read_one_char(input_file,c)) {
        if (is_new_line(c)) {
            line_count++;
        }
    }
    return line_count;
}
// problem: count total lines count

struct Topla { // function object -> functor
    int operator()(int x,int y){
        return x+y;
    }
};
int main() {
    int z = 0;
    // Declarative Programming -> functional programming
    // describe solution
    // files -> transform -> line counts -> reduce/accumulate -> solution
    // pipeline
    vector<int> line_counts{};
    // 1. transform: Higher Order Function
    // auto map_file_to_line_counts = ???; // Pure function
    transform( files.begin(),files.end(), back_inserter(line_counts),map_file_to_line_counts);
    // 2. reduce -> accumulate: Higher Order Function
    auto total_line_count = accumulate(line_counts.begin(),line_counts.end(),0,Topla{});
    cout << "total line count: " << total_line_count << endl;
    // imperative -> total line count: 447152
    // descriptive -> total line count: 447152
    return 0;
}