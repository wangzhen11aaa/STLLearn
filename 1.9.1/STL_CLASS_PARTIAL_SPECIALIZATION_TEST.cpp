#include<iostream>
using namespace std;

template<class I, class O>
struct testClass{
    testClass(){cout << "I , O" << endl;}
};

// Special Design
template<class T>
struct testClass<T*, T*>
{
    testClass(){cout << "T*, T*" << endl;}
};

// Special Design

template<class T>
struct testClass<const T*, T*>{
    testClass(){
        cout << "const T*, T*" << endl;
    }
};

int main(){
    testClass<int, char> t;
    testClass<char* ,char *> t1;
    testClass<const char*, char*> t2;
}