#include <iostream>
#include <cstdio>


using namespace std;

namespace myMM{
// global function
template<class ForwardIterator, class T>
void uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& value)
{
    while(first != last){
        *(first++) = value;
    }
}
}