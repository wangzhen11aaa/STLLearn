#include <iostream>

using namespace std;
// 迭代器中特意声明内嵌型别名称
template<class T>
struct MyIter{
    typedef T value_type; // 内嵌型别名称
    T* _ptr;
public:
    MyIter(T* ptr=0):_ptr(ptr){}
    T& operator*() const {return *_ptr;}
};

template<class I>
typename I::value_type
func (I ite){
    return *ite;
}

int main(){
    MyIter<int> ite(new int(8));
    cout << func(ite);
}
