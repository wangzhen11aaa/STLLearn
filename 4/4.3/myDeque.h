#include <cstddef>
#include "../../2.0/2jjalloc.h"


namespace MySpace{
template<typename T, class Alloc=JJ::allocator<T>, size_t BufSiz = 0>
class deque{
    public:
        typedef T value_type;
        typedef value_type* pointer;

    protected:
        typedef pointer* map_pointer;

    protected:
        map_pointer map;
        size_t size_map; // map
    
    private:
        Alloc alloc;

    // Public method
    public:
    //构造函数
        deque();
};

// Iterator 
// ? Why use BufSiz
template<class T, class Ref, class Ptr, size_t BufSiz>
struct __deque_iterator{
    typedef __deque_iterator<T, T&, T*, BufSiz> iteraotr;
    typedef __deque_iterator<T, const T&, const T*, BufSiz> const_iterator;
    static size_t buffer_size(){return __deque_buf_size(BufSiz, sizeof(T));}


    // inline __deque_buf_size
    inline static size_t __deque_buf_size(size_t n, size_t sz){
        return (n != 0: n :(sz < 512? size_t(512/sz):size_t(1)));
    }


};

}
