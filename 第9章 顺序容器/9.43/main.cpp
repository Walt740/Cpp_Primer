#include <iostream>
#include <string>


using namespace std;

//int main()
//{
///*
//    string s = "some string",s2 = "some other string";
//    //s.insert(0,s2);
//    cout << s << endl;
//
//    s.insert(0,s2,0,s2.size());
//
//    cout << s <<endl;
//*/
///*
//    string s("C++ Primer"),s2 = s;
//    s.insert(s.size()," 4th Ed");
//    s2.append(" 4th Ed");
//    cout << s << endl;
//    cout << s2 << endl;
//
//    s.erase(11,3);
//    s.insert(11,"5th");
//    cout << s << endl;
//
//    s2.replace(11,3,"5th");
//    cout << s2 <<endl ;
//
//    s2.replace(11,3,"Fifth");
//    cout << s2 <<endl;
//*/
//    string s = {"0123456789"};
//    string str{"hello"};
//    auto iter = s.begin();
//    //s.insert(0,str,0,s.size());
//    s.insert(iter,10,'c');
//    cout << s << endl;
//
//    s.replace(s.begin(),s.end(),str.begin(),str.end());
//    cout<< s <<endl;
//    return 0;
//}

/*
C:\Users\Walt740\Documents\C++ Primer\µÚ9ÕÂ Ë³ÐòÈÝÆ÷\9.43\main.cpp|38|
  error: no matching function for call to
  'std::__cxx11::basic_string<char>:zx:
  insert(__gnu_cxx::__normal_iterator<char*,
         std::__cxx11::basic_string<char> >&, std::__cxx11::string&)'|
*/


void func(string& s,const string& oldVal,const string& newVal)
{
    if(!oldVal.size()) return ; //oldvalÎª¿Õ´®£¬Ö±½Ó·µ»Ø
    auto iter = s.begin();
    while(iter <= s.end()-1)
    {
        auto iter1 = iter;
        auto iter2 = oldVal.begin();
        while(iter2 != oldVal.end()&& *iter1 == *iter2)
        {
            iter1++;
            iter2++;
        }
        if(iter2 == oldVal.end())
        {
            iter = s.erase(iter,iter1);
            if(newVal.size())
            {
                iter2 = newVal.end();
                do
                {
                    iter2--;
                    iter = s.insert(iter,*iter2);
                }while(iter2 > newVal.begin());
            }
            iter += newVal.size();
        }
        else
            iter++;
    }
}


int main()
{
    string s = "tho thru tho!";
    func(s,"thru","through");
    cout << s <<endl;

    func(s,"tho","though");
    cout << s <<endl;

    func(s,"through","");
    cout << s <<endl;
    return 0;
}
