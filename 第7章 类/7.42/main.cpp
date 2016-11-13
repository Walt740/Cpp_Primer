#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string Name,ISBN,Author,Publisher;
    double Price = 0;
public:
    Book(const string &n,const string &I,double pr,const string &a,const string &p)
        :Name(n),ISBN(I),Price(pr),Author(a),Publisher(){}
    Book():Book("","",0,"",""){}
    Book(std::istream& is):Book()
    {
        is >> *this;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
