#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};

    for(auto c: vector<int>(vi.crbegin(),vi.crend()) )
        cout << c <<endl;
    return 0;
}
