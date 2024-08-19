#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <ranges>
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


auto
open_file(const string& file_name){
    cout << "[open_file] file name: " << file_name << endl;
    return ifstream{file_name};
}

auto count_lines(ifstream input_file) {
    auto number_of_lines = count(istreambuf_iterator<char>(input_file), istreambuf_iterator<char>(), '\n');
    cout << "[count_lines]: returning... " << number_of_lines << endl;
    return number_of_lines;
}

// problem: count total lines count

int main() {
    // Declarative Programming -> functional programming
    // describe solution
    // files -> transform -> line counts -> reduce/accumulate -> solution
    // pipeline
    // string -> ifstream -> int
    for(int count :  files   | ranges::views::transform(open_file)
                             | ranges::views::transform(count_lines))
                             | ranges::views::parallel() {
        cout << "[for] line count: " << count << endl;
    }
    /*
[open_file] file name: c:\tmp\dictionary-eng.txt
[count_lines]: returning... 349899
[for] line count: 349899
[open_file] file name: c:\tmp\dictionary-tur.txt
[count_lines]: returning... 25821
[for] line count: 25821
[open_file] file name: c:\tmp\cluster-info.txt
[count_lines]: returning... 6647
[for] line count: 6647
[open_file] file name: c:\tmp\algotrading-market-apis.txt
[count_lines]: returning... 137
[for] line count: 137
[open_file] file name: c:\tmp\war-and-peace.txt
[count_lines]: returning... 64648
[for] line count: 64648
     */
    return 0;
}