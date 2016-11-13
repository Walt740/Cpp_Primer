#include <iostream>
#include "StrBlob.h"

using namespace std;

int main()
{
    StrBlob b1;
    {
        StrBlob b2{"a","an","the"};
        b1 = b2;
        b2.push_back("about");

       // cout << b1.data.use_count() << " " << b2.data.use_count() << endl;
    }
    //cout << b1.data.use_count() << " " ;//<< b2.data.use_count() << endl;
    return 0;
}
