#include "3mylist.h"
#pragma once

namespace M{
// template<class Item>
// struct ListIter
// {
//     public:
//     Item* ptr;
//     ListIter(Item* p = 0):ptr(p) {}

//     // 不用实现copy ctor,因为编译器提供的就够了
//     Item& operator*() const {return *ptr;}
//     Item* operator->() const {return ptr;}

//     // 以下两个operator++ 遵循标准做法
//     // pre-increment operator
//     ListIter& operator++(){
//         ptr = ptr->next(); return *this;
//     }

//     // post-increment operator
//     ListIter operator++(int){
//         ListIter tmp = *this;
//         ++*this;
//         return tmp;
//     }

//     bool operator == (const ListIter &i) const{
//         return ptr == i.ptr;
//     }
//     bool operator != (const ListIter &i) const{
//         return ptr != i.ptr;
//     }

// };
// 
template <class Iterator>
struct iterator_traits{
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
};

template <typename Item>
class ListIter:public std::iterator<std::forward_iterator_tag, Item>
{
    public:
        Item * _ptr;
        ListIter(Item* ptr = 0):_ptr(ptr){}
        bool operator == (const ListIter &i) const{
            return _ptr  == i._ptr;
        }
        bool operator != (const ListIter &i) const{
            return _ptr != i._ptr;
        }
        Item& operator*() const {return *_ptr;}
        Item* operator->() const {return _ptr;}

         ListIter& operator++(){
         _ptr = _ptr->next(); 
         return *this;
     }
    // post-increment operator
     ListIter operator++(int){
         ListIter tmp = *this;
         ++*this;
         return tmp;
     }

    // void do_print_iterator_category(std::forward_iterator_tag){
    //     std::cout << "forward_iterator_tag invoked";
    // } 
     // Return category
    //void print_iterator_category(std::forward_iterator_tag fit){
    // void print_iterator_category(){
    //     typename std::iterator<std::forward_iterator_tag, Item>::iterator_category ic;
    //     do_print_iterator_category(ic);
    //  //std::cout << "std::forward_iterator_tag used" <td::endl;
    //  }

};

void do_print_iterator_category(std::forward_iterator_tag v){
    std::cout << "forward_iterator_tag invoke" << std::endl;
}

template<typename ListIter>
void print_iterator_category(){
    typedef typename iterator_traits<ListIter>::iterator_category ic;
    do_print_iterator_category(ic());
}


template <typename T>
bool operator != (const ListItem<T> & item, T n){
    std::cout << item.value() << " vs " << n << std::endl;
    return item.value() != n;
}
template <typename T>
bool operator == (const ListItem<T> & item, T n){
    std::cout << item.value() << " vs " << n << std::endl;
    return item.value() == n;
}



};
