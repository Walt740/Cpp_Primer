#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <iostream>
#include <vector>
using namespace std;
class Example
{
    public:
        Example();
        virtual ~Example();
        constexpr static double rate = 6.5;
        static const int vecSize = 20;
        static std::vector<double> vec;
    protected:

    private:

};

#endif // EXAMPLE_H
