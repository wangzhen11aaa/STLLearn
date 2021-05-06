#include "myList.h"
#include <algorithm>

using namespace std;
int main(){
    //SimpleList<int> slInt(5, 10);
    SimpleList<int> slInt;
    slInt.push_back(1);
    slInt.push_back(3);
    
    std::cout<<slInt<<std::endl;
    std::cout<<slInt.size()<<std::endl; // 8
    // Test transfer.
    SimpleList<int> slInt1;
    slInt1.push_back(2);
    slInt1.push_back(4);

    SimpleList<int>::iterator i = find(slInt.begin(), slInt1.end(), 1);
    std::cout << "Find iterator i : " << *i << std::endl;

    slInt.transfer(i, slInt1.begin(), slInt1.end());

    cout << "Print the last result of slInt " << endl;
    cout << slInt << endl;

    cout << "Print the last result of slInt1 " << endl;
    cout << slInt1 << endl;
    //SimpleList<int> slInt()

    slInt.erase(2);
    slInt.erase(4);

    cout << "After erasing, print the last result of slInt " << endl;
    cout << slInt << endl;

    cout << "Fill slInt1" << endl;
    slInt1.push_back(2);
    slInt1.push_back(4);

    cout << "---------------" << endl;
    cout << "Start test merge() " << endl;
    cout << "Print slInt" << endl;
    cout << slInt << endl;;
    cout << "---------------" << endl;
    cout << "Print slInt1" << endl;
    cout << slInt1 << endl;;
    
    cout << "---------------" << endl;
    slInt.merge(slInt1);

    cout << "End of  test merge() " << endl;
    cout << slInt << endl;

    // Reverse algorithm
    slInt.reverse();
    cout << "End of reverse " << endl;
    cout << slInt << endl;
}