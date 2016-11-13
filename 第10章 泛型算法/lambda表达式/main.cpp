#include <iostream>

using namespace std;

int main()
{
    auto f = []()->int {float i;i=23.4;return i;};


    cout << f() << endl;

    return 0;
}
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//
//
//int main()
//{
//    string Name;
//
//
//    while(
//    bool t =[&]
//            {
//                cout<< "name:\n";
//                cin>>Name;
//                if(1)
//                return Name != "@q";
//            }();
//        )
//
//        cout<< "\tsay "<<Name<<"\n\n"<< t <<endl;
//
//    return 0;
//}
