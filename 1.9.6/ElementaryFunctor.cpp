#include<iostream>
using namespace std;

namespace M{
template <class T>
struct plus{
    plus(){cout << "constructor for plus invoked";}
    T operator()(const T& x, const T& y) const{return x + y;}
};

template<class T>
struct minus{
    T operator()(const T& x, const  T& y) const{return x - y;}
};
};
int main(){
    M::plus<int> plusObj;
    cout << plusObj(2,5) << endl;
    
    // 直接产生仿函数的临时对象
    cout << M::plus<int>()(2,5) << endl;
}