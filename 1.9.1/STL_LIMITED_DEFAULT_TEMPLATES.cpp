#include<iostream>
using namespace std;

class alloc{};

namespace M{
template<class T, class Alloc=alloc, size_t BufSiz=0>
class deque{
    public:
        deque(){cout << "deque" << endl;}
};

//根据前一个参数T，设定下一个参数Sequence的默认值deque<T>
template<class T, class Sequence = deque<T> >
class stack{
    public: 
        stack() {
            cout << "stack" << endl;
        }
    private:
        Sequence c;
};
};

int main(){
    M::stack<int> x;
}