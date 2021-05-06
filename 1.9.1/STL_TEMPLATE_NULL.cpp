#include <iostream>

using namespace std;

namespace M{
#define __STL_TEMPLATE_NULL template<>/* blank */
template<class Key> struct hash{
    void operator()(){cout << "hash<T> " << endl;}
};

// explicit specialization
__STL_TEMPLATE_NULL struct hash<char>{
    void operator()(){cout << "hash<char>" << endl;}
};

// explicit specialization
__STL_TEMPLATE_NULL struct hash<unsigned char>{
    void operator()(){cout << "hash<unsigned char> " << endl;}
};
};
int main(){
    M::hash<long> t1;
    M::hash<char> t2;
    t1();
    t2();
}