#include <iostream>
#include <memory>
// 实现List及 List Iterator
// 定义节点
template<typename T>
struct __list_node{
    typedef __list_node* list_node_pointer;

    list_node_pointer next;
    list_node_pointer prev;
    T data;
};

//定义迭代器__list_iterator
template<typename T>
struct __list_iterator{
    typedef __list_iterator<T> self;
    typedef __list_node<T>* link_type;

    link_type ptr; // 成员

    __list_iterator(link_type p = nullptr):ptr(p){}

    // Dereference to pointer
    T& operator* (){return ptr->data;}

    // Get the address of data 
    T* operator ->(){return &(operator*());}

    self& operator++(){
        ptr = ptr->next;
        return *this;
    }
    self operator++(int){
        self tmp = *this;
    // 尽量复用已有代码
        ++*this;
        return tmp;
    }
    self& operator--(){
        ptr = ptr->prev;
        return *this;
    }
    self operator--(int){
        self tmp = *this;
    // 尽量复用已有代码
        --*this;
        return tmp;
    }

    bool operator==(const __list_iterator& rhs){
        return ptr == rhs.ptr;
    }
    // 尽量复用已有代码
    bool operator!=(const __list_iterator& rhs){
        return !(*this == rhs);
    }

};

template<typename T> class SimpleList;
template<typename T>        
std::ostream& operator<<(std::ostream& os, const SimpleList<T>& s);

template<typename T>
class SimpleList{
    protected:
        typedef __list_node<T> list_node;
        // nodeAllocator 按照list_node为单位分配内存
        typedef std::allocator<list_node> nodeAllocator;
    public:
        typedef list_node*   link_type;
        typedef T       value_type;
        typedef __list_iterator<value_type> iterator;

        // typedef T&      reference;
        // typedef value_type*     pointer;
        // typedef list_node*  link_type;
        // typedef const value_type*   const_pointer;

        typedef size_t  size_type;
    
    // iterator的相关操作
        iterator begin(){
        // 使用implicit conversion
            return node->next;
        }

        iterator begin() const{
            return node->next;
        }

        iterator end(){
            return node;
        }
        iterator end() const{
            return node;
        }
        bool empty()const{return node == node->next;}

    // public:
    //     typedef __list_
        // 分配内存空间
        link_type alloc_node(){
            return allocator.allocate(1);
        }

        // 回收内存空间
        void dealloc_node(link_type p){
            allocator.deallocate(p, 1);
        }
        // 产生一个节点，首先构造内存，然后进行构造
        link_type alloc_ctor_node(const T& val){
            link_type p = alloc_node();
            p->data = val;
            return p;
        }
        void destroy(T* pointer);
        void dealloc_dtor_node(link_type p);
        // 析构节点元素，并释放内存

        void empty_initialize(){
            node = alloc_node();
            node->prev = node;
            node->next = node;
            allocator = nodeAllocator();
        }
        SimpleList(){
            empty_initialize();
        }
            
        iterator insert(iterator position, const T& value);
        void push_back(const value_type& value);
        iterator insert(iterator position, size_t n, const T& value);
        void fill_initialize(size_t n, const T& value);
        SimpleList(size_type n, const T& value);
        size_t size();
        void reverse();

        friend std::ostream& operator<< <> (std::ostream &os, const SimpleList<T>& s);//{
        //     iterator begin = s.begin();
        //     while (begin != s.end()){
        //     os << *begin << std::endl;
        //     begin++;
        // }
        // return os;
       //}
    // Put the [first, last) part before position.
        void transfer(iterator position, iterator first, iterator last){
            if(position != last){
                std::cout << "position's val : " << position.ptr->data << std::endl;
                std::cout << "first's val : " << first.ptr->data<< std::endl;
                std::cout << "last's val : " << last.ptr->data<< std::endl;
                position.ptr->prev->next = first.ptr;
                first.ptr->prev->next = last.ptr;
                last.ptr->prev->next = position.ptr;
                link_type tmp = position.ptr->prev;
                position.ptr->prev = last.ptr->prev;
                last.ptr->prev = first.ptr->prev;
                first.ptr->prev = tmp;
            }
        }

