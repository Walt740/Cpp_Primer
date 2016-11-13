#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

template<typename Sequence>
void println(const Sequence& seq )
{
    for(const auto& elem:seq )
        std::cout << elem << " ";
    std::cout << std::endl;
}

auto eliminate_duplicates(std::vector<std::string> &vs)-> std::vector<std::string>&
{
    std::sort(vs.begin(),vs.end());
    println(vs);
    auto new_end = std::unique(vs.begin(),vs.end());
    println(vs);
    vs.erase(new_end,vs.end());
    return vs;
}

int main()
{
    std::vector<std::string> vs{"a","v","a","s,","v","a","a"};
    println(vs);
    println(eliminate_duplicates(vs));
    return 0;
}
