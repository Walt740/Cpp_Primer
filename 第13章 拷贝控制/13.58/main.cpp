#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    vector<int> data;

};

Foo Foo::sorted() &&
{
    cout << "��ֵ���ð汾" << endl;
    sort(data.begin(),data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "��ֵ���ð汾" << endl;
    //Foo ret(*this);
    //sort(ret.data.begin(),ret.data.end());
    //return ret.sorted();
    return Foo(*this).sorted();
}


int main()
{
    Foo f;
    f.sorted();
    return 0;
}
