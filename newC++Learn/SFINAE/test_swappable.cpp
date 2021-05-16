#include <iostream>
#include <utility>
#include <type_traits>

namespace __swappable_details{
    using std::swap;
    using std::true_type;
    using std::false_type;
    struct __do_is_swappable_iml{
        template <typename _Tp, typename 
            = decltype(swap(std::declval<_Tp&>(), std::declval<_Tp&>()))>
        static true_type __test(int);

        template<typename>
        static false_type __test(...);
    };

    template<typename _Tp>
    struct __is_swappable_impl:public __swappable_details::__do_is_swappable_iml{
        typedef decltype(__test<_Tp>(0)) type;
    };

    template<typename _Tp>
    struct __is_swappable:public __is_swappable_impl<_Tp>::type
    {};
};

class A{

};
int main(){
    __swappable_details::__is_swappable<A> _is_test;
    std::cout << _is_test.value << std::endl;
}