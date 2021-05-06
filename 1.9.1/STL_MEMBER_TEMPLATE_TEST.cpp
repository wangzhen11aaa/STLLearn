#include <iostream>
using namespace std;

class alloc{

};
namespace M{
template<class T, class Alloc=alloc>
class vector{
    public:
        typedef T value_type;
        typedef value_type* iterator;

        template<class I>
        void insert(iterator position, I first, I last){
            cout << "insert() " << endl;
        }
};
};
int main(){
    int ia[5] = {0, 1, 2, 3, 4};
    M::vector<int> x;
    M::vector<int>::iterator ite;
    x.insert(ite, ia, ia+5);
}