#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <list>
#include <algorithm>

using namespace std;

inline bool
is_Shorter(std::string const& lhs,std::string const& rhs)
{
    return lhs.size() < rhs.size();
}

template<typename Sequence>
inline std::ostream& println(Sequence const& seq)
{
    for(const auto & elem:seq) std::cout << elem << " ";
    std::cout << std:: endl;
    return std:: cout;
}

void elimdups(std::vector<std::string>&vs)
{
    std::sort(vs.begin(),vs.end());
    auto new_end = std::unique(vs.begin(),vs.end());
    vs.erase(new_end,vs.end());
}



int main()
{
    std::vector<std::string> v{"1234","1234","1234","Hi","alan","wang"};
    elimdups(v);
   // [](const string &a,const string &b){ return a.size()< b.size();}
    //std::stable_sort(v.begin(),v.end(),is_Shorter);

    //lambda±í´ïÊ½
    //[](const string &a,const string &b){ return a.size()< b.size();}
    std::stable_sort(v.begin(),v.end(),
                     [](const string &a,const string &b){ return a.size()< b.size();});
    println(v);

    return 0;
}
