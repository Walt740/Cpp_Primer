#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> iv(1,10);
    if(!iv.empty())
    {
        auto val1 = *iv.begin();
        auto val2 = iv.front();
        auto last = iv.cend();
        auto val3 = *(--last);
        auto val4 = iv.back();

        cout << "iv.size() = " << iv.size() <<endl;
        cout<< val1 << " "<< val2 <<" " << val3 << " " <<val4 <<endl;
    }


    return 0;
}
