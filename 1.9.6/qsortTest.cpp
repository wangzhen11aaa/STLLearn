#include <cstdlib>
#include <iostream>
using namespace std;

int fcmp(const void *elem1, const void *elem2);

int main(){
    int ia[4] = {32,92, 2,4};
    for (int i = 0; i < 4; i++){
        cout << ia[i] << endl;
    }
    qsort(ia, sizeof(ia)/sizeof(int), sizeof(int), fcmp);

    cout << "After soft " << endl;
    for (int i = 0; i < 4; i++){
        cout << ia[i] << endl;
    }

}
int fcmp(const void *elem1, const void *elem2){
    const int* i1 = (const int*) elem1;
    const int* i2 = (const int*) elem2;

    if (*i1 < *i2) return -1;
    else if (*i1 == *i2) return 0;
    else if (*i1 > *i2) return 1;
}