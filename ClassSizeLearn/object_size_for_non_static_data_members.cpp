#include <iostream>
class A { 
private: 
        float iMem1; 
        //const int iMem2 = 1; 
        static int iMem3; 
        char iMem4; 
}; 
class B { 
        char c; 
        int int1; 
        int int2; 
        int i; 
        long l; 
        short s; 
}; 

class C { 
        int int1; 
        int int2; 
        int i; 
        long l; 
        short s; 
        char c;
        char d;
}; 
class BaseClass { 
        char a; 
        char c;
}; 
 
class DerivedClass : public BaseClass { 
        // result 8
        int i; 
        char d;
}; 

int main(){
    A a;
    std::cout << "Size of a : " << sizeof(a) << std::endl;
    B b;
    std::cout << "Size of b: " << sizeof(b) << std::endl;
    C c;
    std::cout << "Size of c: " << sizeof(c) << std::endl;
    DerivedClass d;
    std::cout << "Size of d: " << sizeof(d) << std::endl;
}