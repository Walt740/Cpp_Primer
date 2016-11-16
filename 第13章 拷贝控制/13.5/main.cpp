#include <iostream>

using namespace std;

class HasPtr
{
public:
    /*
    ��һ����ֵ�󶨵�һ����const�����ã��ᵼ�´�����Ϊ����Ƿ�const������ζ�ſ���ͨ��s�������ֵ�����޸ģ�
    ����ֵ�����޸ģ���Ȼ�ǲ����߼��ģ���ν��ֵ����ֱ�۵ؾ���⣬����ֻ�ܷ��ڵȺ��ұߣ���Ȼֻ�ܷ��ڵȺ��ұߣ�
    �Ǿ���ֻ�ܶ�ȡ����д�룩�����Դ��ˡ���const string &s = string() ����ֵ�󶨵�һ��const���ã��Ǻ���ģ�
    ֻ�ܶ�ȡ�������޸ġ�
    */
    HasPtr(const string &s = string() ) //һ����ֵ��Ҫ�󶨵�һ��const ���͵ı�����
                :ps(new string(s)),i(0){}
    HasPtr(const HasPtr &ex):
        ps(new string(*ex.ps)),i(ex.i)
    {

    }
//    HasPtr(const HasPtr &ex)
//    {
//        ps = new string(*ex.ps); //����psָ��Ķ��󣬶����ǿ���ָ�뱾��
//        i = ex.i;
//    }
private:
    string *ps;
    int i;
};


int main()
{

    return 0;
}
