#include <iostream>
#include <algorithm>

using namespace std;

class IntCompare
{
public:
    IntCompare(int v) : val(v) {}  //构造函数
    bool operator() (int v) { return  val == v ;  }
private:
    int val;
};


int main()
{
    vector<int> vec = {1,2,3,4,5};
    const int oldValue = 2;
    const int newValue = 200;
    IntCompare icmp(oldValue);
    //当谓词为1时，执行可调用对象
    replace_if(vec.begin(),vec.end(),icmp,newValue);
    for(auto &c : vec )
        cout << c << endl;
    return 0;
}
