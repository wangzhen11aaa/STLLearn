#include <iostream>
#include "myhead.h"
using namespace std;

void print(){
    std::cout<<" print "<<std::endl;
}

class A{
    void say(){
        print ();
    }
};