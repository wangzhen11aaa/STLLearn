#include <iostream>
using namespace std;

struct A{
    static void g() {f();}
    inline static void f() { cout << "Hello from f";}
};
int main(){
    A a;
    a.g();
}