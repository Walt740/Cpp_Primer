#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class StrLenBetWeen
{
public:
    StrLenBetWeen(int minLen,int maxLen ): minLen(minLen), maxLen(maxLen ) { }
    bool operator() (const string &str)
    {
        return str.length() >= minLen && str.length() <= maxLen;
    }
private:
    int maxLen;
    int minLen;
};

class StrNotShorterThan
{
public:
    StrNotShorterThan(int len):minLen(len){}
    bool operator()(const string &str){return str.length() >= minLen;}

private:
    int minLen;
};


void read_Str(istream &is, vector<string> &vec)
{
    string word;
    while(is >> word)
    {
        vec.push_back(word);
    }
}

int main()
{
    vector<string> vec;
    read_Str(cin,vec);
    StrLenBetWeen slenBetween(1,9);
    StrNotShorterThan slenNotBetween(10);
    cout << "len 1~9: " << count_if(vec.begin(),vec.end(),slenBetween) <<endl;
    cout << "len >= 10: " << count_if(vec.begin(),vec.end(),slenNotBetween)<<endl;

    return 0;
}
