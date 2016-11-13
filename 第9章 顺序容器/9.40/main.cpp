#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
    vector<int> svec;
    svec.reserve(1024);
    int word = 0;
    for(;word < 1048;word++)
        svec.push_back(word);

    svec.resize(svec.size() + svec.size()/2);
    for(auto &c : svec)
        cout << c <<endl;
    cout <<"svec:size:" << svec.size() << "capacity:" << svec.capacity() << endl;

    return 0;
}

