#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::to_string;
using std::string;
using std::vector;
using std::cout;
using std::endl;


class HasPtr
{
    friend void swap(HasPtr&,HasPtr&);
public:
    /*
    ��һ����ֵ�󶨵�һ����const�����ã��ᵼ�´�����Ϊ����Ƿ�const������ζ�ſ���ͨ��s�������ֵ�����޸ģ�
    ����ֵ�����޸ģ���Ȼ�ǲ����߼��ģ���ν��ֵ����ֱ�۵ؾ���⣬����ֻ�ܷ��ڵȺ��ұߣ���Ȼֻ�ܷ��ڵȺ��ұߣ�
    �Ǿ���ֻ�ܶ�ȡ����д�룩�����Դ��ˡ���const string &s = string() ����ֵ�󶨵�һ��const���ã��Ǻ���ģ�
    ֻ�ܶ�ȡ�������޸ġ�
    */
    //HasPtr( string &s = string()): ps(new string(s)),i(0) {} //vs2015 ��Ȼ����ͨ�� gcc���벻ͨ��
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {cout << "���캯��" <<endl; } //���캯��
	//HasPtr( HasPtr &rhs) : ps(new string(*rhs.ps)), i(rhs.i) { cout << "�������캯��" << endl; } //vs2015 ��Ȼ����ͨ�� gcc���벻ͨ��																			  //vs2015 ��Ȼ����ͨ�� gcc���벻ͨ��
    HasPtr(const HasPtr &rhs) : ps(new string(*rhs.ps)),i(rhs.i) {cout << "�������캯��" <<endl;} //�������캯��
    HasPtr &operator= (const HasPtr& rhs) //��ֵ�����
    {
        auto newps = new string(*rhs.ps);
        delete ps;
        ps = newps;
        i = rhs.i;
        return *this;
    }
    HasPtr &operator= (const string &s) //�����µ�string
    {
        *ps = s;
        return *this;
    }
    string &operator*()
    {
        cout << "������" <<endl;
        return *ps;
    }

    bool operator<(const HasPtr &) const;
    ~HasPtr()
    {
        delete ps;
    }

    void show()
    {
        std::cout << *ps << std::endl;
    }

private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs,HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
    std::cout << "call swap(HasPtr &lhs,HasPtr &rhs)" << std::endl;
}


bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps < *rhs.ps;
}



int main(int argc,char *argv[])
{
    vector<HasPtr>vh;

/*
    HasPtr a("yinhao");
    HasPtr b("zheng");

    vh.push_back(a);
    vh.push_back(b);
*/

    int n = atoi(argv[1]);
    int n = 3;
    /*std::cin >> n;*/
    for(int i = 0;i < n; i++)
       vh.push_back(to_string(n - i));
    cout << "--------------------------------------------------" << endl;
    for(auto p : vh)
        cout << *p << " ";
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    sort(vh.begin(),vh.end());
    cout << "--------------------------------------------------" << endl;
    for(auto p : vh)
        cout << *p << " ";
    cout << endl;
    cout << "--------------------------------------------------" << endl;

    return 0;
}
