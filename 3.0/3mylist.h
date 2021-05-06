// file 3mylist.h
#pragma once

#include <iostream>

namespace M {
template<typename T>
class ListItem{
public:
ListItem(){_next = nullptr;}
T value() const {return _value;}
ListItem* next() const {return _next;}

//private:
T _value;
ListItem* _next;
};

template<typename T>
class List{
public:
    List(){_front = (ListItem<T> *) malloc(sizeof(ListItem<T>)); _end = nullptr; _size=0;}
    void insert_front(T value);
    void insert_end(T value);
    void display(std::ostream &os = std::cout) const;
    ListItem<T>* front(){return _front->_next;}
    ListItem<T>* end() {return _end->_next;}
private:
    // _front 仅仅只是标识.
    ListItem<T>* _end;
    ListItem<T>* _front;
    long _size;
};
template<typename T>
void List<T>::insert_front(T value){
    ListItem<T> *t = (ListItem<T> *) malloc(sizeof(ListItem<T>));
    t->_value = value;
    t->_next = _front->_next; 
    _front->_next = t;
    if(_size == 0){
        _end = t;
    }
    _size++;
}
template<typename T>
void List<T>::insert_end(T value){
    ListItem<T> *t = (ListItem<T> *) malloc(sizeof(ListItem<T>));
    t->_value = value;
    t->_next = nullptr;
    if(_size == 0){
        _front->_next = t;
    }else{
        _end->_next = t;
    }
    _end = t;
    _size++;
}

template<typename T>
void List<T>::display(std::ostream &os) const{
    if(_size == 0){
    }else{
        ListItem<T>  *_i = _front->_next;
        while(_i != nullptr){
            os << _i->_value << std::endl;
            _i = _i->_next;
        }
    }
}
}