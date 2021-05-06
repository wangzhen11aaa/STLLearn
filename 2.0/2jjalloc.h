#ifndef __JJALLOC__
#define __JJALLOC__

#include <new> // for placeholder new
#include <cstddef> // for ptrdiff_t, size_t
#include <cstdlib> // for exit()
#include <climits> // for UNIX_MAX
#include <iostream> // for cerr

namespace JJ{

void no_memory(){
    std::cout << "Failed to allcoate Memory" << std::endl;
    std::exit(1);
}

template<class T>
inline T* _allocate(ptrdiff_t size, T*){
    // set_new_handler函数的作用就是设置new_p指向的函数为new操作或者new[]操作失败时调用的处理函数。
    // 0 means null
    //std::set_new_handler(0);
    std::set_new_handler(no_memory);
    T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));

    if (tmp == 0){
        std::cerr << "Out of Memory" << std::endl;
        exit(1);
    }
    return tmp;
}

template<class T>
inline void _deallocate(T* buffer){
    ::operator delete(buffer);
}

// Use placement new.
template<class T1, class T2>
inline void _construct(T1* p, const T2& value){
    std::cout << "_construct is invoked" << std::endl;
    new(p) T1(value); // placement new. invoke ctor of T1
}

template<class T>
inline void _destory(T* ptr){
    ptr->~T();
}

template <class T>
class allocator{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    // 目前这个不知道什么意思
    typedef ptrdiff_t difference_type;

    // rebind allocator of type U
    // 暂时不清楚为什么会出现这个.
    template <class U>
    struct bind{
        typedef allocator<U> other;
    };
    // hint used for locality ref. 
    // const void* means 万能类型
    pointer allocate(size_type n, const void* hint = 0){
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n){_deallocate(p);}
    
    // 目前没有弄懂在vector模板中哪里调用的construct方法。
    void construct(pointer p, const T& value){
        std::cout << "construct is invoked" << std::endl;
        printf("address %p \n", p);
        printf("value %d \n", value);
        _construct(p, value);
    }

    void destory(pointer p){_destroy(p);}
    pointer address(reference x) {return (pointer) &x;}
    const_pointer const_address(const_reference x){return (const_pointer) &x;}

    size_type max_size() const{
        return size_type(UID_MAX/sizeof(T));
    }
};
};
#endif