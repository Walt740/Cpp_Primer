### 15.8： 给出静态类型和动态类型的定义。
静态类型在编译时就已经确定了，它是变量声明时的类型或表达式生成的类型；而动态类型则是变量或表达式表示的内存中的对象的类型，动态类型直到运行时才能知道。如：Quote *pQuote  = new Bulk_quote; ，指针pQuote的静态类型是Quote，在编译时就已经确定了。但是它的动态类型是Bulk_quote,直到运行时才能知道它指向的是基类还是派生类。如果一个变量是非指针也非引用，则它的静态类型和动态类型永远一致。但基类的指针或引用的动态类型可能与其动态类型不一致。
### 15.9： 在什么情况下表达式的静态类型可能与动态类型不同？请给出三个静态类型与动态类型不同的例子。

* 类的指针或引用的静态类型可能与其动态类型不一致

Bulk_quote bulk; 
Quote *pQuote = &bulk;
Quote &rQuote =bulk;
//传递给item的如果是派生类对象，即是静态类型和动态类型不同的情况
double print_total(ostream &os,const Quote &item,size_t n);
