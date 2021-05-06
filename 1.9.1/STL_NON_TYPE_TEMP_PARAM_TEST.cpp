#include <iostream>
#include <cstddef>

using namespace std;

class alloc{};
namespace M{
inline size_t __deque_buf_size(size_t n, size_t sz){
    return n!=0 ? n : (sz < 512?size_t(512/sz): size_t(1));
}

template<class T, class Ref, class Ptr, size_t BufSiz>
struct __deque_iterator{
    // typedef __deque_iterator<T, T&, T*, BufSiz> itertor;
    // typedef __deque_iterator<T, const T&, const T*, BufSiz> const_itertor;

    static size_t buffer_size() {return __deque_buf_size(BufSiz, sizeof(T));}
};

template <class T, class Alloc=alloc, size_t BufSiz=0>
class deque{
    public:
        typedef __deque_iterator<T, T&, T*, BufSiz> iterator;
        // Add const_iterator
        typedef __deque_iterator<T, const T&, const T*, BufSiz> const_iterator;
};
};

int main(){
    cout << M::deque<int>::iterator::buffer_size() << endl;
    cout << M::deque<int, alloc, 64>::iterator::buffer_size() << endl;
    cout << "---------" << endl; 
    cout << M::deque<int>::const_iterator::buffer_size() << endl;
}