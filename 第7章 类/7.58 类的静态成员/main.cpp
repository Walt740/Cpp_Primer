
#include "Example.h"


//class Account
//{
//public:
//    static double rate(){return interestRate;}
//    static void rate(double);
//
//private:
//    string strName;
//    double dAmount = 0.0;
//    static double dRate;   //利率是相对稳定和统一的，应该是静态成员
//};

//double Example::rate;
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
 int main(){

     Example::vec.push_back(10.5);
     cout << Example::vec.back() << endl;
     cout << Example::rate << endl;
     cout << Example::vecSize << endl;
     return 0;
 }


 
 /*
 一般来说，关于C++类静态成员的初始化，并不会让人感到难以理解，但是提到C++ 静态成员的"类内初始化"那就容易迷糊了。

我们来看如下代码：

复制代码
 1 //example.h
 2 #include<iostream>
 3 #include<vector>
 4 using namespace std;
 5 
 6 class Example{
 7 public:
 8     static double rate = 6.5;
 9     static const int vecSize = 20;
10     static vector<double> vec(vecSize);
11 };
12 
13 //example.cpp
14 #include "example.h"
1516 double Example::rate;
17 vector<double> Example::vec;
18
复制代码
我们需要判断上面的静态数据成员的声明和定义有没有错误，并解释原因。

首先，要谨记：通常情况下，不应该在类内部初始化成员，无论是否为静态成员。

其次，若一定要在类内初始化静态成员，那么就必须满足如下条件才行：

1） 静态成员必须为字面值常量类型的constexpr。

      所谓的字面值类型就是通常遇到的：算术类型，引用，指针等。字面值常量类型就是const型的算术类型，引用，指针等。

      所谓的constexpr，就是常量表达式，指值不会改变且在编译过程中就能得到计算结果的表达式。比如字面值，或者用常量表达式初始化的const对象也是常量表达式。为了帮助用户检查自己声明/定义的变量的值是否为一个常量表达式，C++11新规定，允许将变量声明为constexpr类型，以便由编译器来进行验证变量是否为常量表达式。

2）给静态成员提供的初始值，必须为常量表达式

注意：在C++ primer 第五版中说：只能给静态成员提供const 整数类型的类内初始值，且该const整数类型的初始值必须是常量表达式。我觉得是有误的！详情见后面分析。

 

有了这两条原则，我们就可以对上面的代码进行验证了。

1）static double rate = 6.5; 

显然不满足第一条：因为rate不是常量类型。改成constexprt static const double rate = 6.5即可

从这里也可以看出初始值不一定必须为const 整数类型。

ps: 如果我们不再这里加入constexprt修饰符的话，编译器会提示错误：error: ‘constexpr’ needed for in-class initialization of static data member ‘const double Example::rate’ of non-integral type [-fpermissive] 
大体意思就是，对于非const整数类型的初始值，如果它是常量表达式的话，我们需要手工在前面添加修饰符constexprt。

至于Example.cpp文件中的定义部分，由于我们已经在类内部进行了初始化，就不需要再在类外部进行定义了。如果非要定义的话，必须采用如下格式：

//example.cpp
constexpr const double Example::rate;  //其中的const是可以删除的，因为constexprt本身就包含了const

2）static const int vecSize = 20;

vecSize是const int类型的，且为常量表达式——满足第一条；提供的初始值为20，是一个常量表达式——满足第二条！且由于是const int型的，前面可以不用修饰符constexpr。

3）static vector<double> vec(vecSize);

错误！vector是模板不是字面值常量类型，所以不满足第一条。应该改为 static vector<double> vec; //仅仅且只能进行声明，不能定义

然后在Example.cpp中进行定义：

static vector<double> vec(Example::vecSize);

现在我们可以在Example.cpp中添加测试代码进行测试了：

 

复制代码
 1 #include "example.h"
 2 vector<double> Example::vec(Example::vecSize);
 3 constexpr const double Example::rate;
 4 
 5 int main(){
 6 
 7     Example::vec.push_back(10.5);
 8     cout << Example::vec.back() << endl;
 9     cout << Example::rate << endl;
10     cout << Example::vecSize << endl;
11 }
复制代码
 

 

执行结果：

 

wanchouchou@wanchouchou-virtual-machine:~/c++/7.5$ ./Example 
10.5
6.5
20
 */