    // erase    
        void erase(T v){
            iterator _begin = begin();
            iterator _end = end();
            if (_begin == _end){
                std::cout << "Empty List" << std::endl;
            }
            while(_begin != _end){
                if(*_begin == v){
                    iterator tmp = _begin++;
                    tmp.ptr->prev->next = _begin.ptr;
                    _begin.ptr->prev = tmp.ptr->prev;
                    dealloc_dtor_node(tmp.ptr);
                    std::cout << "in While" << std::endl;
                }
                else
                    _begin++;
            }
        }
        void merge(SimpleList<T> x){
            iterator first1 = begin();
            iterator last1 = end();
            iterator first2 = x.begin();
            iterator last2 = x.end();
            while (first1 != last1 && first2 != last2){
                if(*first2 < *first1){
                    iterator next = first2;
                    transfer(first1, first2, ++next);
                    first2 = next;
                    std::cout << "*first2 < *first1" << *this << std::endl;
                }
                else{
                    std::cout <<"*first2 >= *first1 start" << std::endl;
                    iterator b = begin();
                    iterator e = end();
                    while(b != e){
                        std::cout << *b << std::endl;
                        b++;
                    }
                    std::cout << "Out by ostream " << std::endl;
                    std::cout << *this << std::endl;
                    std::cout <<"*first2 >= *first1 end" << std::endl;
                    first1++;
                }
            }
            if(first2 != last2){
                std::cout << *this;
                transfer(last1, first2, last2);
                std::cout <<"last transfer" << *this << std::endl;
            }
        }
        private:
            link_type node;
            nodeAllocator allocator;
    
};



template<typename T>
size_t SimpleList<T>::size(){
    std::cout << "size() method  not initialized, will return -1 " << std::endl;
    return 0;
}
template<typename T>
void SimpleList<T>::fill_initialize(size_t n, const T& value){
    // 先初始化起始点
    empty_initialize();
    insert(begin(), n, value);
}

template<typename T>
SimpleList<T>::SimpleList(size_type n, const T& value){
    fill_initialize(n, value);
}

template<typename T>
typename SimpleList<T>::iterator SimpleList<T>::insert(
        iterator position, const T& value){

    link_type tmp = alloc_ctor_node(value);
    // 调整双向指针，使tmp插入进去
    tmp->next = position.ptr;
    tmp->prev = position.ptr->prev;

    position.ptr->prev->next = tmp;
    position.ptr->prev = tmp;

    return tmp;
}

template<typename T>
void SimpleList<T>::push_back(const T& value){
    insert(end(), value);
}

template<typename T>
typename SimpleList<T>::iterator SimpleList<T>::insert(
        iterator position, size_t n, const T& value){
    while(n--){
        // 由于是相同的值，所以顺序无关
        insert(position, value);
    }
    return position;
}



template <typename T>
void SimpleList<T>::destroy(T* pointer){
    pointer->~T();
}

// 倒转就是将之前的数据从end()端按照正常顺序重新插入一遍
template<typename T>
void SimpleList<T>::reverse(){
    if (node->next == node || node->next->next == node){
    }
    else
    {
        iterator _first = begin();
        ++_first;
        while(_first != end()){
            iterator old = _first;
            ++_first;
            transfer(begin(), old, _first);
        }
    }
}

template<typename T>
void SimpleList<T>::dealloc_dtor_node(typename SimpleList<T>::link_type  p){
    destroy(&p->data);
    dealloc_node(p);
}

template<typename T>        
std::ostream& operator<< (std::ostream& os, const SimpleList<T>& s){
            __list_iterator<T> _begin = s.begin();
            __list_iterator<T> _end = s.end();
            while (_begin != _end){
                os << *_begin << std::endl;
                _begin++;
            }
        return os;

}