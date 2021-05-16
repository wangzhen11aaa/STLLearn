#include <boost/hana.hpp>
#include <iostream>
#include <string>

using namespace std;

namespace hana = boost::hana;
// 检查类型是否有一个serialize方法
auto hasSerialize = hana::is_valid([](auto &&x) -> decltype(x.serialize()) {x.sayHello(); return string("abc");});
//auto hasSerialize = hana::is_valid([](auto &&x) {x.sayHello(); return string("abc");});

auto testLambda = ([](auto &&x){x.sayHello(); return string("abc");});
// 序列化任意对象
template<typename T>
std::string serialize(T const &obj) {
    cout << "testLambda " <<  testLambda(obj) << endl;
    //cout << "hasSerialize(obj)'s result : " <<  hasSerialize(obj) << endl;
    return hana::if_(hasSerialize(obj),
                     //"true", "false");
                     [](auto &obj) { return obj.serialize(); },
                     [](auto &x) { return to_string(x); }
    )(obj);
    //);
}

// 类型A只有to_string 方法
struct A {
    void sayHello() const{
        cout << "Hello from A " << endl;
    }
};

std::string to_string(const A &) {
    return "I am A";
}

// 类型B有serialize方法
struct B {
    std::string serialize() const {
        return "I am B";
    }

    void sayHello() const {
        cout << "Hello from B " << endl;
    }
};

// 类型C有个serialize数据成员与to_string方法
struct C {
    void sayHello() const {
        cout << "Hello from C " << endl;
    }
    std::string serialize;
};

std::string to_string(const C &) {
    return "I am C";
}

int main() {
    A a;
    B b;
    C c;
    std::cout << serialize(a) << endl;
    std::cout << serialize(b) << endl;
    std::cout << serialize(c) << endl;
}