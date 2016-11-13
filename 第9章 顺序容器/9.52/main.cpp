#include <iostream>
#include <stack>

using namespace std;


int main()
{
    stack<int> intstack; //ø’’ª
    for(size_t ix = 0;ix != 10;++ix)
        intstack.push(ix);

    while(!intstack.empty())
    {
        int value = intstack.top();
        intstack.pop();
    }
    return 0;
}
