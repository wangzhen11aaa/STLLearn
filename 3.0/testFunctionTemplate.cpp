#include <iostream>

using namespace std;
template<class I, class T>
void func_impl(I iter, T t){
    cout << "t : " << t << endl;
    cout << "iter : " << *iter << endl;
};

template<class I>
inline
void func(I iter){
    func_impl(iter, *iter); //func的工作全部转移func_impl
};
int main(){
    int i;
    func(&i);
}