#include <iostream>
#include <vector>

using namespace std;

//int main()
//{
////    cout << "Hello world!" << endl;
//    int someval = 2;
//    vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
//    vector<int>:: iterator iter = iv.begin();
////    auto mid = iv.begin() + iv.size()/2;
////    cout << *mid <<endl ;
//    int org_size = iv.size(),new_elem = 0;
//    //每次循环步都重新计算“mid”，保证正确指向iv原中央元素
//    while(iter != (iv.begin() + org_size / 2 + new_elem))
//       if(*iter == someval)
//        {
//           iter = iv.insert(iter,2*someval);
//           iter+=2;
//           new_elem++ ;
//        }
//        else
//            iter++;
//
//    for(auto iter = iv.cbegin();iter != iv.cend();iter++)
//        cout << *iter <<endl;
//
//    return 0;
//}



int main()
{
//    cout << "Hello world!" << endl;
    int someval = 2;
    vector<int> iv = {1,2,3,4,5,6,7,8,9,10};
    vector<int>:: iterator iter = iv.begin();

    int org_size = iv.size(),i = 0;
    //每次循环步都重新计算“mid”，保证正确指向iv原中央元素
    while(i <= org_size / 2)
    {
       if(*iter == someval)
        {
           iter = iv.insert(iter,2*someval);
           iter+=2;
        }
        else
            iter++;
        i++;
    }
    for(auto iter = iv.cbegin();iter != iv.cend();iter++)
        cout << *iter <<endl;

    return 0;
}
