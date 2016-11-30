#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
    friend std::istream& operator>>(std::istream &is,Date &dt);
    friend std::ostream& operator<<(std::ostream &os,const Date &dt);
    friend bool operator==(const Date &lhs,const Date &rhs);
    friend bool operator!=(const Date &lhs,const Date &rhs);

    friend bool operator< (const Date &lhs,const Date &rhs);
    friend bool operator<=(const Date &lhs,const Date &rhs);
    friend bool operator> (const Date &lhs,const Date &rhs);
    friend bool operator>=(const Date &lhs,const Date &rhs);


    public:
        Date()=default;
        Date(int y,int m,int d); //{year = y;month = m; day = d;}
        Date& operator=(const std::string &date);
    private:
        int year,month,day;
};



#endif // DATE_H
