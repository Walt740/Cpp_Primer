/*

explicit 用于抑制类类型的隐式转换

接受一个string参数的Sales_data构造函数应该是explicit的，
否则编译器就有可能自动把一个string对象转换成Sales_data对象，
这种做法显得有些随意，某些时候与程序员的初衷相违背。


使用explicit的优点是避免因隐式类类型转换而带来意想不到的错误，
缺点是当用户的确需要这样的类类型转换时，不得不使用略显繁琐的
方式来实现


item.combine(static_cast<Sale_data>(cin));





*/


