#include <iostream>

using namespace std;

auto lambda1 = [](auto &&c)->int {cout << c <<  "in lambda1" << endl; return 1;};
// [](auto &&c){} 是一个匿名对象(编译器生成的)，完成一个functor的工作，如果不被调用，也是不会运行的。
auto lambda2 = [](auto &&t){cout << "hello from lambda2" << endl; [](auto &&c) {cout << c <<  "in lambda2's lambda" << endl;};};

int main(){
    int t = 1;
    int s = 2;
    lambda1(t);
    //lambda2();
    lambda2(1);
}