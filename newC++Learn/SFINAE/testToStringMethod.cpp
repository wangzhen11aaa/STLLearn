#include <iostream>
#include <type_traits>
#include <string>

using namespace std;

namespace myTest{
struct HasMemberToStringValidator{
    template<typename T, 
    typename U = typename std::decay<decltype(std::declval<T>().ToString())>::type,
    typename = typename std::enable_if<std::is_same<std::string, U>::value>::type
    >
    static std::true_type test(int){return std::true_type{};};

    template <typename>
    static std::false_type test(...){return std::false_type{};};

};
};
class A{
    public:
        std::string ToString(){
            return string("a");
        };
};
int main(){
    auto t = myTest::HasMemberToStringValidator::test<A>(0);
    cout << t.value << endl;
} 