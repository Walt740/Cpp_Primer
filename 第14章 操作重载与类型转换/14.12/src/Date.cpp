#include "Date.h"

Date::Date(int y,int m,int d)
{
     year = y;
     month = m;
     day = d;
}



std::istream & operator>>(std::istream &is,Date &dt)
{
    is >> dt.year >> dt.month >> dt.day;
    if(!is) //�����������������ȷ��
    {
        Date(0,0,0);
    }
    return is;

}


std::ostream& operator<<(std::ostream &os,const Date &dt)
{
    os << dt.year <<" " << dt.month << " "<< dt.day << std::endl;
    return os;
}
