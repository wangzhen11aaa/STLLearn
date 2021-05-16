#include "2jjalloc.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int ia[5] = {0,1,2,3,4};
    unsigned int i;
    {
        vector<int, JJ::allocator<int> > iv(ia, ia+5);
        for(i = 0; i < iv.size(); i++){
            cout << iv[i] << endl;
        }
        //JJ::allocator<int> alloc;
        auto it = iv.begin();
        printf ("Address of iv.data : %p \n" ,iv.data());
        cout << "Distance : " << std::distance(iv.begin(), it) << std::endl;
        //alloc.deallocate(iv.data()+std::distance(iv.begin(),it), 1);
    }

    cout << "end of program";
    cout << endl;
}