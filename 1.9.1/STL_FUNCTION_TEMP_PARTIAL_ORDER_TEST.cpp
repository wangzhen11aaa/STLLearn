#include <iostream>
using namespace std;

namespace M{
template<class T>
class alloc{

};
template<class T, class Alloc= alloc<T> >
class vector{
    public:
        void my_swap(vector<T, Alloc>& ){
            std::cout << "Swap()" << endl;
            
        }
};
};
int main(){
    M::vector<int> v;
    M::vector<int> v1;
    v.my_swap(v1);
}