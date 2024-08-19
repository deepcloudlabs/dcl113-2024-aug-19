#include <iostream>
#include <vector>
#include <string>
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
int total_line_count = 0;
//endregion

//region procedures
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

auto count_lines_imperative(const string &file_name) {
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

auto count_lines_imperative(const vector<string> &files) {
    auto total_line_count = 0;
    for (auto &file: ::files) { // external loop
        auto line_count = count_lines_imperative(file);
        total_line_count += line_count;
    }
    return total_line_count;
}
//endregion

// problem: count total lines count
int main() {
    // Imperative Programming -> procedural programming
    // algorithm: for-each
    // external loop: out of container(files)
    total_line_count = count_lines_imperative(files);
    cout << "total line count: " << total_line_count << endl;
    return 0;
}


