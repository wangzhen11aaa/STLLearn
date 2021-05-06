#include <iostream>
#include <cstddef>

using namespace std;

class alloc{};

namespace M{
template <class T, class Alloc=alloc, size_t BufSiz=0>
class deque
{
    public:
        deque(){cout << "deque " << endl;}
};

// 得有这些声明
template<class T, class Sequence>
class stack;

using namespace std;
template<class T, class Sequence>
bool operator == (const M::stack<T, Sequence> &x, const M::stack<T, Sequence> &y){
    cout << "operator == " << endl;
    return true;
}

template<class T, class Sequence>
bool operator < (const M::stack<T, Sequence> &x, const M::stack<T, Sequence> &y){
    cout << "operator < " << endl;
    return true;
}
// template<class T, class Sequence>
// bool operator == (const stack<T, Sequence> &x, const stack<T, Sequence> &y);

// template<class T,class Sequence>
// bool operator < (const stack<T, Sequence> &x, const stack<T, Sequence> &y);


// 对于模板的默认参数
template<class T, class Sequence = deque<T> >
class stack{
    // With T
    //friend bool operator == <T> (const stack<T> &, const stack<T> &);
    friend bool operator < <T> (const stack<T> &, const stack<T> &);

    // 没有指定T
    friend bool operator == <> (const stack &, const stack &);
    public:
        stack() {cout << "stack " << endl;}
    private:
        Sequence c;

};
};


int main(){
    const M::stack<int> x;
    const M::stack<int> y;

    cout << ( x == y ) << endl;
    cout << (x < y) << endl;
}