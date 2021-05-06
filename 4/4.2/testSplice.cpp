// CPP program to illustrate the 
// list::splice() function 
#include <stdc++.h> 
using namespace std; 
  
int main() 
{ 
    // initializing lists and iterator 
    list<int> l1 = { 1, 2, 3, 4, 5 }; 
    list<int> l2 = { 6, 7, 8 }; 
    list<int>::iterator it; 
  
    // iterator pointing to 1 
    it = l1.begin(); 
  
    // advance the iterator by 2 positions 
    advance(it, 2); 
  
    // transfer 3, 4 and 5 at the 
    // beginning of l2 
    l2.splice(l2.begin(), l2, it, l1.end()); 
  
    cout << "list l2 after splice operation" << endl; 
    for (auto x : l2) 
        cout << x << " "; 
    return 0; 
}