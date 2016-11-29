#include "Date.h"

Date::Date(int y,int m,int d)
{
     year = y;
     month = m;
     day = d;
}

bool operator==(const Date &lhs,const Date &rhs)
{
    return lhs.year== rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}
bool operator!=(const Date &lhs,const Date &rhs)
{
    return !(lhs == rhs);
}

bool operator< (const Date &lhs,const Date &rhs)
{
     return (lhs.year < rhs.year) ||(lhs.year <rhs.year && lhs.month < rhs.month ||
                lhs.year <rhs.year && lhs.month < rhs.month && lhs.day < rhs.day)   ;
}
bool operator> (const Date &lhs,const Date &rhs)
{
    return !(lhs < rhs);
}
bool operator>=(const Date &lhs,const Date &rhs)
{
    return !(lhs <= rhs);
}
bool operator<=(const Date &lhs,const Date &rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}





std::istream & operator>>(std::istream &is,Date &dt)
{
    is >> dt.year >> dt.month >> dt.day;
    if(!is) //检查输入流的数据正确性
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
