#include <iostream>
#include "String.h"
#include <vector>

using namespace std;

int main()
{
    String s0("1"),s1("2"),s2("2"),s3("3"),s4("4"),s5("5");
    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);

    svec.push_back("good job");
    svec.push_back("hello world");
    for(auto &c : svec)
        cout << c <<endl;





	return 0;
}
