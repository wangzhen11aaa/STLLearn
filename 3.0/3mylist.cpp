#include "3mylist.h"

//namespace M{
template<typename T>
void List<T>::insert_front(T value){
    ListItem<T> *t = (ListItem<T> *) malloc(sizeof(ListItem<T>));
    t->value = value;
    t->_next = _front->next; 
    _front->next = t;
    if(_size == 0){
        _end = t;
    }
    _size++;
}
template<typename T>
void List<T>::insert_end(T value){
    ListItem<T> *t = (ListItem<T> *) malloc(sizeof(ListItem<T>));
    t->value = value;
    _end = t;
    t->_next = nullptr;
    if(_size == 0){
        _front->next = t;
    }
    _size++;
}

template<typename T>
void List<T>::display(std::ostream &os) const{
    if(_size == 0){
    }else{
        List<ListItem<T> > *_i = _front->next;
        while(_i != nullptr){
            os << _i->value << std::endl;
            _i = _i->next;
        }
    }
}
//}
