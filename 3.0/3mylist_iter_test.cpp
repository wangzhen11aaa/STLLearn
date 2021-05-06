#include "3mylist-iter.h"
#include "3mylist.h"
#include <iostream>
#include <algorithm>


using namespace std;
using namespace M;


int main(){
    M::List<int> mylist;
    for(int i = 0; i < 5; i++){
        mylist.insert_front(i);
        mylist.insert_end(i+2);
    }

    mylist.display();
    //mylist.display ();
    M::ListIter<M::ListItem<int> > begin(mylist.front());
    M::ListIter<M::ListItem<int> > end(mylist.end());

    M::ListIter<M::ListItem<int> > iter;

    //typedef M::iterator_traits<M::ListIter<M::ListItem<int> > >::iterator_category ic;
    //ic c;
    //cout << typeid(c).name() << endl;
    // invoke traits
    std::cout << "invoke global print_iterator_category" << std::endl;
    M::print_iterator_category<M::ListIter<M::ListItem<int> > >();
    std::cout << "invoke global print_iterator_category" << std::endl;
    iter = find(begin, end, 3);
    //iter.print_iterator_category();
    //std::cout << "begin->value : " << begin->_value << std::endl;
    if (iter == end){
        cout << "iter is empty" << endl;
    }
    if (iter == end){
         cout << "not found" << endl;
     }else{
         cout << iter->_value << endl;
         cout << "found " << endl;
     }

}