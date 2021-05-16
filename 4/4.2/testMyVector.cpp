#include <iostream>
#include "myVector.h"
#include "stdVector.h"

using namespace std;
using namespace MySpace;
using namespace _STD;
int main(){
    MySpace::Vector<int> v(0);
    cout << "v's size: " << v.size << endl;
    MySpace::Vector<int>::iterator end = v.end();
    v.push_back(end, 1);
    cout << "v's current size: " << v.size << endl;
    v.push_back(end, 2);

    MySpace::Vector<int>::iterator begin = v.begin();
    end = v.end();
    while(begin != end){
        cout << *begin << endl;
        begin++;
    }
    _STD::Vector<int> v1(2, 4);
    v1.printVector();
}